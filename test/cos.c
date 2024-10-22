/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
cos_reference(long double a)
{
	return cosl(a);
}

static const struct unit_test_block cos_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "cos",
	.data.takum_takum = {
		.reference_function = cos_reference,
		.takum8_function    = takum8_cos,
		.takum16_function   = takum16_cos,
		.takum32_function   = takum32_cos,
		.takum64_function   = takum64_cos,
		.takum_linear8_function    = takum_linear8_cos,
		.takum_linear16_function   = takum_linear16_cos,
		.takum_linear32_function   = takum_linear32_cos,
		.takum_linear64_function   = takum_linear64_cos,

	},
};

long double
cos_pi_times_reference(long double a)
{
	return cosl(PI * a);
}

static const struct unit_test_block cos_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "cos_pi_times",
	.data.takum_takum = {
		.reference_function = cos_pi_times_reference,
		.takum8_function    = takum8_cos_pi_times,
		.takum16_function   = takum16_cos_pi_times,
		.takum32_function   = takum32_cos_pi_times,
		.takum64_function   = takum64_cos_pi_times,
		.takum_linear8_function    = takum_linear8_cos_pi_times,
		.takum_linear16_function   = takum_linear16_cos_pi_times,
		.takum_linear32_function   = takum_linear32_cos_pi_times,
		.takum_linear64_function   = takum_linear64_cos_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&cos_utb) +
	       run_unit_test_block(&cos_pi_times_utb);
}
