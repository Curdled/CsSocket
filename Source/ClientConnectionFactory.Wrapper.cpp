#include "ClientConnectionFactory.Wrapper.hpp"

CppSocket::ClientConnectionFactory* ClientConnectionFactory_Constructor( char *hostname_in, int port_in, int socket_type )
{
	CppSocket::SocketType::SocketTypes socktype;
	switch (socket_type)
	{
	case 1:
		socktype = CppSocket::SocketType::SocketTypes::TCP_SOCK;
		break;
	case 2:
		socktype = CppSocket::SocketType::SocketTypes::UDP_SOCK;
		break;
	default:
		socktype = CppSocket::SocketType::SocketTypes::TCP_SOCK;
		break;
	}
	return new CppSocket::ClientConnectionFactory(std::string(hostname_in), port_in, socktype);
}

CppSocket::Connection* ClientConnectionFactory_getConnection(CppSocket::ClientConnectionFactory* p_factory)
{
	return new CppSocket::Connection(p_factory->getConnection());
}

void ClientConnectionFactory_Deconstructor(CppSocket::ClientConnectionFactory* p_factory)
{
	delete p_factory;
}