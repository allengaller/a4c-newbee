
/* Sorgente prelevato da http://sorgenti.big-bug.net
 * Autore: BlackLight - http://blacklight.gotdns.org/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>


#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_SEND_ATTEMPTS 100

int err=1;
unsigned int lport;

/**
 * Invia un buffer sul socket
 * @param sock socket usato per la comunicazione
 * @param buffer puntatore al buffer in memoria
 * @param bufferSize dimensione del buffer in byte
 * @return FALSE in caso di errore.
 */
int tcpSendBuffer(int sock, char * buffer, unsigned int bufferSize)
{
   int bytes_sent;
   unsigned int total = 0;
   unsigned int attempts = MAX_SEND_ATTEMPTS;

   while ((total < bufferSize) && (attempts > 0)) {
      bytes_sent = send( sock, (void *)(buffer+total), (bufferSize-total), 0 );
      if (bytes_sent > 0) total += bytes_sent;
      attempts--;
   };
   
   printf("SEND BUFFER: [%u/%u] bytes. Attempts left: %u\n", total, bufferSize, attempts);

   return (total == bufferSize);	
}


int sockopen (char *host, int port)  {
        int sd;
        char ip[INET6_ADDRSTRLEN];
        struct sockaddr_in server;
        struct hostent *h;


        if ((sd=socket(AF_INET,SOCK_STREAM,0))<0)  {
                return -1;
        }
	
        if (!(h=gethostbyname(host)))  {
                return -1;
        }

        snprintf (ip,sizeof(ip),"%u.%u.%u.%u",
                 h->h_addr[0]&0xFF,h->h_addr[1]&0xFF,h->h_addr[2]&0xFF,h->h_addr[3]&0xFF);

        server.sin_family=h->h_addrtype;
        server.sin_port=htons((unsigned short) port);
        server.sin_addr.s_addr=inet_addr(ip);

        if (connect(sd, (struct sockaddr*) &server, sizeof(struct sockaddr))<0)  {
                return -1;
        }

        return sd;
}

void help()  {
        printf (
               "*** Tiny FTP client - by BlackLight ***\n"
               "\ttftp [options] server\n\n"
               "Options\n\n"
               "\t-h\t\tPrint this help\n"
               "\t-p <port>\tSelect a different port to connect to (default: 21)\n"
               "\t-l <port>\tSelect a different port to listen on in active mode (default: random)\n"
               "\t-U <user>\tUsername to use (default: anonymous)\n"
               "\t-P <pass>\tPassword to use (default: none)\n"
        );
}

void* read_thread (void *arg)  {
      int *sd = (int*) arg;
      char ch;

      while (recv(*sd,&ch,1,0)>0)
            printf ("%c",ch);

      pthread_exit(0);
      return NULL;
}

void* listen_loop (void *arg)  {
      int *sd = (int*) arg;
      int my_sd;
      int len=sizeof(struct sockaddr);
      char ch;
      struct sockaddr_in client;

      if (listen(*sd,1)<0)
         pthread_exit(&err);

         while (1)  {
                 if ((my_sd=accept(*sd, (struct sockaddr*) &client, &len))<0)
                         pthread_exit(&err);

                 while (recv(my_sd,&ch,1,0)>0)
                         printf ("%c",ch);

                 close(my_sd);
         }

      pthread_exit(0);
      return NULL;
}

