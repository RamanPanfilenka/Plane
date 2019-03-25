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
					cout << "������, �������� ����� ����������, ���� ��������� ���� �� ��� ���� � �������� ���" << endl;
					getline(cin,comePoint);	
				}
				if((raceNumber.length() != 0) && (raceNumber.length() == 6))
				{
					this->raceNumber = raceNumber;
				}
				else
				{
					cout << "������ ������ ����� (����� ����� ������ ���� 6-�� ������) " << endl;
					getline(cin,raceNumber);	
				}
				if((timeLiving.tm_hour < 24) && (timeLiving.tm_hour > 0) && (timeLiving.tm_min > 0) && (timeLiving.tm_min < 60))
				{
					this->timeLiving = timeLiving;
				}
				else
				{
					cout << "�������� �����. ������� ��������! �����!" << endl << "������� ����:" << endl;
					cin >> timeLiving.tm_hour;	
					cout << "������� ������:" << endl;
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
