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
    EXPECT(add(1, 2), 3);
    EXPECT(add(3, 4), 7);
    EXPECT(add(2, 2), 4);
}
