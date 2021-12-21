#pragma once
//Facade
#include <iostream>

using namespace std;

class VirtualShopCommunication {
public:
	void buy() {
		cout << "������� ��������" << endl;
	}
	void sale() {
		cout << "������� ��������" << endl;
	}
	void fail() {
		cout << "� ���������, ��� �� ������� ����� ��� ������������ ������� ��������. ������������� ���, ����� �������� ������ �����!!!" << endl;
	}
};

class Backpack {
public:
	void insert() {
		cout << "���������� �������� � ������" << endl;
	}
	void del() {
		cout << "�������� �������� �� �������" << endl;
	}
	void fail() {
		cout << "��� ������ ����������. ��������, ���-�� ����� ��������." << endl;
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



