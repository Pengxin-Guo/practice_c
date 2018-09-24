/*************************************************************************
	> File Name: define.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月23日 星期日 12时48分27秒
 ************************************************************************/

#include <stdio.h>

#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    int a = 7;
    P(MAX(a++, 6));
    printf("a = %d\n", a);
    return 0;
}
