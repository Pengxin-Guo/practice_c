/***********************mZ*************************************************
	> File Name: if_code.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月18日 星期二 18时29分31秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("FOOLISH\n");
    } else if (n < 60) {
        printf("FALL\n");
    } else if (n < 75) {
        printf("MEDIUM\n");
    } else if (n <= 100) {
        printf("GOOD\n");
    }
    return 0;
}
