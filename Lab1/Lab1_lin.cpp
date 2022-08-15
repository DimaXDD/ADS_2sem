#include <iostream>
#include <ctime>
using namespace std;

//0 1 1 2 3 5 8 13 21
int Fibonachi_Cikl(int N) {
	int mass[3] = { 0, 1 };
	N = N - 2;
	for (int c = 0; c <= N; c++) {
		mass[2] = mass[1];
		mass[1] = mass[1] + mass[0];
		mass[0] = mass[2];
	}
	return mass[0];
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	double N, time1, time2, time_razn;
	cout << "Введите N-ое число ряда Фибоначчи: ";
	cin >> N;
	int a = 1, b = 1, c;
	unsigned int start_time = clock();
	cout << "Число = " << Fibonachi_Cikl(N) << endl;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "\nВремя прохождения цикла: " << search_time << " мс." << endl;
}