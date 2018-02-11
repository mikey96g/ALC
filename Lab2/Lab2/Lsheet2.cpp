#include <iostream>

//using namespace std;

template <class T> void swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class WhatKind> void multiples(WhatKind &sum, WhatKind x, int n)
{
	sum = 1;
	for (int i = 0; i <= n; i++)
	{
		sum += (i*x);
	}
}

template <class T1, class T2> T1 init(T1 num1, T1 num2, T2& start)
{
	start = 1;
	return (num1 + num2);
}

/***************************************************************************************

*    Usage: Used
*    Title: Quicksort Alogrithim
*    Author: AlgoList
*    Date: 11/02/2018
*    Availability: http://www.algolist.net/Algorithms/Sorting/Quicksort
*
***************************************************************************************/
template<typename T>
T* quicksort(T* array, int start, int end)
{
	int i = start, j = end;
	int tmp;
	int pivot = array[(start + end) / 2];

	/* partition */

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;

		}

	};
	/* recursion */
	if (start < j)
	{
		quicksort(array, start, j);
	}
	if (i < end) 
	{
		quicksort(array, i, end);
	}
	return array;
}

int main()
{
	//Q1
	int i = 5;
	int j = 6;
	float p = 10.1f;
	float q = 15.2f;


	swap(&i, &j);
	std::cout << "i = " << i << " j = " << j;
	std::cout << "\n\n";
	swap(&p, &q);
	std::cout << "p = " << p << " q = " << q;
	std::cout << "\n\n";

	//Q2
	int sum = 0;
	int n = 3;
	int x = 2;
	multiples(sum, x, n);
	std::cout << sum << "\n\n";

	//Q3
	int num1 = 2;
	int num2 = 3;
	double start = 2.2;
	init(num1, num2, start);
	std::cout << start << "----" << init(num1, num2, start) << "\n\n";

	//Q4
	int arr[] = { 1,3,4,2,9,5,6,11,15,4 };

	quicksort(arr, 0, 9);
	for(int i = 0; i < 10;i++)
	{
		std::cout << arr[i]<<",";
	}


	std::cout << "\n\n";
	system("pause");
	return 0;
}