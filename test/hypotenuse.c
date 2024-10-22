/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
hypotenuse_reference(long double a, long double b)
{
	return hypotl(a, b);
}

static const struct unit_test_block hypotenuse_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM,
	.function_name = "hypotenuse",
	.data.takum_takum_takum = {
		.reference_function = hypotenuse_reference,
		.takum8_function    = takum8_hypotenuse,
		.takum16_function   = takum16_hypotenuse,
		.takum32_function   = takum32_hypotenuse,
		.takum64_function   = takum64_hypotenuse,
		.takum_linear8_function    = takum_linear8_hypotenuse,
		.takum_linear16_function   = takum_linear16_hypotenuse,
		.takum_linear32_function   = takum_linear32_hypotenuse,
		.takum_linear64_function   = takum_linear64_hypotenuse,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&hypotenuse_utb);
}
