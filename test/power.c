/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

static long double
power_reference(long double a, long double b)
{
	return powl(a, b);
}

static const struct unit_test_block power_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM,
	.function_name = "power",
	.data.takum_takum_takum = {
		.reference_function = power_reference,
		.takum8_function    = takum8_power,
		.takum16_function   = takum16_power,
		.takum32_function   = takum32_power,
		.takum64_function   = takum64_power,
		.takum_linear8_function    = takum_linear8_power,
		.takum_linear16_function   = takum_linear16_power,
		.takum_linear32_function   = takum_linear32_power,
		.takum_linear64_function   = takum_linear64_power,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&power_utb);
}
