
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>

#include "DeckElement.h"

using namespace std;

class Deck
{
public:
	int size;

	Deck();

	void operator+=(int num);
	Deck operator+(int num);

	friend Deck operator*=(const Deck &d1, int num);
	friend Deck operator*(const Deck& d1, int num);

	bool operator==(const Deck& d);
	bool operator!=(const Deck& d);

	Deck operator=(Deck deck);

	string getStr();

	void Clear();

	void extract();
	bool isEmpty();

private:
	void popFromHead();
	void popFromTail();

	void append(int number);
	void prepend(int number);

	DeckElement* head;
	DeckElement* tail;
};
