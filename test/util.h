/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include "../takum.h"

#include <stddef.h>
#include <stdint.h>

#undef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#undef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

#define LB_E 1.4426950408889634073599246810018921374266L
#define LG_E 0.4342944819032518276511289189166050822944L
#define PI   3.1415926535897932384626433832795028841972L

extern char *argv0;

enum takum_type {
	TAKUM8,
	TAKUM16,
	TAKUM32,
	TAKUM64,
	TAKUM_LINEAR8,
	TAKUM_LINEAR16,
	TAKUM_LINEAR32,
	TAKUM_LINEAR64,
};

struct takum_type_parameters {
	const char *name;
	size_t n;
	int64_t nar;
	int64_t positive_minimum;
	int64_t positive_maximum;
	int64_t stride_1d;
	int64_t stride_2d;
	long double (*int64_takum_to_extended_float)(int64_t);
	int64_t (*int64_takum_from_extended_float)(long double);
};

extern const struct takum_type_parameters takum_type_parameters[];

enum unit_test_block_type {
	UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,         /* roundtrip conversion */
	UNIT_TEST_BLOCK_TYPE_TAKUM_INT64_TAKUM, /* (takum, int) → takum */
	UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM,       /* takum → takum */
	UNIT_TEST_BLOCK_TYPE_TAKUM_TAKUM_TAKUM, /* (takum, takum) → takum */
	UNIT_TEST_BLOCK_TYPE_TAKUM_UINT8,       /* takum → takum */
};

struct unit_test_block {
	enum unit_test_block_type type;
	const char *function_name;

	union {
		struct {
			takum8 (*takum8_function)(takum8);
			takum16 (*takum16_function)(takum16);
			takum32 (*takum32_function)(takum32);
			takum64 (*takum64_function)(takum64);
			takum_linear8 (*takum_linear8_function)(takum_linear8);
			takum_linear16 (*takum_linear16_function)(
				takum_linear16);
			takum_linear32 (*takum_linear32_function)(
				takum_linear32);
			takum_linear64 (*takum_linear64_function)(
				takum_linear64);
		} roundtrip;

		struct {
			long double (*reference_function)(long double, int64_t);
			takum8 (*takum8_function)(takum8, int64_t);
			takum16 (*takum16_function)(takum16, int64_t);
			takum32 (*takum32_function)(takum32, int64_t);
			takum64 (*takum64_function)(takum64, int64_t);
			takum_linear8 (*takum_linear8_function)(takum_linear8,
			                                        int64_t);
			takum_linear16 (*takum_linear16_function)(
				takum_linear16, int64_t);
			takum_linear32 (*takum_linear32_function)(
				takum_linear32, int64_t);
			takum_linear64 (*takum_linear64_function)(
				takum_linear64, int64_t);
			const int64_t *integer_test_cases;
			size_t integer_test_case_count;
		} takum_int64_takum;

		struct {
			long double (*reference_function)(long double);
			takum8 (*takum8_function)(takum8);
			takum16 (*takum16_function)(takum16);
			takum32 (*takum32_function)(takum32);
			takum64 (*takum64_function)(takum64);
			takum_linear8 (*takum_linear8_function)(takum_linear8);
			takum_linear16 (*takum_linear16_function)(
				takum_linear16);
			takum_linear32 (*takum_linear32_function)(
				takum_linear32);
			takum_linear64 (*takum_linear64_function)(
				takum_linear64);
		} takum_takum;

		struct {
			long double (*reference_function)(long double,
			                                  long double);
			takum8 (*takum8_function)(takum8, takum8);
			takum16 (*takum16_function)(takum16, takum16);
			takum32 (*takum32_function)(takum32, takum32);
			takum64 (*takum64_function)(takum64, takum64);
			takum_linear8 (*takum_linear8_function)(takum_linear8,
			                                        takum_linear8);
			takum_linear16 (*takum_linear16_function)(
				takum_linear16, takum_linear16);
			takum_linear32 (*takum_linear32_function)(
				takum_linear32, takum_linear32);
			takum_linear64 (*takum_linear64_function)(
				takum_linear64, takum_linear64);
		} takum_takum_takum;

		struct {
			uint8_t (*reference_function)(long double,
			                              enum takum_type);
			uint8_t (*takum8_function)(takum8);
			uint8_t (*takum16_function)(takum16);
			uint8_t (*takum32_function)(takum32);
			uint8_t (*takum64_function)(takum64);
			uint8_t (*takum_linear8_function)(takum_linear8);
			uint8_t (*takum_linear16_function)(takum_linear16);
			uint8_t (*takum_linear32_function)(takum_linear32);
			uint8_t (*takum_linear64_function)(takum_linear64);
		} takum_uint8;
	} data;
};

int next_sample(int64_t *, enum unit_test_block_type, enum takum_type);
int run_unit_test_block(const struct unit_test_block *);

#endif
