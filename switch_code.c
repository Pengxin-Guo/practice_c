/*************************************************************************
	> File Name: switch_code.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月18日 星期二 18时52分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1: printf("one\n"); break;
        case 2: printf("two\n"); break;
        case 3: printf("three\n"); break;
        default : printf("error\n");
    }
    return 0;
}
