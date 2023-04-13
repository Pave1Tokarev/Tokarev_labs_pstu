#include "iterator.h"
#include"vector.h"
Iterator::Iterator() {
	elem = nullptr;
}
Iterator::Iterator(const Iterator& t) {
	elem = t.elem;
}
bool Iterator::operator==(const Iterator& t) {
	return(elem = t.elem);
}
bool Iterator::operator!=(const Iterator& t) {
	return(elem != t.elem);
}
void Iterator::operator++() {
	elem++;
}
void Iterator::operator--() {
	elem--;
}
int Iterator::operator*()const{
	return *elem;
}
Iterator& Iterator::operator+(const int t) {
	elem = elem + t;
	return *this;
}