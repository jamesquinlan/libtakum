/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
multiplication_reference(long double a, long double b)
{
	return a * b;
}

static const struct unit_test_block multiplication_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM,
	.function_name = "multiplication",
	.data.takum_takum_takum = {
		.reference_function = multiplication_reference,
		.takum8_function    = takum8_multiplication,
		.takum16_function   = takum16_multiplication,
		.takum32_function   = takum32_multiplication,
		.takum64_function   = takum64_multiplication,
		.takum_linear8_function    = takum_linear8_multiplication,
		.takum_linear16_function   = takum_linear16_multiplication,
		.takum_linear32_function   = takum_linear32_multiplication,
		.takum_linear64_function   = takum_linear64_multiplication,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&multiplication_utb);
}
