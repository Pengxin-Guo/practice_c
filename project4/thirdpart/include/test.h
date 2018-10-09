/*************************************************************************
	> File Name: test.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月05日 星期五 15时17分05秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <stdlib.h>
#include <math.h>

struct TestFuncData{
    int total, expect;
};

typedef void (*test_func_t)(struct TestFuncData *);

struct FuncData {
    const char *a_str, *b_str;
    test_func_t func;
    struct FuncData *next;
};

void addFuncData(const char *a, const char *b, test_func_t func);

int RUN_ALL_TEST();

#define TEST(a,b) \
    void a##_haizeix_##b(struct TestFuncData *); \
    __attribute__((constructor)) \
    void ADDFUNC_##a##_haizeix_##b() { \
        addFuncData(#a, #b, a##_haizeix_##b); \
    } \
    void a##_haizeix_##b(struct TestFuncData *__data)

#define EXPECT(a, b) ({ \
    int ret; \
    printf("%s == %s %s\n", #a, #b, (ret = (a == b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#ifndef EPS
#define EPS 1e-7

#define EXPECT_EQ(a, b) ({ \
    int ret; \
    printf("%s = %s %s\n", #a, #b, (ret = (fabs(a - b) <= EPS)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#endif

#define EXPECT_GT(a, b) ({ \
    int ret; \
    printf("%s > %s %s\n", #a, #b, (ret = (a > b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#define EXPECT_LT(a, b) ({ \
    int ret; \
    printf("%s < %s %s\n", #a, #b, (ret = (a < b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#define EXPECT_NE(a, b) ({ \
    int ret; \
    printf("%s != %s %s\n", #a, #b, (ret = (a != b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#define EXPECT_GE(a, b) ({ \
    int ret; \
    printf("%s >= %s %s\n", #a, #b, (ret = (a >= b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#define EXPECT_LE(a, b) ({ \
    int ret; \
    printf("%s <= %s %s\n", #a, #b, (ret = (a <= b)) ? "True" : "False"); \
    __data->total += 1; \
    __data->expect += ret; \
})

#endif
