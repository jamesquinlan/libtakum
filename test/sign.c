/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
sign_reference(long double a)
{
	if (isfinite(a)) {
		return (a == 0.0L) ? 0.0L : (a > 0.0L) ? 1.0 : -1.0;
	} else {
		return NAN;
	}
}

static const struct unit_test_block sign_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "absolute",
	.data.takum_takum = {
		.reference_function = sign_reference,
		.takum8_function    = takum8_sign,
		.takum16_function   = takum16_sign,
		.takum32_function   = takum32_sign,
		.takum64_function   = takum64_sign,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sign_utb);
}
