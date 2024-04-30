/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

UTIL_BINARY_FLOAT_WRAPPER(arctan2, atan2)

/*
 * We extend to long double and multiply the argument with pi, returning a rounded long double.
 * arctan2pil() is still good enough as we have at least 5 bits of wiggle room anyway.
 */
static float
arctan2pif(float a, float b)
{
	return (float)(atan2l((long double)a, (long double)b) / PI);
}

static double
arctan2pi(double a, double b)
{
	return (double)(atan2l((long double)a, (long double)b) / PI);
}

static long double
arctan2pil(long double a, long double b)
{
	return atan2l(a, b) / PI;
}

UTIL_BINARY_FLOAT_WRAPPER(arctan2_over_pi, arctan2pi)
