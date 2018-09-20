/*************************************************************************
	> File Name: factorial.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月20日 星期四 18时43分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fact(n));
    return 0;
}
