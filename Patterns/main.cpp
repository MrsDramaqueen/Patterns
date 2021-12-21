#include <iostream>
#include <string>
#include <map>
#include "Proxy.h"
#include "Bridge_Or_Delegate.h"
#include "Adapter.h"
#include "Iterator.h"
#include "Facade.h"
#include "Abstract_factory.h"
#include "Singleton.h"



int main() {

	setlocale(LC_ALL, "rus");
	//���������� Proxy
	cout << "Realization pattern Proxy" << endl;
	ITask* myTask = new ProxyTask(new Task());


	cout << myTask->giveHelp("Jupiter") << endl;
	cout << myTask->giveHelp("Mars") << endl;
	cout << myTask->giveHelp("4") << endl;

	//Bridge (�������������)
	cout << "Realization pattern Bridge (�������������)" << endl;
	ILesson* lesson = new AstronomyLesson(new MarsPlanet());
	lesson->change();

	lesson->setIPlanet(new SaturnPlanet());
	lesson->change();

	lesson = new MathLesson(new SaturnPlanet());
	lesson->change();

	lesson->setIPlanet(new MarsPlanet());
	lesson->change();

	lesson = new SafetyLesson(new SaturnPlanet());
	lesson->change();

	lesson->setIPlanet(new MarsPlanet());
	lesson->change();


	//���������� Adapter
	cout << "\nRealization pattern Adapter" << endl;
	float answers = 23;

	Exchange* rAnswers = new RightAnswers(&answers);
	Exchange* vMoney = new AdapterForCoins(&answers);

	cout << *rAnswers->getCurrency() << endl;
	cout << *vMoney->getCurrency() << endl;

	rAnswers->adjust();
	vMoney->adjust();

	//���������� Iterator
	cout << "\nRealization pattern Iterator" << endl;
	AnswerStack stack1;
	for (int i = 1; i < 5; i++) {
		stack1.push(i);
	}

	AnswerStack stack2(stack1);

	cout << boolalpha << (stack1 == stack2) << endl;

	stack1.push(10);

	cout << boolalpha << (stack1 == stack2) << endl;


	//���������� �������� Facade
	cout << "\nRealization pattern Facade" << endl;

	SchoolShop schoolShop;

	schoolShop.thingreceive();

	cout << "-----------------------------" << endl;

	schoolShop.thingdeletion();

	cout << "-----------------------------" << endl;

	schoolShop.mistake();


	//���������� �������� Singleton
	cout << "\nRealization pattern Singleton" << endl;
	ApplicationConnection::getConnection()->insertData("USER_1", "SCHOOL_1", "CLASS_1");

	cout << "Authorized Users: " << ApplicationConnection::getConnection()->selectData() << endl;

	//���������� �������� Abstract Factory
	cout << "\nRealization pattern Abstract Factory" << endl;
	IFactory* lFactory = new LowLevelFactory();

	ISpaceship* lSpaceship = lFactory->startSpaceship();
	IStyle* lStyle = lFactory->startStyle();

	lStyle->reachStyle(lSpaceship);

	IFactory* mFactory = new MiddleLevelFactory();

	ISpaceship* mSpaceship = mFactory->startSpaceship();
	IStyle* mStyle = mFactory->startStyle();

	mStyle->reachStyle(mSpaceship);

	IFactory* hFactory = new HighLevelFactory();

	ISpaceship* hSpaceship = hFactory->startSpaceship();
	IStyle* hStyle = hFactory->startStyle();

	hStyle->reachStyle(hSpaceship);
}