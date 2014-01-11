using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace CsSocket
{
    public class Connection
    {
        [DllImport("Connection.Wrapper.dll", EntryPoint = "Connection_Deconstructor", CallingConvention = CallingConvention.Cdecl)]
        private static extern void _Deconstructor(IntPtr p_in);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "Connection_sendMessage", CallingConvention = CallingConvention.Cdecl)]
        private static extern int _sendMessage(IntPtr p_in, string string_in);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "Connection_recvMessage", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern int _recvMessage(IntPtr p_in, StringBuilder  string_out);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "Connection_getSocket", CallingConvention = CallingConvention.Cdecl)]
        private static extern int _getSocket(IntPtr p_in);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "Connection_closeSocket", CallingConvention = CallingConvention.Cdecl)]
        private static extern void _closeSocket(IntPtr p_in);

        [DllImport("Connection.Wrapper.dll", EntryPoint = "Connection_getConnectionBufferSize", CallingConvention = CallingConvention.Cdecl)]
        private static extern int _getConnectionBufferSize();
        IntPtr _thisPtr = IntPtr.Zero;

        public Connection(IntPtr connection) 
        {
            this._thisPtr = connection;
        }
        ~Connection()
        {
            if(this._thisPtr != IntPtr.Zero)
                _Deconstructor(this._thisPtr);
        }

        public int SendMessage(string msg_in)
        {
            
            return _sendMessage(this._thisPtr, msg_in);
        }
        public int RecvMessage(ref string msg_in)
        {
            StringBuilder output = new StringBuilder(_getConnectionBufferSize());
            IntPtr tmp = IntPtr.Zero;
            int tmp2 =  _recvMessage(this._thisPtr, output);
            msg_in = output.ToString();
            //msg_in = Marshal.PtrToStringAuto(tmp);
            return tmp2;
        }

        public int GetSocket()
        {
            return _getSocket(this._thisPtr);
        }
        public void CloseConnection()
        {
            _closeSocket(this._thisPtr);
        }



    }

    

}
