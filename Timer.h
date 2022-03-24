#pragma once

class Timer {
public:
	Timer(int h, int m, int s);

	float getSec();
	int getMin();
	int getHour();
	void IncSec();
	void CheckTime();

	Timer& operator++();
	Timer operator++(int);
	Timer& operator--();
	Timer operator--(int);

private:
	 int m, h;
	 float s;
};