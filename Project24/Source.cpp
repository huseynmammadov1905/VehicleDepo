





#include <iostream>

#include <stack>

using namespace std;

class Engine {
public:
	string  engineNo;
	string company;
	double volume;

	Engine() {}

	Engine(string engineNo, string company, double volume) {
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}


	void Show() {
		cout << "Company  : " << company << endl;
		cout << "EngineNo : " << engineNo << endl;
		cout << "Volume   : " << volume << endl;
	}
};

class Vehicle {
public:
	static int staticId;
	int id;
	string vendor;
	string model;
	Engine engine;

	Vehicle(string vendor, string model, Engine engine) {
		this->id = staticId++;
		this->vendor = vendor;
		this->model = model;
		this->engine = engine;
	}

	virtual void Show() {
		cout << "Id     : " << id << endl;
		cout << "Vendor : " << vendor << endl;
		cout << "Model  : " << model << endl;
		engine.Show();
	}


};

int Vehicle::staticId = 1;



class Car : public Vehicle {

public:
	bool hasSail;

	Car(string vendor, string model, Engine engine, bool hasSpoiler) : Vehicle(vendor, model, engine) {
		this->hasSail = hasSpoiler;
	}

	void Show() {
		cout << "********* Car *********" << endl;
		Vehicle::Show();
		cout << "Spoiler : " << (hasSail ? "var" : "yox") << endl;
	}
};

class Ship : public Vehicle {

public:
	bool hasSail;

	Ship(string vendor, string model, Engine engine, bool hasSail) : Vehicle(vendor, model, engine) {
		this->hasSail = hasSail;
	}

	void Show() {
		cout << "********* Ship *********" << endl;
		Vehicle::Show();
		cout << "Sail : " << (hasSail ? "var" : "yox") << endl;
	}
};


class Airplane : public Vehicle {

public:
	int engineCount;
	int passengerCapacity;

	Airplane(string vendor, string model, Engine engine, int engineCount, int passengerCapacity) : Vehicle(vendor, model, engine) {
		this->engineCount = engineCount;
		this->passengerCapacity = passengerCapacity;
	}

	void Show() {
		cout << "********* Airplane *********" << endl;
		Vehicle::Show();
		cout << "Engine Count : " << engineCount << endl;
		cout << "Passenger Capacity : " << passengerCapacity << endl;
	}
};


class VehicleDepo {
public:
	stack<Vehicle*> vehicles;

	void AddVehicle(Vehicle* vehicle) {
		vehicles.push(vehicle);
	}

	void ShowVehicles() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}
};

int main() {

	VehicleDepo* vd = new VehicleDepo();
	vd->AddVehicle(new Car("bmw", "x6", Engine("bmw123", "bmw", 3.1), true));
	vd->AddVehicle(new Ship("Cruise", "42394", Engine("Cruise", "234cr", 3.3), true));
	vd->AddVehicle(new Airplane("Boing", "737", Engine("Boing", "141", 100), 4, 360));
	vd->ShowVehicles();
}