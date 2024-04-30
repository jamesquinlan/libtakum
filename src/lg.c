/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(lg, log10)

/*
 * This implementation is a bit of a hack by extending the arguments to long double,
 * however this is not enough to always get correct results as you would need around 512
 * fraction bits to cover all cases.
 */
#undef log101p
#undef log101p
#undef log101p

static float
log101pf(float f)
{
	return (float)log10l(1.0L + (long double)f);
}

static double
log101p(double f)
{
	return (double)log10l(1.0L + (long double)f);
}

static long double
log101pl(long double f)
{
	return log10l(1.0L + (long double)f);
}

UTIL_UNARY_FLOAT_WRAPPER(lg_1_plus, log101p)
