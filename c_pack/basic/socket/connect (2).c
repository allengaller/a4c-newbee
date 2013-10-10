
/* 利用socket的TCP client
此程序会连线TCP server，并将键盘输入的字符串传送给server。
TCP server范例请参考listen（）。
*/
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 1234
#define SERVER_IP “127.0.0.1”

main()
{
    int s;
    struct sockaddr_in addr;
    char buffer[256];
    if((s = socket(AF_INET,SOCK_STREAM , 0)) < 0) {
        perror("socket");
        exit(1);
    }

    /* 填写sockaddr_in结构*/
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    /* 尝试连线*/
    if(connect(s , &addr , sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    /* 接收由server端传来的信息*/
    recv(s , buffer , sizeof(buffer) , 0);
    printf("%s\n" , buffer);
    while(1) {
        bzero(buffer , sizeof(buffer));
        /* 从标准输入设备取得字符串*/
        read(STDIN_FILENO , buffer , sizeof(buffer));
        /* 将字符串传给server端*/
        if(send(s , buffer , sizeof(buffer) , 0) < 0) {
            perror("send");
            exit(1);
        }
    }
}

