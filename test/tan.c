/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
tan_reference(long double a)
{
	return tanl(a);
}

static const struct unit_test_block tan_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "tan",
	.data.takum_takum = {
		.reference_function = tan_reference,
		.takum8_function    = takum8_tan,
		.takum16_function   = takum16_tan,
		.takum32_function   = takum32_tan,
		.takum64_function   = takum64_tan,
		.takum_linear8_function    = takum_linear8_tan,
		.takum_linear16_function   = takum_linear16_tan,
		.takum_linear32_function   = takum_linear32_tan,
		.takum_linear64_function   = takum_linear64_tan,
	},
};

long double
tan_pi_times_reference(long double a)
{
	return (fmodl(a, 1.0) == 0.5) ? NAN : tanl(PI * a);
}

static const struct unit_test_block tan_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "tan_pi_times",
	.data.takum_takum = {
		.reference_function = tan_pi_times_reference,
		.takum8_function    = takum8_tan_pi_times,
		.takum16_function   = takum16_tan_pi_times,
		.takum32_function   = takum32_tan_pi_times,
		.takum64_function   = takum64_tan_pi_times,
		.takum_linear8_function    = takum_linear8_tan_pi_times,
		.takum_linear16_function   = takum_linear16_tan_pi_times,
		.takum_linear32_function   = takum_linear32_tan_pi_times,
		.takum_linear64_function   = takum_linear64_tan_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&tan_utb) +
	       run_unit_test_block(&tan_pi_times_utb);
}
