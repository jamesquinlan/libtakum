/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

static double
hypotenuse(double a, float b)
{
	return sqrt(a * a + b * b);
}

static long double
hypotenusel(long double a, long double b)
{
	return sqrtl(a * a + b * b);
}

UTIL_BINARY_FLOAT_WRAPPER(hypotenuse, hypotenuse)
