#ifndef PORTME_CONFIG_H
#define PORTME_CONFIG_H

#include "portme_helper.h"

#if defined(__CCRX__)

#define COMPILER_VERSION "CC-RX V3.02"
#define FLAGS_STR "-optimize=max -speed -goptimize"

#elif defined(__GNUC__)

#define COMPILER_VERSION "GNURX 2020q4(8.3.0.202004)"
#define FLAGS_STR "-O3"

#elif defined(__ICCRX__)

#define COMPILER_VERSION "ICCRX V4.14.1"
#define FLAGS_STR "-Ohs --no_size_constraints"

#endif

#define HAS_FLOAT 1
#define HAS_TIME_H 0
#define USE_CLOCK 1
#define HAS_STDIO 0
#define HAS_PRINTF 0
#define MAIN_HAS_NOARGC 1
#define MAIN_HAS_NORETURN 1
#define COMPILER_REQUIRES_SORT_RETURN 0

#define VALIDATION_RUN 0
#define PERFORMANCE_RUN 1
#define PROFILE_RUN 0
#define CORE_DEBUG 0

#define CLOCKS_PER_SEC RX_MCU_TIMER_CLK

#if RX_MCU_RUN_CLK == 240000000UL

#define ITERATIONS 16000

#elif RX_MCU_RUN_CLK == 120000000UL

#define ITERATIONS 8000

#elif RX_MCU_RUN_CLK == 54000000UL

#define ITERATIONS 4000

#elif RX_MCU_RUN_CLK == 32000000UL

#define ITERATIONS 2000

#else

#error "Currently the specified RX MCU Run Clock is not supported. Please modify the code here."

#endif

#endif /* CORE_CONFIG_H */
