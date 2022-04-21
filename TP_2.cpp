#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Timer.h"
#include "Deck.h"

#define ENTER 13
#define ESCAPE 32

using namespace std;

Timer timer = Timer(200, 3, 13); 


void DeckLoop() {
	system("@cls||clear");

	Deck d1 = Deck();
	cout << endl << d1.getStr() << endl << endl;
	Deck d2 = Deck();
	cout << endl << d2.getStr() << endl << endl;

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
	printf("9) Exit to menu \n");
	printf("0) Exit programm \n");
		
	cout << endl << "Command:";
	cin >> command;
	cout << endl;
	switch (command)
	{
	case 1:
		cout << "Enter number:";
		cin >> num;
		cout << endl;
		d1 + num;
		cout <<	d1.getStr() << endl << "Increased";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;

	case 2:
		cout << "Enter number:";
		cin >> num;
		cout << endl;
		d1*num;
		cout << d1.getStr() << endl << "Multiplyed";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;

	case 3:
		d1+=0;
		cout << d1.getStr() << endl << "Added";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;

	case 4:
		cout << "Enter number:";
		cin >> num;
		cout << endl;
		d1*=num;
		cout << d1.getStr() << endl << "Head multiplyed";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;

	/*case 5:
		timer--;
		cout << endl << "Assigned";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;*/

	case 6:
		d1 == d2;
		cout << endl << "Test completed";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;

	case 7:
		d1 != d2;
		cout << endl << "Test completed";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;

	/*case 8:
		;
		cout << endl << "Popped";
		cout << endl << endl << "Press any key to exit" << endl;
		_getch();
		break;*/

	case 0:
		exit(0);
		break;
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
		system("@cls||clear");

		cout << "  " << timer.getHour() << ':' << timer.getMin() << ':' << (int)timer.getSec() << endl << endl;

		printf("1) Increase by min difference \n");
		printf("2) Increase by max value \n");
		printf("3) Decrease by max difference \n");
		printf("4) Decrease by yours value \n");
		printf("9) Exit to menu \n");
		printf("0) Exit programm \n");

		int command = 0;
		cout << endl << "Command:"; 
		cin >> command;

		switch (command)
		{
		case 1:
			++timer;
			cout << endl << "Increased";
			cout << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 2:
			timer++;
			cout << endl << "Increased";
			cout << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 3:
			--timer;
			cout << endl << "Decreased";
			cout << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 4:
			timer--;
			cout << endl << "Decreased";
			cout << endl << "Press any key to exit" << endl;
			_getch();
			break;

		case 0:
			exit(0);
			break;
		}
}

int main()
{
	int command = 0;
	while (true)
	{
		cout << "1)Timer" << endl << "2)Deck" << endl << endl << "Enter command:";
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

