/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

/*
 * Define exp10 using pow
 */
static float
ten_raisedf(float f)
{
	return (float)powl(10.0L, (long double)f);
}

static double
ten_raised(double f)
{
	return (double)powl(10.0L, (long double)f);
}

static long double
ten_raisedl(long double f)
{
	return powl(10.0L, f);
}

UTIL_UNARY_FLOAT_WRAPPER(10_raised, ten_raised)

/*
 * This implementation is a bit of a hack by extending the arguments to long double,
 * however this is not enough to always get correct results as you would need around 512
 * fraction bits to cover all cases.
 */
static float
ten_raised_minus_1f(float f)
{
	return (float)(powl(10.0L, (long double)f) - 1.0L);
}

static double
ten_raised_minus_1(double f)
{
	return (double)(powl(10.0L, (long double)f) - 1.0L);
}

static long double
ten_raised_minus_1l(long double f)
{
	return powl(10.0L, f) - 1.0L;
}

UTIL_UNARY_FLOAT_WRAPPER(10_raised_minus_1, ten_raised_minus_1)
