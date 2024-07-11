/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "../takum.h"

#include "codec.h"
#include "util.h"

takum8
takum8_subtraction(takum8 a, takum8 b)
{
	if (a == TAKUM8_NAR || b == TAKUM8_NAR) {
		return TAKUM8_NAR;
	}

	if (a == b) {
		return 0;
	}

	if (a > 0) {
		if (b > 0) {
			float la, lb;

			la = codec_takum8_to_l(a);
			lb = codec_takum8_to_l(b);

			/*
			 * We convert to double as float doesn't have
			 * sufficient dynamic range for the intermediate
			 * result.
			 */
			if (a > b) {
				return codec_takum8_from_s_and_l(
					0,
					la + 2 * (float)log1p(-pow(
							 SQRTE,
							 (double)(lb - la))));
			} else {
				return codec_takum8_from_s_and_l(
					1,
					lb + 2 * (float)log1p(-pow(
							 SQRTE,
							 (double)(la - lb))));
			}
		} else if (b < 0) {
			return takum8_addition(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return -takum8_addition(-a, b);
		} else if (b < 0) {
			return takum8_subtraction(-b, -a);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return -b;
	}
}

takum16
takum16_subtraction(takum16 a, takum16 b)
{
	if (a == TAKUM16_NAR || b == TAKUM16_NAR) {
		return TAKUM16_NAR;
	}

	if (a == b) {
		return 0;
	}

	if (a > 0) {
		if (b > 0) {
			float la, lb;

			la = codec_takum16_to_l(a);
			lb = codec_takum16_to_l(b);

			/*
			 * We convert to double as float doesn't have
			 * sufficient dynamic range for the intermediate
			 * result.
			 */
			if (a > b) {
				return codec_takum16_from_s_and_l(
					0,
					la + 2 * (float)log1p(-pow(
							 SQRTE,
							 (double)(lb - la))));
			} else {
				return codec_takum16_from_s_and_l(
					1,
					lb + 2 * (float)log1p(-pow(
							 SQRTE,
							 (double)(la - lb))));
			}
		} else if (b < 0) {
			return takum16_addition(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return -takum16_addition(-a, b);
		} else if (b < 0) {
			return takum16_subtraction(-b, -a);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return -b;
	}
}

takum32
takum32_subtraction(takum32 a, takum32 b)
{
	if (a == TAKUM32_NAR || b == TAKUM32_NAR) {
		return TAKUM32_NAR;
	}

	if (a == b) {
		return 0;
	}

	if (a > 0) {
		if (b > 0) {
			double la, lb;

			la = codec_takum32_to_l(a);
			lb = codec_takum32_to_l(b);

			if (a > b) {
				return codec_takum32_from_s_and_l(
					0,
					la + 2 * log1p(-pow(SQRTE, lb - la)));
			} else {
				return codec_takum32_from_s_and_l(
					1,
					lb + 2 * log1p(-pow(SQRTE, la - lb)));
			}
		} else if (b < 0) {
			return takum32_addition(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return -takum32_addition(-a, b);
		} else if (b < 0) {
			return takum32_subtraction(-b, -a);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return -b;
	}
}

takum64
takum64_subtraction(takum64 a, takum64 b)
{
	if (a == TAKUM64_NAR || b == TAKUM64_NAR) {
		return TAKUM64_NAR;
	}

	if (a == b) {
		return 0;
	}

	if (a > 0) {
		if (b > 0) {
			long double la, lb;

			la = codec_takum64_to_l(a);
			lb = codec_takum64_to_l(b);

			if (a > b) {
				return codec_takum64_from_s_and_l(
					0,
					la + 2 * log1pl(-powl(SQRTE, lb - la)));
			} else {
				return codec_takum64_from_s_and_l(
					1,
					lb + 2 * log1pl(-powl(SQRTE, la - lb)));
			}
		} else if (b < 0) {
			return takum64_addition(a, -b);
		} else { /* b == 0 */
			return a;
		}
	} else if (a < 0) {
		if (b > 0) {
			return -takum64_addition(-a, b);
		} else if (b < 0) {
			return takum64_subtraction(-b, -a);
		} else { /* b == 0 */
			return a;
		}
	} else { /* a == 0 */
		return -b;
	}
}
