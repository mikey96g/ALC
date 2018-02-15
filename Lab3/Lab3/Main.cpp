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


int main()
{
	int arr[10] = { 2,5,6,4,7,2,8,3,9,10 };
	

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	mergeSort(arr, 0, 10-1);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << "\n\n ";
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}

