#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdexcept>
#include <conio.h>
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
	string getName() const {
		return name;
	}
};
class Transport : public CityObj
{
protected:
	int pollution_level_caused;
public:
	Transport(string n, int plc) :CityObj(n)
	{
		pollution_level_caused = plc;
	}
	virtual void upgrade() = 0;
	virtual string getType() const = 0;

};
class Train :public Transport
{
private:
	int num_trains;
	bool is_bullet;
public:
	Train(string n, int plc, int numtrain, bool isbullet) :Transport(n, plc)
	{
		num_trains = numtrain;
		is_bullet = isbullet;
	}
	void upgrade() override {
		if (!is_bullet)
		{
			is_bullet = true;
			cout << "Train upgraded to bullet.." << endl;
			cout << "Pollution level decresed by 6 levels" << endl;
			pollution_level_caused -= 6;
			if (pollution_level_caused <= 0) {
				pollution_level_caused = 0;
			}
		}
		else
		{
			if (pollution_level_caused > 0) {
				cout << "Upgraded bullet train, Pollution level decreased by 4 levels" << endl;
				pollution_level_caused -= 4;
				if (pollution_level_caused <= 0) {
					pollution_level_caused = 0;
				}
			}
			else {
				cout << "The train has reached maximum level of upgradation." << endl;
			}
			
		}


	}
	void info() {
		cout << " >> Transport name: " << name << endl;
		cout << " >> Train Number : " << num_trains << endl; //trainnum
		cout << " >> Level of pollution caused: " << pollution_level_caused << endl;
	}
	string getType() const {
		return "Train";
	}
};
class Car :public Transport
{
private:
	int num_owners;
	bool isElectric;
public:
	Car(string n, int plc, int owners, bool iselec) :Transport(n, plc)
	{
		num_owners = owners;
		isElectric = iselec;
	}
	void upgrade() override {
		if (!isElectric)
		{
			isElectric = true;
			cout << "Car upgraded to EV.." << endl;
			cout << "Pollution level decresed by 8 levels" << endl;
			pollution_level_caused -= 8;
			if (pollution_level_caused <= 0) {
				pollution_level_caused = 0;
			}
		}
		else
		{
			if (pollution_level_caused <= 0) {
				cout << "Your Car has already reached maximum upgradation level." << endl;
			}
			else {
				cout << "Upgraded Electric Car ,Pollution level decreased by 4 levels" << endl;
				pollution_level_caused -= 4;
				if (pollution_level_caused <= 0) {
					pollution_level_caused = 0;
				}
			}
		};
	}
	void info() {
		cout << " >> Transport name: " << name << endl;
		cout << " >> License Number : " << num_owners << endl;
		cout << " >> Level of pollution caused: " << pollution_level_caused << endl;
	}
	string getType() const {
		return "Car";
	}
};

class Bus : public Transport {
private:
	int lnum;
	bool isElectric;
public:
	Bus(string n, int plc, int lnums, bool iselec) :Transport(n, plc)
	{
		lnum = lnums;
		isElectric = iselec;
	}
	void upgrade() override {
		if (!isElectric)
		{
			isElectric = true;
			cout << "Bus upgraded to EV.." << endl;
			cout << "Pollution level decresed by 8 levels" << endl;
			pollution_level_caused -= 8;
			if (pollution_level_caused <= 0) {
				pollution_level_caused = 0;
			}
		}
		else
		{
			if (pollution_level_caused <= 0) {
				cout << "Your Bus has already reached maximum upgradation level." << endl;
			}
			else {
				cout << "Upgraded Electric Bus ,Pollution level decreased by 4 levels" << endl;
				pollution_level_caused -= 4;
				if (pollution_level_caused <= 0) {
					pollution_level_caused = 0;
				}
			}
			
		};
	}
	void info() {
		cout << " >> Transport name: " << name << endl;
		cout << " >> License number : " << lnum << endl;
		cout << " >> Level of pollution caused: " << pollution_level_caused << endl;
		if (isElectric == 1) {
			cout << " >> Bus is Electric." << endl;
		}
		else {
			cout << "Bus is not Electric." << endl;
		}
	}
	string getType() const {
		return "Bus";
	}
};


