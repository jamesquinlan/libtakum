/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
sin_reference(long double a)
{
	return sinl(a);
}

static const struct unit_test_block sin_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "sin",
	.data.takum_takum = {
		.reference_function = sin_reference,
		.takum8_function    = takum8_sin,
		.takum16_function   = takum16_sin,
		.takum32_function   = takum32_sin,
		.takum64_function   = takum64_sin,
	},
};

long double
sin_pi_times_reference(long double a)
{
	return sinl(PI * a);
}

static const struct unit_test_block sin_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "sin_pi_times",
	.data.takum_takum = {
		.reference_function = sin_pi_times_reference,
		.takum8_function    = takum8_sin_pi_times,
		.takum16_function   = takum16_sin_pi_times,
		.takum32_function   = takum32_sin_pi_times,
		.takum64_function   = takum64_sin_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sin_utb) +
	       run_unit_test_block(&sin_pi_times_utb);
}
