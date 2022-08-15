#include <iostream>
#include <cmath> 
using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	int N, choice = 0, left = 1, right, mid;
	int right2, left2 = left;
	bool check = false;
	cout << "Введите диапозон чисел (от 1 до ?) "; cin >> right;
	right2 = right;
	cout << "Введите загаданное число :) ";	cin >> N;
	mid = right / 2;
	do {
		if (choice == 1) {
			left = mid;
			mid = (right + left) / 2;
		}
		if (choice == 2) {
			right = mid;
			mid = (right + left) / 2;
		}
		if (choice == 3 || mid == N)
			check = true;
		system("cls");
		cout << mid << endl;
		cout << "1)Больше\n2)Меньше\n3)Угадал" << endl;
		cin >> choice;
	} while (check != true);
	system("cls");
	cout << "Угаданное число: " << N << endl;
	cout << "-------------------------\n";
	cout << "Максимальное количество шагов = " << round(log2(right2)) << endl;

	for (int m = 1, n = right2; n > 1; m++)
	{
		mid = (left2 + right2) / 2;
		cout << "Шаг " << m << " число " << mid << endl;
		right2 = mid;
		n = mid;
	}
	return 0;
}