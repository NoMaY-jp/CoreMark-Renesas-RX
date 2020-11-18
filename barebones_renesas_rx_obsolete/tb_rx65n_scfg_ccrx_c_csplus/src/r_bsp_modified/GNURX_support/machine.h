#ifndef MACHINE_H
#define MACHINE_H

#if defined(__CCRX__)

#error "This machine.h cannot be used with the CC-RX compiler."

#else

#define max(x, y) R_BSP_MAX(x, y)
#define min(x, y) R_BSP_MIN(x, y)

#define revl(x) R_BSP_REVL(x)
#define revw(x) R_BSP_REVW(x)

#define xchg(x, y) R_BSP_EXCHANGE(x, y)

#if defined(__GNUC__)
#define rmpab(w, x, y, z) R_BSP_RMPAB(w, x, y, z)
#define rmpaw(w, x, y, z) R_BSP_RMPAW(w, x, y, z)
#define rmpal(w, x, y, z) R_BSP_RMPAL(w, x, y, z)
#elif defined(__ICCRX__)
/* The rmpab(w, x, y, z) exists. */
/* The rmpaw(w, x, y, z) exists. */
/* The rmpal(w, x, y, z) exists. */
#endif

#define rolc(x) R_BSP_ROLC(x)
#define rorc(x) R_BSP_RORC(x)
#define rotl(x, y) R_BSP_ROTL(x, y)
#define rotr(x, y) R_BSP_ROTR(x, y)

#define brk()  R_BSP_BRK()
#define int_exception(x) R_BSP_INT(x)
#define wait() R_BSP_WAIT() /* This is the same definition in the r_cg_macrodriver.h */
#define nop()  R_BSP_NOP()  /* This is the same definition in the r_cg_macrodriver.h */

#define set_ipl(x) R_BSP_SET_IPL(x)
#define get_ipl()  R_BSP_GET_IPL()

#define set_psw(x) R_BSP_SET_PSW(x)
#define get_psw()  R_BSP_GET_PSW()

#define set_fpsw(x) R_BSP_SET_FPSW(x)
#define get_fpsw()  R_BSP_GET_FPSW()

#define set_usp(x) R_BSP_SET_USP(x)
#if defined(__GNUC__)
/* The cast '(unsigned long)' is additionally inserted to prevent the following warning.
 * warning: cast from function call of type 'int' to non-matching type 'void *' [-Wbad-function-cast]
 */
#define get_usp()  (void *)(unsigned long)__builtin_rx_mvfc(0x2)
#elif defined(__ICCRX__)
#define get_usp()  R_BSP_GET_USP()
#endif

#define set_isp(x) R_BSP_SET_ISP(x)
#if defined(__GNUC__)
/* The cast '(unsigned long)' is additionally inserted to prevent the following warning.
 * warning: cast from function call of type 'int' to non-matching type 'void *' [-Wbad-function-cast]
 */
#define get_isp()  (void *)(unsigned long)__builtin_rx_mvfc(0xA)
#elif defined(__ICCRX__)
#define get_isp()  R_BSP_GET_ISP()
#endif

#define set_intb(x) R_BSP_SET_INTB(x)
#if defined(__GNUC__)
/* The cast '(unsigned long)' is additionally inserted to prevent the following warning.
 * warning: cast from function call of type 'int' to non-matching type 'void *' [-Wbad-function-cast]
 */
#define get_intb()  (void *)(unsigned long)__builtin_rx_mvfc(0xC)
#elif defined(__ICCRX__)
#define get_intb()  R_BSP_GET_INTB()
#endif

#define set_bpsw(x) R_BSP_SET_BPSW(x)
#define get_bpsw()  R_BSP_GET_BPSW()

#define set_bpc(x) R_BSP_SET_BPC(x)
#if defined(__GNUC__)
/* The cast '(unsigned long)' is additionally inserted to prevent the following warning.
 * warning: cast from function call of type 'int' to non-matching type 'void *' [-Wbad-function-cast]
 */
#define get_bpc()  (void *)(unsigned long)__builtin_rx_mvfc(0x9)
#elif defined(__ICCRX__)
#define get_bpc()  R_BSP_GET_BPC()
#endif

#define set_fintv(x) R_BSP_SET_FINTV(x)
#if defined(__GNUC__)
/* The cast '(unsigned long)' is additionally inserted to prevent the following warning.
 * warning: cast from function call of type 'int' to non-matching type 'void *' [-Wbad-function-cast]
 */
#define get_fintv()  (void *)(unsigned long)__builtin_rx_mvfc(0xB)
#elif defined(__ICCRX__)
#define get_fintv()  R_BSP_GET_FINTV()
#endif

#define emul(x, y)  R_BSP_EMUL(x, y)
#define emulu(x, y) R_BSP_EMULU(x, y)

#define chg_pmusr() R_BSP_CHG_PMUSR()

#define set_acc(x) R_BSP_SET_ACC(x)
#define get_acc(x) R_BSP_GET_ACC(x)

#define setpsw_i() R_BSP_SETPSW_I()
#define clrpsw_i() R_BSP_CLRPSW_I()

#define macl(x, y, z)  R_BSP_MACL(x, y, z)
#define macw1(x, y, z) R_BSP_MACW1(x, y, z)
#define macw2(x, y, z) R_BSP_MACW2(x, y, z)

#define set_extb(x) R_BSP_SET_EXTB(x)
#if defined(__GNUC__)
/* The cast '(unsigned long)' is additionally inserted to prevent the following warning.
 * warning: cast from function call of type 'int' to non-matching type 'void *' [-Wbad-function-cast]
 */
#define get_extb()  (void *)(unsigned long)__builtin_rx_mvfc(0xD)
#elif defined(__ICCRX__)
#define get_extb()  R_BSP_GET_EXTB()
#endif

#define __bclr(x, y) R_BSP_BIT_CLEAR(x, y)
#define __bset(x, y) R_BSP_BIT_SET(x, y)
#define __bnot(x, y) R_BSP_BIT_REVERSE(x, y)

#ifdef BSP_MCU_DOUBLE_PRECISION_FLOATING_POINT
#ifdef __DPFPU

#define __set_dpsw(x) R_BSP_SET_DPSW(x)
#define __get_dpsw()  R_BSP_GET_DPSW(x)

#define __set_decnt(x) R_BSP_SET_DECNT(x)
#define __get_decnt()  R_BSP_GET_DECNT(x)

#define __set_depc(x) R_BSP_SET_DEPC(x)
#define __get_depc()  R_BSP_GET_DEPC(x)

#define __init_tfu() R_BSP_INIT_TFU()

#endif
#endif

#endif

#endif