class Bike : public Transport {
private:
	int lnum;
	bool isElectric;
public:
	Bike(string n, int plc, int lnums, bool iselec) :Transport(n, plc)
	{
		lnum = lnums;
		isElectric = iselec;
	}
	void upgrade() override {
		if (!isElectric)
		{
			isElectric = true;
			cout << "Bike upgraded to EV.." << endl;
			cout << "Pollution level decresed by 8 levels" << endl;
			pollution_level_caused -= 8;
			if (pollution_level_caused <= 0) {
				pollution_level_caused = 0;
			}
		}
		else
		{
			if (pollution_level_caused <= 0) {
				cout << "Your Bike has already reached maximum upgradation level." << endl;
			}
			else {
				cout << "Upgraded Electric Bike ,Pollution level decreased by 4 levels" << endl;
				pollution_level_caused -= 4;
				if (pollution_level_caused <= 0) {
					pollution_level_caused = 0;
				}
			}

		};
	}
	void info() {
		cout << " >> Transport name: " << name << endl;
		cout << " >> License number : " << lnum << endl;
		cout << " >> Level of pollution caused: " << pollution_level_caused << endl;
		if (isElectric == 1) {
			cout << " >> Bike is Electric." << endl;
		}
		else {
			cout << "Bike is not Electric." << endl;
		}
	}
	string getType() const {
		return "Bike";
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
		energyconsumption -= 2; 
		if (energyconsumption < 0) {
			energyconsumption = 1;
		}
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
	Commercial(string n, int energy, int numshops, int solarpanels) :Building(n, energy)
	{
		num_of_shops = numshops;
		Solarpanels = solarpanels;

	}
	void upgrade()override
	{
		if (Solarpanels < 20)
		{
			energyconsumption -= 3;
			if (energyconsumption < 0) {
				energyconsumption = 1;
			}

		}
		else
			energyconsumption -= 6;
		if (energyconsumption < 0) {
			energyconsumption = 1;
		}
	}
	void info() {
		cout << " >> Building name: " << name << endl;
		cout << " >> Number of Shops: " << num_of_shops << endl;
		cout << " >> Number of Solarpanels: " << Solarpanels << endl;
		cout << " >> Energy Consumption: " << energyconsumption << endl;
	}
	string getType() const {
		return "Commercial";
	}

};
class Industrial :public Building
{
private:
	int pollution_level;
	bool greentech;
public:
	Industrial(string n, int energy, int pl, bool gt) :Building(n, energy)
	{
		pollution_level = pl;
		greentech = gt;

	}
	void upgrade()override
	{
		if (!greentech)
		{
			energyconsumption -= 3;
			if (energyconsumption < 0) {
				energyconsumption = 1;
			}

		}
		else
			energyconsumption -= 6;
		if (energyconsumption < 0) {
			energyconsumption = 1;
		}
	}
	void info() {
		cout << " >> Building name: " << name << endl;
		cout << " >> Pollution Level: " << pollution_level << endl;
		if (greentech)
			cout << " >> The bulding has Green tech " << endl;
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
	vector<Transport*> transports;
	int population;
	int ecoscore;
	float Budget;
public:
	City() {
		ecoscore = 5;
		population = 1000;
		Budget = 10000;
	}
	void Addbuilding() {
		setColor(11);
		cout << "Which type of building do you wish to add?" << endl;
		cout << "1. Residential Building 2. Commercial Building 3. Industrial Building 4. Green Space" << endl;
		setColor(7);
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			setColor(11);
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
			setColor(10);
			cout << "Residential Building Added!" << endl;
			setColor(7);
			break;
		}
		case 2: {
			setColor(11);
			cout << ">> Enter the name of this Commercial Building: ";
			cin.ignore();
			string name;
			getline(cin, name);
			int sh;
			cout << ">> Enter the number of shops: ";
			cin >> sh;
			int sp;
			cout << ">> Enter the number of solar panels: ";
			cin >> sp;
			int e;
			cout << ">> Enter the energy Consumption: ";
			cin >> e;
			cin.ignore();
			Building* b = new Commercial(name, e, sh, sp);
			buildings.push_back(b);
			setColor(10);
			cout << "Commercial Building Added!" << endl;
			setColor(7);
			break;
		}
		case 3: {
			setColor(11);
			cout << ">> Enter the name of this Industrial Building: ";
			cin.ignore();
			string name;
			getline(cin, name);
			int pl;
			cout << ">> Enter the pollution level(0-10): ";
			cin >> pl;
			int gtInput;
			cout << ">> Does the building have greentech (0/1): ";
			do {
				cin >> gtInput;
				if (gtInput != 0 && gtInput != 1) {
					setColor(12); cout << ">> Error: Only enter 0 or 1!!\n"; setColor(7);
				}
			} while (gtInput != 0 && gtInput != 1);
			bool gt = gtInput;
			int e;
			cout << ">> Enter the energy Consumption: ";
			cin >> e;
			cin.ignore();
			Building* b = new Industrial(name, e, pl, gt);
			buildings.push_back(b);
			setColor(10);
			cout << "Industrial Building Added!" << endl;
			setColor(7);
			break;
		}
		default: {
			setColor(12);
			cout << ">> Error: Not a valid choice" << endl;
			setColor(7);
		}

		}
	}

