//По результатам олимпиады участники награждаются дипломами.
//Набравшие одинаковые баллы получают дипломы одинаковой степени.
//Призером олимпиады считается участник, получивший диплом не хуже III степени.
//По результатам олимпиады определите количество призеров.
//Вход: натуральное число призеров(N < 10000) и далее N натуральных чисел – результаты участников(сгенерировать от 1 до 100)
//	Выход : одно число – число призеров.

#include <iostream>
using namespace std;

void sortMethodShella(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int N,
		diploma = 0,
		cnt = 0,
		maxPoint = 100;
	int* results;
	string check;
	cout << "Введите количество участников: ";
	cin >> N;
	if (N >= 10000)
	{
		cout << "Введите кол-во корректно (< 10000)";
		return 0;
	}
	results = new int[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		results[i] = rand() % maxPoint + 1;
		cout << "Призер " << i + 1 << " = " << results[i] << endl;
	}

	sortMethodShella(results, N);

	for (int i = N - 1; i > 0; i--)
	{
		if (diploma == 3)
		{
			break;
		}
		else
		{
			cnt++;
			if (i == 1 && results[i] == results[0]) cnt++;
		}
		if (results[i] != results[i - 1])
		{
			diploma++;
		}
	}

	cout << "\n\nКоличество призеров: " << cnt << endl;

	delete[] results;
}
