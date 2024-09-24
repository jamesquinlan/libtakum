/* See LICENSE file for copyright and license details. */
#include <math.h>
#include <stdint.h>

#include "../takum.h"

#include "codec.h"
#include "util.h"

/*
 * The case NaR is automatically covered given NaN/n=NaN holds for any n.
 *
 * We use a 64 bit integer as a possible base root as even the smallest
 * positive l (which is 2^(-n+5)) divided by the largest signed 64
 * bit integer (2^63-1) is still within the dynamic range of float32,
 * let alone float64, which means that there will never be underflows
 * in terms of l. Of course the final takum representation may underflow
 * to 1.0 in the process.
 * Using different integer types for each takum bit string length would
 * serve no purpose other than to complicate the API. We allow signed n
 * as there is no reason not to.
 */
takum8
takum8_integer_root(takum8 t, int64_t n)
{
	if ((t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return TAKUM8_NAR;
	} else {
		return codec_takum8_from_s_and_l((t < 0),
		                                 codec_takum8_to_l(t) / n);
	}
}

takum16
takum16_integer_root(takum16 t, int64_t n)
{
	if ((t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return TAKUM16_NAR;
	} else {
		return codec_takum16_from_s_and_l((t < 0),
		                                  codec_takum16_to_l(t) / n);
	}
}

takum32
takum32_integer_root(takum32 t, int64_t n)
{
	if ((t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return TAKUM32_NAR;
	} else {
		return codec_takum32_from_s_and_l((t < 0),
		                                  codec_takum32_to_l(t) / n);
	}
}

takum64
takum64_integer_root(takum64 t, int64_t n)
{
	if ((t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return TAKUM64_NAR;
	} else {
		return codec_takum64_from_s_and_l((t < 0),
		                                  codec_takum64_to_l(t) / n);
	}
}