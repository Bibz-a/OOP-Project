#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdexcept>
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#include <iomanip>

using namespace std;

class CityObj {
protected:
	string name;
public:
	CityObj(string n) {
		name = n;
	}
	virtual void info() = 0;
};
class Transport: public CityObj
{
	protected:
	int pollution_level_caused;
	public:
		Transport(string n,int plc):CityObj(n)
		{
			pollution_level_caused=plc;
		}
	virtual void upgrade() = 0;
	virtual string getType() const = 0;
	
};
class Trains:public Transport
{
	private:
	int num_trains;
	bool is_bullet;
	public:
		Trains(string n,int plc,int numtrain,bool isbullet):Transport(n,plc)
		{
			num_trains=numtrain;
			is_bullet=isbullet;
		}
	void upgrade() override {
		if(!is_bullet)
		{
			is_bullet=true;
			cout<<"Train upgraded to bullet.."<<endl;
			cout<<"Pollution level decresed by 6 levels"<<endl;
			pollution_level_caused -= 6;
		}
		else
		{
		cout<<"Upgraded bullet train, Pollution level decreased by 4 levels"<<endl;
		pollution_level_caused -= 4;
	}
		
		
	}
	void info() {
		cout << " >> Transport name: " << name << endl;
		cout << " >> Number of trains : " << num_trains << endl;
		cout << " >> Level of pollution caused: " << pollution_level_caused << endl;
	}
	string getType() const {
		return "Trains";
	}
};
class Cars:public Transport
{
	private:
	int num_owners;
	bool isElectric;
	public:
		Cars(string n,int plc,int owners,bool iselec):Transport(n,plc)
		{
			num_owners=owners;
			isElectric=iselec;
		}
	void upgrade() override {
		if(!isElectric)
		{
			isElectric=true;
			cout<<"Car upgraded to EV.."<<endl;
			cout<<"Pollution level decresed by 8 levels"<<endl;
			pollution_level_caused -= 8;
		}
		else
		{
		cout<<"Upgraded Electric Car ,Pollution level decreased by 4 levels"<<endl;
		pollution_level_caused -= 5;
		};
}
	void info() {
		cout << " >> Transport name: " << name << endl;
		cout << " >> Number of owners : " << num_owners << endl;
		cout << " >> Level of pollution caused: " << pollution_level_caused << endl;
	}
	string getType() const {
		return "Cars";
	}
};
class Building : public CityObj {
protected:
	int energyconsumption;
public:
	Building(string n, int energy) : CityObj(n) {
		energyconsumption = energy;
	}
	virtual void upgrade() = 0;
	virtual string getType() const = 0;

};

class Residential : public Building {
private:
	int occupants;
public:
	Residential(string n, int energy, int occup) : Building(n, energy) {
		occupants = occup;
	}
	void upgrade() override {
		energyconsumption -= 2; //maybe use a better logic here
	}
	void info() {
		cout << " >> Building name: " << name << endl;
		cout << " >> Occupants numbers: " << occupants << endl;
		cout << " >> Energy Consumption: " << energyconsumption << endl;
	}
	string getType() const {
		return "Residential";
	}
};
class Commercial :public Building
{
	private:
	int num_of_shops;
	int Solarpanels;
	public:
	Commercial(string n,int energy,int numshops,int solarpanels):Building(n,energy)
	{
		num_of_shops=numshops;
		Solarpanels=solarpanels;
		
	}
	void upgrade()override
	{
	if(Solarpanels<20)
		{
			energyconsumption-=3;
			
		}
		else
		energyconsumption-=6;
	}
	void info() {
		cout << " >> Building name: " << name << endl;
		cout << " >> Number of Shops: " << num_of_shops << endl;
		cout << " >> Number of Solarpanels: " << Solarpanels << endl;
		cout << " >> Energy Consumption: " << energyconsumption << endl;
	}
	string getType() const {
		return "Commertial";
	}
		
};
class Industrial :public Building
{
	private:
	int pollution_level;
	bool greentech;
	public:
	Industrial(string n,int energy,int pl,bool gt):Building(n,energy)
	{
		pollution_level=pl;
		greentech=gt;
		
	}
	void upgrade()override
	{
		if(!greentech)
		{
			energyconsumption-=3;
			
		}
		else
		energyconsumption-=6;
	}
	void info() {
		cout << " >> Building name: " << name << endl;
		cout << " >> Pollution Level: " << pollution_level<< endl;
		if(greentech)
		cout << " >> The bulding has Green tech " <<endl;
		else
		cout << " >> The bulding does not have Green tech " << endl;
		cout << " >> Energy Consumption: " << energyconsumption << endl;
	}
	string getType() const {
		return "Industrial";
	}
		
};

