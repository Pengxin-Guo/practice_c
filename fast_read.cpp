/*************************************************************************
	> File Name: fast_read.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月18日 星期二 20时26分50秒
 ************************************************************************/

//快速读取整型数据

#include <iostream>
using namespace std;

char ss[1<<17], *A = ss, *B = ss;
inline char gc() {
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++;
}

template<typename T> inline void sdf(T &x) {
    char c;
    T y = 1;
    while (c = gc(), (c < 48 || c > 57) && c != -1) {
        if (c == '-') y = -1;
    }
    x = c ^ 48;
    while (c = gc(), (c <= 57 && c >= 48)) {
        x = (x << 1) + (x << 3) + (c ^ 48);
    }
    x *= y;
}

int main() {
    int n, a;
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        sdf(a);
    }
    return 0;
}
