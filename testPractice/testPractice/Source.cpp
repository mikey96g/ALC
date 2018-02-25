#include <iostream>
#include <exception>

template <class t> void swap(t *a,t *b)
{
	t t = *a;
	*a = *b;
	*b = t;

}

template<class T> int quickSorting(T arr[i], first, last)
{
	int pivot = arr[last];
	int i = first - 1;

	for (int j = first; j <= last-1;j++)
	{
		if (arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],arr[j])
		}
	
	
	}
	swap(&arr[i + 1], &arr[last]);
	return(i + 1);
}