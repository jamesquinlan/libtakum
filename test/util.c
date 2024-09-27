/* See LICENSE file for copyright and license details. */
#include "../takum.h"

#include "util.h"

#include <fenv.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *argv0;

static long double
int64_takum8_to_extended_float(int64_t t)
{
	return takum8_to_extended_float((takum8)t);
}

static long double
int64_takum16_to_extended_float(int64_t t)
{
	return takum16_to_extended_float((takum16)t);
}

static long double
int64_takum32_to_extended_float(int64_t t)
{
	return takum32_to_extended_float((takum32)t);
}

static long double
int64_takum64_to_extended_float(int64_t t)
{
	return takum64_to_extended_float((takum64)t);
}

static int64_t
int64_takum8_from_extended_float(long double f)
{
	return (int64_t)takum8_from_extended_float(f);
}

static int64_t
int64_takum16_from_extended_float(long double f)
{
	return (int64_t)takum16_from_extended_float(f);
}

static int64_t
int64_takum32_from_extended_float(long double f)
{
	return (int64_t)takum32_from_extended_float(f);
}

static int64_t
int64_takum64_from_extended_float(long double f)
{
	return (int64_t)takum64_from_extended_float(f);
}

const struct takum_type_parameters takum_type_parameters[] = {
	[TAKUM8] = {
		.name             = "takum8",
		.n                = 8,
		.nar              = TAKUM8_NAR,
		.positive_minimum = TAKUM8_POSITIVE_MINIMUM,
		.positive_maximum = TAKUM8_POSITIVE_MAXIMUM,
		.stride_1d        = INT64_C(1),
		.stride_2d        = INT64_C(1),
		.maximum_scaled_relative_error = 1e+1L,
		.int64_takum_to_extended_float = int64_takum8_to_extended_float,
		.int64_takum_from_extended_float = int64_takum8_from_extended_float,
	},
	[TAKUM16] = {
		.name             = "takum16",
		.n                = 16,
		.nar              = TAKUM16_NAR,
		.positive_minimum = TAKUM16_POSITIVE_MINIMUM,
		.positive_maximum = TAKUM16_POSITIVE_MAXIMUM,
		.stride_1d        = INT64_C(1),
		.stride_2d        = (INT64_C(1) << 6) - 1,
		.maximum_scaled_relative_error = 1e-2L,
		.int64_takum_to_extended_float = int64_takum16_to_extended_float,
		.int64_takum_from_extended_float = int64_takum16_from_extended_float,
	},
	[TAKUM32] = {
		.name             = "takum32",
		.n                = 32,
		.nar              = TAKUM32_NAR,
		.positive_minimum = TAKUM32_POSITIVE_MINIMUM,
		.positive_maximum = TAKUM32_POSITIVE_MAXIMUM,
		.stride_1d        = (INT64_C(1) << 16) - 1,
		.stride_2d        = (INT64_C(1) << 20) - 1,
		.maximum_scaled_relative_error = 1e-3L,
		.int64_takum_to_extended_float = int64_takum32_to_extended_float,
		.int64_takum_from_extended_float = int64_takum32_from_extended_float,
	},
	[TAKUM64] = {
		.name             = "takum64",
		.n                = 64,
		.nar              = TAKUM64_NAR,
		.positive_minimum = TAKUM64_POSITIVE_MINIMUM,
		.positive_maximum = TAKUM64_POSITIVE_MAXIMUM,
		.stride_1d        = (INT64_C(1) << 48) - 1,
		.stride_2d        = (INT64_C(1) << 52) - 1,
		.maximum_scaled_relative_error = 1e-4L,
		.int64_takum_to_extended_float = int64_takum64_to_extended_float,
		.int64_takum_from_extended_float = int64_takum64_from_extended_float,
	},
};

