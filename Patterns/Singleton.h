#pragma once
//Singleton
#include <iostream>
#include <string>

using namespace std;

class ApplicationConnection {
	ApplicationConnection() {
		cout << "Авторизация" << endl;
	}
	static ApplicationConnection* applicationConnection;

	string name, school, clas;

public:
	ApplicationConnection(const ApplicationConnection&) = delete;
	void operator = (const ApplicationConnection&) = delete;

	static ApplicationConnection* getConnection() {
		if (applicationConnection == nullptr) {
			applicationConnection = new ApplicationConnection();
		}
		return applicationConnection;
	}

	string selectData() const {
		return name + " " + clas;
	}

	void insertData(string n, string s, string c) {
		cout << "Имя Пользователя: " << n << endl << "Школа: " << s << endl << "Класс: " << c << endl;;
		name = n;
		school = s;
		clas = c;
	}

};

ApplicationConnection* ApplicationConnection::applicationConnection = nullptr;


