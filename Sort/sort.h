// 用于实现不同算法的排序
#pragma once

namespace sort {
	// 前置函数
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

	// 冒泡排序
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
	// 选择排序
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
}
