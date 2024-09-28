/* See LICENSE file for copyright and license details. */
#include "../takum.h"
#include "util.h"

#include <math.h>
#include <stdint.h>

long double
root_reference(long double a, int64_t b)
{
	return powl(a, 1.0L / (long double)b);
}

static const int64_t integer_test_cases[] = {
	-100, -10, -1, 0, 1, 10, 100,
};

static const struct unit_test_block root_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM,
	.function_name = "root",
	.data.takum_int64_takum = {
		.reference_function      = root_reference,
		.takum8_function         = takum8_root,
		.takum16_function        = takum16_root,
		.takum32_function        = takum32_root,
		.takum64_function        = takum64_root,
		.integer_test_cases      = integer_test_cases,
		.integer_test_case_count = LEN(integer_test_cases),
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&root_utb);
}
