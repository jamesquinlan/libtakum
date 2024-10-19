/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
sec_reference(long double a)
{
	return 1.0L / cosl(a);
}

static const struct unit_test_block sec_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "sec",
	.data.takum_takum = {
		.reference_function = sec_reference,
		.takum8_function    = takum8_sec,
		.takum16_function   = takum16_sec,
		.takum32_function   = takum32_sec,
		.takum64_function   = takum64_sec,
		.takum_linear8_function    = takum_linear8_sec,
		.takum_linear16_function   = takum_linear16_sec,
		.takum_linear32_function   = takum_linear32_sec,
		.takum_linear64_function   = takum_linear64_sec,
	},
};

long double
sec_pi_times_reference(long double a)
{
	return 1.0L / cosl(PI * a);
}

static const struct unit_test_block sec_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "sec_pi_times",
	.data.takum_takum = {
		.reference_function = sec_pi_times_reference,
		.takum8_function    = takum8_sec_pi_times,
		.takum16_function   = takum16_sec_pi_times,
		.takum32_function   = takum32_sec_pi_times,
		.takum64_function   = takum64_sec_pi_times,
		.takum_linear8_function    = takum_linear8_sec_pi_times,
		.takum_linear16_function   = takum_linear16_sec_pi_times,
		.takum_linear32_function   = takum_linear32_sec_pi_times,
		.takum_linear64_function   = takum_linear64_sec_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sec_utb) +
	       run_unit_test_block(&sec_pi_times_utb);
}