static int64_t
evaluate_reference_function(const struct unit_test_block *utb, int64_t a,
                            int64_t b, enum takum_type takum_type)
{
	long double a_extended_float, b_extended_float,
		raw_output_extended_float = 0.0L;

	/*
	 * Compute the given function, taking special care to handle
	 * possible under - or overflow
	 */
	feclearexcept(FE_UNDERFLOW);
	feclearexcept(FE_OVERFLOW);

	/* convert a to long double */
	a_extended_float =
		takum_type_parameters[takum_type].int64_takum_to_extended_float(
			a);

	switch (utb->type) {
	case UNIT_TEST_BLOCK_TYPE_ROUNDTRIP:
		fprintf(stderr,
		        "%s: evaluate_reference_function: Unexpected call from "
		        "roundtrip test\n",
		        argv0);
		exit(1);
	case UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM:
		raw_output_extended_float =
			utb->data.takum_int64_takum.reference_function(
				a_extended_float, b);
		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM:
		raw_output_extended_float =
			utb->data.takum_takum.reference_function(
				a_extended_float);
		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM:
		/* convert b to long double */
		b_extended_float = takum_type_parameters[takum_type]
		                           .int64_takum_to_extended_float(b);

		raw_output_extended_float =
			utb->data.takum_takum_takum.reference_function(
				a_extended_float, b_extended_float);
		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8:
		/*
		 * we can directly return the raw uint8 output
		 * casted to int64
		 */
		return (int64_t)utb->data.takum_uint8.reference_function(
			a_extended_float, takum_type);
	};

	/*
	 * Depending on possible under-/overflow, obtain the
	 * reference_output
	 */
	if (fetestexcept(FE_UNDERFLOW) && raw_output_extended_float == 0.0) {
		if (signbit(raw_output_extended_float) == 1) {
			return -takum_type_parameters[takum_type]
			                .positive_minimum;
		} else {
			return takum_type_parameters[takum_type]
			        .positive_minimum;
		}
	} else if (fetestexcept(FE_OVERFLOW)) {
		if (raw_output_extended_float > 0.0) {
			return takum_type_parameters[takum_type]
			        .positive_maximum;
		} else {
			return -takum_type_parameters[takum_type]
			                .positive_maximum;
		}
	} else {
		return takum_type_parameters[takum_type]
		        .int64_takum_from_extended_float(
				raw_output_extended_float);
	}
}

static long double
get_scaled_relative_error(long double exact, long double rounded, long double a,
                          long double b)
{
	long double maximum_input = MAX(fabsl(a), fabsl(b));

	return fabsl(exact - rounded) /
	       (fabsl(exact) * (1 + fabsl(maximum_input)));
}

int
check_unary_binary_case(const struct unit_test_block *utb, int64_t a, int64_t b,
                        enum takum_type takum_type, size_t test_number)
{
	int64_t reference_output = 0, output = 1;
	bool failed = true;
	long double scaled_relative_error;

