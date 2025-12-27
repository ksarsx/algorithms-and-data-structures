#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

template <class T>
void merge(vector<T>& a, vector<T>& b, vector<T>& to) {
	int i = 0;
	int j = 0;

	while ((i < a.size()) || (j < b.size())) { // тут стоит учитывать, что a - левый массив, b - правый массив
		if ((j == b.size()) || ((i < a.size()) && (a[i] <= b[j]))) {
			to[i + j] = a[i];
			ans += j;
			i++;
		}
		else {
			to[i + j] = b[j];
			j++;
		}
	}
}

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
	merge<T>(l, r, arr);
}

int main() {
	vector<int> vec = { 3, 8, 4, -4, 8, 7, 6, 5 };
	MergeSort(vec);
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
	cout << ans;
}