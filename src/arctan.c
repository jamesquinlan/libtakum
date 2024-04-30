/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(arctan, atan)

/*
 * We extend to long double and multiply the argument with pi, returning a rounded long double.
 * arctanpil() is still good enough as we have at least 5 bits of wiggle room anyway.
 */
static float
arctanpif(float f)
{
	return (float)(atanl((long double)f) / PI);
}

static double
arctanpi(double f)
{
	return (double)(atanl((long double)f) / PI);
}

static long double
arctanpil(long double f)
{
	return atanl(f) / PI;
}

UTIL_UNARY_FLOAT_WRAPPER(arctan_over_pi, arctanpi)
