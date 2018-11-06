#include <stdio.h>
#include <stdlib.h>
#include "SimpleFunctions.h"

int main() {
	test_1(1945);
	int a = 777; int *b = &a;
	test_2(b);
	b = 0;
	test_3(b);
	int ar = 65535;
	int *br = &ar; int *c = br;
	test_4(&c);
	char z = 'Z';
	test_5(z);
	int r = 1000;
	int *rn = &r;
	test_6(rn);
	char st[] = "zzzn";
	test_7(st,st);
	char *v1 = "A", *v2 = "C", *v3 = "E";
	test_8(v1,v2,v3);
	char v4[] = "afnv";
	test_9(v4,v4,v4);
	int bf = 65;
	char *ab = "A";
	test_10(ab,bf); 
	char *abx = (char *)malloc(4);
    	abx[0] = 1; abx[1] = 0; abx[2] = 0; abx[3] = 2;
    	void *n2 = abx;
    	void *o2 = abx;
	test_11(n2, o2);
	free(abx);
	return 0;
}