/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>

long double
lb_reference(long double a)
{
	return log2l(a);
}

static const struct unit_test_block lb_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "lb",
	.data.takum_takum = {
		.reference_function = lb_reference,
		.takum8_function    = takum8_lb,
		.takum16_function   = takum16_lb,
		.takum32_function   = takum32_lb,
		.takum64_function   = takum64_lb,
		.takum_linear8_function    = takum_linear8_lb,
		.takum_linear16_function   = takum_linear16_lb,
		.takum_linear32_function   = takum_linear32_lb,
		.takum_linear64_function   = takum_linear64_lb,
	},
};

long double
lb_1_plus_reference(long double a)
{
	return log2l(1.0L + a);
}

static const struct unit_test_block lb_1_plus_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,
	.function_name = "lb_1_plus",
	.data.takum_takum = {
		.reference_function = lb_1_plus_reference,
		.takum8_function    = takum8_lb_1_plus,
		.takum16_function   = takum16_lb_1_plus,
		.takum32_function   = takum32_lb_1_plus,
		.takum64_function   = takum64_lb_1_plus,
		.takum_linear8_function    = takum_linear8_lb_1_plus,
		.takum_linear16_function   = takum_linear16_lb_1_plus,
		.takum_linear32_function   = takum_linear32_lb_1_plus,
		.takum_linear64_function   = takum_linear64_lb_1_plus,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&lb_utb) +
	       run_unit_test_block(&lb_1_plus_utb);
}
