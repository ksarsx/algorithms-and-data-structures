#include <iostream>
#include <vector>
using namespace std;


// функция, которая обеспечивает слияние двух отсортированных массивов в один отсортированный ----
template <class T>
void merge(vector<T>& a, vector<T>& b, vector<T>& to) {
	int i = 0;
	int j = 0;

	while (i < a.size() || j < b.size()) { // пока мы не прошли оба массива
		if ((i == a.size()) || ((j < b.size()) && b[j] <= a[i])) {
			to[i + j] = b[j];
			j++;
		}
		else {
			to[i + j] = a[i];
			i++;
		}
	}
}
// -----------------------------------------------------------------------------------------------

// реализация самой сортировки слиянием ----------------------------------------------------------
template <class T>
void MergeSort(vector<T>& arr) {
	if (arr.size() <= 1) return;

	int k = arr.size() / 2;
	vector<T> l;
	vector<T> r;
	for (int i = 0; i < k; i++) l.push_back(arr[i]);
	for (int i = k; i < arr.size(); i++) r.push_back(arr[i]);

	MergeSort(l);
	MergeSort(r);
	merge(l, r, arr);
}
// -----------------------------------------------------------------------------------------------

int main() {
	vector<int> arr = { 3, 8, 4, -4, 8, 7, 6, 5 };
	MergeSort(arr);
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl;
}