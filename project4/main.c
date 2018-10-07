/*************************************************************************
	> File Name: main.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 11时28分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

#ifdef TESTFUNC
    #include "testcase1.h"
    #include "testcase2.h"
#endif

int main() {
    printf("hello world\n");
    return RUN_ALL_TEST();
}
