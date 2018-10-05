/*************************************************************************
	> File Name: test.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月05日 星期五 15时17分05秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

void test1(char *, char *);
void test2(char *, char *);

#define EXPECT(func, num) ({ \
    char *str = NULL; \
    str = (char *)((func == num) ? "True" : "False"); \
    printf("%s == %d %s\n", #func, num, str); \
    return func == num; \
})

//#define TEST(test, func) ({ \
//    printf("[%s, %s]\n", #test, #func); \
//})

#define TEST\(test, is_prime_func\) void test1(char *test, int (*fun)(int))
#define TEST\(test, add_func\) void test2(char *test, int (*fun)(int, int))

#define RUN_ALL_TEST() ({ \
    test1("test", "is_prime_func"); \
    test2("test", "add_func"); \
})



#endif
