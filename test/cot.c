/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
cot_reference(long double a)
{
	return 1.0L / tanl(a);
}

static const struct unit_test_block cot_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "cot",
	.data.takum_takum = {
		.reference_function = cot_reference,
		.takum8_function    = takum8_cot,
		.takum16_function   = takum16_cot,
		.takum32_function   = takum32_cot,
		.takum64_function   = takum64_cot,
	},
};

long double
cot_pi_times_reference(long double a)
{
	return 1.0L / tanl(PI * a);
}

static const struct unit_test_block cot_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "cot_pi_times",
	.data.takum_takum = {
		.reference_function = cot_pi_times_reference,
		.takum8_function    = takum8_cot_pi_times,
		.takum16_function   = takum16_cot_pi_times,
		.takum32_function   = takum32_cot_pi_times,
		.takum64_function   = takum64_cot_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&cot_utb) +
	       run_unit_test_block(&cot_pi_times_utb);
}
