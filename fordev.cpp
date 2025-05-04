#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#include <iomanip>
using namespace std;
dfrertytjtyj

class CityObj {
protected:
	string name;
public:
	CityObj(string n) {
		name = n;
	}
	virtual void info() = 0;
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
			//
			break;
		}
		case 3: {
			//
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
		cin >> choice;

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

