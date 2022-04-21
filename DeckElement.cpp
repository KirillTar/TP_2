#include "DeckElement.h"

DeckElement::DeckElement(int data, DeckElement* next) {
	this->data = data;
	this->next = next;
}

DeckElement::DeckElement(const DeckElement& deckElement) {
	this->data = deckElement.data;
	this->next = deckElement.next;
}

DeckElement::~DeckElement() {
	this->data = 0;
	this->next = nullptr;
}

int DeckElement::getData() {
	return data;
}

void DeckElement::setData(int data) {
	this->data = data;
}

void DeckElement::operator+=(int num) {
	this->data += num;
}

void DeckElement::operator*=(int num) {
	this->data *= num;
}


DeckElement* DeckElement::getNext() {
	return next;
}

void DeckElement::setNext(DeckElement* prev) {
	this->next = next;
}