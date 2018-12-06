#include <stdio.h>

int main() {
	int coun;
	FILE* counter = fopen("counter", "r");
	fscanf(counter, "%d", &coun);
	fclose(counter);
	counter = fopen("counter", "w");
	fprintf(counter, "%d\n", 2 * coun);
	fclose(counter);
}

