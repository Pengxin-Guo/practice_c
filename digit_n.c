/*************************************************************************
	> File Name: digit_n.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月18日 星期二 20时52分44秒
 ************************************************************************/

//用while循环判断一个整数的位数

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, num;
    scanf("%d", &n);
    num = (n == 0);
    while (n) {
        num++;
        n /= 10;
    }
    printf("%d\n", num);
    return 0;
}
