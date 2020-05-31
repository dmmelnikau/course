#pragma once
#include "includes.h"

int Menu_action_for_admin(SOCKET c_sock) {
	int k, id = 0;
	char buf[100], kd[4];
	id = Login_in_menu("Admin", c_sock);
	if (id != 0) {
		for (;;) {
			k = Main_Menu_for_admin();
			itoa(k, buf, 10);
			send(c_sock, buf, 100, 0);
			switch (k) {
			case 0: Add_Expert(c_sock); break;
			case 1: Menu_action_edit_expert(c_sock); break;
			case 2: Menu_action_delete_data(c_sock); break;
			case 3: Output_expert(c_sock); break;
			case 4: Add_Name_Aims(c_sock); break;
			case 5: Delete_Name_Aims(c_sock); break;
			case 6: Menu_action_control_user(c_sock); break;
			case 7: Best_result(c_sock); break;
			case 8: All_result(c_sock); break;
			case 9: return 0;
			}
		}
	}
	else return 0;
}
int Menu_action_for_user(SOCKET c_sock) {
	//User user;
	int id = 0, k;
	char buf[100], kd[4];
	id = Login_in_menu("User", c_sock);
	if (id != 0) {
		for (;;) {
			k = Main_Menu_for_user();
			itoa(k, buf, 10);
			send(c_sock, buf, 100, 0);
			switch (k) {
			case 0: Set_values(c_sock); break;
			case 1: Edit_values(c_sock); break;
			case 2: Best_result(c_sock); break;
			case 3: My_result(c_sock); break;
			case 4: {Headtable_expert(); Print_expert(c_sock); _getch(); _getch(); break; }
			case 5: return 0;
			}
		}
	}
	else return 0;
}
int Menu_action_control_user(SOCKET c_sock) {
	int id = 0, k;
	char buf[100], kd[4];
	for (;;) {
		k = Menu_control_user();
		itoa(k, buf, 10);
		send(c_sock, buf, 100, 0);
		switch (k) {
		case 0: Output_user(c_sock); 	_getch(); _getch(); break;
		case 1: Edit_user(c_sock, "login"); break;
		case 2: Edit_user(c_sock, "password"); break;
		case 3: Menu_action_delete_user(c_sock); break;
		case 4: return 0;
		}
	}
}
int Menu_action_delete_user(SOCKET c_sock) {
	char buf[100];
	int k;
	for (;;) {
		k = Menu_delete_user();
		itoa(k, buf, 10);
		send(c_sock, buf, 100, 0);
		switch (k) {
		case 0: cout << "Данные успешно удалены." << endl; _getch(); _getch(); break;
		case 1: Delete_user(c_sock); break;
		case 2: return 0;
		}
	}
}

int Menu_action_edit_expert(SOCKET c_sock) {
	int code, k;
	char trash[100];
	Output_expert(c_sock);
	cout << "Введите код эксперта, информацию о которым хотите изменить" << endl;
	code = Enter_int();
	char buf[100];
	itoa(code, buf, 10);
	send(c_sock, buf, 100, 0);
	recv(c_sock, buf, sizeof(buf), NULL);
	int id = atoi(buf);
	if (id == 0) {
		cout << "Нет экспертов с данным кодом." << endl;
		_getch(); _getch();
		return 0;
	}
	for (;;) {
		k = Menu_edition_expert();
		itoa(k, buf, 10);
		send(c_sock, buf, 100, 0);
		switch (k) {
		case 0: Edit_expert(c_sock, "lastname"); break;
		case 1: Edit_expert(c_sock, "firstname"); break;
		case 2: Edit_expert(c_sock, "otchestvo"); break;
		case 3: Edit_expert(c_sock, "post"); break;
		case 4: return 0;
		}
	}
}

int Menu_action_delete_data(SOCKET c_sock) {
	char buf[256];
	for (;;) {
		int k = Menu_delete_data();
		itoa(k, buf, 10);
		send(c_sock, buf, 100, 0);
		switch (k) {
		case 0: cout << "Данные успешно удалены." << endl;  _getch(); _getch(); break;
		case 1: Delete_expert(c_sock);  break;
		case 2: return 0;
		}
	}
}
