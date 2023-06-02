#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
	private:
		char name[50];
		int number;
	public:
		Employee()
		{
			//cout << "def const EMP "<<this << endl;
			strcpy(name, "");
			number = 0;
		}
		Employee(char c[50] , int a)
		{
			//cout << "OC EMP "<<this << endl;
			strcpy(name, c);
			number = a;
		}
		void setName(char c[50])
		{
			strcpy(name, c);
		}
		void setNumber(int a)
		{
			number = a;
		}
		char* getName()
		{
			return name;
		}
		int getNumber()
		{
			return number;
		}
		void display()
		{
			cout << getName() << " " << getNumber()<<" ";
		}
		Employee(const Employee& orig)
		{
			//cout<<"Copy Constructor EMPLOYEE "<<this <<endl;
			number = orig.number;
			strcpy(name, orig.name);
		}
		const Employee& operator = (const Employee& rhs)
		{
			//cout << "Assign Operator EMPLOYE  "<<this << endl;
			if (this == &rhs)
			{
				return *this;
			}
			else
			{
				number = rhs.number;
				strcpy(name, rhs.name);
				return *this;

			}
		}
		~Employee()
		{
			//cout << "dest EMP "<<this << endl;
		}
};
class  ProductionWorker :public Employee
{
	private:
		int shift;
		double hourlyPayRate;
	public:
		ProductionWorker()
		{
			//cout << " Def const PW " << this << endl;
			shift = 0;
			hourlyPayRate = 0;
		}
		ProductionWorker(char c[50], int a, int s, double d) :Employee(c, a), shift(s), hourlyPayRate(d)
		{
			//cout << " OC of PW " << this << endl;
		}
		void setShift(int s)
		{
			shift = s;
		}
		void setpayRate(int d)
		{
			hourlyPayRate = d;
		}
		int getShift()
		{
			return shift;
		}
		double getHourRate()
		{
			return hourlyPayRate;
		}
		ProductionWorker(const ProductionWorker& orig):Employee(orig)
		{
			//cout << "Copy Constructor of PW "<<this << endl;
			shift = orig.shift;
			hourlyPayRate = orig.hourlyPayRate;
		}
		const ProductionWorker& operator = (const ProductionWorker& rhs)
		{
			//cout << "Assign Operator  PW "<<this << endl;
			if (this == &rhs)
			{
				return *this;
			}
			else
			{
				Employee::operator=(rhs);
				shift = rhs.shift;
				hourlyPayRate = rhs.hourlyPayRate;

				return *this;

			}
		}
		~ProductionWorker()
		{
			//cout << "dest  PW "<<this  << endl;
		}
		void workerDisplay()
		{
			display();
			cout<<getShift()<<" "<<getHourRate();

		}

};
class TeamLeader:public ProductionWorker
{
	private:
		double monthlyBonus;
		int trainingHours;
		int trainHoursOfLeader;
	public:
		TeamLeader()
		{
			//cout << " Def const TL " << this << endl;
			monthlyBonus = 0;
			trainingHours = 0;
			trainHoursOfLeader = 0;
		}
		TeamLeader(char c[50], int a, int s, double d,double m,int th,int tL) :ProductionWorker(c, a,s,d), monthlyBonus(m),trainingHours(th),trainHoursOfLeader (tL)
		{
			//cout << " OC of TL " << this << endl;
		}
		void setmonthlyBonus(double m)
		{
			monthlyBonus = m;
		}
		void setpayRate(int th)
		{
			trainingHours = th;
		}
		void settrainLeader(int tL)
		{
			trainHoursOfLeader = tL;
		}
		double getHourlyBonus()
		{
			return monthlyBonus;
		}
		int getTrainHours()
		{
			return trainingHours;
		}
		int getTrainLeader()
		{
			return trainHoursOfLeader;
		}
		TeamLeader(const TeamLeader& orig) :ProductionWorker(orig)
		{
			cout << "Copy Constructor of TL "<<this << endl;
			monthlyBonus = orig.monthlyBonus;
			trainingHours = orig.trainingHours;
			trainHoursOfLeader = orig.trainHoursOfLeader;
		}
		const TeamLeader& operator = (const TeamLeader& rhs)
		{
			//cout << "Assign Operator  TL "<<this << endl;
			if (this == &rhs)
			{
				return *this;
			}
			else
			{
				ProductionWorker::operator=(rhs);
				monthlyBonus = rhs.monthlyBonus;
				trainingHours = rhs.trainingHours;
				trainHoursOfLeader = rhs.trainHoursOfLeader;
				return *this;

			}
		}
		void teamDisplay()
		{
			workerDisplay();
			cout << getHourlyBonus() << " " << getTrainHours() << " " << getTrainLeader();
		}
		~TeamLeader()
		{
			//cout << "dest  TL "<<this  << endl;
		}
};
int main()
{
	//Section 1.1
	/*char c[50] = "MIAN WAQAS ALI";
	Employee e(c , 13);
	e.display();
	Employee e1;
	e1 = e;
	e1.display();
	Employee e2=e1;
	e2.display();*/
	 
	
	/*char c1[50];
	int numb;
	cout << "Enter name ";
	cin.getline(c1, 50);
	cout << "Enter number ";
	cin >> numb;
	Employee e(c1, numb);
	cout << " Data on Stack \n";
	e.display();
	cout << " \n Data on Heap\n";
	Employee* e1 = new Employee(c1, numb);
	e1->display();
	cout << "\n Production Worker_______\n";*/
	//Sec 1.2
	//char c[50] = "MIAN WAQAS ALI";
	char c[50];
	int n, sh;
	double pay;
	/*cin.ignore();
	cout << "Enter name ";
	cin.getline(c, 50);
	cout << "Enter number ";
	cin >> n;
	cout << "Enter Shift ";
	cin >> sh;
	cout << "Enter payRate ";
	cin >> pay;*/
	//cout << "STACK\n";
	//ProductionWorker p(c, n,sh,pay);
	//p.workerDisplay();
	//cout << "\nHEAP\n";
	//ProductionWorker* p1 = new ProductionWorker(c, n, sh, pay);
	//p1->workerDisplay();*/
	/*cout << endl;
	ProductionWorker p2;
	p2 = p;
	p2.workerDisplay();
	cout << endl;
	ProductionWorker p3 = p;
	p3.workerDisplay();*/
	//cout << endl;

	/*char c2[50] = "MALIK ALI RAZA";
	TeamLeader t(c2 , 13,2,12.3635,62.76,3,4);
	t.teamDisplay();
	cout << endl;
	TeamLeader t1;
	t1 = t;
	t1.teamDisplay();
	cout << endl;
	TeamLeader t2=t1;
	t2.teamDisplay();
	cout << endl;*/
	int num,trh,trhl;
	double b;
	cout << "Enter the number of Team Leaders ";
	cin >> num;
	TeamLeader** teamLead = new TeamLeader*[num];
	for (int i = 0; i < num; i++)
	{
		cin.ignore();
		cout << "Enter name ";
		cin.getline(c, 50);
		cout << "Enter number ";
		cin >> n;
		cout << "Enter Shift ";
		cin >> sh;
		cout << "Enter payRate ";
		cin >> pay;
		cout << "Enter the bonus ";
		cin >> b;
		cout << "Enter the train hours ";
		cin >> trh;
		cout << "Enter the train hours of leader ";
		cin >> trhl;
		teamLead[i] = new TeamLeader(c, n, sh, pay, b, trh, trhl);
	}
	for (int i = 0; i < num; i++)
	{
		teamLead[i]->teamDisplay();
		cout << endl;
	}
	for (int i = 0; i < num; i++)
	{
		delete[i]teamLead;
		teamLead = nullptr;
	}
	return 0;
}