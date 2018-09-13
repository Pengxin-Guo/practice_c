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
    int num;
    FILE *file = fopen("/dev/null", "w");
    while (scanf("%d", &num) != EOF) {
        printf("%d\n",fprintf(file, "%d", num));
    }
    return 0;
}
