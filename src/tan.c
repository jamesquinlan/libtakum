/* See LICENSE file for copyright and license details. */
#define tanpi  _tanpi
#define tanpil _tanpil
#include <math.h>
#undef tanpi
#undef tanpil

#include "util.h"

UTIL_UNARY_FLOAT_WRAPPER(tan, tan)

/*
 * We extend to long double and multiply the argument with pi, returning a
 * rounded long double. sinpil() is still good enough as we have at least 5 bits
 * of wiggle room anyway.
 */
static double
tanpi(double f)
{
	return (double)tanl(PI * (long double)f);
}

static long double
tanpil(long double f)
{
	return tanl(PI * f);
}

UTIL_UNARY_FLOAT_WRAPPER(tan_pi_times, tanpi)
