#include <iostream>
#include <string>
#include <locale>
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
			this->comePoint = comePoint;
			this->raceNumber = raceNumber;				
			this->timeLiving = timeLiving;
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

class Airport
{
	private:
		Plane *arraysOfPlane;
		int n;
	public:
		Airport(int n)
		{
			arraysOfPlane = new Plane[n];
			CinInfoOfPlanes(n, arraysOfPlane);
			this->n = n;
			SortHours();
		}
		Airport(Plane *arraysOfPlane, int n)
		{
			this->arraysOfPlane = arraysOfPlane;
			this->n = n;
		};
		Airport(Airport &f)
		{
			this->arraysOfPlane = f.arraysOfPlane;
		};
		Airport();


		~Airport(){};

		void CinInfoOfPlanes(int n, Plane *arraysOfPlane)
		{
			for(int i = 0; i < n; i++ )
			{
				system("cls");
				string comePoint, raceNumber;
				cout << "������� ����� ����������(������ �" << i + 1 << "):" << endl;
				getline(cin,comePoint);
				getline(cin,comePoint);
				comePoint = CorrectInput(comePoint);
				system("cls");
				cout << "������� ����� �����(������ �" << i + 1 << "):" << endl;
				getline(cin,raceNumber);
				raceNumber = CorrectInputRaceNumber(raceNumber);
				system("cls");
				tm time; 
				cout << "������� ��� ������(������ �" << i + 1 << "):" << endl;
				cin >> time.tm_hour;
				CorrectInput(time.tm_hour);
				system("cls");
				cout << "������� ������ ������(������ �" << i + 1 << "):" << endl;
				cin >> time.tm_min;
				CorrectInputMin(time.tm_min);
				system("cls");
				Plane tempPlane(comePoint, raceNumber , time);
				arraysOfPlane[i] = tempPlane;
			}
		}
		void ListOfPlanesOneHour(int n)
		{
			tm timeNow;
			cout << "������� ����� ������ �����(����):" << endl;
			cin >> timeNow.tm_hour;
			system("cls");
			cout << "������� ����� ������ �����(������):" << endl;
			cin >> timeNow.tm_min;
			system("cls");
			for(int i = 0; i < n; i++)
			{
				if (arraysOfPlane[i].GetTimeLiving().tm_hour - timeNow.tm_hour == 0)
				{
					Print(arraysOfPlane[i]);
				}
				else
				{
					if(abs(arraysOfPlane[i].GetTimeLiving().tm_hour - timeNow.tm_hour) == 1)
					{
						if((arraysOfPlane[i].GetTimeLiving().tm_hour - timeNow.tm_hour) == 1)
						{
							if((arraysOfPlane[i].GetTimeLiving().tm_min - timeNow.tm_min) <= 0)
							{
								Print(arraysOfPlane[i]);
							}
						}
						else
						{
							if((arraysOfPlane[i].GetTimeLiving().tm_min - timeNow.tm_min) >= 0)
							{
								Print(arraysOfPlane[i]);
							}
						}
					}
				}
			}
		}
		void ListOfPlaneComePoint(string comePoint, int n)
		{
			for(int i = 0; i < n; i++)
			{
				if (arraysOfPlane[i].GetComePoint() == comePoint)
				{
					Print(arraysOfPlane[i]);
				}
			}
		}

		void Print(Plane somePlane)
		{
			cout << "����� ����������: " << somePlane.GetComePoint() << endl << "����� �����: " << somePlane.GetRaceNumber() << endl << "����� �����������: " << somePlane.GetTimeLiving().tm_hour << " ����� " <<  somePlane.GetTimeLiving().tm_min <<  " �����" << endl;
		}
		
		void SortHours()
		{
			int tempN = n - 1;
			int pos = 0;
			for(int i = 0; i< n; i++)
			{
				int max = arraysOfPlane[0].GetTimeLiving().tm_hour;
				pos = 0;
				for(int j = 0; j <= tempN; j++)
				{
					if(arraysOfPlane[j].GetTimeLiving().tm_hour > max)
					{
						max = arraysOfPlane[i].GetTimeLiving().tm_hour;
						pos = j;  
					}
				}
				swap(arraysOfPlane[pos], arraysOfPlane[tempN]);
				tempN--;
			}
			for(int k = 0; k < n; k++)
			{
				for(int i = 0; i < n; i++)
				{
					int temp = arraysOfPlane[i].GetTimeLiving().tm_hour;
					for(int j = i + 1; j < n; j++)
					{
						if(temp == arraysOfPlane[j].GetTimeLiving().tm_hour)
						{
							if (arraysOfPlane[j].GetTimeLiving().tm_min < arraysOfPlane[i].GetTimeLiving().tm_min)
							{
								swap(arraysOfPlane[j], arraysOfPlane[i]);
							}
						}
					}
				}
			}
		}

	private:
		string CorrectInput(string comePoint)
		{
			bool qest = true;
			if((comePoint.length() == 0))
			{
				while (qest)
				{
					cout << "������, �������� ����� ����������, ���� ��������� ���� �� ��� ���� � �������� ���" << endl;
					getline(cin,comePoint);
					if ((comePoint.length() != 0)) qest = false;
				}
			}
			return comePoint;
		}
		string CorrectInputRaceNumber(string raceNumber)
		{
			bool qest = true;
			if((raceNumber.length() == 0) || (raceNumber.length() != 6))
				{
					while (qest)
					{
						cout << "������ ������ ����� (����� ����� ������ ���� 6-�� ������) " << endl;
						getline(cin,raceNumber);	
						if ((raceNumber.length() != 0) && (raceNumber.length() == 6)) qest = false;
					}
					qest = true;
				}
			return raceNumber;
		}
		int CorrectInput(int hour)
		{
			bool qest = true;
			if((hour >= 24) || (hour < 0))
				{
					while (qest)
					{
						cout << "�������� �����. ������� ��������! �����!" << endl << "������� ����:" << endl;
						cin >> hour;	
						if((hour < 24) && (hour >= 0)) qest = false;
					}
				}
			return hour;
		}
		int CorrectInputMin(int min)
		{
			bool qest = true;
			if((min >= 60) || (min < 0))
				{
					while (qest)
					{
						cout << "�������� �����. ������� ��������! �����!" << endl << "������� ������:" << endl;
						cin >> min;	
						if((min < 60) && (min >= 0)) qest = false;
					}
				}
			return min;
		}

};

void Menu()
{
	cout << "1 - ����� �������� �� ������ ����������" << endl 
		<<"2 - ����� �������� ���������� �� ��������� ���"<< endl
		<<"3 - �����" << endl;
}

void main(string arg[])
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������� ���������� ��������, ����:" << endl;
	cin >> n;
	Airport airport(n);
	int z;
	while (true)
	{
		cout << "������� ����� ����" << endl;
		Menu();
		cin >> z;
		system("cls");
		if (z == 1)
		{
			string comePoint;
			cout << "������� ����� ���������:" << endl;
			getline(cin, comePoint);
			getline(cin, comePoint);
			airport.ListOfPlaneComePoint(comePoint, n);
		}
		if (z == 2) 
		{
			airport.ListOfPlanesOneHour(n);
		}
		if (z == 3) break;
		system("pause");
		system("cls");
	}
	system("pause");
}


