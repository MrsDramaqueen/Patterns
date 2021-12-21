#pragma once
//Facade
#include <iostream>

using namespace std;

class VirtualShopCommunication {
public:
	void buy() {
		cout << "Покупка предмета" << endl;
	}
	void sale() {
		cout << "Продажа предмета" << endl;
	}
	void fail() {
		cout << "К сожалению, вам не хватает монет для приобретения данного предмета. Позанимайтесь еще, чтобы накопить больше монет!!!" << endl;
	}
};

class Backpack {
public:
	void insert() {
		cout << "Добавление предмета в рюкзак" << endl;
	}
	void del() {
		cout << "Удаление предмета из рюкзака" << endl;
	}
	void fail() {
		cout << "Ваш рюкзак переполнен. Возможно, что-то нужно выложить." << endl;
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



