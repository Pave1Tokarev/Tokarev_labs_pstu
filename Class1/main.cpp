#include <iostream>
#include"Money.h"
using namespace std;
Money makemoney(int tmp1,int tmp2) {
    Money t;
    t.init(tmp1, tmp2);
    return t;
}
int main()
{
    setlocale(LC_ALL, "rus");
    Money a, b;
    a.init(1000, 50);
    //инициализация a через init
    b.read();
    //инициализация b через read
    a.show();
    b.show();
    cout << "сумма a - " << a.summa()<<endl;
    cout << "сумма b - " << b.summa()<<endl;
    Money* tmp = new Money;
    tmp->init(500,13);
    cout << "сумма tmp - " << tmp->summa()<<endl;
    Money mas1[3];
    for (int i = 0;i < 3;i++) {
        mas1[i].read();
    }
    for (int i = 0;i < 3;i++) {
        cout << "mas1[" << i << "]=" << mas1[i].summa() << endl;
    }
    Money* mas2 = new Money[3];
    for (int i = 0;i < 3;i++) {
        mas2[i].read();
    }
    for (int i = 0;i < 3;i++) {
        cout << "mas2[" << i << "]=" << mas2[i].summa() << endl;
    }
}
