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
	//Реализация Proxy
	cout << "Реализация паттерна Proxy" << endl;
	ITask* myTask = new ProxyTask(new Task());


	cout << myTask->giveHelp("Юпитер") << endl;
	cout << myTask->giveHelp("Марс") << endl;
	cout << myTask->giveHelp("4") << endl;

	//Bridge (Делегирование)
	cout << "Реализация паттерна Bridge (Делегирование)" << endl;
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


	//Реализация Adapter
	cout << "\nРеализация паттерна Adapter" << endl;
	float answers = 23;

	Exchange* rAnswers = new RightAnswers(&answers);
	Exchange* vMoney = new AdapterForCoins(&answers);

	cout << *rAnswers->getCurrency() << endl;
	cout << *vMoney->getCurrency() << endl;

	rAnswers->adjust();
	vMoney->adjust();

	//Реализация Iterator
	cout << "\nРеализация паттерна Iterator" << endl;
	AnswerStack stack1;
	for (int i = 1; i < 5; i++) {
		stack1.push(i);
	}

	AnswerStack stack2(stack1);

	cout << boolalpha << (stack1 == stack2) << endl;

	stack1.push(10);

	cout << boolalpha << (stack1 == stack2) << endl;


	//Реализация паттерна Facade
	cout << "\nРеализация Facade" << endl;

	SchoolShop schoolShop;

	schoolShop.thingreceive();

	cout << "-----------------------------" << endl;

	schoolShop.thingdeletion();

	cout << "-----------------------------" << endl;

	schoolShop.mistake();


	//Реализация паттерна Singleton
	cout << "\nРеализация Singleton" << endl;
	ApplicationConnection::getConnection()->insertData("USER_1", "SCHOOL_1", "CLASS_1");

	cout << "Авторизованные пользователи: " << ApplicationConnection::getConnection()->selectData() << endl;

	//Реализация паттерна Abstract Factory
	cout << "\nРеализация Abstract Factory" << endl;
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