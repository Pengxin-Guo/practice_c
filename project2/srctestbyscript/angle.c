#include <stdio.h>

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > c) {
		swap(&a, &c);
	}
	if (b > c) {
		swap(&b, &c);
	}
	if (a + b <= c) {
		puts("It's not a triangle");
	} else if (a * a + b * b < c * c) {
		puts("It's an obtuse triangle");
	} else if (a * a + b * b > c * c) {
		puts("It's an acute triangle");
	} else {
		puts("It's a right triangle");
	}
	return 0;
}

