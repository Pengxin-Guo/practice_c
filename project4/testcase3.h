/*************************************************************************
	> File Name: testcase3.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 18时52分04秒
 ************************************************************************/

#ifndef _TESTCASE3_H
#define _TESTCASE3_H
#include "binary_search.h"
#include "func_binary.h"

TEST(test, binary_search_func) {
    EXPECT(binary_search(func_binary, 3, 4), -1);
    EXPECT(binary_search(func_binary, 25, 10), 1);
    EXPECT(binary_search(func_binary, 22, 3), -1);
}

#endif