class City {
private:
	vector<Building*> buildings;
	int population;
	int ecoscore;
public:
	City() {
		ecoscore = 5;
		population = 1000;
	}
	void Addbuilding() {
		cout << "Which type of building do you wish to add?" << endl;
		cout << "1. Residential Building 2. Commercial Building 3. Industrial Building 4. Green Space" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << ">> Enter the name of this Residential Building: ";
			cin.ignore();
			string name;
			getline(cin, name);

			cout << ">> Enter the number of occupants: ";
			int o;
			cin >> o;
			cout << ">> Enter the energy Consumption: ";
			int e;
			cin >> e;
			cin.ignore();
			Building* b = new Residential(name, e, o);
			buildings.push_back(b);
			break;
		}
		case 2: {
			cout << ">> Enter the name of this Commercial Building: ";
			cin.ignore();
			string name;
			getline(cin, name);
			int sh;
			cout << ">> Enter the number of shops: ";
			cin>>sh;
			int sp;
			cout << ">> Enter the number of solar panels: ";
			cin>>sp;
			int e;
			cout << ">> Enter the energy Consumption: ";
			cin >> e;
			cin.ignore();
			Building* b = new Commercial(name, e, sh,sp);
			buildings.push_back(b);
			break;
		}
		case 3: {
			cout << ">> Enter the name of this Industrial Building: ";
			cin.ignore();
			string name;
			getline(cin, name);
			int pl;
			cout << ">> Enter the pollution level(0-10): ";
			cin>>pl;
			bool gt;
			cout << ">> Does the building have greentech (0/1): ";
			cin>>gt;
			int e;
			cout << ">> Enter the energy Consumption: ";
			cin >> e;
			cin.ignore();
			Building* b = new Industrial(name, e, pl,gt);
			buildings.push_back(b);
			break;
		}
		default: {
			cout << ">> Error: Not a valid choice" << endl;
		}

		}
	}


	void displaystatus() {
		setColor(11);
		cout << ">> City Information:" << endl;
		setColor(7);
		cout << ">> Current Population " << population << endl;
		cout << ">> Current EcoScore: " << ecoscore << endl;
		setColor(11);
		cout << ">> Current Buildings: " << endl;
		setColor(7);
		for (Building* b : buildings) {
			cout << b->getType() << ": ";
			b->info();
		}

	}
};


void printHeading() {
	setColor(11);
	cout << "\n\n";
	cout << "============================================================\n";
	cout << setw(45) << "SMART ECO CITY SIMULATOR\n";
	cout << "============================================================\n\n";
	setColor(7);
}
void menu(City& MyCity) {
	int choice;
	printHeading();
	do {
		setColor(10);
		cout << "\n >> What would you like to do?\n";
		setColor(14);
		cout << "   >> 1. Build a Building\n";
		cout << "   >> 2. View City Status\n";
		cout << "   >> 3. Exit Simulation\n";
		setColor(7);
		cout << "Enter your choice: ";
		try{
    if (!(cin >> choice)) {
    	cin.clear();
    	cin.ignore(1000, '\n');
        throw invalid_argument(" Invalid input. Please enter an integer (1/2/3).");
    }
		
}
catch(const invalid_argument &e)
	{
		setColor(12);
		cout<<"Caught exception:"<<e.what()<<endl;
	}
		switch (choice) {
		case 1:
			MyCity.Addbuilding();
			break;
		case 2:
			MyCity.displaystatus();
			break;
		case 3:
			setColor(12);
			cout << "\nExiting simulation...\n";
			setColor(7);
			break;
		default:
			setColor(12);
			cout << "Error: Invalid Choice\n";
			setColor(7);
		}
	
	} while (choice != 3);
}

int main() {
	City MyCity;
	menu(MyCity);
	
	return 0;
}
