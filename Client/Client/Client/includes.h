#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)

#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

#include <WinSock2.h>
#include <winsock.h>

#include "exception.h"

using namespace std;

int Menu_action_for_admin(SOCKET c_sock);
int Menu_action_for_user(SOCKET c_sock);
int Menu_action_control_user(SOCKET c_sock);
int Menu_action_delete_user(SOCKET c_sock);
int Menu_action_delete_data(SOCKET c_sock);
int Menu_action_edit_expert(SOCKET c_sock);


int Main_Menu();
int Main_Menu_for_admin();
int Main_Menu_for_user();
int Menu_edition_expert();
int Menu_control_user();
int Menu_delete_user();
int Menu_delete_data();
void draw(const char* str);

void c_Find_user(SOCKET c_sock);
void Add_user(SOCKET c_sock);
int Login_in_menu(const char* name, SOCKET c_sock);
void Add_Expert(SOCKET c_sock);
void Edit_user(SOCKET c_sock, const char* field);
void Add_Name_Aims(SOCKET c_sock);
void Delete_Name_Aims(SOCKET c_sock);
void Delete_user(SOCKET c_sock);
void Edit_expert(SOCKET c_sock, const char* field);
void Headtable_user();
void Print_user(SOCKET c_sock, int n);
void Output_user(SOCKET c_sock);
void Headtable_expert();
void Output_expert(SOCKET c_sock);
void Delete_expert(SOCKET c_sock);
void Set_values(SOCKET c_sock);
void Output_aims_and_values(SOCKET c_sock);
void Methods(SOCKET c_sock);
void Best_result(SOCKET c_sock);
void All_result(SOCKET c_sock);
void Print_expert(SOCKET c_sock);
void Edit_values(SOCKET c_sock);
void My_result(SOCKET c_sock);
void Output_Name_Aims(SOCKET c_sock);

int Enter_value();
int Enter_int();
int Enter_post();