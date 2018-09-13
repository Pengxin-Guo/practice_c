/*************************************************************************
	> File Name: num_str.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月13日 星期四 19时28分18秒
 ************************************************************************/
//读入一个行字符串（可能包含空格），输出这个字符串中字符的数量

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    char str[100];
    scanf("%[^\n]s", str);
    n = printf("%s", str);
    printf(" has %d digits\n", n);
    return 0;
}
