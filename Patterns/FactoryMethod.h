#pragma once
#include <iostream>

using namespace std;

class IProduction {
public:
	virtual void release() = 0;
};

class IBackpack : public IProduction {
public:
	void release() override {
		cout << "A new backpack has been released for you !!!" << endl;
	}
};

class SpaceSuit : public IProduction {
public:
	void release() override {
		cout << "A new spacesuit has been released for you !!!" << endl;
	}
};

class ISpaceShop {
public:
	virtual IProduction* create() = 0;
};

class BackpackSpaceShop : public ISpaceShop {
public:
	IProduction* create() override {
		return new IBackpack();
	}
};

class SpaceSuitSpaceShop : public ISpaceShop {
public:
	IProduction* create() override {
		return new SpaceSuit();
	}
};