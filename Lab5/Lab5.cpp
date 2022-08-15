#include <iostream>
#include <stack>
#define circle stk.push(')'); break;
#define square stk.push(']'); break;
#define curly stk.push('}'); break;
#define math stk.push('>'); break;

using namespace std;

bool correct_skobochki(string s)
{
    stack <char> stk; // создание стека
    for (char symbol : s) {
        switch (symbol) {
            //добавление всех видов скобочек в стек
        case '(': circle;
        case '[': square;
        case '{': curly;
        case '<': math;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stk.empty() || stk.top() != symbol) { //проверка на корректность
                return false;
            }
            stk.pop(); //удаляем верхний элемент
            break;
        default:
            break;
        }
    }
    return stk.empty();
}

bool nalichie_skobochek(string s) { //проверка на наличие скобочек
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '<' || s[i] == '>')
        {
            return true;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    string s;
    cout << "Введите строку для проверке: "; cin >> s;
    nalichie_skobochek(s);
    if (nalichie_skobochek(s) == true)
    {
        correct_skobochki(s);
        if (correct_skobochki(s) == true)
        {
            cout << "\nCкобки расставлены верно";
        }
        else
        {
            cout << "\nCкобки расставлены не верно";
        }
    }
    else
    {
        cout << "\nВ строке нет скобок";
    }
}