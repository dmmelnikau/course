///////////////////////////////////////////////////////////
//  Person.h
//  Implementation of the Class Person
//  Created on:      16-апр-2019 16:14:47
//  Original author: Ariana
///////////////////////////////////////////////////////////

#if !defined(EA_29C9C5A7_7034_45e0_82DB_3B8AA956FA7C__INCLUDED_)
#define EA_29C9C5A7_7034_45e0_82DB_3B8AA956FA7C__INCLUDED_

class Person
{

public:
	Person();
	Person(const Person& name);
	~Person();
	char* Get_fathername();
	char* Get_firstname();
	char* Get_lastname();
	char* Set_fathername(char* str);
	char* Set_firstname(char* str);
	char* Set_lastname(char* str);

protected:
	/**
	 * отчество
	 */
	char fathername[100];
	/**
	 * имя
	 */
	char firstname[100];
	/**
	 * фамилия
	 */
	char lastname[100];

};
#endif // !defined(EA_29C9C5A7_7034_45e0_82DB_3B8AA956FA7C__INCLUDED_)
