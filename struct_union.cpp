/*************************************************************************
> File Name: struct_union.c
> Author: gpx
> Mail: 1457495424@qq.com
> Created Time: 2018年10月04日 星期四 12时08分12秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct test {
    char b;
    short a;
    int c;
    double d;
};

struct Number {
    int type; // 0->int or 1->double 
    union {
        int num1;
        float num2;
    } N;
};

void print(struct Number *n) {
    switch (n->type) {
        case 0: printf("%d\n", n->N.num1);break;
        case 1: printf("%f\n", n->N.num2);break;
    }
    return ;
}

void set(struct Number *n, float num) {
    n->type = 1;
    n->N.num2 = num;
    return ;
}

void set(struct Number *n, int num) {
    n->type = 0;
    n->N.num1 = num;
    return ;
}

int main() {
    srand(time(0));
    struct test a;
    printf("sizeof(person) : %d\n", sizeof(struct person));
    printf("%p %p %p", &a.a, &a.b, &a.c);
    struct Number arr[20];
    for (int i = 0; i < 20; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0: {
                int value = rand() % 100;
                set(arr + i, value);
            } break;
            case 1: {
                float value = (1.0 * (rand() % 10000) / 10000) * 100;
                set(arr + i, value);
            } break;
        }
    }
    for (int i = 0; i < 20; i++) {
        print(arr + i);
    }
    arr[0].N.num2 = 1.0;
    printf("arr[0].N.num1 = %d\n", arr[0].N.num1);
    printf("arr[0].N.num1 = %x\n", arr[0].N.num1);
    return 0;
}
