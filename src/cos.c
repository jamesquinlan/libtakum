/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(cos, cos)

/*
 * We extend to long double and multiply the argument with pi, returning a rounded long double.
 * sinpil() is still good enough as we have at least 5 bits of wiggle room anyway.
 */
static float
cospif(float f)
{
	return (float)cosl(PI * (long double)f);
}

static double
cospi(double f)
{
	return (double)cosl(PI * (long double)f);
}

static long double
cospil(long double f)
{
	return cosl(PI * f);
}

UTIL_UNARY_FLOAT_WRAPPER(cos_pi_times, cospi)
