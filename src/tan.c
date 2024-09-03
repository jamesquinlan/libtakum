/* See LICENSE file for copyright and license details. */
#include <float.h>
#define tanpi  _tanpi
#define tanpil _tanpil
#include <math.h>
#undef tanpi
#undef tanpil

#include "util.h"

/*
 * near the poles, the results of tan() never overflow. Thus any infinity
 * returned by tan() is a 'true' infinity.
 */
#define RESULT_FIXER_MACRO(arg, res) (res)

UTIL_UNARY_FLOAT_WRAPPER(tan, tan, RESULT_FIXER_MACRO)

/*
 * We extend to long double and multiply the argument with pi, returning a
 * rounded long double. tanpil() is still good enough as we have at least 5 bits
 * of wiggle room anyway.
 *
 * We have to be careful with the poles, as we can directly hit them
 * with our arguments, requiring a special check.
 */
static long double
tanpil(long double f)
{
	return (fmodl(f, 1.0) == 0.5) ? NAN : tanl(PI * f);
}

static double
tanpi(double f)
{
	return (double)tanpil((long double)f);
}

UTIL_UNARY_FLOAT_WRAPPER(tan_pi_times, tanpi, RESULT_FIXER_MACRO)
