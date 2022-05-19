#include "Deck.h"

Deck::Deck() 
{
	srand(time(0));

	int len;

	cout << "Enter size: ";
	cin >> len;
	cout << endl;

	for (int i = 0; i < len; ++i)
	{
		int number = rand() % (20 - 15 + 1) + 15;
		append(number);
	}

}


void Deck::Clear()
{
	DeckElement* last = this->tail;
	DeckElement* tmp;

	for (int i = 0; i < size; ++i)
	{
		tmp = last;
		last = last->getNext();
		delete tmp;
	}

	head = nullptr;
	tail = nullptr;
	size = 0;
}

void Deck::append(int number) {
	DeckElement* headElemnet = new DeckElement(number, tail);

	if (head) {
		head->setNext(headElemnet);
	}

	head = headElemnet;

	if (!tail) {
		tail = headElemnet;
	}

	size++;
}

void Deck::prepend(int number) {
	DeckElement* tailElement = new DeckElement(number, tail);

	if (head) {
		head->setNext(tailElement);
	}

	tail = tailElement;

	if (!head) {
		head = tailElement;
	}

	size++;
}


void Deck::operator+=(int num) {

	int command = 0;

	cout << "1. Add to head " << endl << "2. Add to tail" << endl << "Command: ";
	cin >> command;
	cout << endl << endl;

	switch (command)
	{

	case 1:
		num = rand() % (20 - 15 + 1) + 14;
		append(num);
		break;
	case 2:
		num = rand() % (20 - 15 + 1) + 14;
		prepend(num);
		break;
	}
}

void Deck::popFromHead() {
	if (isEmpty())
	{
		cout << "Deck is Empty!";
		return;
	}

	cout << "Value: " << this->head->getData() << endl;

	if (size == 1)
	{
		Clear();
		return;
	}

	DeckElement* beforeHead = this->tail;

	while (beforeHead->getNext() != head) {
		beforeHead = beforeHead->getNext();
	}

	beforeHead->setNext(tail);

	delete head;

	head = beforeHead;

	size--;
}

void Deck::popFromTail() {
	if (isEmpty())
	{
		cout << "Deck is Empty!";
		return;
	}

	cout << "Value: " << this->tail->getData() << endl;

	if (size == 1)
	{
		Clear();
		return;
	}

	DeckElement* next = tail->getNext();

	head->setNext(next);

	delete tail;

	tail = next;

	size--;
}

void Deck::extract()
{
	int command = 0;

	cout << "1. From head " << endl << "2. From tail" << endl << endl << "Command: ";
	cin >> command;
	cout << endl << endl;

	switch (command)
	{

	case 1:
		popFromHead();
		break;
	case 2:
		popFromTail();
		break;
	}
}

Deck Deck::operator+(int num) {
	DeckElement* last = this->tail;

	for (int i = 0; i < size; ++i)
	{
		*last += num;
		last = last->getNext();
	}

	return *this;
}

Deck operator*=(const Deck & d1, int num)
{
	if (d1.size == 0)
	{
		cout << "Deck is Empty!" << endl;
		return d1;
	}

	d1.head->setData(d1.head->getData()*num);
	return d1;
}

Deck operator*(const Deck& d1, int num)
{
	DeckElement* last = d1.head;
	for (int i = 0; i < d1.size; ++i)
	{
		*last *= num;
		last = last->getNext();
	}
	return d1;
}

bool Deck::operator==(const Deck& second)
{
	DeckElement* other = second.tail;
	DeckElement* current = this->tail;

	bool condition = second.size == size; // Если размеры стеков не совпадают то, сразу устанавливаем false 

	if (isEmpty() || second.size == 0)
	{
		cout << "Deck is Empty!";
		return false;
	}

	for (int i = 0; i < min(size, second.size); ++i)
	{
		if (other->getData() != current->getData()) {

			condition = false;
			cout << "\x1b[31m" << other->getData() << " != " << current->getData() << "\x1b[0m"  << endl;

		} else {
			cout << "\x1b[32m" << other->getData() << " == " << current->getData() << "\x1b[0m" << endl;
		}

		current = current->getNext();
		other = other->getNext();
	}

	return condition;
}

bool Deck::operator!=(const Deck& second)
{
	DeckElement* other = second.tail;
	DeckElement* current = this->tail;

	bool condition = second.size != size; // Если размеры стеков не совпадают то, сразу устанавливаем false 
	
	if (isEmpty() || second.size == 0)
	{
		cout << "Deck is Empty!";
		return false;
	}

	for (int i = 0; i < min(size, second.size); ++i)
	{
		if (other->getData() != current->getData()) {
			cout << "\x1b[32m" << other->getData() << " != " << current->getData() << "\x1b[0m" << endl;
		} else {
			condition = condition || false;
			cout << "\x1b[31m" << other->getData() << " == " << current->getData() << "\x1b[0m" << endl;
		}

		current = current->getNext();
		other = other->getNext();
	}

	return condition;
}

Deck Deck::operator=(Deck deck)
{
	Clear();

	DeckElement* current = deck.tail;

	do
	{
		append(current->getData());

	} while ((current = current->getNext()) != deck.tail);


	return *this;
}

string Deck::getStr() {

	if (isEmpty())
	{
		string result = "Deck is Empty!";
		return result;
	}

	DeckElement* current = this->tail;
	string result = "";

	do
	{
		if (current != tail) result += " <=> ";
		result += std::to_string(current->getData());

	} while ((current = current->getNext()) != tail && current);

	return result;
}


bool Deck::isEmpty() {
	return size == 0;
}
