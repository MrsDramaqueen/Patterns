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
		information = "On this planet, the average temperature is +500 ° C !!!";
	}

	void visit(Venus& fly) override {
		information = "There is a lot of carbon dioxide on this planet !!!";
	}

	void visit(Earth& fly) override {
		information = "There is life on this planet !!!";
	}

	void visit(Mars& fly) override {
		information = "This planet is bright red !!!";
	}

};