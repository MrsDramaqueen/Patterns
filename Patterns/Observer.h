#pragma once
//Observer
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IObserver {
public:
	virtual void update(double p) = 0;
};

class IObservable {
public:
	virtual void addObserver(IObserver* o) = 0;
	virtual void removeObserver(IObserver* o) = 0;

	virtual void notify() = 0;
	virtual ~IObservable() {}
};

class Weather : public IObservable {
private:
	vector<IObserver*> observers;
	double precipitation;
public:
	Weather(double p) : precipitation(p) {}
	void changePrecipitation(double p) {
		precipitation = p;
		notify();
	}
	void addObserver(IObserver* o) override {
		observers.push_back(o);
	}
	void removeObserver(IObserver* o) override {
		observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
	}

	void notify() override {
		for (auto o : observers) {
			o->update(precipitation);
		}
	}

};

class JuniorClass : public IObserver {
private:
	IObservable* weather;
public:
	JuniorClass(IObservable* obj) : weather(obj) {
		obj->addObserver(this);
	}

	void update(double p) override {
		if (p > 250) {
			cout << "Junior classes cannot explore this area with such a rainfall: " << p << endl;
			weather->removeObserver(this);
		}
	}

};

class MiddleClass : public IObserver {
private:
	IObservable* weather;
public:
	MiddleClass(IObservable* obj) : weather(obj) {
		obj->addObserver(this);
	}

	void update(double p) override {
		if (p > 500) {
			cout << "The middle classes cannot explore this area with this amount of precipitation: " << p << endl;
			weather->removeObserver(this);
		}
	}

};
