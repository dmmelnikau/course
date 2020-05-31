#pragma once
#include "includes.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");


	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return 0; }

	HANDLE  hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hStdout, (WORD)((15 << 4) | 0));

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);// указание адреса и порта сервера
	sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(3487);
	dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(s, (sockaddr *)&dest_addr, sizeof(dest_addr));

	char buf[100];
	int key;

	for (;;) {
		key = Main_Menu();
		itoa(key, buf, 10);
		send(s, buf, 100, 0);
		switch (key) {
		case 0: Menu_action_for_admin(s); break;
		case 1: Menu_action_for_user(s); break;
		case 2: Add_user(s); break;
		case 3: return 0;
		}
	}

	closesocket(s);
	WSACleanup();

	return 0;
}