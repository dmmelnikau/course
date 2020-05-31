#pragma once
#include "includes.h"

using namespace std;

int Main_Menu() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) draw("1) Войти как администратор");
		else cout << "1) Войти как администратор" << endl;
		if (key == 1) draw("2) Войти как эксперт");
		else cout << "2) Войти как эксперт" << endl;
		if (key == 2) draw("3) Регистрация");
		else cout << "3) Регистрация" << endl;
		if (key == 3) draw("4) Выход");
		else cout << "4) Выход" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}
int Main_Menu_for_admin() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 10) % 10;
		if (key == 0) draw("1) Добавить эксперта");
		else cout << "1) Добавить эксперта" << endl;
		if (key == 1) draw("2) Редактировать информацию об эксперте");
		else cout << "2) Редактировать информацию об эксперте" << endl;
		if (key == 2) draw("3) Удалить эксперта");
		else cout << "3) Удалить эксперта" << endl;
		if (key == 3) draw("4) Просмотреть данные обо всех экспертах");
		else cout << "4) Просмотреть данные обо всех экспертах" << endl;
		if (key == 4) draw("5) Добавить альтернативу");
		else cout << "5) Добавить альтернативу" << endl;
		if (key == 5) draw("6) Удалить альтернативу");
		else cout << "6) Удалить альтернативу" << endl;
		if (key == 6) draw("7) Управление пользователями");
		else cout << "7) Управление пользователями" << endl;
		if (key == 7) draw("8) Вывести наилучшую альтернативу");
		else cout << "8) Вывести наилучшую альтернативу" << endl;
		if (key == 8) draw("9) Вывести все результаты");
		else cout << "9) Вывести все результаты" << endl;
		if (key == 9) draw("10) Выход в начальное меню");
		else cout << "10) Выход в начальное меню" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	ch = _getch();
	return key;
}
int Main_Menu_for_user() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) draw("1) Заполнить данные");
		else cout << "1) Заполнить данные" << endl;
		if (key == 1) draw("2) Редактировать введенные значения");
		else cout << "2) Редактировать введенные значения" << endl;
		if (key == 2) draw("3) Вывести наилучшую альтернативу");
		else cout << "3) Вывести наилучшую альтернативу" << endl;
		if (key == 3) draw("4) Вывести свои значения");
		else cout << "4) Вывести свои значения" << endl;
		if (key == 4) draw("5) Просмотреть личные данные");
		else cout << "5) Просмотреть личные данные" << endl;
		if (key == 5) draw("6) Выход в начальное меню");
		else cout << "6) Выход в начальное меню" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}

int Menu_search_and_filtration() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) draw("1) Поиск по фамилии");
		else cout << "1) Поиск по фамилии" << endl;
		if (key == 1) draw("2) Поиск по имени");
		else cout << "2) Поиск по имени" << endl;
		if (key == 2) draw("3) Фильтрация по категории");
		else cout << "3) Фильтрация по категории" << endl;
		if (key == 3) draw("4) Фильтрация по первой букве фамилии");
		else cout << "4) Фильтрация по первой букве фамилии" << endl;
		if (key == 4) draw("5) Выход в меню 2-го уровня");
		else cout << "5) Выход в меню 2-го уровня" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}
int Menu_edition_expert() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) draw("1) Редактировать фамилию");
		else cout << "1) Редактировать фамилию" << endl;
		if (key == 1) draw("2) Редактировать имя");
		else cout << "2) Редактировать имя" << endl;
		if (key == 2) draw("3) Редактировать отчество");
		else cout << "3) Редактировать отчество" << endl;
		if (key == 3) draw("4) Редактировать категорию");
		else cout << "4) Редактировать категорию" << endl;
		if (key == 4) draw("5) Выход в меню 2-го уровня");
		else cout << "5) Выход в меню 2-го уровня" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}
int Menu_control_user() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) draw("1) Показать всех пользователей и их пароли");
		else cout << "1) Показать всех пользователей и их пароли" << endl;
		if (key == 1) draw("2) Редактировать имя пользователя");
		else cout << "2) Редактировать имя пользователя" << endl;
		if (key == 2) draw("3) Редактировать пароль пользователя");
		else cout << "3) Редактировать пароль пользователя" << endl;
		if (key == 3) draw("4) Удалить");
		else cout << "4) Удалить" << endl;
		if (key == 4) draw("5) Выход в меню 2-го уровня");
		else cout << "5) Выход в меню 2-го уровня" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}

int Menu_delete_user() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) draw("1) Удалить всех пользователей");
		else cout << "1) Удалить всех пользователей" << endl;
		if (key == 1) draw("2) Удалить одного пользователя");
		else cout << "2) Удалить одного пользователя" << endl;
		if (key == 2) draw("3) Выход в меню 2 - го уровня");
		else cout << "3) Выход в меню 2-го уровня" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}

int Menu_delete_data() {
	int key = 0;
	char ch;
	int code;
	while (true) {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) draw("1) Удалить все данные об экспертах");
		else cout << "1) Удалить все данные об экспертах" << endl;
		if (key == 1) draw("2) Удалить одного эксперта");
		else cout << "2) Удалить одного эксперта" << endl;
		if (key == 2) draw("3) Выход в меню 2-го уровня");
		else cout << "3) Выход в меню 2-го уровня" << endl;

		ch = _getch();
		if ((ch == 0) || (ch == -32))
			continue;
		code = static_cast<int>(ch);
		if (code == 80) { key++; }
		else if (code == 72) { key--; }
		else if (code == 13)
			break;
	}
	return key;
}

void draw(const char* str) {
	HANDLE  hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, (WORD)((8 << 4) | 15));
	cout << ">" << str << endl;
	//SetConsoleTextAttribute(hStdout, (WORD)((15<<4) | 0));
	SetConsoleTextAttribute(hStdout, (WORD)((15) | 0));
}