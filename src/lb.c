/* See LICENSE file for copyright and license details. */
#include <float.h>
#define log21p  _log21p
#define log21pl _log21pl
#include <math.h>
#undef log21p
#undef log21pl

#include "util.h"

/*
 * no need to fix the result for negative infinity (zero argument), as
 * it is a 'true' infinity, but we fix the overflow to positive infinity
 */
#define RESULT_FIXER_MACRO(arg, res)                                           \
	((isinf(res) && (res) > 0.0) ? DBL_MAX : (res))

UTIL_UNARY_FLOAT_WRAPPER(lb, log2, RESULT_FIXER_MACRO)

/*
 * This implementation is a bit of a hack by extending the arguments to long
 * double, however this is not enough to always get correct results as you would
 * need around 512 fraction bits to cover all cases.
 */
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

UTIL_UNARY_FLOAT_WRAPPER(lb_1_plus, log21p, RESULT_FIXER_MACRO)
