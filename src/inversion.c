/* See LICENSE file for copyright and license details. */
#include "../takum.h"

#include "util.h"

takum8
takum8_inversion(takum8 t)
{
	union util_takum8_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT8_C(0x7f)) + 1;

	return (t == TAKUM8_NAR) ? TAKUM8_NAR : out.value;
}

takum16
takum16_inversion(takum16 t)
{
	union util_takum16_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT16_C(0x7fff)) + 1;

	return (t == TAKUM16_NAR) ? TAKUM16_NAR : out.value;
}

takum32
takum32_inversion(takum32 t)
{
	union util_takum32_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT32_C(0x7fffffff)) + 1;

	return (t == TAKUM32_NAR) ? TAKUM32_NAR : out.value;
}

takum64
takum64_inversion(takum64 t)
{
	union util_takum64_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT64_C(0x7fffffffffffffff)) + 1;

	return (t == TAKUM64_NAR) ? TAKUM64_NAR : out.value;
}

/* no need to fix the result, as inv(0)=inf yields NaR without our doing */
#define RESULT_FIXER_MACRO(arg, res) (res)

static long double
inversionl(long double f)
{
	return 1.0l / f;
}

static double
inversion(double f)
{
	return (double)inversionl((long double)f);
}

UTIL_UNARY_FLOAT_TAKUM_LINEAR_WRAPPER(inversion, inversion, RESULT_FIXER_MACRO)
