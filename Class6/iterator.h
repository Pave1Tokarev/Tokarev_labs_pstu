#pragma once
class Iterator {
	friend class vector;
public:
	Iterator();
	Iterator(const Iterator& t);
	bool operator==(const Iterator& t);
	bool operator!=(const Iterator& t);
	void operator++();
	void operator--();
	int operator*()const;
	Iterator& operator+(const int t);
private:
	int* elem;
};

