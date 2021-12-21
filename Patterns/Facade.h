#pragma once
//Facade
#include <iostream>

using namespace std;

class VirtualShopCommunication {
public:
	void buy() {
		cout << "Buying an item" << endl;
	}
	void sale() {
		cout << "Selling an item" << endl;
	}
	void fail() {
		cout << "Unfortunately, you do not have enough coins to purchase this item. Do some more to accumulate more coins !!!" << endl;
	}
};

class Backpack {
public:
	void insert() {
		cout << "Adding an item to your backpack" << endl;
	}
	void del() {
		cout << "Removing an item from your backpack" << endl;
	}
	void fail() {
		cout << "Your backpack is full. Perhaps something needs to be laid out." << endl;
	}
};

class SchoolShop {
private:
	VirtualShopCommunication virtualShopComm;
	Backpack backpack;
public:
	void thingreceive() {
		virtualShopComm.buy();
		backpack.insert();
	}
	void thingdeletion() {
		virtualShopComm.sale();
		backpack.del();
	}
	void mistake() {
		virtualShopComm.fail();
		backpack.fail();
	}


};



