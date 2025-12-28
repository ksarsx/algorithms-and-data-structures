#include <iostream>
#include <vector>
#include <random>
using namespace std;

template <class T>
vector<int> Partition(vector<T>& arr, int start, int finish, T x) {
	vector<T> B;
	vector<T> C;
	vector<T> D;

	// заполнение B, C, D
	for (int i = start; i < finish; i++) {
		if (arr[i] < x) B.push_back(arr[i]);
		else if (arr[i] == x) C.push_back(arr[i]);
		else D.push_back(arr[i]);
	}

	// смена структуры исходного массива в [B .. C .. D]
	int b = 0;
	for (int i = start; i < (start + B.size()); i++) {
		arr[i] = B[b];
		b++;
	}
	int c = 0;
	for (int i = (start + B.size()); i < (start + B.size() + C.size()); i++) {
		arr[i] = C[c];
		c++;
	} 
	int d = 0;
	for (int i = (start + B.size() + C.size()); i < finish; i++) {
		arr[i] = D[d];
		d++;
	}
	
	vector<int> result = { (int)B.size(), (int)C.size(), (int)D.size() };
	return result;
}

template <class T>
void QuickSort(vector<T>& arr, int start, int finish) {
	if (finish - start <= 1) return;

	static mt19937 generator(42); // генератор Мерсенна Твистера с фиксированным сидом
	uniform_int_distribution<int> dist(start, finish - 1);
	T x = arr[dist(generator)];

	vector<int> lmn = Partition<T>(arr, start, finish, x);
	QuickSort(arr, start, start + lmn[0]);
	QuickSort(arr, start + lmn[0] + lmn[1], finish);
}


int main() {
	vector<int> vec = { 3, 8, 4, -4, 8, 7, 6, 5 };
	QuickSort(vec, 0, vec.size());
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
}