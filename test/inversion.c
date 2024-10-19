/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
inversion_reference(long double a)
{
	return 1.0L / a;
}

static const struct unit_test_block inversion_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "inversion",
	.data.takum_takum = {
		.reference_function = inversion_reference,
		.takum8_function    = takum8_inversion,
		.takum16_function   = takum16_inversion,
		.takum32_function   = takum32_inversion,
		.takum64_function   = takum64_inversion,
		.takum_linear8_function    = takum_linear8_inversion,
		.takum_linear16_function   = takum_linear16_inversion,
		.takum_linear32_function   = takum_linear32_inversion,
		.takum_linear64_function   = takum_linear64_inversion,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&inversion_utb);
}
