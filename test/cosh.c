/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
cosh_reference(long double a)
{
	return coshl(a);
}

static const struct unit_test_block cosh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "cosh",
	.data.takum_takum = {
		.reference_function = cosh_reference,
		.takum8_function    = takum8_cosh,
		.takum16_function   = takum16_cosh,
		.takum32_function   = takum32_cosh,
		.takum64_function   = takum64_cosh,
		.takum_linear8_function    = takum_linear8_cosh,
		.takum_linear16_function   = takum_linear16_cosh,
		.takum_linear32_function   = takum_linear32_cosh,
		.takum_linear64_function   = takum_linear64_cosh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&cosh_utb);
}
