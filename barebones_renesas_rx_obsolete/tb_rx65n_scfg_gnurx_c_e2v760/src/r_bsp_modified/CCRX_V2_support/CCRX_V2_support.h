#ifndef CCRX_V2_SUPPORT_H
#define CCRX_V2_SUPPORT_H

#if defined(__CCRX__) && defined(__RENESAS_VERSION__) && (__RENESAS_VERSION__ < 0x02050000)

#ifdef __cplusplus
extern "C" {
#endif

void __bclr(unsigned char *data, unsigned long bit);
void __bset(unsigned char *data, unsigned long bit);
void __bnot(unsigned char *data, unsigned long bit);

#ifdef __cplusplus
}
#endif

#endif

#endif
