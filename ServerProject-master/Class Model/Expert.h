///////////////////////////////////////////////////////////
//  Expert.h
//  Implementation of the Class Expert
//  Created on:      16-апр-2019 16:14:47
//  Original author: Ariana
///////////////////////////////////////////////////////////

#if !defined(EA_7694880C_152E_4018_9D28_C5D8476B6F86__INCLUDED_)
#define EA_7694880C_152E_4018_9D28_C5D8476B6F86__INCLUDED_

#include "Person.h"

class Expert : public Person
{

public:
	Expert()
	    : code(0),code_post(0),count_aims(0),Person()
	{

	}
	Expert(const Expert& Expert, const Person& name);
	~Expert();
	void Add_Expert(SOCKET c_sock);
	void Add_Name_Aims(SOCKET c_sock);
	int Check_Expert(int code);
	void Delete_expert(SOCKET c_sock);
	void Delete_Name_Aims(SOCKET c_sock);
	void Edit(SOCKET prm1, const char* field, int code);
	void Edit_fathername(SOCKET c_sock);
	void Edit_firstname(SOCKET c_sock);
	void Edit_lastname(SOCKET c_sock);
	void Edit_post(SOCKET c_sock);
	void Edit_value(SOCKET c_sock);
	void From_file(fstream& fp);
	int Get_code();
	int Get_code_post();
	void Name_aim_From_file();
	friend ostream & operator<<(ostream& stream, Expert ex);
	void Output(SOCKET c_sock);
	void Output_aims_and_values(SOCKET c_sock);
	void Output_one(SOCKET c_sock);
	void Print(SOCKET c_sock);
	void Set_code(int k);
	void Set_code_post(int k);
	void Set_name_aims(SOCKET prm1);
	void Set_values(SOCKET prm1);
	void Value_From_file(int c);

protected:
	int code;
	int code_post;
	int count_aims;
	/**
	 * Aim* aims;
	 */
	vector<string> name_aims;
	int values[100][100];

private:
	friend list<T> Creat_list(const char* file_name, list<T> l);
	friend list<T> Delete(list<T> l, int k);
	friend fstream Open_File(const char* name);

};
#endif // !defined(EA_7694880C_152E_4018_9D28_C5D8476B6F86__INCLUDED_)
