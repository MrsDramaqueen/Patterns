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
		cout << "During the assignment, you answered enough questions correctly to receive a bonus!" << endl;
	}
	else {
		cout << "You didn't have enough before getting the bonus. Don't worry, it will work next time !!" << endl;
	}
	return !it1() && !it2();
}

