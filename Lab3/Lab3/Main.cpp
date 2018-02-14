#include <iostream> 
#include <exception>

void merge(int arrayMerge[], int start, int end, int m) {};

void mergeSort(int arraryToSort[],int startIndex, int length)
{
	for (int i = 0;i <= length;i++)
	{
		if (arraryToSort[i] > length && arraryToSort[i] <startIndex)
		{
			throw std::exception();
		}
	}

	//avoids overflow for large l and h
	if(startIndex < length)
	{
		int m = 1 + (length - 1) / 2;

		//Sort first and second halves
		mergeSort(arraryToSort, startIndex, m);
		mergeSort(arraryToSort, m + 1, length);

		merge(arraryToSort, startIndex, length, m);
	}

}



int main()
{
	std::cout << "\n\n";
	system("pause");
	return 0;
}

