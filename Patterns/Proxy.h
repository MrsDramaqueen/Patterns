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
		description = "�������� ����� ������� ������� � ����� ��������� �������: ";
		rightAnswer = "������";
		helpMessage = "��� ����� ������� �� ����� �� ������";
	}

	string giveHelp(string num) override {
		cout << description << endl;
		string currentAnswer = "��� ����� �� ������: " + num;
		if (num == rightAnswer) {
			currentAnswer += "\n����� �����!!\n";
		}
		else {
			currentAnswer += "\n����� �������. ���������: " + helpMessage + "\n";
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
			currentAnswer.insert(0, "�� ��� �������� �� ���� ������. ���������� � ����������!!");
		}
		return currentAnswer;
	}

};
