#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Timer.h"
#include "Deck.h"

#define ENTER 13
#define ESCAPE 32

using namespace std;

Timer timer = Timer(12, 3, 13); 


void DeckLoop() {
	Deck d1 = Deck();
	Deck d2 = Deck();

	for (;;) {
		system("@cls||clear");
		cout << "Deck 1: " << d1.getStr() << endl;
		cout << "Deck 2: " << d2.getStr() << endl << endl;

		int command = 0;
		int num = 0;
		printf("1) Increase by number \n");
		printf("2) Multiply by number \n");
		printf("3) Add element \n");
		printf("4) Multiply head by number \n");
		printf("5) Assign \n");
		printf("6) Equality test \n");
		printf("7) Inequality test \n");
		printf("8) Pop element \n");
		printf("0) Exit to menu \n");

		cout << endl << "Command: ";
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			cout << "Enter number: ";

			cin >> num;
			cout << endl;

			d1 + num;
			
			break;

		case 2:
			cout << "Enter number: ";

			cin >> num;
			cout << endl;

			d1 * num;

			break;

		case 3:
			d1 += 0;
			break;

		case 4:
			cout << "Enter number: ";
			cin >> num;
			cout << endl;

			d1 *= num;

			break;

		case 5:
			d2 = d1;
			cout << endl << "Assigned";
			cout << endl << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 6:
			if (d1 == d2) {
				cout << endl << "\x1b[32mEquals\x1b[0m";
			} else {
				cout << endl << "\x1b[31mNot Equals\x1b[0m";
			}
			cout << endl << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 7:

			if (d1 != d2) {
				cout << endl << "\x1b[32mNot Equals\x1b[0m";
			} else {
				cout << endl << "\x1b[31mEquals\x1b[0m";
			}

			cout << endl << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 8:
			d1.extract();

			cout << endl << endl << "Press any key to exit" << endl;
			_getch();
			break;

		}

		if (command == 0) break;
	}
}

void TimerLoop() 
{
	int x = 0;
	while (x != ENTER)
	{
		timer.CheckTime();
		timer.IncSec();
		Sleep(100);
		if ((int)round(timer.getSec() * 10) % 10 == 0)
		{
			system("@cls||clear");
			cout << "  " << timer.getHour() << ':' << timer.getMin() << ':' << (int)timer.getSec() << endl << endl << "Press ENTER to show commands";
		}
		if (GetKeyState(ENTER) & 0x8000)
		{
			x = ENTER;
		}
	}

	for (;;) {

		system("@cls||clear");
		
		timer.CheckTime();

		cout << "  " << timer.getHour() << ':' << timer.getMin() << ':' << (int)timer.getSec() << endl << endl;

		printf("1) Increase by min difference \n");
		printf("2) Increase by max value \n");
		printf("3) Decrease by max difference \n");
		printf("4) Decrease by yours value \n");
		printf("9) Exit to menu \n");
		printf("0) Exit programm \n");

		int command = 0;
		cout << endl << "Command: ";
		cin >> command;

		switch (command)
		{
		case 1:
			++timer;
			cout << endl << "Increased";
			break;

		case 2:
			timer++;
			cout << endl << "Increased";
			break;

		case 3:
			--timer;
			cout << endl << "Decreased";
			break;

		case 4:
			timer--;
			cout << endl << "Decreased";

			break;

		case 0:
			exit(0);
			break;
		}
	}
}

int main()
{
	int command = 0;
	while (true)
	{
		cout << "1)Timer" << endl << "2)Deck" << endl << endl << "Enter command: ";
		cin >> command;
		system("@cls||clear");
		switch (command) 
		{
		case 1: TimerLoop(); break;
		case 2: DeckLoop(); break;
		}
		system("@cls||clear");
	}
}

