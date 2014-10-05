#include <iostream>
 
#include <cstdlib>
 
using std::rand;
using std::swap;
 
// pivot - "опорный" элемент
// partition - переупорядочивает элементы части массива,
// заданной отрезком [left, right), так что в начале
// следуют элементы меньшие pivot, а в конце - большие;
// возвращает место начала блока элементов, больших pivot;
int partition(int *a, int l, int r, int pivot) {
	int i = l - 1;
	int j = r + 1;

	while (true)
	{
	    do
	    {
		i++;
	    }
	    while (a[i] < pivot);

	    do
	    {
		j--;
	    }
	    while (a[j] > pivot);

	    if (i < j)
		swap(a[i], a[j]);
	    else
	        return j;
	}
}
 
void my_qsort(int * arr, int l, int r) {
	if (l >= r)
	    return;
	
	int pivot = rand() % (r - l) + l;
	int j = partition(arr, l, r, pivot);
	my_qsort(arr, l, j);
	my_qsort(arr, j + 1, r);
}

void print_arr(int * arr, int size, char delim = ' ')
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << delim;
    }
    std::cout << std::endl;
}


int main()
{
	const int n = 10;
	int a[n] = { 4, 6, 7, 3, 8, 2, 1, 0, 3, 11 };
	print_arr(a, n);
	my_qsort(a, 0, n - 1);
	print_arr(a, n);
}
