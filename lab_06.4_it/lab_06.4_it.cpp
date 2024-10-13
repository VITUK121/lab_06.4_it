#include <iostream>
#include <ctime>
using namespace std;

double* make_arr(int size) {
	double* arr = new double[size];
	for (int i = 0; i != size; i++) {
		arr[i] = -10. + rand() * (10. - (-10.)) / RAND_MAX;
	}
	return arr;
}

void print_arr(double* arr, int size) {
	for (int i = 0; i != size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int min_index(double* arr, int size) {
	int index = 0;
	double result = arr[0];

	for (int i = 1; i != size; i++) {
		(result > arr[i]) ? (result = arr[i], index = i) : (NULL);
	}
	return index;
}

double sum_between_two(double* arr, int size) {
	int a = -1, b = -1;
	double sum = 0;
	for (int i = 0; i != size; i++) {
		if (arr[i] < 0) {
			a = i;
			break;
		}
	}
	for (int j = a+1; j != size; j++) {
		if (arr[j] < 0) {
			b = j;
			break;
		}
	}

	if (a == -1 || b == -1) {
		cout << "Not enough negative numbers!" << endl;
		return -1.;
	}
	for (int i = a+1; i != b; i++) {
		sum += arr[i];
	}
	return sum;
}

void change_arr(double* arr, int size) {
	double* temp = new double[size];
	int index = 0;

	for (int i = 0; i != size; i++) {
		if (fabs(arr[i]) <= 1) {
			temp[index] = arr[i];
			index++;
		}
	}

	for (int i = 0; i != size; i++) {
		if (fabs(arr[i]) > 1) {
			temp[index] = arr[i];
			index++;
		}
	}

	for(int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}

	delete[] temp;
}

int main() {
	srand(time(NULL));
	int n;
	cout << "n = "; cin >> n;

	double* a = make_arr(n);
	print_arr(a, n);
	cout << "min_index() = " << min_index(a, n) << endl;
	cout << "sum() = " <<  sum_between_two(a, n) << endl;
	change_arr(a, n);
	print_arr(a, n);
	delete[] a;
}