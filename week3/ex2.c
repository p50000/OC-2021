#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp; 
}

void print_array(int arr[], int arr_size) 
{
	for(int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
}

void bubble_sort(int arr[], int arr_len) 
{
	for(int i = 0; i < arr_len; i++) {
		for(int j = i + 1; j < arr_len; j++) {
			if(arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

int main()
{
	int arr_len;
	printf("Size of the array: ");
	scanf("%d", &arr_len);

	int* array = (int*)malloc(sizeof(int) * arr_len);
	printf("Array content: ");
	for(int i = 0; i < arr_len; i++) {
		scanf("%d", &array[i]);
	}

	bubble_sort(array, arr_len);
	
	printf("Sorted array: ");
	print_array(array, arr_len);
}