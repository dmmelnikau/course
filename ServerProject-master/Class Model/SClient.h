///////////////////////////////////////////////////////////
//  SClient.h
//  Implementation of the Class SClient
//  Created on:      16-апр-2019 16:14:47
//  Original author: Ariana
///////////////////////////////////////////////////////////

#if !defined(EA_1E1D9DB4_1226_495a_8C52_B670D2448A6C__INCLUDED_)
#define EA_1E1D9DB4_1226_495a_8C52_B670D2448A6C__INCLUDED_

class SClient
{

public:
	SClient();

	SClient(SOCKET s, SOCKADDR_IN sock_in);
	~SClient();
	void handle();

private:
	char buffer[1024];
	SOCKADDR_IN c_addr;
	SOCKET c_sock;

};
#endif // !defined(EA_1E1D9DB4_1226_495a_8C52_B670D2448A6C__INCLUDED_)
