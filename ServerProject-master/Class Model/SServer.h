///////////////////////////////////////////////////////////
//  SServer.h
//  Implementation of the Class SServer
//  Created on:      16-апр-2019 16:14:47
//  Original author: Ariana
///////////////////////////////////////////////////////////

#if !defined(EA_26873B34_0053_43ce_A7C7_05FE1532BAC8__INCLUDED_)
#define EA_26873B34_0053_43ce_A7C7_05FE1532BAC8__INCLUDED_

class SServer
{

public:
	unsigned short port;

	SServer();
	~SServer();
	void closeServer();
	SOCKET handle();
	void startServer();

private:
	SOCKET this_s;
	WSAData wData;

};
#endif // !defined(EA_26873B34_0053_43ce_A7C7_05FE1532BAC8__INCLUDED_)
