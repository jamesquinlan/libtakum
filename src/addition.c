/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "../takum.h"

#include "codec.h"
#include "util.h"

takum8
takum8_addition(takum8 a, takum8 b)
{
	float la, lb;

	la = codec_takum8_to_l(a);
	lb = codec_takum8_to_l(b);

	if (a > 0) {
		if (b > 0) {
			if (a > b) {
				return codec_takum8_from_s_and_l(
					0,
					la + 2 * log1pf(powf(SQRTE, lb - la)));
			} else {
				return codec_takum8_from_s_and_l(
					0,
					lb + 2 * log1pf(powf(SQRTE, la - lb)));
			}
		} else if (b < 0) {
			return takum8_subtraction(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return takum8_subtraction(b, -a);
		} else if (b < 0) {
			return -takum8_addition(-a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return b;
	}
}

takum16
takum16_addition(takum16 a, takum16 b)
{
	float la, lb;

	la = codec_takum16_to_l(a);
	lb = codec_takum16_to_l(b);

	if (a > 0) {
		if (b > 0) {
			if (a > b) {
				return codec_takum16_from_s_and_l(
					0,
					la + 2 * log1pf(powf(SQRTE, lb - la)));
			} else {
				return codec_takum16_from_s_and_l(
					0,
					lb + 2 * log1pf(powf(SQRTE, la - lb)));
			}
		} else if (b < 0) {
			return takum16_subtraction(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return takum16_subtraction(b, -a);
		} else if (b < 0) {
			return -takum16_addition(-a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return b;
	}
}

takum32
takum32_addition(takum32 a, takum32 b)
{
	double la, lb;

	la = codec_takum32_to_l(a);
	lb = codec_takum32_to_l(b);

	if (a > 0) {
		if (b > 0) {
			if (a > b) {
				return codec_takum32_from_s_and_l(
					0, la + 2 * log1p(pow(SQRTE, lb - la)));
			} else {
				return codec_takum32_from_s_and_l(
					0, lb + 2 * log1p(pow(SQRTE, la - lb)));
			}
		} else if (b < 0) {
			return takum32_subtraction(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return takum32_subtraction(b, -a);
		} else if (b < 0) {
			return -takum32_addition(-a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return b;
	}
}

takum64
takum64_addition(takum64 a, takum64 b)
{
	long double la, lb;

	la = codec_takum64_to_l(a);
	lb = codec_takum64_to_l(b);

	if (a > 0) {
		if (b > 0) {
			if (a > b) {
				return codec_takum64_from_s_and_l(
					0,
					la + 2 * log1pl(powl(SQRTE, lb - la)));
			} else {
				return codec_takum64_from_s_and_l(
					0,
					lb + 2 * log1pl(powl(SQRTE, la - lb)));
			}
		} else if (b < 0) {
			return takum64_subtraction(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return takum64_subtraction(b, -a);
		} else if (b < 0) {
			return -takum64_addition(-a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return b;
	}
}
