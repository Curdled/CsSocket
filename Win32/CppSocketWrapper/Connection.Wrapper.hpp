#include "Connection.hpp"

extern "C"
{
	__DLL__ int  __cdecl  Connection_sendMessage(CppSocket::Connection *p_conn, char *string_in);
	__DLL__ int  __cdecl  Connection_recvMessage(CppSocket::Connection *p_conn, char *string_in);

	__DLL__ int __cdecl Connection_getConnectionBufferSize();

	__DLL__  size_t __cdecl  Connection_getSocket(CppSocket::Connection *p_conn);
	__DLL__ void __cdecl Connection_closeSocket(CppSocket::Connection *p_conn);

	//__DLL__ CppSocket::Connection* __cdecl Connection_Constructor(size_t sock_in);
	__DLL__ void  __cdecl  Connection_Deconstructor(CppSocket::Connection *p_conn);
}