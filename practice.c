/*************************************************************************
	> File Name: practice.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月20日 星期四 21时01分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

int digit(int n) {
    return floor(log10(n)) + 1;
}

struct test {
    char a;
    char b;
    char c;
    int d;
};

struct Data {
    int x, y;
};

int main() {
    /*int n = 123;
    printf("%d\n", printf("hello world\n"));
    printf("%d\n", printf("n = %d\n", n));
    printf("%d\n", printf("n = %d\n", 12000));
    printf("%d\n", printf("n = %d\n", -567));
    printf("%d\n", printf("n = %d\n", INT32_MIN));
    printf("%d\n", printf("n = %d\n", INT32_MAX));

    int temp = 0;
    temp |= 1, 2;
    printf("%d\n", temp);

    printf("%d\n", digit(0));

    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(int));

    struct test aaa;
    printf("%p %p %p %p\n", &aaa.a, &aaa.b, &aaa.c, &aaa.d);

    struct Data a[2], *p = a;
    //表示a[1].x;
    a[1].x;
    p[1].x;
    (a + 1)->x;
    (p + 1)->x;

    int a[2][3] = {{1, 2, 4}, {4, 5, 5}};
    int *p;
    p = &a[0][0];
    printf("%p\n", p);
    printf("%d", *(p + 3));
    printf("%p %p\n", p, &a[1][0]);*/

    int arr[2][3] = {-1};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
