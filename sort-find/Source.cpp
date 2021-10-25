#include <stdio.h>
#include <locale.h>

#define MAX_SIZE 15

void fill_arr(int[], int*, int);
void print_arr(int[], int);
void insert_sort(int[], int);
int barrier_find(int[], int, int);
int binary_find(int[], int, int);

int main() {
	setlocale(LC_ALL, "Rus");
	int x, find_result, size = 0;
	int arr[MAX_SIZE + 1];

	fill_arr(arr, &size, MAX_SIZE);

	printf("\nВведите элемент, который нужно найти: ");
	scanf("%d", &x);

	printf("\nМассива отсортирован:\n");
	print_arr(arr, size);
	printf(" -> ");
	insert_sort(arr, size);
	print_arr(arr, size);
	printf("\n");

	find_result = barrier_find(arr, size, x);
	if (find_result == -1) printf("В массиве нет элемента %d", x);
	else printf("Индекс искомого элемента(%d) = %d", x, find_result);
	printf("\n");

	return 0;
}

void fill_arr(int arr[], int* size, int max_size) {
	printf("Введите размер массива(Макс %d): ", max_size);
	scanf("%d", size);

	while (1) {
		if (*size > 0 && *size <= max_size) break;
		printf("Неккоректный размер! Мин 1, Макс %d\nВведите размер массива: ", max_size);
		scanf("%d", size);
	}

	printf("Заполните массив\n");
	for (int i = 0; i < *size; i++) {
		printf("Введите %dй эл: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

void print_arr(int arr[], int size) {
	printf("[ ");
	for (int i = 0; i < size; printf("%d ", arr[i++]));
	printf("]");
}

void insert_sort(int arr[], int size) {
	int x, rem;
	for (int i = 1; i < size; i++) {
		x = arr[i];
		rem = i - 1;
		while (rem >= 0 && arr[rem] > x) {
			arr[rem + 1] = arr[rem];
			rem--;
		}
		arr[rem + 1] = x;
	}
}

int barrier_find(int arr[], int size, int x) {
	arr[size] = x;
	int i = 0;
	while (arr[i] != x) i++;
	if (i == size) i = -1;
	return i;
}

int binary_find(int arr[], int size, int x) {
	int middle, found = 0, position = -1;
	int start = 0, end = size;
	while (!found && start <= end) {
		middle = (start + end) / 2;
		if (arr[middle] == x) {
			found = 1;
			position = middle;
			break;
		}
		if (x < arr[middle]) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return position;
}