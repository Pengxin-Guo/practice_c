/*************************************************************************
	> File Name: var_para.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月20日 星期四 19时35分14秒
 ************************************************************************/

//实现可变参数max_int，从若干个传入的参数中返回最大值。
//int max_int(int n, ...);

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max_int(int num, ...) {
    int ans = 0, temp;
    va_list arg;
    va_start(arg, num);
    while (num--) {
        temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 1, 5, 3));
    printf("%d\n", max_int(2, 1, 3));
    printf("%d\n", max_int(6, 6, 5, 3, 7, 9, 10));
    printf("%d\n", max_int(3, 1, 9, 10));
    return 0;
}
