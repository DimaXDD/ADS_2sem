#include <ctime>
#include <iostream>
#include <Windows.h>
using namespace std;

struct node {
    int numberKey;
    string number;
    string surname;
    string name;
    string patronynic;
    node* next;
    bool markOfDel;


};
const int SIZE = 8;
node* arr[SIZE];

unsigned int hashFunction(string str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    return sum % SIZE;
}
void addElement() {
    setlocale(LC_ALL, "rus");
    string num;
    string surname;
    string name;
    string patronymic;
    cout << "Введите номер" << endl;
    cin >> num;
    cout << "Введите фамилию" << endl;
    cin >> surname;
    cout << "Введите имя" << endl;
    cin >> name;
    cout << "Введите отчество" << endl;
    cin >> patronymic;

    int key = hashFunction(num);
    node* head = arr[key];
    unsigned int start_time = clock(); // начальное время
    if (arr[key] == NULL) {
        arr[key] = new node;
        arr[key]->surname = surname;
        arr[key]->name = name;
        arr[key]->patronynic = patronymic;
        arr[key]->number = num;
        arr[key]->next = NULL;
    }
    else {
        while (head != NULL) {

            if (head->next == NULL) {

                head->next = new node;

                head->next->surname = surname;
                head->next->name = name;
                head->next->patronynic = patronymic;
                head->next->number = num;
                head->next->next = NULL;
                break;

            }
            head = head->next;
        }
    }
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // 

    cout << search_time << endl;
}

void dellElement() {
    setlocale(LC_ALL, "rus");
    string number;
    cout << "Введите номер " << endl;
    cin >> number;

    int key = hashFunction(number);
    node* head = arr[key];
    unsigned int start_time = clock();
    while (head != NULL) {
        if (head->number == number) {
            head->markOfDel = true;
        }
        head = head->next;
    }
}

void printElements() {
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] != NULL && arr[i]->markOfDel != true)
        {
            cout << "ФИО: " << arr[i]->surname << " " << arr[i]->name << " " << arr[i]->patronynic << endl;
            cout << "Номер : " << arr[i]->number << endl;
            if (arr[i]->next != NULL)
            {
                node* temp = arr[i];
                temp = temp->next;
                while (temp != NULL && temp->markOfDel != true)
                {
                    cout << "ФИО: " << temp->surname << " " << temp->name << " " << temp->patronynic << endl;
                    cout << "Номер : " << temp->number << endl;
                    temp = temp->next;
                }
            }
        }

    }

}

void findElement() {
    setlocale(LC_ALL, "rus");
    string number;
    cout << "Введите номер " << endl;
    cin >> number;

    int key = hashFunction(number);
    node* head = arr[key];
    unsigned int start_time = clock();
    while (head != NULL) {
        if (head->number == number) {
            cout << "Key: " << key << endl;
            cout << "ФИО: " << head->surname << " " << head->name << " " << head->patronynic << endl;
            cout << "Номер : " << head->number << endl;
            break;
        }
        head = head->next;
    }
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // итоговое время

    cout << endl << "Время поиска: " << search_time << endl;
}

void menu() {
    setlocale(LC_ALL, "rus");
    int choice;

    cout << "1.Добавление элементов в хэш таблицу" << endl;
    cout << "2.Поиск элемента" << endl;
    cout << "3.Список элементов" << endl;
    cout << "4.Удаление элемента" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1: addElement(); menu(); break;
    case 2: findElement(); menu(); break;
    case 3: printElements(); menu(); break;
    case 4: dellElement(); menu(); break;
    default:
        break;
    }

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
}