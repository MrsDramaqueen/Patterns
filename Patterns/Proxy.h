#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ITask {
public:
	virtual string giveHelp(string num) = 0;
	virtual ~ITask() {}

};

class Task : public ITask {
private:
	string description, helpMessage;
	string rightAnswer;

public:
	Task() {
		description = "Назовите самую крупную планету в нашей Солнечной системе: ";
		rightAnswer = "Юпитер";
		helpMessage = "Эта пятая планета по счету от Солнца";
	}

	string giveHelp(string num) override {
		cout << description << endl;
		string currentAnswer = "Ваш ответ на вопрос: " + num;
		if (num == rightAnswer) {
			currentAnswer += "\nОтвет верен!!\n";
		}
		else {
			currentAnswer += "\nОтвет неверен. Подсказка: " + helpMessage + "\n";
		}
		return currentAnswer;
	}

};

class ProxyTask : public ITask {
private:
	ITask* currentTask;
	map<string, string> cache;
public:
	ProxyTask(ITask* currentTask) : currentTask(currentTask) {}
	~ProxyTask() { delete currentTask; }

	string giveHelp(string num) override {
		string currentAnswer;
		if (cache.find(num) == cache.end()) {
			currentAnswer = currentTask->giveHelp(num);
			cache[num] = currentAnswer;
		}
		else {
			currentAnswer = cache[num];
			currentAnswer.insert(0, "Вы уже отвечали на этот вопрос. Переходите к следующему!!");
		}
		return currentAnswer;
	}

};
