/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

/* no need to fix the result */
#define RESULT_FIXER_MACRO(arg, res) (res)

UTIL_UNARY_FLOAT_WRAPPER(arcsin, asin, RESULT_FIXER_MACRO)

/*
 * We extend to long double and multiply the argument with pi, returning a
 * rounded long double. arcsinpil() is still good enough as we have at least 5
 * bits of wiggle room anyway.
 */
static double
arcsinpi(double f)
{
	return (double)(asinl((long double)f) / PI);
}

static long double
arcsinpil(long double f)
{
	return asinl(f) / PI;
}

UTIL_UNARY_FLOAT_WRAPPER(arcsin_over_pi, arcsinpi, RESULT_FIXER_MACRO)
