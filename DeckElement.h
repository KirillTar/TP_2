#pragma once

class DeckElement {
public:
	DeckElement(int data, DeckElement* next);
	DeckElement(const DeckElement& deckElement);

	~DeckElement();
	int getData();
	void operator+=(int num);
	void operator*=(int num);

	DeckElement* getNext();
	void setNext(DeckElement* next);
	void setData(int data);

private:
	int data;
	DeckElement* next;
};