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
#include "Builder.h"
#include "VIsitor.h"
#include "Observer.h"
#include "Memento.h"
#include "FactoryMethod.h"



int main() {

	setlocale(LC_ALL, "rus");
	//Реализация Proxy
	cout << "Realization pattern Proxy" << endl;
	ITask* myTask = new ProxyTask(new Task());


	cout << myTask->giveHelp("Jupiter") << endl;
	cout << myTask->giveHelp("Mars") << endl;
	cout << myTask->giveHelp("4") << endl;

	//Bridge (Делегирование)
	cout << "Realization pattern Bridge (Делегирование)" << endl;
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
	cout << "\nRealization pattern Adapter" << endl;
	float answers = 23;

	Exchange* rAnswers = new RightAnswers(&answers);
	Exchange* vMoney = new AdapterForCoins(&answers);

	cout << *rAnswers->getCurrency() << endl;
	cout << *vMoney->getCurrency() << endl;

	rAnswers->adjust();
	vMoney->adjust();

	//Реализация Iterator
	cout << "\nRealization pattern Iterator" << endl;
	AnswerStack stack1;
	for (int i = 1; i < 5; i++) {
		stack1.push(i);
	}

	AnswerStack stack2(stack1);

	cout << boolalpha << (stack1 == stack2) << endl;

	stack1.push(10);

	cout << boolalpha << (stack1 == stack2) << endl;


	//Реализация паттерна Facade
	cout << "\nRealization pattern Facade" << endl;

	SchoolShop schoolShop;

	schoolShop.thingreceive();

	cout << "-----------------------------" << endl;

	schoolShop.thingdeletion();

	cout << "-----------------------------" << endl;

	schoolShop.mistake();


	//Реализация паттерна Singleton
	cout << "\nRealization pattern Singleton" << endl;
	ApplicationConnection::getConnection()->insertData("USER_1", "SCHOOL_1", "CLASS_1");

	cout << "Authorized Users: " << ApplicationConnection::getConnection()->selectData() << endl;

	//Реализация паттерна Abstract Factory
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

	//Реализация паттерна Builder
	cout << "\nРеализация Паттерна Builder" << endl;
	//Изменения корабля младшего уровней
	IEngnierOfSpace* lowEngnier = new LowLevelSpaceshipEngenier();
	Creator creator(lowEngnier);

	Spaceship* lowLevelSpaceship = creator.ChangeOnlyColor();
	cout << lowLevelSpaceship->aboutSpaceship() << endl;

	//Изменения корабля среднего уровней
	IEngnierOfSpace* middleEngnier = new MiddleLevelSpaceshipEngenier();
	creator.setEngnier(middleEngnier);

	Spaceship* middleLevelSpaceship = creator.ChangeOnlyEngine();
	cout << middleLevelSpaceship->aboutSpaceship() << endl;

	//Изменения корабля высокого уровней
	IEngnierOfSpace* highEngnier = new HighLevelSpaceshipEngenier();
	creator.setEngnier(highEngnier);

	Spaceship* highLevelSpaceship = creator.ChangeFullSpaceship();
	cout << highLevelSpaceship->aboutSpaceship() << endl;

	//Реализация паттерна Visitor
	cout << "\nРеализация паттерна Visitor" << endl;
	Mercury mercury;
	Venus venus;
	Earth earth;
	Mars mars;

	Planet* planets[] = { &mercury, &venus, &earth, &mars };

	for (auto planet : planets) {
		SpaceTravel visitor;
		planet->accept(visitor);
		cout << visitor.information << endl;
	}

	//Реализация паттерна Observer
	cout << "\nРеализация паттерна Observer" << endl;
	Weather* weather = new Weather(567);

	JuniorClass* junior = new JuniorClass(weather);
	MiddleClass* middle = new MiddleClass(weather);

	weather->changePrecipitation(354);
	weather->changePrecipitation(534);

	//Реализация паттерна Memento
	cout << "\nРеализация паттерна Memento" << endl;
	Purchase* purchase = new Purchase(100, 4);

	Memory* memory = new Memory(purchase);
	cout << "---------Начальное состояние---------" << endl;
	purchase->getCoins();
	purchase->getHelpMessages();

	cout << "---------Трата монет, покупка подсказок---------" << endl;
	purchase->spend();
	purchase->buy();

	purchase->getCoins();
	purchase->getHelpMessages();

	cout << "---------Сохранение состояния---------" << endl;
	memory->backup();

	cout << "---------Трата монет, покупка подсказок---------" << endl;
	purchase->spend();
	purchase->buy();

	purchase->getCoins();
	purchase->getHelpMessages();

	cout << "---------Восстановление состояния---------" << endl;
	memory->undo();

	purchase->getCoins();
	purchase->getHelpMessages();


	//Реализация паттерна Factory Method
	cout << "\nРеализация паттерна Factory Method" << endl;

	ISpaceShop* produce = new BackpackSpaceShop();

	IProduction* backpack = produce->create();

	produce = new SpaceSuitSpaceShop();

	IProduction* spacesuit = produce->create();

	backpack->release();
	spacesuit->release();
}