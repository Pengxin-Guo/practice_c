/*************************************************************************
	> File Name: num_n.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月13日 星期四 18时30分05秒
 ************************************************************************/
//使用printf函数，求解一个数字n的十进制表示的数字位数

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    //FILE *file = fopen("/dev/null", "w");
    char buffer[100];
    while (scanf("%d", &n) != EOF) {
        //printf("%d\n",fprintf(file, "%d", n));
        printf("%d\n", sprintf(buffer, "%d", n));
    }
    return 0;
}
