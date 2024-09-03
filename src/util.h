/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include "../takum.h"

#define SQRTE 1.6487212707001281468486507878141635716538L
#define PI    3.1415926535897932384626433832795028841972L

#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

/*
 * Even though just in regard to the number of significand digits we could
 * use float32 for both takum8 and takum16, float32 has insufficient dynamic
 * range in both cases.
 */
#define UTIL_UNARY_FLOAT_WRAPPER(NAME, FLOAT_FUNCTION, RESULT_FIXER_MACRO)     \
	takum8 takum8_##NAME(takum8 t)                                         \
	{                                                                      \
		double arg = takum8_to_float64(t), res = FLOAT_FUNCTION(arg);  \
                                                                               \
		return takum8_from_float64(RESULT_FIXER_MACRO(arg, res));      \
	}                                                                      \
                                                                               \
	takum16 takum16_##NAME(takum16 t)                                      \
	{                                                                      \
		double arg = takum16_to_float64(t), res = FLOAT_FUNCTION(arg); \
                                                                               \
		return takum16_from_float64(RESULT_FIXER_MACRO(arg, res));     \
	}                                                                      \
                                                                               \
	takum32 takum32_##NAME(takum32 t)                                      \
	{                                                                      \
		double arg = takum32_to_float64(t), res = FLOAT_FUNCTION(arg); \
                                                                               \
		return takum32_from_float64(RESULT_FIXER_MACRO(arg, res));     \
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

#define UTIL_BINARY_FLOAT_WRAPPER(NAME, FLOAT_FUNCTION, RESULT_FIXER_MACRO)    \
	takum8 takum8_##NAME(takum8 a, takum8 b)                               \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = takum8_to_float64(a);                                     \
		fb = takum8_to_float64(b);                                     \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return takum8_from_float64(RESULT_FIXER_MACRO(fa, fb, res));   \
	}                                                                      \
                                                                               \
	takum16 takum16_##NAME(takum16 a, takum16 b)                           \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = takum16_to_float64(a);                                    \
		fb = takum16_to_float64(b);                                    \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return takum16_from_float64(RESULT_FIXER_MACRO(fa, fb, res));  \
	}                                                                      \
                                                                               \
	takum32 takum32_##NAME(takum32 a, takum32 b)                           \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = takum32_to_float64(a);                                    \
		fb = takum32_to_float64(b);                                    \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return takum32_from_float64(RESULT_FIXER_MACRO(fa, fb, res));  \
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

#endif