int main (int argc, char **argv)  {
        int c,sd,act_sd;
        unsigned int port=21;
        int slen=sizeof(struct sockaddr_in);
        char buff[BUFSIZ],tmp[BUFSIZ],pcmd[BUFSIZ];
        char *user=NULL,*pass=NULL,*host=NULL;
        struct sockaddr_in server,client;
        pthread_t t,sock;

	printf("argc: %d argv: %s %s %s\n", argc, argv[0], argv[1], argv[2]);
        srand ((unsigned) time(NULL));
        lport=(rand()%64511)+1024;

        if (!argv[1])  {
                help();
                exit(1);
        }

        while ((c=getopt(argc,argv,"hp:U:P:l:"))>0)  {
                switch (c)  {
                        case 'h':
                                help();
                                exit(0);
                                break;

                        case 'p':
                                port=atoi(optarg);
                                break;

                        case 'U':
                                user=optarg;
                                break;

                        case 'P':
                                pass=optarg;
                                break;

                        case 'l':
                             lport=atoi(optarg);
                             break;

                        default:
                                help();
                                exit(1);
                                break;
                }
        }

        host=argv[argc-1];

        if ((sd=sockopen(host,port))<0)  {
                printf ("%s - Connection error: %s\n",argv[0],strerror(errno));
                exit(2);
        }
        if (!user)
           user="anonymous";

        memset (buff,0,sizeof(buff));

        if (!pass)
           snprintf (buff,sizeof(buff),"USER %s\r\nSYST\r\n",user);
        else
           snprintf (buff,sizeof(buff),"USER %s\r\nPASS %s\r\nSYST\r\n",user,pass);

        send (sd,buff,strlen(buff),0);

        if (pthread_create(&t,NULL,read_thread,&sd))  {
           printf ("%s - Error creating thread: %s\n",argv[0],strerror(errno));
           exit(-1);
        }

        server.sin_family=AF_INET;
        server.sin_port=htons((unsigned short) lport);
        server.sin_addr.s_addr=INADDR_ANY;

        if ((act_sd=socket(AF_INET,SOCK_STREAM,0))<0)  {
           printf ("%s - Unable to create socket: %s\n",argv[0],strerror(errno));
           exit(1);
        }

        if (bind(act_sd, (struct sockaddr*) &server, slen)<0)  {
           printf ("%s - Unable to bind socket: %s\n",argv[0],strerror(errno));
           exit(1);
        }

           if (pthread_create(&sock,NULL,listen_loop,&act_sd))  {
                   printf ("%s - Error creating thread: %s\n",argv[0],strerror(errno));
                   exit(-1);
           }

           while (1)  {
                   memset (buff,0,sizeof(buff));

              printf ("tftp> ");
              fgets (buff,sizeof(buff),stdin);
              buff[strlen(buff)-1]=0;

              getsockname(sd, (struct sockaddr*) &client, &slen);

              snprintf (pcmd,sizeof(pcmd),"PORT %d,%d,%d,%d,%d,%d\r\n",
                       (client.sin_addr.s_addr & 0x000000FF),
                       (client.sin_addr.s_addr & 0x0000FF00) >> 8,
                       (client.sin_addr.s_addr & 0x00FF0000) >> 16,
                       (client.sin_addr.s_addr & 0xFF000000) >> 24,
                       (lport & 0xFF00) >> 8,
                       (lport & 0x00FF));

		printf("pcmd: %s", pcmd);
              if (!strcasecmp(buff,"help"))  {
                 printf (
                         "Commands:\n\n"
                         "help\t\tPrint this help\n"
                         "put\t\tSend files to the server\n"
                         "get\t\tGet a file from the server\n"
                         "rm\t\tRemove a file from the server\n"
                         "rename\t\tRename a file\n"
                         "mkdir\t\tMake a new directory\n"
                         "rmdir\t\tRemove a directory\n"
                         "ls\t\tShow directories on the server\n"
                         "pwd\t\tPrint current directory\n"
                         "cd\t\tChange current directory\n"
                         "quit\t\tQuit current session\n\n"
                         );
              }

              else if (!strcasecmp(buff,"put"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("Local file: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"STOR %s\r\n",tmp);
		
		printf("buff is: %s\n", buff);
		int sent;
	
                sent = send (sd,pcmd,strlen(pcmd),0);
		printf("first: %d\n", sent);
                sent =  send (sd,buff,strlen(buff),0);
		printf("second: %d\n", sent);

		/* test Giovanni
                 char *fileBuff;
                 FILE *fp;
                 int length;
                 
                 fp = fopen(tmp, "rb");
                 
                 rewind(fp);
                 fseek(fp, 0, SEEK_END);
                 length = ftell(fp);     //< legge la lunghezza del file

                 rewind(fp);
                 fileBuff = (char *)malloc(length * sizeof(char));
                 fread(fileBuff, length, 1, fp);
                 
                 tcpSendBuffer(sd, fileBuff, length);
                 free(fileBuff);
                 fclose(fp);
                  fine test Giovanni*/
              }

              else if (!strcasecmp(buff,"get"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("Remote file: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"RETR %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"rm"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("Remote file: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"DELE %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"rmdir"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("Remote directory: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"RMD %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"rename"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("Remote file: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"RNFR %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);

                 memset (buff,0,sizeof(buff));
                 printf ("New name: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"RNTO %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"mkdir"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("New directory name: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"MKD %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"ls"))  {
                 snprintf (buff,sizeof(buff),"LIST\r\n");

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"cd"))  {
                 memset (buff,0,sizeof(buff));
                 printf ("Remote directory: ");
                 fgets (tmp,sizeof(tmp),stdin);
                 tmp[strlen(tmp)-1]=0;
                 snprintf (buff,sizeof(buff),"CWD %s\r\n",tmp);

                 send (sd,pcmd,strlen(pcmd),0);
                 send (sd,buff,strlen(buff),0);
              }

              else if (!strcasecmp(buff,"quit"))  {
                   memset (buff,0,sizeof(buff));
                   snprintf (buff,sizeof(buff),"QUIT");
                   send (sd,buff,strlen(buff),0);
                   printf ("Quitting tftp...\n");
                   break;
              }

              else  {
                    strncat (buff,"\r\n",sizeof(buff));

                    if (strcmp(buff,"\r\n"))  {
                       send (sd,pcmd,strlen(pcmd),0);
                       send (sd,buff,strlen(buff),0);
                    }
              }
        }

        close(sd);
        return 0;
}
