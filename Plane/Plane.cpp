#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Plane
{
	private:
		string comePoint;
		string raceNumber;
		tm timeLiving;
	public:
		Plane ()
		{
			comePoint = "this Point";
			raceNumber = "0";
			timeLiving.tm_hour = 0;
			timeLiving.tm_min = 0;
		}

		Plane (string comePoint, string raceNumber, tm timeLiving)
		{
			while (true)
			{
				if((comePoint.length() != 0))
				{
					this->comePoint = comePoint;
				}
				else
				{
					cout << "Ошибка, неверный пункт назанчения, плиз подумайте надо ли вам туда и измените его" << endl;
					getline(cin,comePoint);	
				}
				if((raceNumber.length() != 0) && (raceNumber.length() == 6))
				{
					this->raceNumber = raceNumber;
				}
				else
				{
					cout << "Ошибка номера рейса (Номер рейса должен быть 6-ти значен) " << endl;
					getline(cin,raceNumber);	
				}
				if((timeLiving.tm_hour < 24) && (timeLiving.tm_hour > 0) && (timeLiving.tm_min > 0) && (timeLiving.tm_min < 60))
				{
					this->timeLiving = timeLiving;
				}
				else
				{
					cout << "Неверное время. Введите норально! Козлы!" << endl << "Введите часы:" << endl;
					cin >> timeLiving.tm_hour;	
					cout << "Введите минуты:" << endl;
					cin >> timeLiving.tm_min;
				}
			}

		}

		Plane (Plane &f)
		{
			this->comePoint = f.comePoint;
			this->raceNumber = f.raceNumber;
			this->timeLiving = f.timeLiving;
		}


		~Plane(){};

		tm GetTimeLiving()
		{
			return timeLiving;
		}

		string GetComePoint()
		{
			return comePoint;
		}

		string GetRaceNumber()
		{
			return raceNumber;
		}
};
