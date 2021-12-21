#pragma once
//Bridge
#include <iostream>

using namespace std;

class IPlanet {
public:
	virtual void fly() = 0;
};

class MarsPlanet : public IPlanet {
public:
	void fly() override {
		cout << "The planet Mars. ";
	}
};

class SaturnPlanet : public IPlanet {
public:
	void fly() override {
		cout << "The planet Saturn. ";
	}
};

class ILesson {
protected:
	IPlanet* planet;
public:
	ILesson(IPlanet* ip) : planet(ip) {}
	void setIPlanet(IPlanet* ip) {
		planet = ip;
	}
	virtual void change() = 0;
};

class MathLesson : public ILesson {
public:
	MathLesson(IPlanet* ip) : ILesson(ip) {}
	void change() override {
		planet->fly();
		cout << "Math lesson" << endl;
	}
};

class AstronomyLesson : public ILesson {
public:
	AstronomyLesson(IPlanet* ip) : ILesson(ip) {}
	void change() override {
		planet->fly();
		cout << "Astronomy Lesson" << endl;
	}
};

class SafetyLesson : public ILesson {
public:
	SafetyLesson(IPlanet* ip) : ILesson(ip) {}
	void change() override {
		planet->fly();
		cout << "Safety Lesson" << endl;
	}
};

