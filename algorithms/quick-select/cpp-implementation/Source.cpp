#include <iostream>
#include <random>
#include <vector>
using namespace std;


template <class T>
vector<int> Partition(vector<T>& arr, int start, int finish, T x) {
	vector<T> B;
	vector<T> C;
	vector<T> D;


	for (int i = start; i < finish; i++) {
		if (arr[i] < x) B.push_back(arr[i]);
		else if (arr[i] == x) C.push_back(arr[i]);
		else D.push_back(arr[i]);
	}


	int b, c, d;
	b = 0;
	c = 0;
	d = 0;
	for (int i = start; i < finish; i++) {
		if (b < B.size()) {
			arr[i] = B[b];
			b++;
		}
		else if (c < C.size()) {
			arr[i] = C[c];
			c++;
		}
		else {
			arr[i] = D[d];
			d++;
		}
	}

	vector<int> result = { (int)B.size(), (int)C.size(), (int)D.size() };
	return result;
}

template <class T>
T QuickSelect(vector<T>& arr, int start, int finish, int k) {
	if (finish - start == 1) return arr[start];

	static mt19937 generator(42); // генератор Мерсенна Твистера с фиксированным сидом
	uniform_int_distribution<int> dist(start, finish - 1);
	T x = arr[dist(generator)];

	vector<int> lmn = Partition<T>(arr, start, finish, x);
	if (k < lmn[0]) return QuickSelect(arr, start, start + lmn[0], k);
	else if (k < (lmn[0] + lmn[1])) return x;
	else return QuickSelect(arr, start + lmn[0] + lmn[1], start + lmn[0] + lmn[1] + lmn[2], k - lmn[0] - lmn[1]); // start + lmn[0] + lmn[1] + lmn[2] == finish
}

int main() {
	vector<int> vec = { 3, 8, 4, -4, 8, 7, 6, 5 };
	cout << QuickSelect(vec, 0, vec.size(), 0) << endl; // -4
}