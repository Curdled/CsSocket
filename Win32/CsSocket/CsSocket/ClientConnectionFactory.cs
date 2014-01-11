using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace CsSocket
{
    public enum SocketType
    {
        TCP_SOCKET,
        UDP_SOCKET
    }

    public class ClientConnectionFactory
    {
        [DllImport("Connection.Wrapper.dll", EntryPoint = "ClientConnectionFactory_Constructor", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr _Constructor(string hostname, int port_in, int socket_type);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "ClientConnectionFactory_Deconstructor", CallingConvention = CallingConvention.Cdecl)]
        private static extern void _Deconstructor(IntPtr p_in);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "ClientConnectionFactory_getConnection", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr _getConnection(IntPtr p_in);

        IntPtr _thisPtr = IntPtr.Zero;

        public ClientConnectionFactory(string hostname, int port_in, SocketType socket_type = SocketType.TCP_SOCKET)
        {
            int socket_number = 1;
            switch(socket_type)
            {
                case SocketType.TCP_SOCKET:
                    socket_number = 1;
                    break;
                case SocketType.UDP_SOCKET:
                    socket_number = 2;
                    break;
                default:
                    socket_number = 1;
                    break;
            };

           this._thisPtr = _Constructor(hostname, port_in, socket_number);
        }

        ~ClientConnectionFactory()
        {
            _Deconstructor(this._thisPtr);
        }

        public Connection getConnection()
        {
            return new Connection(_getConnection(this._thisPtr));
        }


    }
}
