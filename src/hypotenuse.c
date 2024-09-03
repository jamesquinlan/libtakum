/* See LICENSE file for copyright and license details. */
#include <float.h>
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

/* fix overflow in the result */
#define RESULT_FIXER_MACRO(a, b, res) (isinf(res) ? DBL_MAX : (res))

UTIL_BINARY_FLOAT_WRAPPER(hypotenuse, hypotenuse, RESULT_FIXER_MACRO)
