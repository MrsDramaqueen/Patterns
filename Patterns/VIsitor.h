#pragma once
//Visitor
#include <iostream>
#include <string>

using namespace std;

class Mercury;
class Venus;
class Earth;
class Mars;

class IVisitor {
public:
	virtual void visit(Mercury& fly) = 0;
	virtual void visit(Venus& fly) = 0;
	virtual void visit(Earth& fly) = 0;
	virtual void visit(Mars& fly) = 0;

	virtual ~IVisitor() = default;
};

class Planet {
public:
	virtual void accept(IVisitor& v) = 0;

	virtual ~Planet() = default;
};

class Mercury : public Planet {
public:
	void accept(IVisitor& v) override {
		v.visit(*this);
	}
};

class Venus : public Planet {
public:
	void accept(IVisitor& v) override {
		v.visit(*this);
	}
};

class Earth : public Planet {
public:
	void accept(IVisitor& v) override {
		v.visit(*this);
	}
};

class Mars : public Planet {
public:
	void accept(IVisitor& v) override {
		v.visit(*this);
	}
};

class SpaceTravel : public IVisitor {
public:
	string information;
	
	void visit(Mercury& fly) override {
		information = "На этой планете средняя температура - +500 °C!!!";
	}

	void visit(Venus& fly) override {
		information = "На этой планете очень много углекислого газа!!!";
	}

	void visit(Earth& fly) override {
		information = "На это планете есть жизнь!!!";
	}

	void visit(Mars& fly) override {
		information = "Эта планета имеет ярко-красный цвет!!!";
	}

};