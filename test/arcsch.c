/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
arcsch_reference(long double a)
{
	return asinh(1.0L / a);
}

static const struct unit_test_block arcsch_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "arcsch",
	.data.takum_takum = {
		.reference_function = arcsch_reference,
		.takum8_function    = takum8_arcsch,
		.takum16_function   = takum16_arcsch,
		.takum32_function   = takum32_arcsch,
		.takum64_function   = takum64_arcsch,
		.takum_linear8_function    = takum_linear8_arcsch,
		.takum_linear16_function   = takum_linear16_arcsch,
		.takum_linear32_function   = takum_linear32_arcsch,
		.takum_linear64_function   = takum_linear64_arcsch,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arcsch_utb);
}
