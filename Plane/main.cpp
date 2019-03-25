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
				cout << "Введите пункт назначения(Самолёт №" << i + 1 << "):" << endl;
				getline(cin,comePoint);
				getline(cin,comePoint);
				comePoint = CorrectInput(comePoint);
				system("cls");
				cout << "Введите номер рейса(Самолёт №" << i + 1 << "):" << endl;
				getline(cin,raceNumber);
				raceNumber = CorrectInputRaceNumber(raceNumber);
				system("cls");
				tm time; 
				cout << "Введите час вылета(Самолёт №" << i + 1 << "):" << endl;
				cin >> time.tm_hour;
				CorrectInput(time.tm_hour);
				system("cls");
				cout << "Введите минуты вылета(Самолёт №" << i + 1 << "):" << endl;
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
			cout << "Введите какое сейчас время(часы):" << endl;
			cin >> timeNow.tm_hour;
			system("cls");
			cout << "Введите какое сейчас время(минуты):" << endl;
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
			cout << "Пункт назначения: " << somePlane.GetComePoint() << endl << "Номер рейса: " << somePlane.GetRaceNumber() << endl << "Время отправления: " << somePlane.GetTimeLiving().tm_hour << " часов " <<  somePlane.GetTimeLiving().tm_min <<  " минут" << endl;
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
					cout << "Ошибка, неверный пункт назанчения, плиз подумайте надо ли вам туда и измените его" << endl;
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
						cout << "Ошибка номера рейса (Номер рейса должен быть 6-ти значен) " << endl;
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
						cout << "Неверное время. Введите норально! Козлы!" << endl << "Введите часы:" << endl;
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
						cout << "Неверное время. Введите норально! Козлы!" << endl << "Введите минуты:" << endl;
						cin >> min;	
						if((min < 60) && (min >= 0)) qest = false;
					}
				}
			return min;
		}

};

void Menu()
{
	cout << "1 - Вывод самолётов по пункту назначения" << endl 
		<<"2 - Вывод самолётов вылетевших за ближайший час"<< endl
		<<"3 - Выход" << endl;
}

void main(string arg[])
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество самолётов, плиз:" << endl;
	cin >> n;
	Airport airport(n);
	int z;
	while (true)
	{
		cout << "Введите пункт меню" << endl;
		Menu();
		cin >> z;
		system("cls");
		if (z == 1)
		{
			string comePoint;
			cout << "Введите пункт назнчения:" << endl;
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


