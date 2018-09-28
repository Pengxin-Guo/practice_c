/*************************************************************************
> File Name: server.c
> Author: gpx
> Mail: 1457495424@qq.com
> Created Time: 2018年09月24日 星期一 11时13分19秒
************************************************************************/

#include "./head.h"

#define PORT 33333                                                                                //端口号

int main() {
    int a = 0;
	int server_listen, socketfd, pid;
    struct sockaddr_in my_addr;
    if ((server_listen = socket(AF_INET,SOCK_STREAM,0)) < 0) {                                    //建立socket
        perror("socket error");
        exit(1);
    }
    my_addr.sin_family = AF_INET;                                                                 //该属性表示接收本机或其他机器传输
	my_addr.sin_port = htons(PORT);                                                               //端口号，转化为网络字节序
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);                                                  //IP，括号内容表示本机IP
	bzero(&(my_addr.sin_zero), sizeof(my_addr));                                                  //将其他属性置0
    if (bind(server_listen, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0) {           //绑定地址结构体和socket
		perror("bind error");
        //close(server_listen);
		return -1;
	}
    if (listen(server_listen, 20) < 0) {                                                          //开启监听，第二个参数是最大监听数
        perror("listen error");
        exit(0);
    }                                       
    while (1) {
        struct sockaddr_in client_addr;                                                           //客户端socket
        socklen_t len = sizeof(client_addr);
        if ((socketfd = accept(server_listen, (struct sockaddr*)&client_addr, &len)) < 0) {       //建立服务器与客户端的连接
            perror("accept error");
            break;
        }
        bzero(&client_addr, len);
        char client_mess[20] = {"0"};
        getpeername(socketfd, (struct sockaddr *)&client_addr, &len);                             //用于获取与某个套接字关联的外地协议地址
        inet_ntop(AF_INET, (void *)&client_addr.sin_addr, client_mess, 63);
        if ((pid = fork()) < 0) {
            perror("Erroe forking child process");
        }
        if (pid == 0) {
            close(server_listen);
            char message[MAX_SIZE] = {0};
            FILE *fpcpu, *fpdisk, *fpmem;
            if (opendir(client_mess) == NULL) {
                mkdir(client_mess, 0755);
            }
            char filecpu[10] = {0};
            sprintf(filecpu, "./%s/CPULog.log", client_mess);
            fpcpu = fopen(filecpu, "a+");
            char filedisk[10] = {0};
            sprintf(filedisk, "./%s/DiskLog.log", client_mess);
            fpdisk = fopen(filedisk, "a+");
            char filemem[10] = {0};
            sprintf(filemem, "./%s/MemLog.log", client_mess);
            fpmem = fopen(filemem, "a+");
            while ((a = recv(socketfd, message, MAX_SIZE - 1, 0)) > 0) {
                message[a] = '\0';
                //printf("%s\n", message); 
                if (message[0] == 'c') {
                    printf("%s***\n", message);
                    fprintf(fpcpu, "%s", message + 1);
                    memset(message, 0, sizeof(message));
                } else if (message[0] == 'd') {
                    printf("%s*****\n", message);
                    fprintf(fpdisk, "%s", message + 1);
                    memset(message, 0, sizeof(message));
                } else if (message[0] == 'm') {
                    printf("%s********\n", message);
                    fprintf(fpmem, "%s", message + 1);
                    memset(message, 0, sizeof(message));
                }
            }
            //printf("\n");
            fclose(fpcpu);
            fclose(fpdisk);
            fclose(fpmem);
            close(socketfd);
            exit(0);
        }
        close(socketfd);
    }
    close(server_listen);
	return 0;
}