	void AddTransport() {
		cout << "Which type of Transport do you wish to add?" << endl;
		cout << "1. Train 2. Car 3. Bus 4. Bike" << endl;
		int choice;
		cin >> choice;
		cin.ignore();
		string name;
		cout << ">> Enter the name of the transport: ";
		getline(cin, name);
		int plc;
		cout << ">> Enter pollution level caused: ";
		cin >> plc;

		switch (choice) {
		case 1: {
			int num;
			int ibullet;
			cout << ">> Enter Train Number: ";
			cin >> num;
			cout << ">> Is it a bullet train (0/1): ";
			do {
				cin >> ibullet;
				if (ibullet != 0 && ibullet != 1) {
					setColor(12); cout << ">> Error: Only enter 0 or 1!!\n"; setColor(7);
				}
			} while (ibullet != 0 && ibullet != 1);
			bool bullet = ibullet;
			transports.push_back(new Train(name, plc, num, bullet));
			setColor(10);
			cout << "Train Added!" << endl;
			setColor(7);
			break;
		}
		case 2: {
			int owners;
			int ielec;
			cout << ">> Enter License Number: ";
			cin >> owners;
			cout << ">> Is the car electric (0/1): ";

			do {
				cin >> ielec;
				if (ielec != 0 && ielec != 1) {
					setColor(12); cout << ">> Error: Only enter 0 or 1!!\n"; setColor(7);
				}
			} while (ielec != 0 && ielec != 1);
			bool elec = ielec;
			transports.push_back(new Car(name, plc, owners, elec));
			setColor(10);
			cout << "Car Added!" << endl;
			setColor(7);
			break;
		}
		case 3: {
			int lic;
			int ielec;
			cout << ">> Enter license number: ";
			cin >> lic;
			cout << ">> Is the bus electric (0/1): ";
			do {
				cin >> ielec;
				if (ielec != 0 && ielec != 1) {
					setColor(12); cout << ">> Error: Only enter 0 or 1!!\n"; setColor(7);
				}
			} while (ielec != 0 && ielec != 1);
			bool elec = ielec;
			transports.push_back(new Bus(name, plc, lic, elec));
			setColor(10);
			cout << "Bus Added!" << endl;
			setColor(7);
			break;
		}
		case 4: {
			int lic;
			int ielec;
			cout << ">> Enter license number: ";
			cin >> lic;
			cout << ">> Is your bike Electic? (0/1): ";
			do {
				cin >> ielec;
				if (ielec != 0 && ielec != 1) {
					setColor(12); cout << ">> Error: Only enter 0 or 1!!\n"; setColor(7);
				}
			} while (ielec != 0 && ielec != 1);
			bool elec = ielec;
			transports.push_back(new Bike(name, plc, lic, elec));
			setColor(10);
			cout << "Bike Added!" << endl;
			setColor(7);
			break;
		}
		default:
			setColor(12);
			cout << ">> Error: Not a valid choice" << endl;
			setColor(7);
		}
	}

