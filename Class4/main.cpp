#include"Pair.h"
#include"Rectangle.h"
#include <iostream>
using namespace std;
int main()
{
	Pair a;
	cin >> a;
	cout << a.multyply();
	cout << endl;
	cout << a;
	Rectangle b(24,9);
	Rectangle c = b;
	cout << c.get_square()<<endl;
	cout << c.get_perimeter() << endl;
}

