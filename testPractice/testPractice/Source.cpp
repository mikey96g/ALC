#include <string>
#include <iostream>
#include <cstdlib>

template<class t>
void swap(t *a, t *b)
{
	t t = *a;
	*a = *b;
	*b = t;

}

template<class T>
int partition(T arr[],int start, int last)
{
	T pivot = arr[last];
	int i = start - 1;

	for (int j = start; j < last;j++)
	{
		if (*(array[j]) <= (*pivot)) 
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	
	}
	swap(arr[i+1],arr[pivot]);
	return (i + 1);

}

template<class T>
void quicksort(T ray[],int first,int last)
{
	pi = partition(ray, first, last);

	quicksort(ray, first, pi - 1);
	quicksort(ray, pi - 1, last);

}



