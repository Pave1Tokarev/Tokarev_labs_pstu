#include "Vector.h"
#include <iostream>
using namespace std;
template <typename t>
Vector<t>::Vector(int s, t k);
template <typename t>
Vector<t>::Vector(const Vector<t>& a);
template<typename t>
Vector<t>::~Vector();
template<typename t>
ostream& operator<< (ostream& out, const Vector<t>& a);
template<typename t>
istream& operator>> (istream& in, Vector<t>& a);
template <typename t>
int Vector<t>::operator()();
template <typename t>
t Vector<t>::operator[](int tm);
template <typename t>
Vector<t> Vector<t>::operator+(const Vector<t>&a);
template <typename t>
Vector<t>& Vector<t>::operator=(const Vector<t>& a);
template <typename t>
void Vector<t>::set_element(int index, t& a);