/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include "../takum.h"

#define LB_E  1.4426950408889634073599246810018921374266L
#define LG_E  0.4342944819032518276511289189166050822944L
#define PI    3.1415926535897932384626433832795028841972L
#define SQRTE 1.6487212707001281468486507878141635716538L

#undef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#undef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

/*
 * Even though just in regard to the number of significand digits we could
 * use float32 for both takum8 and takum16, float32 has insufficient dynamic
 * range in both cases.
 */
#define UTIL_UNARY_FLOAT_TAKUM_WRAPPER(NAME, FLOAT_FUNCTION,                   \
                                       RESULT_FIXER_MACRO)                     \
	takum8 takum8_##NAME(takum8 t)                                         \
	{                                                                      \
		long double arg = takum8_to_extended_float(t),                 \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return takum8_from_extended_float(                             \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	takum16 takum16_##NAME(takum16 t)                                      \
	{                                                                      \
		long double arg = takum16_to_extended_float(t),                \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return takum16_from_extended_float(                            \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	takum32 takum32_##NAME(takum32 t)                                      \
	{                                                                      \
		long double arg = takum32_to_extended_float(t),                \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return takum32_from_extended_float(                            \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	takum64 takum64_##NAME(takum64 t)                                      \
	{                                                                      \
		long double arg = takum64_to_extended_float(t),                \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return takum64_from_extended_float(                            \
			RESULT_FIXER_MACRO(arg, res));                         \
	}

#define UTIL_UNARY_FLOAT_TAKUM_LINEAR_WRAPPER(NAME, FLOAT_FUNCTION,            \
                                              RESULT_FIXER_MACRO)              \
	takum_linear8 takum_linear8_##NAME(takum_linear8 t)                    \
	{                                                                      \
		double arg = takum_linear8_to_float64(t),                      \
		       res = FLOAT_FUNCTION(arg);                              \
                                                                               \
		return takum_linear8_from_float64(                             \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	takum_linear16 takum_linear16_##NAME(takum_linear16 t)                 \
	{                                                                      \
		double arg = takum_linear16_to_float64(t),                     \
		       res = FLOAT_FUNCTION(arg);                              \
                                                                               \
		return takum_linear16_from_float64(                            \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	takum_linear32 takum_linear32_##NAME(takum_linear32 t)                 \
	{                                                                      \
		double arg = takum_linear32_to_float64(t),                     \
		       res = FLOAT_FUNCTION(arg);                              \
                                                                               \
		return takum_linear32_from_float64(                            \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	takum_linear64 takum_linear64_##NAME(takum_linear64 t)                 \
	{                                                                      \
		long double arg = takum_linear64_to_extended_float(t),         \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return takum_linear64_from_extended_float(                     \
			RESULT_FIXER_MACRO(arg, res));                         \
	}

#define UTIL_BINARY_FLOAT_TAKUM_WRAPPER(NAME, FLOAT_FUNCTION,                  \
                                        RESULT_FIXER_MACRO)                    \
	takum8 takum8_##NAME(takum8 a, takum8 b)                               \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = takum8_to_extended_float(a);                              \
		fb = takum8_to_extended_float(b);                              \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return takum8_from_extended_float(                             \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	takum16 takum16_##NAME(takum16 a, takum16 b)                           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = takum16_to_extended_float(a);                             \
		fb = takum16_to_extended_float(b);                             \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return takum16_from_extended_float(                            \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	takum32 takum32_##NAME(takum32 a, takum32 b)                           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = takum32_to_extended_float(a);                             \
		fb = takum32_to_extended_float(b);                             \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return takum32_from_extended_float(                            \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	takum64 takum64_##NAME(takum64 a, takum64 b)                           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = takum64_to_extended_float(a);                             \
		fb = takum64_to_extended_float(b);                             \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return takum64_from_extended_float(                            \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}

#define UTIL_BINARY_FLOAT_TAKUM_LINEAR_WRAPPER(NAME, FLOAT_FUNCTION,           \
                                               RESULT_FIXER_MACRO)             \
	takum_linear8 takum_linear8_##NAME(takum_linear8 a, takum_linear8 b)   \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = takum_linear8_to_float64(a);                              \
		fb = takum_linear8_to_float64(b);                              \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return takum_linear8_from_float64(                             \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	takum_linear16 takum_linear16_##NAME(takum_linear16 a,                 \
	                                     takum_linear16 b)                 \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = takum_linear16_to_float64(a);                             \
		fb = takum_linear16_to_float64(b);                             \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return takum_linear16_from_float64(                            \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	takum_linear32 takum_linear32_##NAME(takum_linear32 a,                 \
	                                     takum_linear32 b)                 \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = takum_linear32_to_float64(a);                             \
		fb = takum_linear32_to_float64(b);                             \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return takum_linear32_from_float64(                            \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	takum_linear64 takum_linear64_##NAME(takum_linear64 a,                 \
	                                     takum_linear64 b)                 \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = takum_linear64_to_extended_float(a);                      \
		fb = takum_linear64_to_extended_float(b);                      \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return takum_linear64_from_extended_float(                     \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}

/* type punning unions */
union util_takum8_union {
	int8_t value;
	uint8_t bits;
};

union util_takum16_union {
	int16_t value;
	uint16_t bits;
};

union util_takum32_union {
	int32_t value;
	uint32_t bits;
};

union util_takum64_union {
	int64_t value;
	uint64_t bits;
};

#endif
