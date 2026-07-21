#include <iostream>
#include "sort.h"
using namespace std;
// 数组仅用于测试 The array is only for testing.
int const n = 10;
int a[n] = { 5, 2, 9, 1, 5, 6, 7, 3, 4, 8 };
int main() {
	//sort::bubbleSort(a,n);
	//sort::selctionSort(a,n);
	//sort::gnomeSort(a, n);
	sort::insertionSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}