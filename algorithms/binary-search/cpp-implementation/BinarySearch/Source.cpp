#include <iostream>
#include <random>
using namespace std;


int main() {
	//---Генерация массива случайными числами------------------------------------------------------------------------------------------
	mt19937 generator(42); // генератор Мерсенна Твистера с фиксированным сидом
	uniform_int_distribution<int> dist(1, 100);

	int arr[100];
	int last_number = dist(generator);
	arr[0] = last_number;
	int new_number;
	for (int i = 1; i < 100; i++) {
		dist = uniform_int_distribution<int>(last_number, last_number + 10);
		new_number = dist(generator);
		arr[i] = new_number;
		last_number = new_number;
	}
	//---------------------------------------------------------------------------------------------------------------------------------
	

	// !!! потом надо будет вынести как отдельную функцию !!! 
	//---Реализация бинарного поиска------------------------------------------------------------------------------------------------
	int x = 87; 
	int left = 0;
	int right = 100;
	
	int mid;
	
	while (right - left > 1) {
		mid = (left + right) / 2;

		if (arr[mid] > x) right = mid;
		else left = mid;
	}
	if (arr[left] == x) cout << left << endl;
	else cout << "No" << endl;
	//------------------------------------------------------------------------------------------------------------------------------
}