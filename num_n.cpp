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
    FILE *fout = fopen("/dev/null", "w");
    char str[100];
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", fprintf(fout, "%d", n));     //输出数字n的位数
        printf("%d\n", sprintf(str, "%d", n));      //输出数字n的位数

        //sprintf的另一种用法
        for (int i = 1, j = 0; i <= 20; i++) {
            j += sprintf(str + j, "%d", i);         //将1到20拼接到数组str中
        }
        printf("str = %s\n", str);
    }
    return 0;
}
