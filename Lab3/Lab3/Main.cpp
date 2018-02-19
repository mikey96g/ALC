#include <iostream> 
#include <exception>

void merge(int arraySortedInTwoHalves[], int startIndex, int length)
{
	int size = (length - startIndex) + 1;
	int *b = new int[size]();

	int i = startIndex;
	int mid = (startIndex + length) / 2;
	int k = 0;
	int j = mid + 1;

	while (k < size)
	{
		if((i<=mid) && (arraySortedInTwoHalves[i] <  arraySortedInTwoHalves[j]))
		{
			b[k++] = arraySortedInTwoHalves[i++];
		}
		else
		{
			b[k++] = arraySortedInTwoHalves[j++];
		}

	}

	for(k=0; k < size; k++)
	{
		arraySortedInTwoHalves[startIndex + k] = b[k];
	}
	delete[]b;

}

//The recursive merge sort function
void mergeSort(int iArray[], int startIndex, int endIndex)
{
	int midIndex;

	//Check for base case
	if (startIndex >= endIndex)
	{
		return;
	}

	//First, divide in half
	midIndex = (startIndex + endIndex) / 2;

	//First recursive call
	mergeSort(iArray, startIndex, midIndex);
	//Second recursive call
	mergeSort(iArray, midIndex + 1, endIndex);
	//The merge function
	merge(iArray, startIndex, endIndex);

}

//swap for pointers
void swap(int* a,int* n)
{
	int t = *a;
	*a = *n;
	*n = t;
}

int quickSortDivide(int theArray[], int first, int last)
{
	int pivot = theArray[last];//pivot
	int i = (first - 1); //Index of smaller element

	for (int j = first; j<= last - 1; j++)
	{
		if(theArray[j]<=pivot)
		{
			i++;
			swap(&theArray[i], &theArray[j]);						
		}
	}
	swap(&theArray[i + 1], &theArray[last]);
	return (i + 1);
}

void quickSort(int theArray[], int first, int last)
{
	if(first < last)
	{
		/*pi is partioning index, theArray[p] is now at the right place */
		int pi = quickSortDivide(theArray, first, last);

		/*Separately sort elements before divide and after divide*/
		quickSort(theArray,first,pi -1);
		quickSort(theArray, pi+1,last);

	}
}
/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



int main()
{
	/*int arr[10] = { 2,5,6,4,7,2,8,3,9,10 };
	

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	mergeSort(arr, 0, 10-1);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << "\n\n ";
	}*/

	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);

	std::cout << "\n\n";
	system("pause");
	return 0;
}

