/*************************************************************************
	> File Name: radix_sort.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月21日 星期日 11时10分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void radix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65536] = {0};
    for (int i = 0; i < n; i++) cnt[num[i] & 0xffff]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    //cnt[0] = 0;
    for (int i = 65536; i >= 1; i--) cnt[i] = cnt[i - 1];
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[(temp[i] >> 16) & 0xffff]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    cnt[0] = 0;
    for (int i = 65536; i >= 1; i--) cnt[i] = cnt[i - 1];
    for (int i = 0; i < n; i++) num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
    return ;
}

/*
void radix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65537] = {0};
    for (int i = 0; i < n; i++) cnt[(num[i] & 0xffff) + 1]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[((temp[i] >> 16) & 0xffff) + 1]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
    return ;
}
*/

void output(int *num, int n) {
    for (int i = 0; i < n; i++) printf("%d ", num[i]);
    printf("\n");
    return ;
}

#define swap(a, b) { \
    a ^= b; b ^= a; a ^= b; \
}

void merge_sort(int *num, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

int main() {
    srand(time(0));
    int arr[100];
    for (int i = 0; i < 100; i++) arr[i] = rand() % 100;
    merge_sort(arr, 0, 99);
    output(arr, 100);
    printf("\n");
    radix_sort(arr, 100);
    output(arr, 100);
    return 0;
}
