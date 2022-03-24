#include "Timer.h"
#include <algorithm>
#include <iostream>

using namespace std;

Timer::Timer(int h, int m, int s) {
	this->s = s;
	this->m = m;
	this->h = h;
}

void Timer::CheckTime() {
	if (s < 0) { s = 0; }
	if (m < 0) { m = 0; }
	if (h < 0) { h = 0; }
	if (s >59.9) { m ++; s = 0; }
	if (m >59) { h ++; m = 0; }
}

float Timer::getSec() {
	return s;
}

int Timer::getMin() {
	return m;
}

int Timer::getHour() {
	return h;
}

void Timer::IncSec()
{
	s+= 0.1;
}

unsigned int Min(int d1, int d2, int d3)
{
	return std::min(d1, std::min(d2, d3));
}

unsigned int Max(int d1, int d2, int d3)
{
	return std::max(d1, std::max(d2, d3));
}

Timer& Timer::operator++() {
	 int minDiff = Min(abs(s - m), abs(s - h), abs(m - h));
	 if ((minDiff + s) > 60)
	 {
		 this->s = (minDiff + s) - 60;
		 this->m += (minDiff + s) / 60;
	 }
	 else
	 {
		 this->s += minDiff;
	 }
	 if ((minDiff + m) > 60)
	 {
		 this->m = (minDiff + m) - 60;
		 this->h += (minDiff + m) / 60;
	 }
	 else
	 {
		 this->m += minDiff;
	 }
	 this->h += minDiff;
	 return *this;
}

Timer Timer::operator++(int) {
	int command = 0;
	int maxValue = Max(s, m, h);

	printf("1) Increase seconds \n");
	printf("2) Increase minutes \n");
	printf("3) Increase hours \n");

	cout << endl << "Enter command: ";
	cin >> command;

	switch (command)
	{
	case 1:
		if ((maxValue + s) > 60)
		{
			this->s = (maxValue + s) - (maxValue / 60)*60;
			this->m += (maxValue + s) / 60;
		}
		else
		{
			this->s += maxValue;
		}
		break;
	case 2:
		if ((maxValue + m) > 60)
		{
			this->m = (maxValue + m) - (maxValue / 60) * 60;
			this->h += (maxValue + m) / 60;
		}
		else
		{
			this->m += maxValue;
		}
		break;
	case 3:
		this->h += maxValue;
		break;
	}
	return *this;
}

Timer& Timer::operator--() {
	int maxDiff = Max(abs(s - m), abs(s - h), abs(m - h));
	this->s -= maxDiff;
	this->m -= maxDiff;
	this->h -= maxDiff;
	return *this;
}

Timer Timer::operator--(int) {
	int t;
	int command = 0;
	
	printf("1) decrease seconds \n");
	printf("2) decrease minutes \n");
	printf("3) decrease hours \n");

	cout << endl << "Enter command: ";
	cin >> command;

	cout << endl << "Enter number: ";
	cin >> t;

	switch (command)
	{
	case 1:
		this->s -= t;
		break;
	case 2:
		this->m -= t;
		break;
	case 3:
		this->h -= t;
		break;
	}
	return *this;
}