	switch (utb->type) {
	case UNIT_TEST_BLOCK_TYPE_ROUNDTRIP:
		/* Determine the output of the roundtrip function */
		switch (takum_type) {
		case TAKUM8:
			output = (int64_t)utb->data.roundtrip.takum8_function(
				(takum8)a);
			break;
		case TAKUM16:
			output = (int64_t)utb->data.roundtrip.takum16_function(
				(takum16)a);
			break;
		case TAKUM32:
			output = (int64_t)utb->data.roundtrip.takum32_function(
				(takum32)a);
			break;
		case TAKUM64:
			output = (int64_t)utb->data.roundtrip.takum64_function(
				(takum64)a);
			break;
		}

		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM:
		/* Compute reference_function(a, b) */
		reference_output =
			evaluate_reference_function(utb, a, b, takum_type);

		/* Determine the output of the tested function */
		switch (takum_type) {
		case TAKUM8:
			output = (int64_t)utb->data.takum_int64_takum
			                 .takum8_function((takum8)a, b);
			break;
		case TAKUM16:
			output = (int64_t)utb->data.takum_int64_takum
			                 .takum16_function((takum16)a, b);
			break;
		case TAKUM32:
			output = (int64_t)utb->data.takum_int64_takum
			                 .takum32_function((takum32)a, b);
			break;
		case TAKUM64:
			output = (int64_t)utb->data.takum_int64_takum
			                 .takum64_function((takum64)a, b);
			break;
		}

		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM:
		/* Compute reference_function(a) */
		reference_output =
			evaluate_reference_function(utb, a, 0, takum_type);

		/* Determine the output of the tested function */
		switch (takum_type) {
		case TAKUM8:
			output = (int64_t)utb->data.takum_takum.takum8_function(
				(takum8)a);
			break;
		case TAKUM16:
			output =
				(int64_t)utb->data.takum_takum.takum16_function(
					(takum16)a);
			break;
		case TAKUM32:
			output =
				(int64_t)utb->data.takum_takum.takum32_function(
					(takum32)a);
			break;
		case TAKUM64:
			output =
				(int64_t)utb->data.takum_takum.takum64_function(
					(takum64)a);
			break;
		}

		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM:
		/* Compute reference_function(a, b) */
		reference_output =
			evaluate_reference_function(utb, a, b, takum_type);

		/* Determine the output of the tested function */
		switch (takum_type) {
		case TAKUM8:
			output = (int64_t)utb->data.takum_takum_takum
			                 .takum8_function((takum8)a, (takum8)b);
			break;
		case TAKUM16:
			output = (int64_t)utb->data.takum_takum_takum
			                 .takum16_function((takum16)a,
			                                   (takum16)b);
			break;
		case TAKUM32:
			output = (int64_t)utb->data.takum_takum_takum
			                 .takum32_function((takum32)a,
			                                   (takum32)b);
			break;
		case TAKUM64:
			output = (int64_t)utb->data.takum_takum_takum
			                 .takum64_function((takum64)a,
			                                   (takum64)b);
			break;
		}

		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8:
		/* Compute reference_function(a) */
		reference_output =
			evaluate_reference_function(utb, a, 0, takum_type);

		/* Determine the output of the tested function */
		switch (takum_type) {
		case TAKUM8:
			output = (int64_t)utb->data.takum_uint8.takum8_function(
				(takum8)a);
			break;
		case TAKUM16:
			output =
				(int64_t)utb->data.takum_uint8.takum16_function(
					(takum16)a);
			break;
		case TAKUM32:
			output =
				(int64_t)utb->data.takum_uint8.takum32_function(
					(takum32)a);
			break;
		case TAKUM64:
			output =
				(int64_t)utb->data.takum_uint8.takum64_function(
					(takum64)a);
			break;
		}

		break;
	}

	switch (utb->type) {
	case UNIT_TEST_BLOCK_TYPE_ROUNDTRIP:
		failed = (output != a);

		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8:
		failed = (output != reference_output);

		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM:
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM:
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM:
		scaled_relative_error = get_scaled_relative_error(
			takum_type_parameters[takum_type]
				.int64_takum_to_extended_float(
					reference_output),
			takum_type_parameters[takum_type]
				.int64_takum_to_extended_float(output),
			takum_type_parameters[takum_type]
				.int64_takum_to_extended_float(a),
			0.0L);

		failed = (scaled_relative_error >
		          takum_type_parameters[takum_type]
		                  .maximum_scaled_relative_error);

		/*
		 * If we failed but the sign is only flipped, we assume
		 * correctness
		 */
		if (failed && reference_output == -output) {
			failed = 0;
		}

		break;
	}

	/*
	 * check the output and optionally increment the failure count
	 * and print an error message
	 */
	if (failed) {
		switch (utb->type) {
		case UNIT_TEST_BLOCK_TYPE_ROUNDTRIP:
			fprintf(stderr,
			        "%s: %s_%s: Failed unit test %zu "
			        "(roundtrip of %.20Le returned %.20Le)\n",
			        argv0, takum_type_parameters[takum_type].name,
			        utb->function_name, test_number,
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(a),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(output));
			break;
		case UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM:
			fprintf(stderr,
			        "%s: %s_%s: Failed unit test %zu "
			        "(%s_%s(%.20Le, %" PRIi64 ") returned %.20Le "
			        "instead "
			        "of "
			        "%.20Le)\n",
			        argv0, takum_type_parameters[takum_type].name,
			        utb->function_name, test_number,
			        takum_type_parameters[takum_type].name,
			        utb->function_name,
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(a),
			        b,
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(output),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(
						reference_output));
			break;
		case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM:
			fprintf(stderr,
			        "%s: %s_%s: Failed unit test %zu "
			        "(%s_%s(%.20Le) returned %.20Le "
			        "instead "
			        "of "
			        "%.20Le)\n",
			        argv0, takum_type_parameters[takum_type].name,
			        utb->function_name, test_number,
			        takum_type_parameters[takum_type].name,
			        utb->function_name,
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(a),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(output),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(
						reference_output));
			break;
		case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM:
			fprintf(stderr,
			        "%s: %s_%s: Failed unit test %zu "
			        "(%s_%s(%.20Le, %.20Le) returned %.20Le "
			        "instead "
			        "of "
			        "%.20Le)\n",
			        argv0, takum_type_parameters[takum_type].name,
			        utb->function_name, test_number,
			        takum_type_parameters[takum_type].name,
			        utb->function_name,
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(a),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(b),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(output),
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(
						reference_output));
			break;
		case UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8:
			fprintf(stderr,
			        "%s: %s_%s: Failed unit test %zu "
			        "(%s_%s(%.20Le) returned %" PRIi64 " "
			        "instead of %" PRIi64 ")\n",
			        argv0, takum_type_parameters[takum_type].name,
			        utb->function_name, test_number,
			        takum_type_parameters[takum_type].name,
			        utb->function_name,
			        takum_type_parameters[takum_type]
			                .int64_takum_to_extended_float(a),
			        output, reference_output);
			break;
		}

		return 1;
	} else {
		return 0;
	}
}

