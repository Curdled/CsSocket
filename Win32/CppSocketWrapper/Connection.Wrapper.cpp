#include "Connection.Wrapper.hpp"
#include <iostream>

extern "C"
{
	int Connection_sendMessage(CppSocket::Connection *p_conn, char *string_in)
	{
		std::string s = std::string(string_in);

		//std::cout << "send msg: " <<  s << std::endl;
		int value = p_conn->sendMessage(std::string(string_in));
		//std::cout << "send msg: " << value << std::endl;
		return value;
	}

	int Connection_recvMessage(CppSocket::Connection *p_conn, char *string_in)
	{
		std::string tmp;
		int tmp2 = p_conn->recvMessage(tmp);
		//std::cout << "recv msg: " <<  tmp << std::endl;
		strncpy_s(string_in, tmp.length()+1, tmp.c_str(), tmp.length());
		//std::copy(tmp.begin(), tmp.end(), string_in);
		return tmp2;
	}

	void Connection_closeSocket(CppSocket::Connection *p_conn)
	{
		p_conn->closeSocket();
	}

	size_t Connection_getSocket(CppSocket::Connection *p_conn)
	{
		 return p_conn->getSocket();
	}

	//CppSocket::Connection* Connection_Constructor(size_t conn_in)
	//{
	//	return new CppSocket::Connection(conn_in);
	//}

	void Connection_Deconstructor(CppSocket::Connection *p_conn)
	{
		delete p_conn;
	}

	int Connection_getConnectionBufferSize()
	{
		return CppSocket::_cm_message_len_;
	}
}