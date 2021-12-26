#pragma once
//Memento
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Memento {
public:
	virtual int getCoins() = 0;
	virtual int getHelpMessages() = 0;
	virtual ~Memento() {}
};

class ExchangeMemento : public Memento {
private:
	int coins;
	int helpMessages;
public:
	ExchangeMemento(int c, int hm) : coins(c), helpMessages(hm) {}
	int getCoins() override {
		return coins;
	}
	int getHelpMessages() override {
		return helpMessages;
	}
};

class Purchase {
private:
	int coins;
	int helpMessages;
public:
	Purchase(int c, int hm) : coins(c), helpMessages(hm) {}
	void getCoins() {
		cout << "Количество монет: " << coins << endl;
	}
	void getHelpMessages() {
		cout << "Количество подсказок: " << helpMessages << endl;
	}
	void spend() {
		coins -= 15;
	}
	void buy() {
		++helpMessages;
	}

	ExchangeMemento* save() {
		return new ExchangeMemento(coins, helpMessages);
	}

	void restore(Memento* exchangeMemento) {
		coins = exchangeMemento->getCoins();
		helpMessages = exchangeMemento->getHelpMessages();

		delete exchangeMemento;
	}
};

class Memory {
private:
	stack<Memento*> history;
	Purchase* purchase;
public:
	Memory(Purchase* pur) : purchase(pur) {}
	void backup() {
		history.push(purchase->save());
	}
	void undo() {
		if (history.empty()) return;

		purchase->restore(history.top());
		history.pop();
	}
};