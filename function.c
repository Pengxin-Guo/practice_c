/*************************************************************************
	> File Name: function.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月20日 星期四 20时10分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

int is_prime(int x);
int max_int(int n, ...);

int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);
    }
    P(max_int(3, 1, 2, 3));
    P(max_int(4, 1, 2, 4, 9));
    return 0;
}
