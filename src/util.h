/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include "../takum.h"

#define SQRTE 1.6487212707001281468486507878141635716538L
#define PI    3.1415926535897932384626433832795028841972L

#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

#define UTIL_UNARY_FLOAT_WRAPPER(NAME, FLOATFUNC)                              \
	takum8 takum8_##NAME(takum8 t)                                         \
	{                                                                      \
		return takum8_from_float32(                                    \
			FLOATFUNC##f(takum8_to_float32(t)));                   \
	}                                                                      \
                                                                               \
	takum16 takum16_##NAME(takum16 t)                                      \
	{                                                                      \
		return takum16_from_float32(                                   \
			FLOATFUNC##f(takum16_to_float32(t)));                  \
	}                                                                      \
                                                                               \
	takum32 takum32_##NAME(takum32 t)                                      \
	{                                                                      \
		return takum32_from_float64(FLOATFUNC(takum32_to_float64(t))); \
	}                                                                      \
                                                                               \
	takum64 takum64_##NAME(takum64 t)                                      \
	{                                                                      \
		return takum64_from_extended_float(                            \
			FLOATFUNC##l(takum64_to_extended_float(t)));           \
	}

#define UTIL_BINARY_FLOAT_WRAPPER(NAME, FLOATFUNC)                             \
	takum8 takum8_##NAME(takum8 a, takum8 b)                               \
	{                                                                      \
		float fa, fb;                                                  \
                                                                               \
		fa = takum8_to_float32(a);                                     \
		fb = takum8_to_float32(b);                                     \
                                                                               \
		return takum8_from_float32(FLOATFUNC##f(fa, fb));              \
	}                                                                      \
                                                                               \
	takum16 takum16_##NAME(takum16 a, takum16 b)                           \
	{                                                                      \
		float fa, fb;                                                  \
                                                                               \
		fa = takum16_to_float32(a);                                    \
		fb = takum16_to_float32(b);                                    \
                                                                               \
		return takum16_from_float32(FLOATFUNC##f(fa, fb));             \
	}                                                                      \
                                                                               \
	takum32 takum32_##NAME(takum32 a, takum32 b)                           \
	{                                                                      \
		double fa, fb;                                                 \
                                                                               \
		fa = takum32_to_float64(a);                                    \
		fb = takum32_to_float64(b);                                    \
                                                                               \
		return takum32_from_float64(FLOATFUNC(fa, fb));                \
	}                                                                      \
                                                                               \
	takum64 takum64_##NAME(takum64 a, takum64 b)                           \
	{                                                                      \
		long double fa, fb;                                            \
                                                                               \
		fa = takum64_to_extended_float(a);                             \
		fb = takum64_to_extended_float(b);                             \
                                                                               \
		return takum64_from_extended_float(FLOATFUNC##l(fa, fb));      \
	}

#endif
