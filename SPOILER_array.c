```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insert(int ** array, int * size, int index, int value);
void delete(int ** array, int * size, int index);
int min(int * array, int size);
int max(int * array, int size);
int linearSearch(int * array, int size, int value);
void bubbleSort(int ** array, int size);
int binarySearch(int * array, int size, int value);
void printArray(int * array, int size);

int main() {
	int * arr = (int *) malloc(sizeof(int));
	int size = 1;
	arr[0] = 1;
	insert(&arr, &size, 0, 2);
	insert(&arr, &size, 0, 4);
	insert(&arr, &size, 0, 3);
	insert(&arr, &size, 2, 5);
	insert(&arr, &size, 0, 2);
	printArray(arr, size);
	delete(&arr, &size, 2);
	printArray(arr, size);
	printf("Min: %d\n", min(arr, size));
	printf("Max: %d\n", max(arr, size));
	printf("Found 3 at index: %d\n", linearSearch(arr, size, 3));
	printf("Found 5 at index: %d\n", linearSearch(arr, size, 5));

	bubbleSort(&arr, size);
	printArray(arr, size);
	printf("Found 3 at index: %d\n", binarySearch(arr, size, 3));
	printf("Found 5 at index: %d\n", binarySearch(arr, size, 5));
	return 0;
}

void printArray(int * array, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	putchar('\n');
}

void insert(int ** array, int * size, int index, int value) {
	int sz = *size + 1;
	int * tmp = (int *) realloc(*array, sz * sizeof(int));
	assert(tmp); // check tmp != NULL
	for (int i = sz; i > index; --i) {
		tmp[i] = tmp[i - 1];
	}
	tmp[index] = value;

	*array = tmp;
	*size = sz;
}

void delete(int ** array, int * size, int index) {
	int sz = *size - 1;
	int * tmp = *array;
	for (int i = index; i < sz; ++i) {
		tmp[i] = tmp[i + 1];
	}
	*array = tmp;
	*size = sz;
}

int min(int * array, int size) {
	if (size == 0) return -1;
	int m = array[0];
	for (int i = 1; i < size; ++i) {
		if (m > array[i]) {
			m = array[i];
		}
	}
	return m;
}

int max(int * array, int size) {
	if (size == 0) return -1;
	int m = array[0];
	for (int i = 1; i < size; ++i) {
		if (m < array[i]) {
			m = array[i];
		}
	}
	return m;
}

int linearSearch(int * array, int size, int value) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int ** array, int size) {
	int * tmp = *array;
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (tmp[i] > tmp[j]) {
				swap(&tmp[i], &tmp[j]);
			}
		}
	}
	*array = tmp;
}

int binarySearch(int * array, int size, int value) {
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (array[mid] == value) {
			return mid;
		} else if (array[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}
```