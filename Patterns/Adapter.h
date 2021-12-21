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
		cout << "The number of correct answers to questions during this lesson is: " << endl;
		return currentNumber;
	}

	void adjust() override {
		cout << "Converting correct answers to game currency" << endl;
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
		cout << "For each correct answer, 10 coins are awarded" << endl;
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
		cout << "The number of coins earned during the task: " << endl;
		return convert;
	}

	void adjust() override {
		Coins::adjust();
	}
};

