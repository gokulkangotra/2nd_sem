// C Program to perform insertion operation in an  array
#include <stdio.h>

int main()
{
	int arr[50]= { 0 };
	int i, x, position, n = 10;

	// initial array of size 10
	for (i = 0; i < 10; i++)
		arr[i] = i + 1;

	// print the original array
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// element to be inserted
	x = 50;

	// position at which element is to be inserted
	position = 9;

	// increase the size by 1
	n++;

	// shift elements forward
	for (i = n - 1; i >= position; i--)
		arr[i] = arr[i - 1];

	// insert x at position
	arr[position - 1] = x;

	// print the updated array
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