	void displaystatus() {
		setColor(11);
		cout << ">> City Information:" << endl;
		cout << ">> Current Population: " << population << endl;
		cout << ">> Current EcoScore: " << ecoscore << endl;
		cout << ">> Current Budget: " << Budget << endl;
		cout << ">> Current Buildings: ";
		setColor(7);
		if (buildings.empty()) {
			setColor(6);
			cout << " No Buildings added yet." << endl;
			setColor(7);
		}
		else {
			setColor(4);
			cout << "Press a key to move" << endl;
			for (Building* b : buildings) {
				cout << endl;
				cout << b->getType() << "Type :";
				b->info();
				_getch();
			}
			setColor(7);
		}
		cout << ">> Current Transports: ";
		setColor(7);
		if (transports.empty()) {
			setColor(6);
			cout << " No Transports added yet." << endl;
			setColor(7);
		}
		else {
			cout << "Press a key to move" << endl;
			setColor(4);
			for (Transport* p : transports) {
				cout << endl;
				cout << p->getType() << "Type :";
				p->info();
				_getch();
			}
		}

	}
	void UpgradeTransport() {
		if (transports.empty()) {
			cout << "Error: No transports added yet!" << endl;
		}
		else {
			int i;
			for (i = 0; i < transports.size(); ++i) {
				cout << i + 1 << ". " << transports[i]->getName() << endl;
			}

			cout << "Choose which Transport you wish to upgrade: ";

			int choice;
			cin >> choice;

			while (choice < 1 || choice > i) {
				cout << "Invalid choice! Enter a valid number: ";
				cin >> choice;
			}

		
			transports[choice - 1]->upgrade(); 
		}
		
		

	}
	void UpgradeBuildings() {
		if (buildings.empty()) {
			cout << "Error: No buildings added yet!" << endl;
		}
		else {
			int i;
			for (i = 0; i < buildings.size(); ++i) {
				cout << i + 1 << ". " << buildings[i]->getName() << endl;
			}

			cout << "Choose which Building you wish to upgrade: ";

			int choice;
			cin >> choice;

			while (choice < 1 || choice > i) {
				cout << "Invalid choice! Enter a valid number: ";
				cin >> choice;
			}


			buildings[choice - 1]->upgrade();
		}



	}
	~City() {
		for (auto b : buildings) delete b;
		for (auto t : transports) delete t;
	}


};


void printHeading() {
	system("cls");
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
	setColor(14);
	cout << "Intital Status of Your City!" << endl;
	setColor(7);
	MyCity.displaystatus();
	cout << endl;
	cout << "==============================================================" << endl;
	do {
		setColor(10);
		cout << "\n >> What would you like to do?\n";
		setColor(14);
		cout << "   >> 1. Build a Building\n";
		cout << "   >> 2. View City Status\n";
		cout << "   >> 3. Add Transport\n";
		cout << "   >> 4. Upgrade Transport\n";
		cout << "   >> 5. Upgrade Building\n";
		cout << "   >> 6. Exit Simulation\n";
		setColor(7);
		cout << "Enter your choice: ";
		try {
			if (!(cin >> choice)) {
				cin.clear();
				cin.ignore(1000, '\n');
				throw invalid_argument(" Invalid input. Please enter an integer (1/2/3).");
			}

		}
		catch (const invalid_argument& e)
		{
			setColor(12);
			cout << "Caught exception:" << e.what() << endl;
		}
		switch (choice) {
		case 1:
			MyCity.Addbuilding();
			break;
		case 2:
			MyCity.displaystatus();
			break;
		case 3:
			MyCity.AddTransport();
			break;
		case 4:
			MyCity.UpgradeTransport();
			break;
		case 5:
			MyCity.UpgradeBuildings();
			break;
		case 6:
			setColor(12);
			cout << "\nExiting simulation...\n";
			setColor(7);
			break;
		default:
			setColor(12);
			cout << "Error: Invalid Choice\n";
			setColor(7);
		}

	} while (choice != 6);
}

int main() {
	City MyCity;
	menu(MyCity);

	return 0;
}
