/* See LICENSE file for copyright and license details. */
#include "../takum.h"

#include "util.h"

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
