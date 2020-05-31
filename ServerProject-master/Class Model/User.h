///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      16-апр-2019 16:14:47
//  Original author: Ariana
///////////////////////////////////////////////////////////

#if !defined(EA_B704AF83_4A86_41ef_8804_1ABC015DEE11__INCLUDED_)
#define EA_B704AF83_4A86_41ef_8804_1ABC015DEE11__INCLUDED_

#include "Person.h"

class User : public Person
{

public:
	User();
	User(const User& user, const Person& name);
	~User();
	static void Add_user(SOCKET prm1);
	int Check_User(list<User> list_user, const char* name);
	char* Deencrypt(char* password);
	void Delete_user(SOCKET c_sock);
	static void Edit(SOCKET c_soket, const char* field);
	void Edit_login(SOCKET prm1);
	void Edit_password(SOCKET prm1);
	char* Encrypt(char* password);
	void Find_user();
	void From_file(fstream& fp);
	char* Get_login();
	char* Get_password();
	int Login_in_menu(const char* name, SOCKET c_sock);
	friend ostream & operator<<(ostream& stream, User u);
	static void Output(SOCKET c_sock);
	void Print(SOCKET c_sock);
	char* Set_fathername(char* s);
	char* Set_firstname(char* s);
	char* Set_lastname(char* s);
	char* Set_login(char* login);
	char* Set_login();
	char* Set_password(char* password);
	char* Set_password();
	static void User_output(list<User> L);

private:
	char login[256];
	char password[256];

	friend list<T> Creat_list(const char* file_name, list<User> l);
	friend list<T> Delete(list<T> l, int k);
	friend fstream Open_File(const char* name);

};
#endif // !defined(EA_B704AF83_4A86_41ef_8804_1ABC015DEE11__INCLUDED_)
