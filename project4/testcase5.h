/*************************************************************************
	> File Name: testcase5.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 20时14分25秒
 ************************************************************************/

#ifndef _TESTCASE5_H
#define _TESTCASE5_H
#include "palindrome_number.h"

TEST(test, palindrome_number_func) {
    EXPECT(palindrome_number(432), 1);
    EXPECT(palindrome_number(333), 1);
    EXPECT(palindrome_number(2823), 0);
}

#endif
