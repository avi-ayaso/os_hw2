#include <stdio.h>

int main() {
	int coun, succ;
	FILE* counter = fopen("counter", "r");
	FILE* success = fopen("success", "r");
	fscanf(counter, "%d", &coun);
	fscanf(success, "%d", &succ);
	fclose(counter);
	fclose(success);
	counter = fopen("counter", "w");
	success = fopen("success", "w");
	fprintf(counter, "%d\n", 2 * coun);
	fprintf(success, "%d\n", 2 * succ);
	fclose(counter);
	fclose(success);
}
