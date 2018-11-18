/*************************************************************************
	> File Name: master.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年11月15日 星期四 18时37分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "./master.h"

#define INS 5
#define PORT 33333

void *func(void *);

int queue[INS + 1] = {0};

typedef struct Node {
    struct sockaddr_in addr;
    struct Node *next;
}Node, *LinkedList;

LinkedList linkedlist[INS + 1];

typedef struct Mypara{
    struct sockaddr_in addr;
    int num;
}Mypara;

//FILE *log[INS + 1];

Node insert(LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    //ret.data = 0;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
        //ret.data = 1;
    }
    return ret;
}

void output(LinkedList head, int num) {
    if (head == NULL) {
        printf("empty\n");
        return ;
    }
    Node *p = head;
    char logfile[20];
    while (p) {
        printf("%s:%d\n", inet_ntoa(p->addr.sin_addr), ntohs(p->addr.sin_port));
        p = p->next;
    }
    printf("\n");
    return ;
}

int find_min(int N, int *arr) {
    int min = arr[0];
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (min > arr[i]) {
            min = arr[i];
            ans = i;
        }
    }
    return ans;
}

int get_conf_value(char *pathname, char *key_name, char *value) {
    FILE *fp = NULL;
    if ((fp = fopen (pathname, "r")) == NULL) {
        printf ("pathname NULL!\n");
        exit(0);
    }
    size_t len = 0;
    char *line = NULL;
    ssize_t  read;
    int key_len = strlen(key_name);
    while (( read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, key_name) != NULL) {
            if (line[key_len] == '=') {
                strncpy(value, &line[key_len + 1], read - key_len - 1);
                key_len = strlen(value);
                value[key_len - 1] = '\0';
                fclose(fp);
                return 1;
            }
        }
    } 
    fclose(fp);
    return 0;
}

int create_listen(int port) {
    int server_listen;
    struct sockaddr_in my_addr;
    if ((server_listen = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        perror("socket error");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(PORT);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&(my_addr.sin_zero), sizeof(my_addr));
    if (bind(server_listen, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0) {
		perror("bind error");
        //close(server_listen);
		return -1;
	}
    if (listen(server_listen, 20) < 0) {
        perror("listen error");
        exit(0);
    }
    return server_listen;
}

int exist(struct sockaddr_in addr) {
    for (int i = 0; i < INS; i++) {
        Node *p = linkedlist[i];
        while (p) {
            if (p->addr.sin_addr.s_addr == addr.sin_addr.s_addr) {
                return 1;
            }
            p = p->next;
        }
    }
    return 0;
}

Node *delete_node(LinkedList head, Node *del) {
    Node *p, *q, ret;
    ret.next = head;
    p = &ret;
    q = p->next;
    while (q) {
        if (q->addr.sin_addr.s_addr == del->addr.sin_addr.s_addr) {
            //printf("delete %s:%d\n", inet_ntoa(q->addr.sin_addr), ntohs(q->addr.sin_port));
            p->next = q->next;
            free(q);
            break;
        }
        p = p->next;
        q = q->next;
    }
    return ret.next;
}

void connect_or_delete(LinkedList head) {
    Node *p = head, *temp;
    while (p) {
        int sockfd;
        if (connect(sockfd, (struct sockaddr *)&(p->addr), sizeof(struct sockaddr)) < 0) {
            //printf("connect error\n");
            temp = p->next;
            head = delete_node(head, p);
            p = temp;
        } else {
            p = p->next;
        }
    }
    output(head, 1);
   return ; 
}

int main() {
    //freopen("in.in", "r", stdin);
    pthread_t t[INS + 1];
    Mypara para[INS + 1];
    char value[20] = {0}, start[10] = {0}, finish[10] = {0}, port[10] = {0};
    get_conf_value("./config.conf", "prename", value);
    get_conf_value("./config.conf", "start", start);
    get_conf_value("./config.conf", "finish", finish);
    get_conf_value("./config.conf", "port", port);
    for (int i = atoi(start); i <= atoi(finish); i++) {
        char ip[100];
        sprintf(ip, "%s.%d", value, i);
        //printf("%s\n", ip);
        struct sockaddr_in addr;
        addr.sin_port = htons(atoi(port));
        addr.sin_addr.s_addr = inet_addr(ip);
        int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->addr = addr;
        p->next = NULL;
        ret = insert(linkedlist[sub], p, queue[sub]);
        queue[sub]++;
        linkedlist[sub] = ret.next;
    }
    //sleep(1);
    /*
    for (int i = 0; i < INS; i++) {
        printf("%d ", queue[i]);
        printf("   ......\n");
        output(linkedlist[i], i);
    }
    */
    for (int i = 0; i < INS; i++) {
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
        //printf("Current pthread id = %ld\n", t[i]);
    }
    /*
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);
    */
    int server_listen = create_listen(PORT);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        int socketfd;
        if ((socketfd = accept(server_listen, (struct sockaddr*)&client_addr, &len)) < 0) {
            perror("accept error");
            break;
        }
        if (exist(client_addr)) {
            printf("already exists\n");
            continue;
        }
        int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->addr = client_addr;
        p->next = NULL;
        ret = insert(linkedlist[sub], p, queue[sub]);
        queue[sub]++;
        linkedlist[sub] = ret.next;
        printf("insert into %d linkedlist\n", sub);
        output(linkedlist[sub], sub);
    }
    return 0;
}

void *func(void *argv) {
    Mypara *para;
    para = (Mypara *)argv;
    connect_or_delete(linkedlist[para->num]);
    /*
    //printf("%s %d\n", para->s, para->num);
    Node *p, ret;
    p = (Node *)malloc(sizeof(Node));
    p->addr = para->addr;
    p->next = NULL;
    ret = insert(linkedlist[para->num], p, queue[para->num]);
    queue[para->num]++;
    linkedlist[para->num] = ret.next;
    */
    return NULL;
}
