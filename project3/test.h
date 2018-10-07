/*************************************************************************
	> File Name: test.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月05日 星期五 15时17分05秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <stdlib.h>

struct TestFuncData{
    int total, expect;
};

typedef void (*test_func_t)();
struct FuncData {
    const char *a_str, *b_str;
    test_func_t func;
    struct FuncData *next;
};

struct FuncData *FuncData_head = NULL;

struct FuncData *getFuncData(const char *a, const char *b, test_func_t func, struct FuncData *next) {
    struct FuncData *p = (struct FuncData *)malloc(sizeof(struct FuncData));
    p->a_str = a;
    p->b_str = b;
    p->func = func;
    p->next = next;
    return p;
}

#define TEST(a,b) \
    void a##_haizeix_##b(struct TestFuncData *); \
    __attribute__((constructor)) \
    void ADDFUNC_##a##_haizeix_##b() { \
        FuncData_head = getFuncData(#a, #b, a##_haizeix_##b, FuncData_head); \
    } \
    void a##_haizeix_##b(struct TestFuncData *__data)

#define EXPECT(a, b) ({ \
    int ret; \
    printf("%s == %s %s\n", #a, #b, (ret = (a == b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})


int RUN_ALL_TEST() {
    struct FuncData *current_node, *next_node;
    if (FuncData_head == NULL) return 0;
    current_node = FuncData_head->next;
    FuncData_head->next = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = FuncData_head;
        FuncData_head = current_node;
        current_node = next_node;
    }
    char color[3][100] = {
        "[ \033[1;32m%.2lf%%\033[0m ] total : %d，expect : %d\n",
        "[ \033[0;31m%.2lf%%\033[0m ] total : %d，expect : %d\n",
        "[ \033[1;31m%.2lf%%\033[0m ] total : %d，expect : %d\n"};
    for (struct FuncData *p = FuncData_head; p; p = p->next) {
        printf("[%s, %s]\n", p->a_str, p->b_str);
        struct TestFuncData data = {0, 0};
        p->func(&data);
        double rate = 1.0 * data.expect / data.total * 100;
        int index = 0;
        if (rate < 100) index = 1;
        if (rate < 50) index = 2;
        printf(color[index], rate, data.total, data.expect);
    }
    return 0;
}



#endif
