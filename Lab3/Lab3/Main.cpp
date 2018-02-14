#include <iostream> 
#include <exception>

void merge(int arraySortedInTwoHalves[], int startIndex, int length) 
{
	int m = 1 + (length - 1) / 2;
	int i, j, k;
	int n1 = m - startIndex + 1;
	int n2 = length - m;

	//temp arrarys
	int *temp1 = new int[n1]();
	int *temp2 = new int[n2]();

	//copy data to temp arrarys
	for (i = 0; i < n1; i++)
		temp1[i] = arraySortedInTwoHalves[startIndex + i];
	for (j = 0; j < n2; j++)
		temp2[j] = arraySortedInTwoHalves[m + 1 + j];

	//merge the temp arrarys back into the arrary
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = startIndex; // Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (temp1[i] <= temp2[j])
		{
			arraySortedInTwoHalves[k] = temp1[i];
			i++;
		}
		else
		{
			arraySortedInTwoHalves[k] = temp2[j];
			j++;
		}
		k++;

	}
	/* Copy the remaining elements of temp1, if there
	are any */
	while (i < n1)
	{
		arraySortedInTwoHalves[k] = temp1[i];
		i++;
		k++;
	}
	/* Copy the remaining elements of temp2, if there
	are any */
	while (j < n2)
	{
		arraySortedInTwoHalves[k] = temp2[i];
		i++;
		k++;
	}
};

void mergeSort(int arraryToSort[],int startIndex, int length)
{
	for (int i = 0;i <= length;i++)
	{
		if (arraryToSort[i] > length && arraryToSort[i] <startIndex)
		{
			throw std::exception();
		}
	}

	
	if(startIndex < length)
	{
		//avoids overflow for large l and h
		int m = 1 + (length - 1) / 2;

		//Sort first and second halves
		mergeSort(arraryToSort, startIndex, m);
		mergeSort(arraryToSort, m + 1, length);

		merge(arraryToSort, startIndex, length);
	}

}



int main()
{
	int arr[6] = { 2, 11, 13, 5, 6, 7 };
	

	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}
	mergeSort(arr, 0, 6 - 1);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n";
	//system("pause");
	return 0;
}

