#pragma once
#include <iostream>

using namespace std;

class Exchange {
public:
	virtual float* getCurrency() = 0;
	virtual void adjust() = 0;
	virtual ~Exchange() {};

};

class RightAnswers : public Exchange {
private:
	float* currentNumber;
public:
	RightAnswers(float* cn) : currentNumber(cn) {}
	~RightAnswers() override {
		delete currentNumber;
	}

	float* getCurrency() override {
		cout << "���������� ���������� ������� �� ������� � ���� ������� ����� ����������: " << endl;
		return currentNumber;
	}

	void adjust() override {
		cout << "����������� ���������� ������� � ������� ������" << endl;
	}
};

class Coins {
private:
	float* currentNumber;
public:
	Coins(float* cn) : currentNumber(cn) {}
	~Coins() {
		delete currentNumber;
	}
	float* getCurrency() {
		return currentNumber;
	}
protected:
	void adjust() {
		cout << "�� ������ ���������� ����� ����������� 10 �����" << endl;
	}
};

class AdapterForCoins : public Exchange, private Coins {
private:
	float* convert;
public:
	AdapterForCoins(float* cn) : Coins(cn) {}
	~AdapterForCoins() {
		delete convert;
	}

	float* getCurrency() override {
		convert = Coins::getCurrency();
		*convert = *convert * 10;
		cout << "���������� �����, ������������ � ���� �������: " << endl;
		return convert;
	}

	void adjust() override {
		Coins::adjust();
	}
};

