#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Timer.h"

#define ENTER 13
#define ESCAPE 32

using namespace std;

Timer timer = Timer(300, 0, 40);

//void IntegerLoop() {
//	int num;
//
//	cout << "Введите начальное число: ";
//	cin >> num;
//	system("@cls||clear");
//
//	Integer integer(num);
//
//	string commands[] = {
//		"Вычесть число (--int)",
//		"Вычесть еденицу (int--)",
//		"Прибавть число (++int)",
//		"Прибавть еденицу (int++)",
//		"Получить отрицательное значение (!)",
//		"\033[31mВернуться в меню\033[0m"
//	};
//	
//	lastSelectedMenuLine = 0;
//
//	while (true)
//	{
//		string status = "Значение класса Integer: \033[31m" + to_string(integer.getData()) + "\033[0m";
//
//		int command = menu(status, commands, 6);
//
//		switch (command)
//		{
//			case 0:
//				--integer;
//				break;
//			case 1:
//				integer--;
//				break;
//			case 2:
//				++integer;
//				break;
//			case 3:
//				integer--;
//				break;
//			case 4:
//				cout << !integer;
//				backLoop();
//				break;
//			case 5:
//				return;
//		}
//	}
//}
//
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
		cout << "1)Timer" << endl;
		cin >> command;
		system("@cls||clear");
		switch (command) 
		{
		case 1: TimerLoop();
		}
		system("@cls||clear");
	}
}

