#include "clocks.h"
#include <ctime>
#include "outlib.h"

Time::Time()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
};

Time::~Time()
{
};

bool operator == (Time &time1, Time &time2)
{
	if (time1.hours == time2.hours)
	{
		if (time1.minutes == time2.minutes)
		{
			if (time1.seconds == time2.seconds)
			{
				return true;
			};
		};
	};
	return false;
};

bool operator != (Time &time1, Time &time2)
{
	return !(time1 == time2);
};



TimeFinder::TimeFinder()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
};

TimeFinder::~TimeFinder()
{
};

Time TimeFinder::findTime()
{
	time_t result = time(NULL);

	char str[26];
	ctime_s(str, sizeof str, &result);
	string strr = str;
	
	Time answer;

	answer.setHours(atoi(strr.substr(11, 2).c_str()));
	answer.setMinutes(atoi(strr.substr(14, 2).c_str()));
	answer.setSeconds(atoi(strr.substr(17, 2).c_str()));

	return answer;
};



SkyNet::SkyNet()
{
};

SkyNet::~SkyNet()
{
	delete device;
};

void SkyNet::setStrategy(IATA* _device)
{
	this->device = _device;
};

Time SkyNet::getAnswer()
{
	Time answer;

	device->countTime();
	answer = device->getTime();
	
	return answer;
};



IATA::IATA()
{
};

IATA::~IATA()
{
};

Time IATA::getTime()
{
	Time answer;
	answer.setHours(this->hours);
	answer.setMinutes(this->minutes);
	answer.setSeconds(this->seconds);

	return answer;
};



DeLorean::DeLorean()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
};

DeLorean::~DeLorean()
{
};

/*I'm dissapointed. That's not the algorithm that I want. I'm just so stupid to do it*/
void DeLorean::countTime()
{
	TimeFinder timeFinder;
	Time time;
	int timePeriod = 23;
	time = timeFinder.findTime();
	this->hours = time.getHours();
	this->minutes = time.getMinutes();
	this->seconds = time.getSeconds();
	if (this->hours == 0) this->hours +=24 ;
	this->hours += timePeriod;
	this->hours -= 24;

};



T800::T800()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
};

T800::~T800()
{
};

void T800::countTime()
{
	TimeFinder timeFinder;
	Time now, then;
	OutManager outManager;
	now = timeFinder.findTime();
	this->hours = now.getHours();
	this->minutes = now.getMinutes();
	this->seconds = now.getSeconds();

	int steps = 0;
	int i = 0;
	steps = 60 * 60 * 23;
	float one_percent = steps / 100;

	/*It works like donkey. We arrived? We arrived? We arrived?*/
	while (i < steps)
	{
		
		then = timeFinder.findTime();
		if (then != now)
		{
			now = timeFinder.findTime();
			this->hours = now.getHours();
			this->minutes = now.getMinutes();
			this->seconds = now.getSeconds();
			i++;
			outManager.terminatorOut(i, one_percent);
		};
	};
};