/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
sinh_reference(long double a)
{
	return sinhl(a);
}

static const struct unit_test_block sinh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "sinh",
	.data.takum_takum = {
		.reference_function = sinh_reference,
		.takum8_function    = takum8_sinh,
		.takum16_function   = takum16_sinh,
		.takum32_function   = takum32_sinh,
		.takum64_function   = takum64_sinh,
		.takum_linear8_function    = takum_linear8_sinh,
		.takum_linear16_function   = takum_linear16_sinh,
		.takum_linear32_function   = takum_linear32_sinh,
		.takum_linear64_function   = takum_linear64_sinh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sinh_utb);
}
