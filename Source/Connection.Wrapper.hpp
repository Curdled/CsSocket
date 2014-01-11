#include "Connection.hpp"

extern "C"
{
	__DLL__ int  __cdecl  sendMessage(CppSocket::Connection *p_conn, std::string *string_in);
	__DLL__ int  __cdecl  recvMessage(CppSocket::Connection *p_conn, std::string *string_in);

	__DLL__  size_t __cdecl  getSocket(CppSocket::Connection *p_conn);
	__DLL__ void __cdecl closeSocket(CppSocket::Connection *p_conn);

	__DLL__ void  __cdecl  Deconstructor(CppSocket::Connection *p_conn);
}