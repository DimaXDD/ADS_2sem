//В сети магазинов "ФИТ-Аудио" проводится рекламная акция.Каждый второй товар – бесплатно.
//Естественно, кассирам дано указание пробивать товары в таком порядке, чтобы магазин потерял как можно меньше денег.
//По списку товаров определите максимальную сумму в чеке.
//	Вход: натуральное число товаров(N < 10000) и далее N натуральных чисел – цены товаров.
//	Цену товара сгенерировать(Например, от 1 до 100).
//		Выход : Порядок пробивания на кассе и число – максимальная сумма чека.

#include <iostream>
using namespace std;

void bubbleSort(int* arr, int N)
{
	int temp = 0;
	bool isSorted = false;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			isSorted = true;
			arr[i + 1] = temp;
		}
		if (N == i + 2)
		{
			if (!isSorted)
				break;
			else
			{
				isSorted = false;
				i = -1;
			}
		}
	}
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int num, sum = 0;
	//Генерация и заполнение случайными числами одномерного динамического массива
    cout << "Введите количество элементов в массиве: "; cin >> num;
	if (num >= 10000)
	{
		cout << "Введите кол-во корректно (< 10000)";
		return 0;
	}
	int* arr = new int[num];
	cout << "Вывод цен: \n";
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << ";" << "\n";
	}
	cout << "\n";
	bubbleSort(arr, num);


	cout << "Чек после сортировки: \n";
	for (int i = 0, start = 0, end = num - 1; i < num; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			cout << arr[start++] << ";" << "\n";
		}
		else
		{
			sum += arr[end];
			cout << arr[end--] << ";" << "\n";
		}
	}
	cout << "\nМаксимальная сумма: " << sum;
	delete[] arr;
}