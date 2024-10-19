/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
arsech_reference(long double a)
{
	return acosh(1.0L / a);
}

static const struct unit_test_block arsech_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "arsech",
	.data.takum_takum = {
		.reference_function = arsech_reference,
		.takum8_function    = takum8_arsech,
		.takum16_function   = takum16_arsech,
		.takum32_function   = takum32_arsech,
		.takum64_function   = takum64_arsech,
		.takum_linear8_function    = takum_linear8_arsech,
		.takum_linear16_function   = takum_linear16_arsech,
		.takum_linear32_function   = takum_linear32_arsech,
		.takum_linear64_function   = takum_linear64_arsech,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arsech_utb);
}
