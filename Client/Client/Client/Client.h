#pragma once
#include "includes.h"

//class SClient
//{
//public:
//	SClient(SOCKET s, SOCKADDR_IN sock_in);
//	~SClient();
//	void handle();
//private:
//	SOCKET c_sock;
//	SOCKADDR_IN c_addr;
//	char buffer[1024];
//};
//
//SClient::SClient(SOCKET s, SOCKADDR_IN sock_in)
//{
//
//	c_sock = s;
//	c_addr = sock_in;
//	printf("Client created\n");
//	handle();
//}
//
//
//SClient::~SClient()
//{
//}
//
//void SClient::handle()
//{
//	while (true)
//	{
//		int k = recv(c_sock, buffer, sizeof(buffer), NULL);
//		if (k>0) {
//			printf(buffer);
//		}
//		Sleep(30);
//	}
//}

//int init_sock() {
//	int len;
//	sockaddr_in address;
//	int result;
//	int s;
//	s = socket(AF_INET, SOCK_STREAM, 0);
//	address.sin_family = AF_INET;   ///интернет домен
//	address.sin_addr.s_addr = inet_addr("127.0.0.1");   ///соединяемся с 127,0,0,1
//	address.sin_port = htons(21);    /// 21 порт
//	len = sizeof(address);
//	result = connect(s, (sockaddr *)&address, len);   ///установка соединения
//	if (result == -1) {
//		perror("oops: client");
//		return -1;
//	}
//	return s;
//}
//
//int readServ(int s) {
//	int rc;
//	fd_set fdr;
//	FD_ZERO(&fdr);
//	FD_SET(s, &fdr);
//	timeval timeout;
//	timeout.tv_sec = 1;   ///зададим  структуру времени со значением 1 сек
//	timeout.tv_usec = 0;
//	do {
//		char buff[512] = { ' ' };
//		recv(s, buff, 512, 0);   ///получаем данные из потока
//		cout << buff;
//		rc = select(s + 1, &fdr, NULL, NULL, &timeout);    
//	} while (rc);     ///проверяем результат
//	return 2;
//}

//int init_data() {
//	send(s, "PASV\r\n", strlen("PASV\r\n"), 0);
//	char buff[128];
//	recv(s, buff, 128, 0);
//	cout << buff; ////выводим на экран полученную от сервера строку
//	int a, b;
//	char *tmp_char;
//	tmp_char = strtok(buff, "(");
//	tmp_char = strtok(NULL, "(");
//	tmp_char = strtok(tmp_char, ")");
//	int c, d, e, f;
//	sscanf(tmp_char, "%d,%d,%d,%d,%d,%d", &c, &d, &e, &f, &a, &b);
//	int len;
//	sockaddr_in address;
//	int result;
//	int port = a * 256 + b;
//	ds = socket(AF_INET, SOCK_STREAM, 0);
//	address.sin_family = AF_INET;
//	address.sin_addr.s_addr = inet_addr(addr);    ///addr - у меня глобальная переменная с адресом сервера
//	address.sin_port = htons(port);
//	len = sizeof(address);
//	result = connect(ds, (sockaddr *)&address, len);
//	if (result == -1) {
//		perror("oops: client");
//		return -1;
//	}
//	return 0;
//}
//
//int login() {
//	cout << "Введите логин: "; 
//	char name[64]; 
//	cin >> name;
//	char str[512];
//	sprintf(str, "USER %s\r\n", name);
//	send(s, str, strlen(str), 0);
//	readServ();
//	cout << "Введите пароль: "; char pass[64]; cin >> pass;
//	sprintf(str, "PASS %s\r\n", pass);
//	send(s, str, strlen(str), 0);
//	readServ(s);
//	return 0;
//}