#include "ClientConnectionFactory.hpp"

extern "C"
{
	__DLL__ CppSocket::ClientConnectionFactory* __cdecl  ClientConnectionFactory_Constructor( char *hostname_in, int port_in, int socket_type );

	__DLL__ void __cdecl ClientConnectionFactory_Deconstructor(CppSocket::ClientConnectionFactory* p_factory);

	__DLL__ CppSocket::Connection* __cdecl ClientConnectionFactory_getConnection(CppSocket::ClientConnectionFactory* p_factory);
}