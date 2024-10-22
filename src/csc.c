/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

/*
 * near the pole in 0, the results of csc() never overflow. Thus any infinity
 * returned by csc() is a 'true' infinity.
 */
#define RESULT_FIXER_MACRO(arg, res) (res)

static long double
cscl(long double f)
{
	return 1.0l / sinl(f);
}

static double
csc(double f)
{
	return (double)cscl((long double)f);
}

UTIL_UNARY_FLOAT_TAKUM_WRAPPER(csc, csc, RESULT_FIXER_MACRO)
UTIL_UNARY_FLOAT_TAKUM_LINEAR_WRAPPER(csc, csc, RESULT_FIXER_MACRO)

static long double
csc_pi_timesl(long double f)
{
	return cscl(PI * f);
}

static double
csc_pi_times(double f)
{
	return (double)csc_pi_timesl((long double)f);
}

UTIL_UNARY_FLOAT_TAKUM_WRAPPER(csc_pi_times, csc_pi_times, RESULT_FIXER_MACRO)
UTIL_UNARY_FLOAT_TAKUM_LINEAR_WRAPPER(csc_pi_times, csc_pi_times,
                                      RESULT_FIXER_MACRO)
