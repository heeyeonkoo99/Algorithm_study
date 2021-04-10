#include <stdio.h>
#pragma warning(suppress : 4996)

int array[1001];

int main(void) {
	int number, i, j, min, index, temp;
	scanf_s("%d", &number);
	for (i = 0; i < number; i++) {
		scanf_s("%d", &array[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001;
		for (j = i; j < number; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < number; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}