/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(2_raised, exp2)

/*
 * This implementation is a bit of a hack by extending the arguments to long
 * double, however this is not enough to always get correct results as you would
 * need around 512 fraction bits to cover all cases.
 */
static float
two_raised_minus_1f(float f)
{
	return (float)(exp2l((long double)f) - 1.0L);
}

static double
two_raised_minus_1(double f)
{
	return (double)(exp2l((long double)f) - 1.0L);
}

static long double
two_raised_minus_1l(long double f)
{
	return exp2l(f) - 1.0L;
}

UTIL_UNARY_FLOAT_WRAPPER(2_raised_minus_1, two_raised_minus_1)
