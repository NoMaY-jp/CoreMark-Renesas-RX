#if defined(__CCRX__) && defined(__RENESAS_VERSION__) && (__RENESAS_VERSION__ < 0x02050000)
#include "CCRX_V2_support.h"
#pragma inline_asm ___bclr
#pragma inline_asm ___bset
#pragma inline_asm ___bnot
static void ___bclr(void);
static void ___bset(void);
static void ___bnot(void);
static void ___bclr(void) { bclr r2, [r1] }
static void ___bset(void) { bset r2, [r1] }
static void ___bnot(void) { bnot r2, [r1] }
void __bclr(unsigned char *data, unsigned long bit) { (void)data; (void)bit; ___bclr(); }
void __bset(unsigned char *data, unsigned long bit) { (void)data; (void)bit; ___bset(); }
void __bnot(unsigned char *data, unsigned long bit) { (void)data; (void)bit; ___bnot(); }
#endif
