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
		cout << " оличество правильных ответов на вопросы в ходе данного урока составл€ет: " << endl;
		return currentNumber;
	}

	void adjust() override {
		cout << " онвертаци€ правильных ответов в игровую валюту" << endl;
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
		cout << "«а каждый правильный ответ начилс€етс€ 10 монет" << endl;
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
		cout << " оличество монет, заработанных в ходе задани€: " << endl;
		return convert;
	}

	void adjust() override {
		Coins::adjust();
	}
};

