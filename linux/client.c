/*************************************************************************
	> File Name: client.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月23日 星期日 16时20分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "./head.h"
#define MAX_SIZE 100

int main(int argc, char *argv[]) {
    int sock_client;
    char buffer[MAX_SIZE];                                        //数据缓冲区
    struct sockaddr_in dest_addr;                                 //服务器端网络地址结构体
    int port = atoi(argv[2]);                                     //服务器端口号
    char *host = argv[1];                                         //代表服务器IP地址
    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {    //建立socket
        perror("Socket");
        return -1;
    }
    dest_addr.sin_family = AF_INET;                               //设置为IP通信
    dest_addr.sin_port = htons(port);                             //端口号
    dest_addr.sin_addr.s_addr = inet_addr(host);                  //服务器IP地址
    if (connect(sock_client, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) < 0) {
        perror("Connent");
        return -1;
    }
    while (1) {
        scanf("%[^\n]s", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
    }
    close(sock_client);
    return 0;
}
