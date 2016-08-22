#pragma once
#include <string>
#include "outlib.h"
using namespace std;


/*The leukocyte of this program*/
class Time
{
	/*I'm so lazy to move realization to clocks.cpp*/
public:
	Time();
	~Time();
	void setHours(int _hours) { this->hours = _hours; };
	void setMinutes(int _minutes) { this->minutes = _minutes; };
	void setSeconds(int _seconds) { this->seconds = _seconds; };
	int getHours() { return this->hours; };
	int getMinutes() { return this->minutes; };
	int getSeconds() { return this->seconds; };
	friend bool operator == (Time &time1, Time &time2);
	friend bool operator != (Time &time1, Time &time2);

private:
	int hours;
	int minutes;
	int seconds;
};


class IATA;



class TimeFinder
{
public:
	TimeFinder();
	~TimeFinder();
	Time findTime();

private:
	int hours;
	int minutes;
	int seconds;
};



/*To avoid compatibility with DeLorean, SkyNet and supports only ATA interface*/
class SkyNet
{
public:
	SkyNet();
	~SkyNet();
	void setStrategy(IATA* _device);
	Time getAnswer();

protected:
	IATA* device;
};


class IATA
{
public:
	IATA();
	~IATA();
	Time getTime();

	virtual void countTime() = 0;
protected:
	int hours;
	int minutes;
	int seconds;
};



class DeLorean : public IATA
{
public:
	DeLorean();
	~DeLorean();

	void countTime();

private:

};


/*T-800 is cool but while he return will pass 23 hours*/
class T800 : public IATA
{
public:
	T800();
	~T800();
	void countTime();

private:

};