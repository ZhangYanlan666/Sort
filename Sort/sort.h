// 用于实现不同算法的排序 For implementing various sorting algorithms
#pragma once

namespace sort {
	// 前置函数 Predefined functions
	template<typename T>
	void Swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}
	template<typename T>
	bool defaultCmp(const T& a, const T& b) {
		return a > b;
	}

	// 冒泡排序 Bubble Sort
	template<typename T, typename Compare = decltype(&defaultCmp<T>)>
	void bubbleSort(T* arr, int len, Compare cmp = defaultCmp<T>) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (cmp(arr[j], arr[j + 1])) {
					Swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	// 选择排序 Selection Sort
	template<typename T, typename Compare = decltype(&defaultCmp<T>)>
	void selctionSort(T* arr, int len, Compare cmp = defaultCmp<T>) {
		for (int i = 0; i < len - 1; i++){
			int minn = i;
			for (int j = i + 1; j < len; j++) {
				if (cmp(arr[minn], arr[j]))
					minn = j;
			}
			Swap(arr[i], arr[minn]);
		}
	}

	// 地精排序 Gnome Sort
	template<typename T, typename Compare = decltype(&defaultCmp<T>)>
	void gnomeSort(T* arr, int len, Compare cmp = defaultCmp<T>) {
		int i = 0;
		while (i < len) {
			if (i == 0 || !cmp(arr[i - 1], arr[i])) {
				i++;
			}
			else {
				Swap(arr[i], arr[i - 1]);
				i--;
			}
		}
	}
	// 插入排序 Insertion Sort
	template<typename T, typename Compare = decltype(&defaultCmp<T>)>
	void insertionSort(T* arr, int len, Compare cmp = defaultCmp<T>) {
		for (int i = 1; i < len; i++) {
			int j = i;
			while (j > 0 && cmp(arr[j - 1], arr[j])) {
				Swap(arr[j], arr[j - 1]);
				j--;
			}
		}
	}
}
