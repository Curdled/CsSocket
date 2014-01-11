#include "Connection.Wrapper.hpp"
#include <iostream>
int sendMessage(CppSocket::Connection *p_conn, std::string *string_in)
{
	std::cout << *string_in << std::endl;
	return p_conn->sendMessage(*string_in);
}

int recvMessage(CppSocket::Connection *p_conn, std::string *string_in)
{
	std::cout << *string_in << std::endl;
	return p_conn->recvMessage(*string_in);
}

void closeSocket(CppSocket::Connection *p_conn)
{
	p_conn->closeSocket();
}

size_t getSocket(CppSocket::Connection *p_conn)
{
	return p_conn->getSocket();
}

void Deconstructor(CppSocket::Connection *p_conn)
{
	delete p_conn;
}