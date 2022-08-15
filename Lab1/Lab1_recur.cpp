#include <iostream>
#include <ctime>
using namespace std;

int number_fibonachi(int counter)
{
	if (counter == 0)
	{
		return 0;
	}
	if (counter == 1)
	{
		return 1;
	}
	return number_fibonachi(counter - 1) + number_fibonachi(counter - 2);
}

int main()
{
	int rec;
	setlocale(LC_ALL, "RUS");
	int N;
	cout << "Введите число: ";
	cin >> N;
	unsigned int start_time = clock();
	rec = number_fibonachi(N - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << rec << endl;
	cout << "Время выполнения рекурсии: " << search_time << " мс." << endl;
	return 0;

}