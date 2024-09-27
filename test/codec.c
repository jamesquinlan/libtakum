/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>

#include "../takum.h"
#include "util.h"

#include "../src/codec.h"

takum8
takum8_codec_roundtrip(takum8 t)
{
	return codec_takum8_from_s_and_l(t < 0, codec_takum8_to_l(t));
}

takum16
takum16_codec_roundtrip(takum16 t)
{
	return codec_takum16_from_s_and_l(t < 0, codec_takum16_to_l(t));
}

takum32
takum32_codec_roundtrip(takum32 t)
{
	return codec_takum32_from_s_and_l(t < 0, codec_takum32_to_l(t));
}

takum64
takum64_codec_roundtrip(takum64 t)
{
	return codec_takum64_from_s_and_l(t < 0, codec_takum64_to_l(t));
}

static const struct unit_test_block codec_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
	.function_name = "to_l/from_s_and_l",
	.data.roundtrip = {
		.takum8_function    = takum8_codec_roundtrip,
		.takum16_function   = takum16_codec_roundtrip,
		.takum32_function   = takum32_codec_roundtrip,
		.takum64_function   = takum64_codec_roundtrip,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&codec_utb);
}
