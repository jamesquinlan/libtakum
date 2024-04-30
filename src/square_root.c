/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "../takum.h"

#include "codec.h"
#include "util.h"

/*
 * The case NaR is automatically covered given
 * NaN/2=NaN holds.
 */

takum8
takum8_square_root(takum8 t)
{
	if (t < 0) {
		return TAKUM8_NAR;
	} else {
		return codec_takum8_from_s_and_l(0, ldexpf(codec_takum8_to_l(t), -1));
	}
}

takum16
takum16_square_root(takum16 t)
{
	if (t < 0) {
		return TAKUM16_NAR;
	} else {
		return codec_takum16_from_s_and_l(0, ldexpf(codec_takum16_to_l(t), -1));
	}
}

takum32
takum32_square_root(takum32 t)
{
	if (t < 0) {
		return TAKUM32_NAR;
	} else {
		return codec_takum32_from_s_and_l(0, ldexp(codec_takum32_to_l(t), -1));
	}
}

takum64
takum64_square_root(takum64 t)
{
	if (t < 0) {
		return TAKUM64_NAR;
	} else {
		return codec_takum64_from_s_and_l(0, ldexpl(codec_takum64_to_l(t), -1));
	}
}
