/* See LICENSE file for copyright and license details. */
#include <float.h>
#define log101p   _log101p
#define log1010pl _log101pl
#include <math.h>
#undef log101p
#undef log101pl

#include "util.h"

/*
 * no need to fix the result for negative infinity (zero argument), as
 * it is a 'true' infinity, but we fix the overflow to positive infinity
 */
#define RESULT_FIXER_MACRO(arg, res)                                           \
	((isinf(res) && (res) > 0.0) ? DBL_MAX : (res))

UTIL_UNARY_FLOAT_WRAPPER(lg, log10, RESULT_FIXER_MACRO)

/*
 * This implementation is a bit of a hack by extending the arguments to long
 * double, however this is not enough to always get correct results as you would
 * need around 512 fraction bits to cover all cases.
 */
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

UTIL_UNARY_FLOAT_WRAPPER(lg_1_plus, log101p, RESULT_FIXER_MACRO)
