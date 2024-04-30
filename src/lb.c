/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(lb, log2)

/*
 * This implementation is a bit of a hack by extending the arguments to long double,
 * however this is not enough to always get correct results as you would need around 512
 * fraction bits to cover all cases.
 */
#undef log21p
#undef log21p
#undef log21p

static float
log21pf(float f)
{
	return (float)log2l(1.0L + (long double)f);
}

static double
log21p(double f)
{
	return (double)log2l(1.0L + (long double)f);
}

static long double
log21pl(long double f)
{
	return log2l(1.0L + (long double)f);
}

UTIL_UNARY_FLOAT_WRAPPER(lb_1_plus, log21p)
