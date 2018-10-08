/*************************************************************************
	> File Name: testcase4.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 19时59分35秒
 ************************************************************************/

#ifndef _TESTCASE4_H
#define _TESTCASE4_H
#include "newton.h"
#include "func_newton.h"

TEST(test, newton_func) {
    EXPECT_EQ(newton(f1, f1_prime, 5), 3);
    EXPECT_EQ(newton(f1, f1_prime, 9), 3);
    EXPECT_EQ(newton(f1, f1_prime, 30), 8);
}


#endif