int
next_sample(int64_t *i, enum unit_test_block_type utb_type,
            enum takum_type takum_type)
{
	int64_t stride = 0;

	switch (utb_type) {
	case UNIT_TEST_BLOCK_TYPE_ROUNDTRIP:
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM:
	case UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8:
		stride = takum_type_parameters[takum_type].stride_1d;
		break;
	case UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM:
	case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM:
		stride = takum_type_parameters[takum_type].stride_2d;
		break;
	}

	/* check the distance from the 'finish', but do that only when
	 * *i is larger than or equal to 0 to avoid an overflow */
	if (*i >= 0 &&
	    (uint64_t)takum_type_parameters[takum_type].positive_maximum -
	                    (uint64_t)*i <
	            (uint64_t)stride) {
		/* the stride would overflow, don't increase i, return 1 */
		return 1;
	} else {
		/* we are safe, apply the stride and return 0 */
		*i += stride;
		return 0;
	}
}

static int
run_unit_test_on_type(const struct unit_test_block *utb,
                      enum takum_type takum_type)

{
	size_t failed_count = 0, coverage_test_count = 0, i;
	int64_t a, b;

	/*
	 * We iterate over (almost) all takums of the given type,
	 * especially making sure that the results properly saturate
	 * (both on under- and overflow) and NaN is propagated in
	 * all cases.
	 *
	 * For this we assume that our conversion routines between
	 * takum and float are correct, which is a valid assumption
	 * given we test those separately.
	 */
	for (a = takum_type_parameters[takum_type].nar;;) {
		switch (utb->type) {
		case UNIT_TEST_BLOCK_TYPE_ROUNDTRIP:
		case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM:
		case UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8:
			failed_count += check_unary_binary_case(
				utb, a, 0, takum_type, coverage_test_count);
			coverage_test_count++;

			if (next_sample(&a, utb->type, takum_type)) {
				goto done;
			}

			break;
		case UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM:
			for (i = 0; i < utb->data.takum_int64_takum
			                        .integer_test_case_count;
			     i++) {
				failed_count += check_unary_binary_case(
					utb, a,
					utb->data.takum_int64_takum
						.integer_test_cases[i],
					takum_type, coverage_test_count);
				coverage_test_count++;
			}

			if (next_sample(&a, utb->type, takum_type)) {
				goto done;
			}

			break;
		case UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM:
			for (b = a;;) {
				failed_count += check_unary_binary_case(
					utb, a, b, takum_type,
					coverage_test_count);
				coverage_test_count++;

				if (next_sample(&b, utb->type, takum_type)) {
					break;
				}
			}

			if (next_sample(&a, utb->type, takum_type)) {
				goto done;
			}

			break;
		}
	}
done:

	printf("%s: %s_%s: %zu/%zu unit tests passed.\n", argv0,
	       takum_type_parameters[takum_type].name, utb->function_name,
	       coverage_test_count - failed_count, coverage_test_count);

	return (failed_count > 0) ? 1 : 0;
}

int
run_unit_test_block(const struct unit_test_block *utb)
{
	return run_unit_test_on_type(utb, TAKUM8) +
	       run_unit_test_on_type(utb, TAKUM16) +
	       run_unit_test_on_type(utb, TAKUM32) +
	       run_unit_test_on_type(utb, TAKUM64);
}
