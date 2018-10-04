/*************************************************************************
> File Name: ip_num_union.c
> Author: gpx
> Mail: 1457495424@qq.com
> Created Time: 2018年10月04日 星期四 10时08分19秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

union IP {
    unsigned char arr[4];
    unsigned int num;
};

int main() {
    int a, b, c, d;
    union IP ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.arr[0] = a;
        ip.arr[1] = b;
        ip.arr[2] = c;
        ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
