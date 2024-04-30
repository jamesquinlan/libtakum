/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(sin, sin)

/*
 * We extend to long double and multiply the argument with pi, returning a
 * rounded long double. sinpil() is still good enough as we have at least 5 bits
 * of wiggle room anyway.
 */
static float
sinpif(float f)
{
	return (float)sinl(PI * (long double)f);
}

static double
sinpi(double f)
{
	return (double)sinl(PI * (long double)f);
}

static long double
sinpil(long double f)
{
	return sinl(PI * f);
}

UTIL_UNARY_FLOAT_WRAPPER(sin_pi_times, sinpi)
