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
    Node *p = head;
    char logfile[20];
    while (p) {
        //printf("%d ", p->data);
        printf("假装在输出*** ");
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

int main() {
    //freopen("in.in", "r", stdin);
    pthread_t t[INS + 1];
    Mypara para[INS + 1];
    int temp;
    for (int i = 0; i < INS; i++) {
        //para[i].addr = ?;
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
        printf("Current pthread id = %ld\n", t[i]);
    }

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);

    while (1) {
        int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        //p->addr = ?;
        p->next = NULL;
        ret = insert(linkedlist[sub], p, queue[sub]);
        queue[sub]++;
        linkedlist[sub] = ret.next;
    }

    for (int i = 0; i < INS; i++) {
        printf("%d ", queue[i]);
        printf("   ......   ");
        output(linkedlist[i], i);
    }
    printf("\n");
    return 0;
}

void *func(void *argv) {
    Mypara *para;
    para = (Mypara *)argv;
    //printf("%s %d\n", para->s, para->num);
    Node *p, ret;
    p = (Node *)malloc(sizeof(Node));
    p->addr = para->addr;
    p->next = NULL;
    ret = insert(linkedlist[para->num], p, queue[para->num]);
    queue[para->num]++;
    linkedlist[para->num] = ret.next;
    return NULL;
}
