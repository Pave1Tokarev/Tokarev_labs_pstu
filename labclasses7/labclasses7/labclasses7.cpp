#include <iostream>
#include"Time.h"
#include"Vector.h"
int main()
{
    setlocale(LC_ALL, "rus");
   cout << "Заполните вектор1 для 2 элементов" << endl;
    Time b(2,3),a(1,1);
    Vector<Time>container1(2, a);
    cin >> container1;
    cout << "Заполните вектор2 для 2 элементов" << endl;
    Vector<Time>container2(2,b);
    cin >> container2;
    cout << "Результат сложения 2 векторов" << endl;
    Vector<Time>container3(2, b);
    container3 = container1+container2;
    cout << container3;
    cout << "Выведем 2 элемент" << endl;
    cout << container3[1]<<endl;
    cout << "Размер векора : " << container3();
}
