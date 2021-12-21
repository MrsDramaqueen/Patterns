#pragma once
//Abstract factory
#include <iostream>

using namespace std;

class ISpaceship {
public:
	virtual void createSpaceship() = 0;
};

class LowLevelSpaceship : public ISpaceship {
public:
	void createSpaceship() override {
		cout << "����������� ������� �������� �������" << endl;
	}
};

class MiddleLevelSpaceship : public ISpaceship {
public:
	void createSpaceship() override {
		cout << "����������� ������� �������� �������" << endl;
	}
};

class HighLevelSpaceship : public ISpaceship {
public:
	void createSpaceship() override {
		cout << "����������� ������� �������� ������" << endl;
	}
};

class IStyle {
public:
	virtual void reachStyle(ISpaceship* spaceship) = 0;
};

class LowStyle : public IStyle {
public:
	void reachStyle(ISpaceship* spaceship) override {
		cout << "������� �����: ";
		spaceship->createSpaceship();
	}
};

class MiddleStyle : public IStyle {
public:
	void reachStyle(ISpaceship* spaceship) override {
		cout << "����� ����������:  ";
		spaceship->createSpaceship();
	}
};

class HighStyle : public IStyle {
public:
	void reachStyle(ISpaceship* spaceship) override {
		cout << "����� ����������������� � ����� ��������: ";
		spaceship->createSpaceship();
	}
};

class IFactory {
public:
	virtual ISpaceship* startSpaceship() = 0;
	virtual IStyle* startStyle() = 0;
};

class LowLevelFactory : public IFactory {
public:
	ISpaceship* startSpaceship() override {
		return new LowLevelSpaceship();
	}
	IStyle* startStyle() override {
		return new LowStyle();
	}
};

class MiddleLevelFactory : public IFactory {
public:
	ISpaceship* startSpaceship() override {
		return new MiddleLevelSpaceship();
	}
	IStyle* startStyle() override {
		return new MiddleStyle();
	}
};

class HighLevelFactory : public IFactory {
public:
	ISpaceship* startSpaceship() override {
		return new HighLevelSpaceship();
	}
	IStyle* startStyle() override {
		return new HighStyle();
	}
};

