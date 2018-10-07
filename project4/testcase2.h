/*************************************************************************
	> File Name: testcase2.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 11时30分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "add.h"

TEST(test, add_func) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_NE(add(3, 4), 8);
    EXPECT_GE(add(2, 2), 4);
    EXPECT_GT(add(2, 7), 5);
    EXPECT_LT(add(3, 8), 10);
    EXPECT_LE(add(3, 5), 15);
}
