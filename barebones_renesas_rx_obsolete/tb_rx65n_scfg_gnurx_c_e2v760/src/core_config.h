#define ITERATIONS 8000
#define CLOCKS_PER_SEC 120000000UL

#if defined(__CCRX__)

#define COMPILER_VERSION "CC-RX V2.03"
#define FLAGS_STR "-optimize=max -speed -goptimize"

#elif defined(__GNUC__)

#define COMPILER_VERSION "GNURX 2019q4(8.3.0.201904)"
#define FLAGS_STR "-O3"

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
