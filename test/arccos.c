/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
arccos_reference(long double a)
{
	return acosl(a);
}

static const struct unit_test_block arccos_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "arccos",
	.data.takum_takum = {
		.reference_function = arccos_reference,
		.takum8_function    = takum8_arccos,
		.takum16_function   = takum16_arccos,
		.takum32_function   = takum32_arccos,
		.takum64_function   = takum64_arccos,
		.takum_linear8_function    = takum_linear8_arccos,
		.takum_linear16_function   = takum_linear16_arccos,
		.takum_linear32_function   = takum_linear32_arccos,
		.takum_linear64_function   = takum_linear64_arccos,
	},
};

long double
arccos_over_pi_reference(long double a)
{
	return acosl(a) / PI;
}

static const struct unit_test_block arccos_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "arccos_over_pi",
	.data.takum_takum = {
		.reference_function = arccos_over_pi_reference,
		.takum8_function    = takum8_arccos_over_pi,
		.takum16_function   = takum16_arccos_over_pi,
		.takum32_function   = takum32_arccos_over_pi,
		.takum64_function   = takum64_arccos_over_pi,
		.takum_linear8_function    = takum_linear8_arccos_over_pi,
		.takum_linear16_function   = takum_linear16_arccos_over_pi,
		.takum_linear32_function   = takum_linear32_arccos_over_pi,
		.takum_linear64_function   = takum_linear64_arccos_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arccos_utb) +
	       run_unit_test_block(&arccos_over_pi_utb);
}
