#ifndef CONFIG_EXT_H
#define CONFIG_EXT_H

#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || (defined(__cplusplus) && (__cplusplus >= 201103L))

#define U_Config_UART_Send_UWT( serial, ... )\
    do\
    {\
        extern volatile bool g_##serial##_tx_ready_flag;\
        g_##serial##_tx_ready_flag = false;\
        R_Config_##serial##_Serial_Send( __VA_ARGS__ );\
        do{}while (g_##serial##_tx_ready_flag == false);\
    }while (0)

#define U_Config_UART_Receive_UWT( serial, ... )\
    do\
    {\
        extern volatile bool g_##serial##_rx_ready_flag;\
        g_##serial##_rx_ready_flag = false;\
        R_Config_##serial##_Serial_Receive( __VA_ARGS__ );\
        do{}while (g_##serial##_rx_ready_flag == false);\
    }while (0)

#define U_CONFIG_UART_SEND_IMPL( serial )\
    volatile bool g_##serial##_tx_ready_flag = true

#define U_CONFIG_UART_RECEIVE_IMPL( serial )\
    volatile bool g_##serial##_rx_ready_flag = false

#define U_Config_SCI0_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI0,  __VA_ARGS__  )
#define U_Config_SCI1_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI1,  __VA_ARGS__  )
#define U_Config_SCI2_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI2,  __VA_ARGS__  )
#define U_Config_SCI3_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI3,  __VA_ARGS__  )
#define U_Config_SCI4_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI4,  __VA_ARGS__  )
#define U_Config_SCI5_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI5,  __VA_ARGS__  )
#define U_Config_SCI6_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI6,  __VA_ARGS__  )
#define U_Config_SCI7_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI7,  __VA_ARGS__  )
#define U_Config_SCI8_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI8,  __VA_ARGS__  )
#define U_Config_SCI9_UART_Send_UWT(...)     U_Config_UART_Send_UWT(    SCI9,  __VA_ARGS__  )
#define U_Config_SCI10_UART_Send_UWT(...)    U_Config_UART_Send_UWT(    SCI10, __VA_ARGS__  )
#define U_Config_SCI11_UART_Send_UWT(...)    U_Config_UART_Send_UWT(    SCI11, __VA_ARGS__  )
#define U_Config_SCI12_UART_Send_UWT(...)    U_Config_UART_Send_UWT(    SCI12, __VA_ARGS__  )
#define U_Config_SCI0_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI0,  __VA_ARGS__  )
#define U_Config_SCI1_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI1,  __VA_ARGS__  )
#define U_Config_SCI2_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI2,  __VA_ARGS__  )
#define U_Config_SCI3_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI3,  __VA_ARGS__  )
#define U_Config_SCI4_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI4,  __VA_ARGS__  )
#define U_Config_SCI5_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI5,  __VA_ARGS__  )
#define U_Config_SCI6_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI6,  __VA_ARGS__  )
#define U_Config_SCI7_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI7,  __VA_ARGS__  )
#define U_Config_SCI8_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI8,  __VA_ARGS__  )
#define U_Config_SCI9_UART_Receive_UWT(...)  U_Config_UART_Receive_UWT( SCI9,  __VA_ARGS__  )
#define U_Config_SCI10_UART_Receive_UWT(...) U_Config_UART_Receive_UWT( SCI10, __VA_ARGS__  )
#define U_Config_SCI11_UART_Receive_UWT(...) U_Config_UART_Receive_UWT( SCI11, __VA_ARGS__  )
#define U_Config_SCI12_UART_Receive_UWT(...) U_Config_UART_Receive_UWT( SCI12, __VA_ARGS__  )

#define U_CONFIG_SCI0_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI0  )
#define U_CONFIG_SCI1_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI1  )
#define U_CONFIG_SCI2_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI2  )
#define U_CONFIG_SCI3_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI3  )
#define U_CONFIG_SCI4_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI4  )
#define U_CONFIG_SCI5_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI5  )
#define U_CONFIG_SCI6_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI6  )
#define U_CONFIG_SCI7_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI7  )
#define U_CONFIG_SCI8_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI8  )
#define U_CONFIG_SCI9_UART_SEND_IMPL()     U_CONFIG_UART_SEND_IMPL(    SCI9  )
#define U_CONFIG_SCI10_UART_SEND_IMPL()    U_CONFIG_UART_SEND_IMPL(    SCI10 )
#define U_CONFIG_SCI11_UART_SEND_IMPL()    U_CONFIG_UART_SEND_IMPL(    SCI11 )
#define U_CONFIG_SCI12_UART_SEND_IMPL()    U_CONFIG_UART_SEND_IMPL(    SCI12 )
#define U_CONFIG_SCI0_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI0  )
#define U_CONFIG_SCI1_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI1  )
#define U_CONFIG_SCI2_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI2  )
#define U_CONFIG_SCI3_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI3  )
#define U_CONFIG_SCI4_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI4  )
#define U_CONFIG_SCI5_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI5  )
#define U_CONFIG_SCI6_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI6  )
#define U_CONFIG_SCI7_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI7  )
#define U_CONFIG_SCI8_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI8  )
#define U_CONFIG_SCI9_UART_RECEIVE_IMPL()  U_CONFIG_UART_RECEIVE_IMPL( SCI9  )
#define U_CONFIG_SCI10_UART_RECEIVE_IMPL() U_CONFIG_UART_RECEIVE_IMPL( SCI10 )
#define U_CONFIG_SCI11_UART_RECEIVE_IMPL() U_CONFIG_UART_RECEIVE_IMPL( SCI11 )
#define U_CONFIG_SCI12_UART_RECEIVE_IMPL() U_CONFIG_UART_RECEIVE_IMPL( SCI12 )

#define U_CONFIG_SCI_CALLBACK_TRANSMITEND( serial )\
    do{\
        extern volatile bool g_##serial##_tx_ready_flag;\
        g_##serial##_tx_ready_flag = true;\
        r_Config_##serial##_callback_transmitend();\
    }while(0)

#define U_CONFIG_SCI_CALLBACK_RECEIVEEND( serial )\
    do{\
        extern volatile bool g_##serial##_rx_ready_flag;\
        g_##serial##_rx_ready_flag = true;\
        r_Config_##serial##_callback_receiveend();\
    }while(0)

#define U_CONFIG_SCI0_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI0  )
#define U_CONFIG_SCI1_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI1  )
#define U_CONFIG_SCI2_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI2  )
#define U_CONFIG_SCI3_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI3  )
#define U_CONFIG_SCI4_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI4  )
#define U_CONFIG_SCI5_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI5  )
#define U_CONFIG_SCI6_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI6  )
#define U_CONFIG_SCI7_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI7  )
#define U_CONFIG_SCI8_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI8  )
#define U_CONFIG_SCI9_CALLBACK_TRANSMITEND()  U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI9  )
#define U_CONFIG_SCI10_CALLBACK_TRANSMITEND() U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI10 )
#define U_CONFIG_SCI11_CALLBACK_TRANSMITEND() U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI11 )
#define U_CONFIG_SCI12_CALLBACK_TRANSMITEND() U_CONFIG_SCI_CALLBACK_TRANSMITEND( SCI12 )
#define U_CONFIG_SCI0_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI0  )
#define U_CONFIG_SCI1_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI1  )
#define U_CONFIG_SCI2_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI2  )
#define U_CONFIG_SCI3_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI3  )
#define U_CONFIG_SCI4_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI4  )
#define U_CONFIG_SCI5_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI5  )
#define U_CONFIG_SCI6_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI6  )
#define U_CONFIG_SCI7_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI7  )
#define U_CONFIG_SCI8_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI8  )
#define U_CONFIG_SCI9_CALLBACK_RECEIVEEND()   U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI9  )
#define U_CONFIG_SCI10_CALLBACK_RECEIVEEND()  U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI10 )
#define U_CONFIG_SCI11_CALLBACK_RECEIVEEND()  U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI11 )
#define U_CONFIG_SCI12_CALLBACK_RECEIVEEND()  U_CONFIG_SCI_CALLBACK_RECEIVEEND(  SCI12 )

#define r_Config_SCI0_callback_transmitend( ... )    r_Config_SCI0_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI0_callback_transmitendXXXvoid()  r_Config_SCI0_callback_transmitend( void )
#define r_Config_SCI0_callback_transmitendXXX()      U_CONFIG_SCI0_CALLBACK_TRANSMITEND()

#define r_Config_SCI1_callback_transmitend( ... )    r_Config_SCI1_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI1_callback_transmitendXXXvoid()  r_Config_SCI1_callback_transmitend( void )
#define r_Config_SCI1_callback_transmitendXXX()      U_CONFIG_SCI1_CALLBACK_TRANSMITEND()

#define r_Config_SCI2_callback_transmitend( ... )    r_Config_SCI2_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI2_callback_transmitendXXXvoid()  r_Config_SCI2_callback_transmitend( void )
#define r_Config_SCI2_callback_transmitendXXX()      U_CONFIG_SCI2_CALLBACK_TRANSMITEND()

#define r_Config_SCI3_callback_transmitend( ... )    r_Config_SCI3_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI3_callback_transmitendXXXvoid()  r_Config_SCI3_callback_transmitend( void )
#define r_Config_SCI3_callback_transmitendXXX()      U_CONFIG_SCI3_CALLBACK_TRANSMITEND()

#define r_Config_SCI4_callback_transmitend( ... )    r_Config_SCI4_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI4_callback_transmitendXXXvoid()  r_Config_SCI4_callback_transmitend( void )
#define r_Config_SCI4_callback_transmitendXXX()      U_CONFIG_SCI4_CALLBACK_TRANSMITEND()

#define r_Config_SCI5_callback_transmitend( ... )    r_Config_SCI5_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI5_callback_transmitendXXXvoid()  r_Config_SCI5_callback_transmitend( void )
#define r_Config_SCI5_callback_transmitendXXX()      U_CONFIG_SCI5_CALLBACK_TRANSMITEND()

#define r_Config_SCI6_callback_transmitend( ... )    r_Config_SCI6_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI6_callback_transmitendXXXvoid()  r_Config_SCI6_callback_transmitend( void )
#define r_Config_SCI6_callback_transmitendXXX()      U_CONFIG_SCI6_CALLBACK_TRANSMITEND()

#define r_Config_SCI7_callback_transmitend( ... )    r_Config_SCI7_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI7_callback_transmitendXXXvoid()  r_Config_SCI7_callback_transmitend( void )
#define r_Config_SCI7_callback_transmitendXXX()      U_CONFIG_SCI7_CALLBACK_TRANSMITEND()

#define r_Config_SCI8_callback_transmitend( ... )    r_Config_SCI8_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI8_callback_transmitendXXXvoid()  r_Config_SCI8_callback_transmitend( void )
#define r_Config_SCI8_callback_transmitendXXX()      U_CONFIG_SCI8_CALLBACK_TRANSMITEND()

#define r_Config_SCI9_callback_transmitend( ... )    r_Config_SCI9_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI9_callback_transmitendXXXvoid()  r_Config_SCI9_callback_transmitend( void )
#define r_Config_SCI9_callback_transmitendXXX()      U_CONFIG_SCI9_CALLBACK_TRANSMITEND()

#define r_Config_SCI10_callback_transmitend( ... )   r_Config_SCI10_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI10_callback_transmitendXXXvoid() r_Config_SCI10_callback_transmitend( void )
#define r_Config_SCI10_callback_transmitendXXX()     U_CONFIG_SCI10_CALLBACK_TRANSMITEND()

#define r_Config_SCI11_callback_transmitend( ... )   r_Config_SCI11_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI11_callback_transmitendXXXvoid() r_Config_SCI11_callback_transmitend( void )
#define r_Config_SCI11_callback_transmitendXXX()     U_CONFIG_SCI11_CALLBACK_TRANSMITEND()

#define r_Config_SCI12_callback_transmitend( ... )   r_Config_SCI12_callback_transmitendXXX##__VA_ARGS__()
#define r_Config_SCI12_callback_transmitendXXXvoid() r_Config_SCI12_callback_transmitend( void )
#define r_Config_SCI12_callback_transmitendXXX()     U_CONFIG_SCI12_CALLBACK_TRANSMITEND()

#define r_Config_SCI0_callback_receiveend( ... )     r_Config_SCI0_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI0_callback_receiveendXXXvoid()   r_Config_SCI0_callback_receiveend( void )
#define r_Config_SCI0_callback_receiveendXXX()       U_CONFIG_SCI0_CALLBACK_RECEIVEEND()

#define r_Config_SCI1_callback_receiveend( ... )     r_Config_SCI1_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI1_callback_receiveendXXXvoid()   r_Config_SCI1_callback_receiveend( void )
#define r_Config_SCI1_callback_receiveendXXX()       U_CONFIG_SCI1_CALLBACK_RECEIVEEND()

#define r_Config_SCI2_callback_receiveend( ... )     r_Config_SCI2_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI2_callback_receiveendXXXvoid()   r_Config_SCI2_callback_receiveend( void )
#define r_Config_SCI2_callback_receiveendXXX()       U_CONFIG_SCI2_CALLBACK_RECEIVEEND()

#define r_Config_SCI3_callback_receiveend( ... )     r_Config_SCI3_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI3_callback_receiveendXXXvoid()   r_Config_SCI3_callback_receiveend( void )
#define r_Config_SCI3_callback_receiveendXXX()       U_CONFIG_SCI3_CALLBACK_RECEIVEEND()

#define r_Config_SCI4_callback_receiveend( ... )     r_Config_SCI4_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI4_callback_receiveendXXXvoid()   r_Config_SCI4_callback_receiveend( void )
#define r_Config_SCI4_callback_receiveendXXX()       U_CONFIG_SCI4_CALLBACK_RECEIVEEND()

#define r_Config_SCI5_callback_receiveend( ... )     r_Config_SCI5_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI5_callback_receiveendXXXvoid()   r_Config_SCI5_callback_receiveend( void )
#define r_Config_SCI5_callback_receiveendXXX()       U_CONFIG_SCI5_CALLBACK_RECEIVEEND()

#define r_Config_SCI6_callback_receiveend( ... )     r_Config_SCI6_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI6_callback_receiveendXXXvoid()   r_Config_SCI6_callback_receiveend( void )
#define r_Config_SCI6_callback_receiveendXXX()       U_CONFIG_SCI6_CALLBACK_RECEIVEEND()

#define r_Config_SCI7_callback_receiveend( ... )     r_Config_SCI7_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI7_callback_receiveendXXXvoid()   r_Config_SCI7_callback_receiveend( void )
#define r_Config_SCI7_callback_receiveendXXX()       U_CONFIG_SCI7_CALLBACK_RECEIVEEND()

#define r_Config_SCI8_callback_receiveend( ... )     r_Config_SCI8_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI8_callback_receiveendXXXvoid()   r_Config_SCI8_callback_receiveend( void )
#define r_Config_SCI8_callback_receiveendXXX()       U_CONFIG_SCI8_CALLBACK_RECEIVEEND()

#define r_Config_SCI9_callback_receiveend( ... )     r_Config_SCI9_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI9_callback_receiveendXXXvoid()   r_Config_SCI9_callback_receiveend( void )
#define r_Config_SCI9_callback_receiveendXXX()       U_CONFIG_SCI9_CALLBACK_RECEIVEEND()

#define r_Config_SCI10_callback_receiveend( ... )    r_Config_SCI10_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI10_callback_receiveendXXXvoid()  r_Config_SCI10_callback_receiveend( void )
#define r_Config_SCI10_callback_receiveendXXX()      U_CONFIG_SCI10_CALLBACK_RECEIVEEND()

#define r_Config_SCI11_callback_receiveend( ... )    r_Config_SCI11_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI11_callback_receiveendXXXvoid()  r_Config_SCI11_callback_receiveend( void )
#define r_Config_SCI11_callback_receiveendXXX()      U_CONFIG_SCI11_CALLBACK_RECEIVEEND()

#define r_Config_SCI12_callback_receiveend( ... )    r_Config_SCI12_callback_receiveendXXX##__VA_ARGS__()
#define r_Config_SCI12_callback_receiveendXXXvoid()  r_Config_SCI12_callback_receiveend( void )
#define r_Config_SCI12_callback_receiveendXXX()      U_CONFIG_SCI12_CALLBACK_RECEIVEEND()

#endif /* (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || (defined(__cplusplus) && (__cplusplus >= 201103L)) */

#endif
