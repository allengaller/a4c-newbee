#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<seeno.h>

#define EHCO_PORT 8080
#define MAX_CLIENT_NUM 10

int main()
{
    int socket_fd;
    struct sockaddr_in serv_addr;
    int clientfd;
    struct sockaddr_in clientAdd;
    char buff[101];
    socklen_t len;
    int closing =0;
    int n;

    /*创建Socket*/
    sick_fd = socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd==-1){
        perror("Create socket error!\");
        return 0;
    }else{
        printf("Success to create socket %d\n",sock_fd);
    }

    /*设置server地址结构*/
    bzero(&serv_addr, sizeof(serv_addr));//初始化结构占用的内存
    serv_addr.sin_family = AF_INET:      //设置地址传输层类型
    serv_addr.sin_port = htons(EHCO_PORT);//设置监听端口
    serv_addr.sin_addr.s_addr = htons(INADDR_ANY);//设置服务器地址
    bzero(&(serv_addr.sin_zero),8);

    /*把地址和套接字绑定*/
    if(bind(sock_fd,(struct sockaddr*)&serv_addr, sizeof(serv_addr))!=0){
        printf("bind address fail! %d\n",errno);
        close(sock_fd);
        return 0;
    }else{
        printf("Sucess to bind address!\n");
    }
    
}
