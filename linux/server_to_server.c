/*************************************************************************
> File Name: cl2.cpp
> Author: ldc
> Mail: litesla
> Created Time: 2018年09月24日 星期一 10时25分36秒
************************************************************************/

#include "./head.h"

#define maxnbuf 1000

int main(int av,char *argv[]) {
    int fd_client;
    int size = 0;
    char buffer[maxnbuf];
    struct sockaddr_in dest_addr;
    int port = atoi(argv[2]);
    char *host = argv[1];

    if ((fd_client = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(fd_client, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("connect");
        return -1;
    }
    pid_t pid = fork();
    if (pid <= 0) {
        while (1) {
            size = recv(fd_client, buffer, sizeof(buffer), 0);
            if(size < 0) continue;
            buffer[size] = '\0';
            printf("%s : ", inet_ntoa(dest_addr.sin_addr));
            printf("%s\n", buffer);
        }
    }else{
        while (1) {
            scanf("%[^\n]s", buffer);
            getchar();
            size = send(fd_client,buffer,strlen(buffer), 0);
        }

    }
    close(fd_client);
    return 0;
}
