/*************************************************************************
	> File Name: func_newton.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 19时57分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

double f1(double x, double n) {
    return x * x - n;
}

double f1_prime(double x) {
    return 2 * x;
}
