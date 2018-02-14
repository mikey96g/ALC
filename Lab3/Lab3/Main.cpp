#include <iostream> 
#include <exception>

void merge(int arraySortedInTwoHalves[], int startIndex, int length) 
{
	int m = 1 + (length - 1) / 2;
	int i, j, k;
	int n1 = m - startIndex + 1;
	int n2 = length - m;

	//temp arrarys
	int *temp1 = new int[n1];
	int *temp2 = new int[n2];

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
	std::cout << "\n\n";
	system("pause");
	return 0;
}

