#include <stdio.h>
#include "hw2_syscalls.h"

#ifndef TEST_H
#define TEST_H

#define CHECK(condition, func, text)									\
	coun++;																\
	if(!(condition)) {													\
		fprintf(stderr, " > %s: %s, errno = %d.\n", func, text, errno);	\
		succ--;															\
	}

FILE* counter;
FILE* success;

void __start() {
	counter = fopen("counter", "w");
	success = fopen("success", "w");
	fprintf(counter, "%d\n", 0);
	fprintf(success, "%d\n", 0);
	fclose(counter);
	fclose(success);
}

void __end() {
	int __coun, __succ, __res;
	counter = fopen("counter", "r");
	success = fopen("success", "r");
	fscanf(counter, "%d\n", &__coun);
	fscanf(success, "%d\n", &__succ);
	__res = (int)((((double)__succ) / __coun) * 100);
	if(__res == 100) {
		printf("Wow! You have all right - it is PERFECT!\n");
	} else {
		printf("You have in summery %d%. You can more...\n", __res);
	}
	fclose(counter);
	fclose(success);
}

void start(int num) {
	fprintf(stderr, "test #%d:\n", num);
	counter = fopen("counter", "r");
	success = fopen("success", "r");
}

void end(int coun, int succ) {
	int __coun, __succ;
	fscanf(counter, "%d", &__coun);
	fscanf(success, "%d", &__succ);
	fclose(counter);
	fclose(success);
	counter = fopen("counter", "w");
	success = fopen("success", "w");
	fprintf(counter, "%d\n", coun + __coun);
	fprintf(success, "%d\n", coun + succ + __succ);
	fclose(counter);
	fclose(success);
}

#endif // TEST_H
