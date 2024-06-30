/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "../takum.h"

#include "codec.h"
#include "util.h"

/* Conversion from float32 */
takum8
takum8_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM8_NAR;
	} else {
		return codec_takum8_from_s_and_l(f < 0, 2 * logf(fabsf(f)));
	}
}

takum16
takum16_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM16_NAR;
	} else {
		return codec_takum16_from_s_and_l(f < 0, 2 * logf(fabsf(f)));
	}
}

takum32
takum32_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM32_NAR;
	} else {
		return codec_takum32_from_s_and_l(f < 0,
		                                  (double)(2 * logf(fabsf(f))));
	}
}

takum64
takum64_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM64_NAR;
	} else {
		return takum64_from_takum32(codec_takum32_from_s_and_l(
			f < 0, (long double)(2 * logf(fabsf(f)))));
	}
}

/* Conversion from float64 */
takum8
takum8_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM8_NAR;
	} else {
		return takum8_from_takum32(
			codec_takum32_from_s_and_l(f < 0, 2 * log(fabs(f))));
	}
}

takum16
takum16_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM16_NAR;
	} else {
		return takum16_from_takum32(
			codec_takum32_from_s_and_l(f < 0, 2 * log(fabs(f))));
	}
}

takum32
takum32_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM32_NAR;
	} else {
		return codec_takum32_from_s_and_l(f < 0, 2 * log(fabs(f)));
	}
}

takum64
takum64_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM64_NAR;
	} else {
		return codec_takum64_from_s_and_l(
			f < 0, (long double)(2 * log(fabs(f))));
	}
}

/* Conversion from extended float */
takum8
takum8_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM8_NAR;
	} else {
		return takum8_from_takum64(
			codec_takum64_from_s_and_l(f < 0, 2 * logl(fabsl(f))));
	}
}

takum16
takum16_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM16_NAR;
	} else {
		return takum16_from_takum64(
			codec_takum64_from_s_and_l(f < 0, 2 * logl(fabsl(f))));
	}
}

takum32
takum32_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM32_NAR;
	} else {
		return takum32_from_takum64(
			codec_takum64_from_s_and_l(f < 0, 2 * logl(fabsl(f))));
	}
}

takum64
takum64_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return TAKUM64_NAR;
	} else {
		return codec_takum64_from_s_and_l(f < 0, 2 * logl(fabsl(f)));
	}
}

/* Conversion to float32 */
float
takum8_to_float32(takum8 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) * powf(SQRTE, codec_takum8_to_l(t));
}

float
takum16_to_float32(takum16 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(SQRTE, codec_takum16_to_l(t));
}

float
takum32_to_float32(takum32 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(SQRTE, (float)codec_takum32_to_l(t));
}

float
takum64_to_float32(takum64 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(SQRTE, (float)codec_takum64_to_l(t));
}

/* Conversion to float64 */
double
takum8_to_float64(takum8 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       pow(SQRTE, (double)codec_takum8_to_l(t));
}

double
takum16_to_float64(takum16 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       pow(SQRTE, (double)codec_takum16_to_l(t));
}

double
takum32_to_float64(takum32 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) * pow(SQRTE, codec_takum32_to_l(t));
}

double
takum64_to_float64(takum64 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       pow(SQRTE, (double)codec_takum64_to_l(t));
}

/* Conversion to extended float */
long double
takum8_to_extended_float(takum8 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(SQRTE, (long double)codec_takum8_to_l(t));
}

long double
takum16_to_extended_float(takum16 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(SQRTE, (long double)codec_takum16_to_l(t));
}

long double
takum32_to_extended_float(takum32 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(SQRTE, (long double)codec_takum32_to_l(t));
}

long double
takum64_to_extended_float(takum64 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(SQRTE, codec_takum64_to_l(t));
}
