/*************************************************************************
> File Name: my_printf.c
> Author: gpx
> Mail: 1457495424@qq.com
> Created Time: 2018年09月20日 星期四 20时43分38秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>

int digit(long long n) {
    if (n == 0) return 1;
    return floor(log10(n)) + 1;
}


int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        long long temp = va_arg(arg, int);
                        if (temp < 0) {
                            putchar('-');
                            cnt++;
                            //if (temp == -temp) {
                            //    putchar('2');putchar('1');putchar('4');putchar('7');putchar('4');
                            //    putchar('8');putchar('3');putchar('6');putchar('4');putchar('8');
                            //    cnt += 10;
                            //    break;
                            //}
                            temp = -temp;
                        }
                        int dig_temp = digit(temp);
                        while (temp) {
                            int num = temp / (int)pow(10, dig_temp - 1);
                            putchar(num + '0');
                            cnt++;
                            temp = temp % (int)pow(10, dig_temp - 1);
                            dig_temp -= 1;
                        }
                        for (int i = 0; i < dig_temp; i++) {
                            putchar('0');
                            cnt++;
                        }
                        break;
                    } 
                    default : 
                    fprintf(stderr, "error : unknow %%%c\n", frm[i]); 
                    exit(1);
                }
            } break;
            default:
            putchar(frm[i]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("%d\n", my_printf("hello world\n"));
    my_printf("%d\n", my_printf("n = %d\n", n));
    my_printf("%d\n", my_printf("n = %d\n", 12000));
    my_printf("%d\n", my_printf("n = %d\n", 0));
    my_printf("%d\n", my_printf("n = %d\n", -567));
    my_printf("%d\n", my_printf("n = %d\n", INT32_MIN));
    my_printf("%d\n", my_printf("n = %d\n", INT32_MAX));
    return 0;
}
