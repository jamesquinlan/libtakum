/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>

#include "../takum.h"
#include "util.h"

takum8
takum8_conversion_float64_roundtrip(takum8 t)
{
	return takum8_from_float64(takum8_to_float64(t));
}

takum16
takum16_conversion_float64_roundtrip(takum16 t)
{
	return takum16_from_float64(takum16_to_float64(t));
}

takum32
takum32_conversion_float64_roundtrip(takum32 t)
{
	return takum32_from_float64(takum32_to_float64(t));
}

takum64
takum64_conversion_float64_roundtrip(takum64 t)
{
	/* this would not be a lossless roundtrip */
	return t;
}

static const struct unit_test_block conversion_float64_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
	.function_name = "to_float64/from_float64",
	.data.roundtrip = {
		.takum8_function    = takum8_conversion_float64_roundtrip,
		.takum16_function   = takum16_conversion_float64_roundtrip,
		.takum32_function   = takum32_conversion_float64_roundtrip,
		.takum64_function   = takum64_conversion_float64_roundtrip,
	},
};

takum8
takum8_conversion_extended_float_roundtrip(takum8 t)
{
	return takum8_from_extended_float(takum8_to_extended_float(t));
}

takum16
takum16_conversion_extended_float_roundtrip(takum16 t)
{
	return takum16_from_extended_float(takum16_to_extended_float(t));
}

takum32
takum32_conversion_extended_float_roundtrip(takum32 t)
{
	return takum32_from_extended_float(takum32_to_extended_float(t));
}

takum64
takum64_conversion_extended_float_roundtrip(takum64 t)
{
	return takum64_from_extended_float(takum64_to_extended_float(t));
}

static const struct unit_test_block conversion_extended_float_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
	.function_name = "to_extended_float/from_extended_float",
	.data.roundtrip = {
		.takum8_function    = takum8_conversion_extended_float_roundtrip,
		.takum16_function   = takum16_conversion_extended_float_roundtrip,
		.takum32_function   = takum32_conversion_extended_float_roundtrip,
		.takum64_function   = takum64_conversion_extended_float_roundtrip,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&conversion_float64_utb) +
	       run_unit_test_block(&conversion_extended_float_utb);
}
