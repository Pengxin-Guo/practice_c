/*************************************************************************
	> File Name: guang.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年11月13日 星期二 19时55分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "./head.h"

void *my_fun(int n) {
    printf("子线程id:%lu 遍历树莓派%d\n", pthread_self(), n);
    return NULL;
}

int main() {
    pthread_t pthid;
    int res, i;
    for (i = 1; i <= 5; i++) {
        res = pthread_create(&pthid, NULL, my_fun(i), NULL);
        printf("%lu***\n", pthid);
        if(res != 0)
        {
            printf("%s***\n",strerror(res));   //打印错误信息
            break;
        }
        printf("i : %d\n", i);
    }
    printf("主线程id:%lu\n", pthread_self());
    sleep(2);
    //pthread_exit(NULL);            // 退出当前线程, 并没有结束整个进程
    return 0;
}
