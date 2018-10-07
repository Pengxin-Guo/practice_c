/*************************************************************************
	> File Name: palindrome_number.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 20时11分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int palindrome_number(int x) {
    int temp = x, num = 0;
    while (temp) {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    return num == x;
}
