#pragma once
#include <iostream>

using namespace std;

class AnswerStack {
private:
	int answers[10];
	int length;

public:
	friend class StackIterator;
	AnswerStack() {
		length = -1;
	}
	void push(int value) {
		answers[++length] = value;
	}
};

class StackIterator {
private:
	const AnswerStack& stack;
	int index;
public:
	StackIterator(const AnswerStack& st) : stack(st) {
		index = 0;
	}
	void operator++() {
		index++;
	}
	int operator*() {
		return stack.answers[index];
	}
	bool operator()() {
		return index != stack.length + 1;
	}
};

bool operator==(const AnswerStack& s1, const AnswerStack& s2) {
	StackIterator it1(s1), it2(s2);

	for (; it1(); ++it1, ++it2) {
		if (*it1 < *it2) {
			break;
		}
	}
	if ((!it1()) && (!it2())) {
		cout << "В ходе задания вы правильно ответили на достаточное количество вопросов, чтобы получить бонус!" << endl;
	}
	else {
		cout << "Вам немного не хватило до получения бонуса. Не переживайте, получится в следующий раз!!" << endl;
	}
	return !it1() && !it2();
}

