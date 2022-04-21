#include "Deck.h"

Deck::Deck() 
{
	int i;
	int num;
	cout << "Enter size:";
	cin >> size;
	cout << endl;
	for (i = 0; i <= size; ++i)
	{
		num = rand() % (20 - 15 + 1) + 15;
		DeckElement* element = new DeckElement(num, head);
		if (i==0)
			this->tail = element;
		this->head = element;
	}
	this->tail->setNext(this->head);
}

void Deck::setHead(DeckElement* element) {
	this->head = element;
}

void Deck::setTail(DeckElement* element) {
	this->tail = element;
}

DeckElement* Deck::getHead() {
	return head;
}

DeckElement* Deck::getTail() {
	return tail;
}

bool Deck::isEmpty() {
	return this->head == nullptr;
}

void Deck::operator+=(int num) {
	DeckElement* element;
	int command = 0;
	cout << "1.Add to head || 2.Add to tail"<< endl <<"Command:";
	cin >> command;
	cout << endl << endl;
	switch (command)
	{
	case 1:
			num = rand() % (20 - 15 + 1) + 14;
			element = new DeckElement(num, head);
			this->tail->setNext(element);
			this->head = element;
			this->head->setNext(tail);
	case 2:
			num = rand() % (20 - 15 + 1) + 14;
			element = new DeckElement(num, tail);
			this->head->setNext(element);
			this->tail = element;
			this->tail->setNext(head);
			break;
	}
	size++;
}

Deck Deck::operator+(int num) {
	int i;
	DeckElement* last = this->head;
	for (i = 0; i < size; ++i)
	{
		*last += num;
		last = last->getNext();
	}
	return *this;
}

//void Deck::pop() {
//	if (isEmpty()) return;
//
//	DeckElement* last = this->head;
//	DeckElement* prev = last;
//
//	int command = 0;
//	cout << "1.Pop from head || 2.Pop from tail" << endl << "Command:" << command;
//	switch (command)
//	{
//	case 1:
//
//		if (!last->getNext())
//		{
//			head = nullptr;
//			delete last;
//			return;
//		}
//			while (last)
//			{
//				if (last->getNext()) {
//					prev = last;
//					last = last->getNext();
//				}
//				else {
//					break;
//				}
//			}
//			prev->setNext(nullptr);
//			delete last;
//		}
//}

	Deck operator*=(const Deck & d1, int num)
{
	d1.head->setData(d1.head->getData()*num);
	return d1;
}

Deck operator*(const Deck& d1, int num)
{
	int i;
	DeckElement* last = d1.head;
	for (i = 0; i < d1.size; ++i) 
	{
		*last *= num;
		last = last->getNext();
	}
	return d1;
}

bool Deck::operator==(const Deck& d1)
{
	DeckElement* other = d1.head;
	DeckElement* current = this->head;

	if (d1.size != size)
	{
		cout << "Not equal" << endl;
		return false;
	}
	for (int i = 0; i < size; ++i)
	{
		if (other->getData() != current->getData())
			cout << other->getData() << "!=" << current->getData() << endl;
		else
			cout << other->getData() << "=" << current->getData() << endl;
		current = current->getNext();
		other = other->getNext();
	}
	return true;
}

bool Deck::operator!=(const Deck& d1)
{
	return !this->operator==(d1);
}

//Deck& operator=Deck(const Deck& src) = default;
//Deck& operator=Deck(Deck&& src) = default;

string Deck::getStr() {
	DeckElement* current = this->head;
	string result = "";

	while (current != tail)
	{
		result += std::to_string(current->getData());

		current = current->getNext();

		if (current != tail) result += " <=> ";
	}
	return result;
}
