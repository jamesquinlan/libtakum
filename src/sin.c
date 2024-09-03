/* See LICENSE file for copyright and license details. */
#define sinpi  _sinpi
#define sinpil _sinpil
#include <math.h>
#undef sinpi
#undef sinpil

#include "util.h"

/* no need to fix the result */
#define RESULT_FIXER_MACRO(arg, res) (res)

UTIL_UNARY_FLOAT_WRAPPER(sin, sin, RESULT_FIXER_MACRO)

/*
 * We extend to long double and multiply the argument with pi, returning a
 * rounded long double. sinpil() is still good enough as we have at least 5 bits
 * of wiggle room anyway.
 */
static long double
sinpil(long double f)
{
	return sinl(PI * f);
}

static double
sinpi(double f)
{
	return (double)sinpil((long double)f);
}

UTIL_UNARY_FLOAT_WRAPPER(sin_pi_times, sinpi, RESULT_FIXER_MACRO)
