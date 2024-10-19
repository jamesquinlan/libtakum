/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
csc_reference(long double a)
{
	return 1.0L / sinl(a);
}

static const struct unit_test_block csc_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "csc",
	.data.takum_takum = {
		.reference_function = csc_reference,
		.takum8_function    = takum8_csc,
		.takum16_function   = takum16_csc,
		.takum32_function   = takum32_csc,
		.takum64_function   = takum64_csc,
		.takum_linear8_function    = takum_linear8_csc,
		.takum_linear16_function   = takum_linear16_csc,
		.takum_linear32_function   = takum_linear32_csc,
		.takum_linear64_function   = takum_linear64_csc,
	},
};

long double
csc_pi_times_reference(long double a)
{
	return 1.0L / sinl(PI * a);
}

static const struct unit_test_block csc_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "csc_pi_times",
	.data.takum_takum = {
		.reference_function = csc_pi_times_reference,
		.takum8_function    = takum8_csc_pi_times,
		.takum16_function   = takum16_csc_pi_times,
		.takum32_function   = takum32_csc_pi_times,
		.takum64_function   = takum64_csc_pi_times,
		.takum_linear8_function    = takum_linear8_csc_pi_times,
		.takum_linear16_function   = takum_linear16_csc_pi_times,
		.takum_linear32_function   = takum_linear32_csc_pi_times,
		.takum_linear64_function   = takum_linear64_csc_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&csc_utb) +
	       run_unit_test_block(&csc_pi_times_utb);
}
