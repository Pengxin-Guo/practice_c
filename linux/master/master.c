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

int queue[INS + 1] = {0};                                                // queue[i]代表第i个链表中连接的节点数量

typedef struct Node {
    int data;                                                            // 数据类型
    struct Node *next;
}Node, *LinkedList;

LinkedList linkedlist[INS + 1];                                          // linkedlist[i]代表第i个线程的链表

typedef struct Mypara{
    char *s;                                                             // 数据类型(实际项目中应与Node中的data一致)
    int num;                                                             // 记录是第几个线程
}Mypara;

//FILE *log[INS + 1];

Node insert(LinkedList head, Node *node, int index) {                    // 在head的末尾插入node, 返回虚拟头结点
    Node *p, ret;
    p = &ret;
    ret.data = 0;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
        ret.data = 1;
    }
    return ret;
}

void output(LinkedList head, int num) {
    Node *p = head;
    char logfile[20];
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

int find_min(int N, int *arr) {                                          // 找到连接的节点数最少的链表, 并返回这个链表下标
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
    freopen("in.in", "r", stdin);                                        // 用in.in这个文件代替标准输入
    pthread_t t[INS + 1];
    Mypara para[INS + 1];
    int temp;
    for (int i = 0; i < INS; i++) {                                      // 开5个子线程
        para[i].s = "Hello HaiZei!";
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
    // 等待5个子线程都执行完了, 主线程再继续执行
    while (scanf("%d", &temp) != EOF) {
        int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->data = temp;
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
    printf("%s %d\n", para->s, para->num);
    Node *p, ret;
    for (int i = para->num; i <= 10; i++) {
        p = (Node *)malloc(sizeof(Node));
        p->data = i;
        p->next = NULL;
        ret = insert(linkedlist[para->num], p, queue[para->num]);
        queue[para->num]++;
        linkedlist[para->num] = ret.next;
    }
    output(linkedlist[para->num], para->num);
    return NULL;
}
