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
		if (key == 0) draw("1) ����� ��� �������������");
		else cout << "1) ����� ��� �������������" << endl;
		if (key == 1) draw("2) ����� ��� �������");
		else cout << "2) ����� ��� �������" << endl;
		if (key == 2) draw("3) �����������");
		else cout << "3) �����������" << endl;
		if (key == 3) draw("4) �����");
		else cout << "4) �����" << endl;

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
		if (key == 0) draw("1) �������� ��������");
		else cout << "1) �������� ��������" << endl;
		if (key == 1) draw("2) ������������� ���������� �� ��������");
		else cout << "2) ������������� ���������� �� ��������" << endl;
		if (key == 2) draw("3) ������� ��������");
		else cout << "3) ������� ��������" << endl;
		if (key == 3) draw("4) ����������� ������ ��� ���� ���������");
		else cout << "4) ����������� ������ ��� ���� ���������" << endl;
		if (key == 4) draw("5) �������� ������������");
		else cout << "5) �������� ������������" << endl;
		if (key == 5) draw("6) ������� ������������");
		else cout << "6) ������� ������������" << endl;
		if (key == 6) draw("7) ���������� ��������������");
		else cout << "7) ���������� ��������������" << endl;
		if (key == 7) draw("8) ������� ��������� ������������");
		else cout << "8) ������� ��������� ������������" << endl;
		if (key == 8) draw("9) ������� ��� ����������");
		else cout << "9) ������� ��� ����������" << endl;
		if (key == 9) draw("10) ����� � ��������� ����");
		else cout << "10) ����� � ��������� ����" << endl;

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
		if (key == 0) draw("1) ��������� ������");
		else cout << "1) ��������� ������" << endl;
		if (key == 1) draw("2) ������������� ��������� ��������");
		else cout << "2) ������������� ��������� ��������" << endl;
		if (key == 2) draw("3) ������� ��������� ������������");
		else cout << "3) ������� ��������� ������������" << endl;
		if (key == 3) draw("4) ������� ���� ��������");
		else cout << "4) ������� ���� ��������" << endl;
		if (key == 4) draw("5) ����������� ������ ������");
		else cout << "5) ����������� ������ ������" << endl;
		if (key == 5) draw("6) ����� � ��������� ����");
		else cout << "6) ����� � ��������� ����" << endl;

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
		if (key == 0) draw("1) ����� �� �������");
		else cout << "1) ����� �� �������" << endl;
		if (key == 1) draw("2) ����� �� �����");
		else cout << "2) ����� �� �����" << endl;
		if (key == 2) draw("3) ���������� �� ���������");
		else cout << "3) ���������� �� ���������" << endl;
		if (key == 3) draw("4) ���������� �� ������ ����� �������");
		else cout << "4) ���������� �� ������ ����� �������" << endl;
		if (key == 4) draw("5) ����� � ���� 2-�� ������");
		else cout << "5) ����� � ���� 2-�� ������" << endl;

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
		if (key == 0) draw("1) ������������� �������");
		else cout << "1) ������������� �������" << endl;
		if (key == 1) draw("2) ������������� ���");
		else cout << "2) ������������� ���" << endl;
		if (key == 2) draw("3) ������������� ��������");
		else cout << "3) ������������� ��������" << endl;
		if (key == 3) draw("4) ������������� ���������");
		else cout << "4) ������������� ���������" << endl;
		if (key == 4) draw("5) ����� � ���� 2-�� ������");
		else cout << "5) ����� � ���� 2-�� ������" << endl;

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
		if (key == 0) draw("1) �������� ���� ������������� � �� ������");
		else cout << "1) �������� ���� ������������� � �� ������" << endl;
		if (key == 1) draw("2) ������������� ��� ������������");
		else cout << "2) ������������� ��� ������������" << endl;
		if (key == 2) draw("3) ������������� ������ ������������");
		else cout << "3) ������������� ������ ������������" << endl;
		if (key == 3) draw("4) �������");
		else cout << "4) �������" << endl;
		if (key == 4) draw("5) ����� � ���� 2-�� ������");
		else cout << "5) ����� � ���� 2-�� ������" << endl;

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
		if (key == 0) draw("1) ������� ���� �������������");
		else cout << "1) ������� ���� �������������" << endl;
		if (key == 1) draw("2) ������� ������ ������������");
		else cout << "2) ������� ������ ������������" << endl;
		if (key == 2) draw("3) ����� � ���� 2 - �� ������");
		else cout << "3) ����� � ���� 2-�� ������" << endl;

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
		if (key == 0) draw("1) ������� ��� ������ �� ���������");
		else cout << "1) ������� ��� ������ �� ���������" << endl;
		if (key == 1) draw("2) ������� ������ ��������");
		else cout << "2) ������� ������ ��������" << endl;
		if (key == 2) draw("3) ����� � ���� 2-�� ������");
		else cout << "3) ����� � ���� 2-�� ������" << endl;

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