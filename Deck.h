
#include <iostream>
#include <sstream>
#include "DeckElement.h"

using namespace std;

class Deck
{
public:
	Deck();

	void operator+=(int num);
	Deck operator+(int num);

	friend Deck operator*=(const Deck &d1, int num);
	friend Deck operator*(const Deck& d1, int num);

	/*Deck operator=(int value);*/

	bool operator==(const Deck& d);
	bool operator!=(const Deck& d);


	string getStr();

	void setHead(DeckElement* element);
	DeckElement* getHead();
	
	void setTail(DeckElement* element);
	DeckElement* getTail();

	/*void pop();*/
	bool isEmpty();

private:
	DeckElement* head;
	DeckElement* tail;
	int size;
};
