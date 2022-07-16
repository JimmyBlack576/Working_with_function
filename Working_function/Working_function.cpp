#include <iostream>
#include <Windows.h>

using namespace std;

void num_to_the_power(int x, int y);

int sum_of_values(int* x, int* y, int* sum);

void enter_data(int* x, int* y);

int perfect_number(int x, int y);

void show_card();

void happy_number();






int main()
{
    setlocale(LC_ALL, "ru");
    int x, y, sum=0;
    cout << "Task 1\n\n";
    enter_data(&x, &y);
    num_to_the_power(x,y);
    Sleep(1500);
    system("cls");
    //----------------------
    cout << "Task 2\n\n";
    enter_data(&x, &y);
    sum_of_values(&x, &y, &sum);
    cout << sum<<endl;
    Sleep(1500);
    system("cls");
    //----------------------
    cout << "Task 3\n\n";
    enter_data(&x, &y);
    perfect_number(x, y);
    Sleep(1500);
    system("cls");
    //----------------------
    cout << "Task 4\n\n";
    show_card();
    Sleep(1500);
    system("cls");
    //----------------------
    cout << "Task 5\n\n";
    happy_number();
    Sleep(1500);
    system("cls");

    return 0;
}

//Функция ввода параметров
void enter_data(int* x, int* y) {
    cout << "Введите значение №1: \n";
    cin >> *x;
    cout << "Введите значение №2: \n";
    cin >> *y;
}
//Сложение в диапазоне
int sum_of_values(int* x, int* y, int* sum) {
    for (int i = *x + 1; i < *y; i++) {
        *sum += i;
    }
    return *sum;
}
//Функция возведения в степень
void num_to_the_power(int x, int y) {
    float s = 1;
    for (int i = 1; i <= abs(y); i++)
    {
        s = s * x;
    }
    if (y < 0) { s = 1 / s; }
    cout << s;
}
//Функция поиска совершенного числа
int perfect_number(int x, int y) {
    for (int i = x; i < y; i++)
    {
        int result = 0;
        for (int j = 1; j < i; j++)
        {
            if ((i % j) == 0)
            {
                result += j;
            }
        }
        if (result == i && result)
        {
            cout << result << " \n";
        }
    }
    return 0;
}
//Функция вывода карты
void show_card() {
    char c;
    cout << "Which card to show? \n";
    cin >> c;
    cout << string(11, '=') << endl;
    for (int j = 0; j <= 8; j++) {
        for (int i = 0; i <= 11; i++) {
            if (i == 0) { cout << '|'; }
            else if (i == 1 && j == 0) { cout << c; }
            else if (i == 5 && j == 4) { cout << c; }
            else if (i == 9 && j == 8) { cout << c; }
            else if (i > 0 && i < 10)cout << ' ';
            else if (i == 10) { cout << '|' << endl; }
        }
    }
    cout << string(11, '=') << endl;
}
//Функция расчета счастливого числа
void happy_number() {
    int num;
    do{
    cout << "Enter a six-digit number: \n";
    cin >> num;
    if (num <= 99999 || num > 999999) cout << "Wrong number!\n";
    } while (num <= 99999 || num > 999999);
    int n1 = 0, n2 = 0;
    for (int i = 0; i < 6; i++) {
        int c = num % 10;
        if (i < 3) n1 += c;
        else      n2 += c;
        num = num / 10;
    }
    if (n1 == n2) cout << "Happy number!\n";
    else cout << "Do not happy number!\n";
}