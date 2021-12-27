#pragma once
//Builder
#include <iostream>
#include <string>

using namespace std;

class Spaceship {
	string data;
public:
	Spaceship() {
		data = "";
	}
	string aboutSpaceship() {
		cout << "List of changes: " << endl;
		return data;
	}
	void appendData(string info) {
		data += info;
	}
};

class IEngnierOfSpace {
public:
	virtual void updateEngine() = 0;
	virtual void updateWings() = 0;
	virtual void changeColor() = 0;

	virtual Spaceship* getChanges() = 0;
};

class LowLevelSpaceshipEngenier : public IEngnierOfSpace {

	Spaceship* spaceship;
public:
	LowLevelSpaceshipEngenier() {
		spaceship = new Spaceship;
	}
	~LowLevelSpaceshipEngenier() {
		delete spaceship;
	}

	void updateEngine() override {
		spaceship->appendData("Your junior spaceship's engine has been successfully upgraded !!! ");
	}

	void updateWings() override {
		spaceship->appendData("Your junior spaceship wings have been successfully upgraded !!! ");
	}

	void changeColor() override {
		spaceship->appendData("Your junior spaceship color changed successfully !!! ");
	}

	Spaceship* getChanges() override {
		return spaceship;
	}

};

class MiddleLevelSpaceshipEngenier : public IEngnierOfSpace {

	Spaceship* spaceship;
public:
	MiddleLevelSpaceshipEngenier() {
		spaceship = new Spaceship;
	}
	~MiddleLevelSpaceshipEngenier() {
		delete spaceship;
	}

	void updateEngine() override {
		spaceship->appendData("Your mid-level spaceship's engine has been successfully upgraded !!! ");
	}

	void updateWings() override {
		spaceship->appendData("The wings of your intermediate spaceship have been successfully upgraded !!! ");
	}

	void changeColor() override {
		spaceship->appendData("Your mid-level spaceship color changed successfully !!! ");
	}

	Spaceship* getChanges() override {
		return spaceship;
	}

};

class HighLevelSpaceshipEngenier : public IEngnierOfSpace {

	Spaceship* spaceship;
public:
	HighLevelSpaceshipEngenier() {
		spaceship = new Spaceship;
	}
	~HighLevelSpaceshipEngenier() {
		delete spaceship;
	}

	void updateEngine() override {
		spaceship->appendData("Your high level spaceship's engine has been successfully upgraded !!!!\n");
	}

	void updateWings() override {
		spaceship->appendData("Your high level spaceship wings have been successfully upgraded !!!\n");
	}

	void changeColor() override {
		spaceship->appendData("Your High Level Spaceship Color Changed Successfully !!\n");
	}

	Spaceship* getChanges() override {
		return spaceship;
	}

};

class Creator {
	IEngnierOfSpace* engnier;
public:
	Creator(IEngnierOfSpace* engn) : engnier(engn) {}

	void setEngnier(IEngnierOfSpace* engn) {
		engnier = engn;
	}

	Spaceship* ChangeFullSpaceship() {
		engnier->updateEngine();
		engnier->updateWings();
		engnier->changeColor();
		return engnier->getChanges();
	}

	Spaceship* ChangeOnlyColor() {
		engnier->changeColor();
		return engnier->getChanges();
	}

	Spaceship* ChangeOnlyEngine() {
		engnier->updateEngine();
		return engnier->getChanges();
	}

	Spaceship* ChangeOnlyWings() {
		engnier->updateWings();
		return engnier->getChanges();
	}

};
