#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#include "post.h"

#define SA      struct sockaddr
#define MAXLINE (4096*5)

#define MAX_URL_LEN     (128)

//static void http_post_thread(post_info *pi);

extern int h_errno;

struct url_info {
    char ip[16];
    short port;
    char *page;
};

static ssize_t process_http(int sockfd, char *poststr, struct url_info *ui)
{
    char sendline[MAXLINE + 1], recvline[MAXLINE + 1];
    ssize_t n;
    snprintf(sendline, MAXLINE,
            "POST %s HTTP/1.1\r\n"
            "Host: \r\n"
            "Content-type: text/plain\r\n"
            "Content-length: %d\r\n\r\n"
            "%s", ui->page, strlen(poststr), poststr);

    printf("sendline = \n%s\n", sendline);

    write(sockfd, sendline, strlen(sendline));
    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = '\0';
        printf("%s\n", recvline);
    }
    printf("hahaha\n");
    return n;
}

static void url_parse(struct url_info *ui,const char *url)
{
    char *path;
    char port[10] = {0};
    unsigned short size = 0;
    unsigned int p = 80;
    unsigned short isport = 0;

    if(NULL == url)
    {
        return;
    }
    printf("url = \"%s\"\n", url);

    /* Find host IP */
    if ((path = strstr(url, "://")) != NULL) {		   
        path += 3;

    } else if((path = strstr(url, ":/")) != NULL) {
        path += 2;
    }

    if ((strstr(path, ":")) != NULL) {
        size = strcspn(path, ":");
        isport = 1;
    } else {
        size = strcspn(path, "/");
    }

    memcpy(ui->ip, path, size);

    /* Find host port */
    if(isport) {
        path += size+1;
        size = strcspn(path, "/");
        memcpy(port, path, size);
        p = atoi(port);
    }
    /* Find host port*/
    ui->port = p;

    /* Find host page*/
    path += size;
    ui->page = path;
}


void* http_post_thread(post_info *pi)
{
    pthread_detach(pthread_self());
    int sockfd;
    long count = 0;
    struct sockaddr_in servaddr;

    char **pptr;

    struct url_info *ui;

    printf("http post 1");
    ui = (struct url_info *) calloc(1, sizeof(*ui));
    if (ui == NULL) {
        printf("calloc error");
        goto end;
    }

    printf("http post 2");
    if(NULL == pi->url){
        printf("url is NULL\n");
        goto end;
    }
    url_parse(ui, pi->url);//url解析

    printf("ui->ip: %s\n", ui->ip);//解析出来的ip
    printf("ui->port: %d\n", ui->port);//解析出来的端口号
    //printf("ui->page: %s\n", ui->page);

    char str[50];
    struct hostent *hptr;
    if ((hptr = gethostbyname(ui->ip)) == NULL) {
        fprintf(stderr, " gethostbyname error for host: %s: %s",
                ui->ip, hstrerror(h_errno));
        goto end;
    }
    //printf("hostname: %s\n", hptr->h_name);
    if (hptr->h_addrtype == AF_INET
            && (pptr = hptr->h_addr_list) != NULL) {
        printf("address: %s\n",
                inet_ntop(hptr->h_addrtype, *pptr, str,
                    sizeof(str)));
    } else {
        fprintf(stderr, "Error call inet_ntop \n");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(ui->port);
    inet_pton(AF_INET, str, &servaddr.sin_addr);

    connect(sockfd, (SA *) & servaddr, sizeof(servaddr));
    process_http(sockfd, pi->poststr, ui);
    close(sockfd);
    //printf("Count: %d\n", ++count);

    free(ui);
    ui = NULL;
end: 
    free(pi->url);
    pi->url = NULL;
    free(pi->poststr);
    pi->poststr = NULL;
    free(pi);
    pi = NULL;
    return NULL;
}

void http_post(post_info *pi)
{
    pthread_t pid;
    int rc;
    post_info *th_pi = NULL;
    char* poststr = NULL;
    char* url = NULL;

    url = malloc(MAX_URL_LEN);
    memset(url, 0, MAX_URL_LEN);
    memcpy(url, pi->url, strlen(pi->url));

    poststr = malloc(pi->postlen+1);
    memset(poststr, 0, pi->postlen+1);
    memcpy(poststr, pi->poststr, pi->postlen);

    th_pi = malloc(sizeof(post_info));
    th_pi->url = url;
    th_pi->poststr = poststr;
    th_pi->postlen = pi->postlen;


    rc = pthread_create(&pid, NULL, (void *)http_post_thread, th_pi);//启动线程
    if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        perror("[Create Post Thread]");
    }
}

  
int main(void) {

    post_info *pi;
    pi = (struct post_info *) calloc(1, sizeof(*pi));
    if (pi == NULL) {
        printf("calloc error");
        return 0;
    }
    pi->url = "http://127.0.0.1:8888/foo?my_var=BianJiang";
    pi->poststr = "<msg> hello,wolrd </msg>\r\n";

    http_post(pi);

    free(pi); 
    printf("main end");
}

