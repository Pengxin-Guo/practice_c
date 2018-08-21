/*************************************************************************
	> File Name: sum_a_b.cpp
	> Author:gpx 
	> Mail:1457495424@qq.com 
	> Created Time: 2018年08月21日 星期二 10时21分23秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        int c, d;
        while (b != 0) {
            c = a ^ b;
            d = (a & b) << 1;
            a = c;
            b = d;
        }
        printf("%d\n", a);
    }
    return 0;
}
