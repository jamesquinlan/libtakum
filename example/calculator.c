/* See LICENSE file for copyright and license details. */
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../takum.h"

#include "util.h"

enum takum_type {
	TAKUM_TYPE_TAKUM8,
	TAKUM_TYPE_TAKUM16,
	TAKUM_TYPE_TAKUM32,
	TAKUM_TYPE_TAKUM64,
	TAKUM_TYPE_TAKUM_LINEAR8,
	TAKUM_TYPE_TAKUM_LINEAR16,
	TAKUM_TYPE_TAKUM_LINEAR32,
	TAKUM_TYPE_TAKUM_LINEAR64,
};

struct number {
	enum takum_type takum_type;
	takum8 takum8_value;
	takum16 takum16_value;
	takum32 takum32_value;
	takum64 takum64_value;
	takum_linear8 takum_linear8_value;
	takum_linear16 takum_linear16_value;
	takum_linear32 takum_linear32_value;
	takum_linear64 takum_linear64_value;
	int64_t integer_value;
};

static int
number_from_string(const char *token, enum takum_type takum_type,
                   struct number *number)
{
	long long raw_integer_value;
	long double raw_float_value, float_value;
	int64_t integer_value;
	char *integer_endptr, *float_endptr;

	/*
	 * First attempt to parse the string as an integer, specifying
	 * base 0 to support prefixes '0' and '0x' for octal and
	 * hexadecimal numbers respectively.
	 */
	raw_integer_value = strtoll(token, &integer_endptr, 0);
	raw_float_value = strtold(token, &float_endptr);

	if (*integer_endptr == '\0') {
		/*
		 * The number is integral, but we still have to check
		 * the bounds as long long can be larger than int64_t.
		 */
		if (raw_integer_value >= INT64_MAX ||
		    raw_integer_value < INT64_MIN) {
			/* Set the output to a non-integral NaR */
			float_value = NAN;
			integer_value = INT64_MAX;
		} else {
			float_value = (long double)raw_integer_value;
			integer_value = (int64_t)raw_integer_value;
		}
	} else if (*float_endptr == '\0') {
		if (raw_float_value == -1.0 || raw_float_value == 0.0 ||
		    raw_float_value == 1.0) {
			/* The number is integral -1, 0 or 1 */
			float_value = raw_float_value;
			integer_value = (int64_t)raw_float_value;
		} else {
			/*
			 * The number is not integral, but a decimal number.
			 * The cases infinity and NaN are just passed along.
			 */
			float_value = raw_float_value;
			integer_value = INT64_MAX;
		}
	} else {
		/* The number is neither integral nor decimal */
		fprintf(stderr, "invalid token '%s'\n", token);
		return 1;
	}

	/* Write the number's takum type into the number struct */
	number->takum_type = takum_type;

	/*
	 * Convert the float depending on the takum type, but also
	 * convert the takum value to the other types so we can always
	 * use them even if we mix types.
	 */
	switch (takum_type) {
	case TAKUM_TYPE_TAKUM8:
		number->takum8_value = takum8_from_extended_float(float_value);

		number->takum16_value =
			takum16_from_takum8(number->takum8_value);
		number->takum32_value =
			takum32_from_takum8(number->takum8_value);
		number->takum64_value =
			takum64_from_takum8(number->takum8_value);
		number->takum_linear8_value =
			takum_linear8_from_takum8(number->takum8_value);
		number->takum_linear16_value =
			takum_linear16_from_takum8(number->takum8_value);
		number->takum_linear32_value =
			takum_linear32_from_takum8(number->takum8_value);
		number->takum_linear64_value =
			takum_linear64_from_takum8(number->takum8_value);

		break;
	case TAKUM_TYPE_TAKUM16:
		number->takum16_value =
			takum16_from_extended_float(float_value);

		number->takum8_value =
			takum8_from_takum16(number->takum16_value);
		number->takum32_value =
			takum32_from_takum16(number->takum16_value);
		number->takum64_value =
			takum64_from_takum16(number->takum16_value);
		number->takum_linear8_value =
			takum_linear8_from_takum16(number->takum16_value);
		number->takum_linear16_value =
			takum_linear16_from_takum16(number->takum16_value);
		number->takum_linear32_value =
			takum_linear32_from_takum16(number->takum16_value);
		number->takum_linear64_value =
			takum_linear64_from_takum16(number->takum16_value);

		break;
	case TAKUM_TYPE_TAKUM32:
		number->takum32_value =
			takum32_from_extended_float(float_value);

		number->takum8_value =
			takum8_from_takum32(number->takum32_value);
		number->takum16_value =
			takum16_from_takum32(number->takum32_value);
		number->takum64_value =
			takum64_from_takum32(number->takum32_value);
		number->takum_linear8_value =
			takum_linear8_from_takum32(number->takum32_value);
		number->takum_linear16_value =
			takum_linear16_from_takum32(number->takum32_value);
		number->takum_linear32_value =
			takum_linear32_from_takum32(number->takum32_value);
		number->takum_linear64_value =
			takum_linear64_from_takum32(number->takum32_value);

		break;
	case TAKUM_TYPE_TAKUM64:
		number->takum64_value =
			takum64_from_extended_float(float_value);

		number->takum8_value =
			takum8_from_takum64(number->takum64_value);
		number->takum16_value =
			takum16_from_takum64(number->takum64_value);
		number->takum32_value =
			takum32_from_takum64(number->takum64_value);
		number->takum_linear8_value =
			takum_linear8_from_takum64(number->takum64_value);
		number->takum_linear16_value =
			takum_linear16_from_takum64(number->takum64_value);
		number->takum_linear32_value =
			takum_linear32_from_takum64(number->takum64_value);
		number->takum_linear64_value =
			takum_linear64_from_takum64(number->takum64_value);

		break;
	case TAKUM_TYPE_TAKUM_LINEAR8:
		number->takum_linear8_value =
			takum_linear8_from_extended_float(float_value);

		number->takum8_value =
			takum8_from_takum_linear8(number->takum_linear8_value);
		number->takum16_value =
			takum16_from_takum_linear8(number->takum_linear8_value);
		number->takum32_value =
			takum32_from_takum_linear8(number->takum_linear8_value);
		number->takum64_value =
			takum64_from_takum_linear8(number->takum_linear8_value);
		number->takum_linear16_value =
			takum_linear16_from_takum_linear8(
				number->takum_linear8_value);
		number->takum_linear32_value =
			takum_linear32_from_takum_linear8(
				number->takum_linear8_value);
		number->takum_linear64_value =
			takum_linear64_from_takum_linear8(
				number->takum_linear8_value);

		break;
	case TAKUM_TYPE_TAKUM_LINEAR16:
		number->takum_linear16_value =
			takum_linear16_from_extended_float(float_value);

		number->takum8_value = takum8_from_takum_linear16(
			number->takum_linear16_value);
		number->takum16_value = takum16_from_takum_linear16(
			number->takum_linear16_value);
		number->takum32_value = takum32_from_takum_linear16(
			number->takum_linear16_value);
		number->takum64_value = takum64_from_takum_linear16(
			number->takum_linear16_value);
		number->takum_linear8_value = takum_linear8_from_takum_linear16(
			number->takum_linear16_value);
		number->takum_linear32_value =
			takum_linear32_from_takum_linear16(
				number->takum_linear16_value);
		number->takum_linear64_value =
			takum_linear64_from_takum_linear16(
				number->takum_linear16_value);

		break;
	case TAKUM_TYPE_TAKUM_LINEAR32:
		number->takum_linear32_value =
			takum_linear32_from_extended_float(float_value);

		number->takum8_value = takum8_from_takum_linear32(
			number->takum_linear32_value);
		number->takum16_value = takum16_from_takum_linear32(
			number->takum_linear32_value);
		number->takum32_value = takum32_from_takum_linear32(
			number->takum_linear32_value);
		number->takum64_value = takum64_from_takum_linear32(
			number->takum_linear32_value);
		number->takum_linear8_value = takum_linear8_from_takum_linear32(
			number->takum_linear32_value);
		number->takum_linear16_value =
			takum_linear16_from_takum_linear32(
				number->takum_linear32_value);
		number->takum_linear64_value =
			takum_linear64_from_takum_linear32(
				number->takum_linear32_value);

		break;
	case TAKUM_TYPE_TAKUM_LINEAR64:
		number->takum_linear64_value =
			takum_linear64_from_extended_float(float_value);

		number->takum8_value = takum8_from_takum_linear64(
			number->takum_linear64_value);
		number->takum16_value = takum16_from_takum_linear64(
			number->takum_linear64_value);
		number->takum32_value = takum32_from_takum_linear64(
			number->takum_linear64_value);
		number->takum64_value = takum64_from_takum_linear64(
			number->takum_linear64_value);
		number->takum_linear8_value = takum_linear8_from_takum_linear64(
			number->takum_linear64_value);
		number->takum_linear16_value =
			takum_linear16_from_takum_linear64(
				number->takum_linear64_value);
		number->takum_linear32_value =
			takum_linear32_from_takum_linear64(
				number->takum_linear64_value);

		break;
	}

	number->integer_value = integer_value;

	return 0;
}

static void
number_from_takum8(takum8 t, struct number *number)
{
	number->takum_type = TAKUM_TYPE_TAKUM8;
	number->takum8_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == TAKUM8_ONE) {
		number->integer_value = 1;
	} else if (t == -TAKUM8_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum16_value = takum16_from_takum8(number->takum8_value);
	number->takum32_value = takum32_from_takum8(number->takum8_value);
	number->takum64_value = takum64_from_takum8(number->takum8_value);
	number->takum_linear8_value =
		takum_linear8_from_takum8(number->takum8_value);
	number->takum_linear16_value =
		takum_linear16_from_takum8(number->takum8_value);
	number->takum_linear32_value =
		takum_linear32_from_takum8(number->takum8_value);
	number->takum_linear64_value =
		takum_linear64_from_takum8(number->takum8_value);
}

static void
number_from_takum16(takum16 t, struct number *number)
{
	number->takum_type = TAKUM_TYPE_TAKUM16;
	number->takum16_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == TAKUM16_ONE) {
		number->integer_value = 1;
	} else if (t == -TAKUM16_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value = takum8_from_takum16(number->takum16_value);
	number->takum32_value = takum32_from_takum16(number->takum16_value);
	number->takum64_value = takum64_from_takum16(number->takum16_value);
	number->takum_linear8_value =
		takum_linear8_from_takum16(number->takum16_value);
	number->takum_linear16_value =
		takum_linear16_from_takum16(number->takum16_value);
	number->takum_linear32_value =
		takum_linear32_from_takum16(number->takum16_value);
	number->takum_linear64_value =
		takum_linear64_from_takum16(number->takum16_value);
}

static void
number_from_takum32(takum32 t, struct number *number)
{
	number->takum_type = TAKUM_TYPE_TAKUM32;
	number->takum32_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == TAKUM32_ONE) {
		number->integer_value = 1;
	} else if (t == -TAKUM32_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value = takum8_from_takum32(number->takum32_value);
	number->takum16_value = takum16_from_takum32(number->takum32_value);
	number->takum64_value = takum64_from_takum32(number->takum32_value);
	number->takum_linear8_value =
		takum_linear8_from_takum32(number->takum32_value);
	number->takum_linear16_value =
		takum_linear16_from_takum32(number->takum32_value);
	number->takum_linear32_value =
		takum_linear32_from_takum32(number->takum32_value);
	number->takum_linear64_value =
		takum_linear64_from_takum32(number->takum32_value);
}

static void
number_from_takum64(takum64 t, struct number *number)
{
	number->takum_type = TAKUM_TYPE_TAKUM64;
	number->takum64_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == TAKUM64_ONE) {
		number->integer_value = 1;
	} else if (t == -TAKUM64_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value = takum8_from_takum64(number->takum64_value);
	number->takum16_value = takum16_from_takum64(number->takum64_value);
	number->takum32_value = takum32_from_takum64(number->takum64_value);
	number->takum_linear8_value =
		takum_linear8_from_takum64(number->takum64_value);
	number->takum_linear16_value =
		takum_linear16_from_takum64(number->takum64_value);
	number->takum_linear32_value =
		takum_linear32_from_takum64(number->takum64_value);
	number->takum_linear64_value =
		takum_linear64_from_takum64(number->takum64_value);
}

static void
number_from_takum_linear8(takum_linear8 t, struct number *number)
{
	double float_value;

	number->takum_type = TAKUM_TYPE_TAKUM_LINEAR8;
	number->takum_linear8_value = t;

	float_value = takum_linear8_to_float64(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value =
		takum8_from_takum_linear8(number->takum_linear8_value);
	number->takum16_value =
		takum16_from_takum_linear8(number->takum_linear8_value);
	number->takum32_value =
		takum32_from_takum_linear8(number->takum_linear8_value);
	number->takum64_value =
		takum64_from_takum_linear8(number->takum_linear8_value);
	number->takum_linear16_value =
		takum_linear16_from_takum_linear8(number->takum_linear8_value);
	number->takum_linear32_value =
		takum_linear32_from_takum_linear8(number->takum_linear8_value);
	number->takum_linear64_value =
		takum_linear64_from_takum_linear8(number->takum_linear8_value);
}

static void
number_from_takum_linear16(takum_linear16 t, struct number *number)
{
	double float_value;

	number->takum_type = TAKUM_TYPE_TAKUM_LINEAR16;
	number->takum_linear16_value = t;

	float_value = takum_linear16_to_float64(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value =
		takum8_from_takum_linear16(number->takum_linear16_value);
	number->takum16_value =
		takum16_from_takum_linear16(number->takum_linear16_value);
	number->takum32_value =
		takum32_from_takum_linear16(number->takum_linear16_value);
	number->takum64_value =
		takum64_from_takum_linear16(number->takum_linear16_value);
	number->takum_linear8_value =
		takum_linear8_from_takum_linear16(number->takum_linear16_value);
	number->takum_linear32_value = takum_linear32_from_takum_linear16(
		number->takum_linear16_value);
	number->takum_linear64_value = takum_linear64_from_takum_linear16(
		number->takum_linear16_value);
}

static void
number_from_takum_linear32(takum_linear32 t, struct number *number)
{
	double float_value;

	number->takum_type = TAKUM_TYPE_TAKUM_LINEAR32;
	number->takum_linear32_value = t;

	float_value = takum_linear32_to_float64(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value =
		takum8_from_takum_linear32(number->takum_linear32_value);
	number->takum16_value =
		takum16_from_takum_linear32(number->takum_linear32_value);
	number->takum32_value =
		takum32_from_takum_linear32(number->takum_linear32_value);
	number->takum64_value =
		takum64_from_takum_linear32(number->takum_linear32_value);
	number->takum_linear8_value =
		takum_linear8_from_takum_linear32(number->takum_linear32_value);
	number->takum_linear16_value = takum_linear16_from_takum_linear32(
		number->takum_linear32_value);
	number->takum_linear64_value = takum_linear64_from_takum_linear32(
		number->takum_linear32_value);
}

static void
number_from_takum_linear64(takum_linear64 t, struct number *number)
{
	long double float_value;

	number->takum_type = TAKUM_TYPE_TAKUM_LINEAR64;
	number->takum_linear64_value = t;

	float_value = takum_linear64_to_extended_float(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->takum8_value =
		takum8_from_takum_linear64(number->takum_linear64_value);
	number->takum16_value =
		takum16_from_takum_linear64(number->takum_linear64_value);
	number->takum32_value =
		takum32_from_takum_linear64(number->takum_linear64_value);
	number->takum64_value =
		takum64_from_takum_linear64(number->takum_linear64_value);
	number->takum_linear8_value =
		takum_linear8_from_takum_linear64(number->takum_linear64_value);
	number->takum_linear16_value = takum_linear16_from_takum_linear64(
		number->takum_linear64_value);
	number->takum_linear32_value = takum_linear32_from_takum_linear64(
		number->takum_linear64_value);
}

static void
number_print(const struct number *number)
{
	if (number->integer_value != INT64_MAX) {
		/* the number is integral */
		printf("%" PRIi64 "\n", number->integer_value);
	} else {
		long double float_value = 0.0;

		switch (number->takum_type) {
		case TAKUM_TYPE_TAKUM8:
			float_value =
				takum8_to_extended_float(number->takum8_value);
			break;
		case TAKUM_TYPE_TAKUM16:
			float_value = takum16_to_extended_float(
				number->takum16_value);
			break;
		case TAKUM_TYPE_TAKUM32:
			float_value = takum32_to_extended_float(
				number->takum32_value);
			break;
		case TAKUM_TYPE_TAKUM64:
			float_value = takum64_to_extended_float(
				number->takum64_value);
			break;
		case TAKUM_TYPE_TAKUM_LINEAR8:
			float_value = takum_linear8_to_extended_float(
				number->takum_linear8_value);
			break;
		case TAKUM_TYPE_TAKUM_LINEAR16:
			float_value = takum_linear16_to_extended_float(
				number->takum_linear16_value);
			break;
		case TAKUM_TYPE_TAKUM_LINEAR32:
			float_value = takum_linear32_to_extended_float(
				number->takum_linear32_value);
			break;
		case TAKUM_TYPE_TAKUM_LINEAR64:
			float_value = takum_linear64_to_extended_float(
				number->takum_linear64_value);
			break;
		}

		if (isnan(float_value)) {
			printf("NaR\n");
		} else {
			printf("%Lg\n", float_value);
		}
	}
}

struct stack {
	struct number *data;
	size_t size;
	size_t capacity;
};

static void
stack_init(struct stack *stack)
{
	stack->data = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

static void
stack_free(struct stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

static int
stack_push(struct stack *stack, const struct number *number)
{
	if (stack->size == stack->capacity) {
		/* expand stack */
		stack->capacity += 1;
		if ((stack->data = realloc(stack->data,
		                           stack->capacity *
		                                   sizeof(*(stack->data)))) ==
		    NULL) {
			fprintf(stderr, "could not expand stack due to memory "
			                "exhaustion\n");
			return 1;
		}
	}

	memcpy(&(stack->data[stack->size++]), number, sizeof(*number));

	return 0;
}

static int
stack_pop(struct stack *stack, struct number **number)
{
	if (stack->size == 0) {
		fprintf(stderr, "stack underflow\n");
		return 1;
	} else {
		*number = &(stack->data[--(stack->size)]);
		return 0;
	}
}

enum operator_type {
	OPERATOR_TYPE_HELP,
	OPERATOR_TYPE_POWER,
	OPERATOR_TYPE_PRECISION,
	OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
	OPERATOR_TYPE_TAKUM_INT64_TAKUM,
	OPERATOR_TYPE_TAKUM_TAKUM,
	OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
};

static const struct {
	const char *identifier;
	enum operator_type type;

	union {
		struct {
			enum takum_type type;
		} switch_takum_type;

		struct {
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
		} takum_int64_takum;

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
		} takum_takum;

		struct {
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
	} implementation;
} operators[] = {
	{
		.identifier = "?",
		.type = OPERATOR_TYPE_HELP,
	},
	{
		.identifier = "+",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_addition,
			.takum16_function = takum16_addition,
			.takum32_function = takum32_addition,
			.takum64_function = takum64_addition,
			.takum_linear8_function = takum_linear8_addition,
			.takum_linear16_function = takum_linear16_addition,
			.takum_linear32_function = takum_linear32_addition,
			.takum_linear64_function = takum_linear64_addition,
		},
	},
	{
		.identifier = "-",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_subtraction,
			.takum16_function = takum16_subtraction,
			.takum32_function = takum32_subtraction,
			.takum64_function = takum64_subtraction,
			.takum_linear8_function = takum_linear8_subtraction,
			.takum_linear16_function = takum_linear16_subtraction,
			.takum_linear32_function = takum_linear32_subtraction,
			.takum_linear64_function = takum_linear64_subtraction,
		},
	},
	{
		.identifier = "*",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_multiplication,
			.takum16_function = takum16_multiplication,
			.takum32_function = takum32_multiplication,
			.takum64_function = takum64_multiplication,
			.takum_linear8_function = takum_linear8_multiplication,
			.takum_linear16_function = takum_linear16_multiplication,
			.takum_linear32_function = takum_linear32_multiplication,
			.takum_linear64_function = takum_linear64_multiplication,
		},
	},
	{
		.identifier = "/",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_division,
			.takum16_function = takum16_division,
			.takum32_function = takum32_division,
			.takum64_function = takum64_division,
			.takum_linear8_function = takum_linear8_division,
			.takum_linear16_function = takum_linear16_division,
			.takum_linear32_function = takum_linear32_division,
			.takum_linear64_function = takum_linear64_division,
		},
	},
	{
		.identifier = "^",
		.type = OPERATOR_TYPE_POWER,
	},
	{
		.identifier = "abs",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_absolute,
			.takum16_function = takum16_absolute,
			.takum32_function = takum32_absolute,
			.takum64_function = takum64_absolute,
			.takum_linear8_function = takum_linear8_absolute,
			.takum_linear16_function = takum_linear16_absolute,
			.takum_linear32_function = takum_linear32_absolute,
			.takum_linear64_function = takum_linear64_absolute,
		},
	},
	{
		.identifier = "arccos",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arccos,
			.takum16_function = takum16_arccos,
			.takum32_function = takum32_arccos,
			.takum64_function = takum64_arccos,
			.takum_linear8_function = takum_linear8_arccos,
			.takum_linear16_function = takum_linear16_arccos,
			.takum_linear32_function = takum_linear32_arccos,
			.takum_linear64_function = takum_linear64_arccos,
		},
	},
	{
		.identifier = "arccos_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arccos_over_pi,
			.takum16_function = takum16_arccos_over_pi,
			.takum32_function = takum32_arccos_over_pi,
			.takum64_function = takum64_arccos_over_pi,
			.takum_linear8_function = takum_linear8_arccos_over_pi,
			.takum_linear16_function = takum_linear16_arccos_over_pi,
			.takum_linear32_function = takum_linear32_arccos_over_pi,
			.takum_linear64_function = takum_linear64_arccos_over_pi,
		},
	},
	{
		.identifier = "arccot",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arccot,
			.takum16_function = takum16_arccot,
			.takum32_function = takum32_arccot,
			.takum64_function = takum64_arccot,
			.takum_linear8_function = takum_linear8_arccot,
			.takum_linear16_function = takum_linear16_arccot,
			.takum_linear32_function = takum_linear32_arccot,
			.takum_linear64_function = takum_linear64_arccot,
		},
	},
	{
		.identifier = "arccot_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arccot_over_pi,
			.takum16_function = takum16_arccot_over_pi,
			.takum32_function = takum32_arccot_over_pi,
			.takum64_function = takum64_arccot_over_pi,
			.takum_linear8_function = takum_linear8_arccot_over_pi,
			.takum_linear16_function = takum_linear16_arccot_over_pi,
			.takum_linear32_function = takum_linear32_arccot_over_pi,
			.takum_linear64_function = takum_linear64_arccot_over_pi,
		},
	},
	{
		.identifier = "arccsc",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arccsc,
			.takum16_function = takum16_arccsc,
			.takum32_function = takum32_arccsc,
			.takum64_function = takum64_arccsc,
			.takum_linear8_function = takum_linear8_arccsc,
			.takum_linear16_function = takum_linear16_arccsc,
			.takum_linear32_function = takum_linear32_arccsc,
			.takum_linear64_function = takum_linear64_arccsc,
		},
	},
	{
		.identifier = "arccsc_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arccsc_over_pi,
			.takum16_function = takum16_arccsc_over_pi,
			.takum32_function = takum32_arccsc_over_pi,
			.takum64_function = takum64_arccsc_over_pi,
			.takum_linear8_function = takum_linear8_arccsc_over_pi,
			.takum_linear16_function = takum_linear16_arccsc_over_pi,
			.takum_linear32_function = takum_linear32_arccsc_over_pi,
			.takum_linear64_function = takum_linear64_arccsc_over_pi,
		},
	},
	{
		.identifier = "arcosh",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcosh,
			.takum16_function = takum16_arcosh,
			.takum32_function = takum32_arcosh,
			.takum64_function = takum64_arcosh,
			.takum_linear8_function = takum_linear8_arcosh,
			.takum_linear16_function = takum_linear16_arcosh,
			.takum_linear32_function = takum_linear32_arcosh,
			.takum_linear64_function = takum_linear64_arcosh,
		},
	},
	{
		.identifier = "arcoth",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcoth,
			.takum16_function = takum16_arcoth,
			.takum32_function = takum32_arcoth,
			.takum64_function = takum64_arcoth,
			.takum_linear8_function = takum_linear8_arcoth,
			.takum_linear16_function = takum_linear16_arcoth,
			.takum_linear32_function = takum_linear32_arcoth,
			.takum_linear64_function = takum_linear64_arcoth,
		},
	},
	{
		.identifier = "arcsch",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcsch,
			.takum16_function = takum16_arcsch,
			.takum32_function = takum32_arcsch,
			.takum64_function = takum64_arcsch,
			.takum_linear8_function = takum_linear8_arcsch,
			.takum_linear16_function = takum_linear16_arcsch,
			.takum_linear32_function = takum_linear32_arcsch,
			.takum_linear64_function = takum_linear64_arcsch,
		},
	},
	{
		.identifier = "arcsec",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcsec,
			.takum16_function = takum16_arcsec,
			.takum32_function = takum32_arcsec,
			.takum64_function = takum64_arcsec,
			.takum_linear8_function = takum_linear8_arcsec,
			.takum_linear16_function = takum_linear16_arcsec,
			.takum_linear32_function = takum_linear32_arcsec,
			.takum_linear64_function = takum_linear64_arcsec,
		},
	},
	{
		.identifier = "arcsec_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcsec_over_pi,
			.takum16_function = takum16_arcsec_over_pi,
			.takum32_function = takum32_arcsec_over_pi,
			.takum64_function = takum64_arcsec_over_pi,
			.takum_linear8_function = takum_linear8_arcsec_over_pi,
			.takum_linear16_function = takum_linear16_arcsec_over_pi,
			.takum_linear32_function = takum_linear32_arcsec_over_pi,
			.takum_linear64_function = takum_linear64_arcsec_over_pi,
		},
	},
	{
		.identifier = "arcsin",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcsin,
			.takum16_function = takum16_arcsin,
			.takum32_function = takum32_arcsin,
			.takum64_function = takum64_arcsin,
			.takum_linear8_function = takum_linear8_arcsin,
			.takum_linear16_function = takum_linear16_arcsin,
			.takum_linear32_function = takum_linear32_arcsin,
			.takum_linear64_function = takum_linear64_arcsin,
		},
	},
	{
		.identifier = "arcsin_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arcsin_over_pi,
			.takum16_function = takum16_arcsin_over_pi,
			.takum32_function = takum32_arcsin_over_pi,
			.takum64_function = takum64_arcsin_over_pi,
			.takum_linear8_function = takum_linear8_arcsin_over_pi,
			.takum_linear16_function = takum_linear16_arcsin_over_pi,
			.takum_linear32_function = takum_linear32_arcsin_over_pi,
			.takum_linear64_function = takum_linear64_arcsin_over_pi,
		},
	},
	{
		.identifier = "arctan2",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_arctan2,
			.takum16_function = takum16_arctan2,
			.takum32_function = takum32_arctan2,
			.takum64_function = takum64_arctan2,
			.takum_linear8_function = takum_linear8_arctan2,
			.takum_linear16_function = takum_linear16_arctan2,
			.takum_linear32_function = takum_linear32_arctan2,
			.takum_linear64_function = takum_linear64_arctan2,
		}
	},
	{
		.identifier = "arctan2_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_arctan2_over_pi,
			.takum16_function = takum16_arctan2_over_pi,
			.takum32_function = takum32_arctan2_over_pi,
			.takum64_function = takum64_arctan2_over_pi,
			.takum_linear8_function = takum_linear8_arctan2_over_pi,
			.takum_linear16_function = takum_linear16_arctan2_over_pi,
			.takum_linear32_function = takum_linear32_arctan2_over_pi,
			.takum_linear64_function = takum_linear64_arctan2_over_pi,
		},
	},
	{
		.identifier = "arctan",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arctan,
			.takum16_function = takum16_arctan,
			.takum32_function = takum32_arctan,
			.takum64_function = takum64_arctan,
			.takum_linear8_function = takum_linear8_arctan,
			.takum_linear16_function = takum_linear16_arctan,
			.takum_linear32_function = takum_linear32_arctan,
			.takum_linear64_function = takum_linear64_arctan,
		},
	},
	{
		.identifier = "arctan_over_pi",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arctan_over_pi,
			.takum16_function = takum16_arctan_over_pi,
			.takum32_function = takum32_arctan_over_pi,
			.takum64_function = takum64_arctan_over_pi,
			.takum_linear8_function = takum_linear8_arctan_over_pi,
			.takum_linear16_function = takum_linear16_arctan_over_pi,
			.takum_linear32_function = takum_linear32_arctan_over_pi,
			.takum_linear64_function = takum_linear64_arctan_over_pi,
		},
	},
	{
		.identifier = "arsech",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arsech,
			.takum16_function = takum16_arsech,
			.takum32_function = takum32_arsech,
			.takum64_function = takum64_arsech,
			.takum_linear8_function = takum_linear8_arsech,
			.takum_linear16_function = takum_linear16_arsech,
			.takum_linear32_function = takum_linear32_arsech,
			.takum_linear64_function = takum_linear64_arsech,
		},
	},
	{
		.identifier = "arsinh",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_arsinh,
			.takum16_function = takum16_arsinh,
			.takum32_function = takum32_arsinh,
			.takum64_function = takum64_arsinh,
			.takum_linear8_function = takum_linear8_arsinh,
			.takum_linear16_function = takum_linear16_arsinh,
			.takum_linear32_function = takum_linear32_arsinh,
			.takum_linear64_function = takum_linear64_arsinh,
		},
	},
	{
		.identifier = "artanh",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_artanh,
			.takum16_function = takum16_artanh,
			.takum32_function = takum32_artanh,
			.takum64_function = takum64_artanh,
			.takum_linear8_function = takum_linear8_artanh,
			.takum_linear16_function = takum_linear16_artanh,
			.takum_linear32_function = takum_linear32_artanh,
			.takum_linear64_function = takum_linear64_artanh,
		},
	},
	{
		.identifier = "cos",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_cos,
			.takum16_function = takum16_cos,
			.takum32_function = takum32_cos,
			.takum64_function = takum64_cos,
			.takum_linear8_function = takum_linear8_cos,
			.takum_linear16_function = takum_linear16_cos,
			.takum_linear32_function = takum_linear32_cos,
			.takum_linear64_function = takum_linear64_cos,
		},
	},
	{
		.identifier = "cos_pi_times",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_cos_pi_times,
			.takum16_function = takum16_cos_pi_times,
			.takum32_function = takum32_cos_pi_times,
			.takum64_function = takum64_cos_pi_times,
			.takum_linear8_function = takum_linear8_cos_pi_times,
			.takum_linear16_function = takum_linear16_cos_pi_times,
			.takum_linear32_function = takum_linear32_cos_pi_times,
			.takum_linear64_function = takum_linear64_cos_pi_times,
		},
	},
	{
		.identifier = "cosh",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_cosh,
			.takum16_function = takum16_cosh,
			.takum32_function = takum32_cosh,
			.takum64_function = takum64_cosh,
			.takum_linear8_function = takum_linear8_cosh,
			.takum_linear16_function = takum_linear16_cosh,
			.takum_linear32_function = takum_linear32_cosh,
			.takum_linear64_function = takum_linear64_cosh,
		},
	},
	{
		.identifier = "cot",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_cot,
			.takum16_function = takum16_cot,
			.takum32_function = takum32_cot,
			.takum64_function = takum64_cot,
			.takum_linear8_function = takum_linear8_cot,
			.takum_linear16_function = takum_linear16_cot,
			.takum_linear32_function = takum_linear32_cot,
			.takum_linear64_function = takum_linear64_cot,
		},
	},
	{
		.identifier = "cot_pi_times",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_cot_pi_times,
			.takum16_function = takum16_cot_pi_times,
			.takum32_function = takum32_cot_pi_times,
			.takum64_function = takum64_cot_pi_times,
			.takum_linear8_function = takum_linear8_cot_pi_times,
			.takum_linear16_function = takum_linear16_cot_pi_times,
			.takum_linear32_function = takum_linear32_cot_pi_times,
			.takum_linear64_function = takum_linear64_cot_pi_times,
		},
	},
	{
		.identifier = "coth",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_coth,
			.takum16_function = takum16_coth,
			.takum32_function = takum32_coth,
			.takum64_function = takum64_coth,
			.takum_linear8_function = takum_linear8_coth,
			.takum_linear16_function = takum_linear16_coth,
			.takum_linear32_function = takum_linear32_coth,
			.takum_linear64_function = takum_linear64_coth,
		},
	},
	{
		.identifier = "csc",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_csc,
			.takum16_function = takum16_csc,
			.takum32_function = takum32_csc,
			.takum64_function = takum64_csc,
			.takum_linear8_function = takum_linear8_csc,
			.takum_linear16_function = takum_linear16_csc,
			.takum_linear32_function = takum_linear32_csc,
			.takum_linear64_function = takum_linear64_csc,
		},
	},
	{
		.identifier = "csc_pi_times",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_csc_pi_times,
			.takum16_function = takum16_csc_pi_times,
			.takum32_function = takum32_csc_pi_times,
			.takum64_function = takum64_csc_pi_times,
			.takum_linear8_function = takum_linear8_csc_pi_times,
			.takum_linear16_function = takum_linear16_csc_pi_times,
			.takum_linear32_function = takum_linear32_csc_pi_times,
			.takum_linear64_function = takum_linear64_csc_pi_times,
		},
	},
	{
		.identifier = "csch",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_csch,
			.takum16_function = takum16_csch,
			.takum32_function = takum32_csch,
			.takum64_function = takum64_csch,
			.takum_linear8_function = takum_linear8_csch,
			.takum_linear16_function = takum_linear16_csch,
			.takum_linear32_function = takum_linear32_csch,
			.takum_linear64_function = takum_linear64_csch,
		},
	},
	{
		.identifier = "exp",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_exp,
			.takum16_function = takum16_exp,
			.takum32_function = takum32_exp,
			.takum64_function = takum64_exp,
			.takum_linear8_function = takum_linear8_exp,
			.takum_linear16_function = takum_linear16_exp,
			.takum_linear32_function = takum_linear32_exp,
			.takum_linear64_function = takum_linear64_exp,
		},
	},
	{
		.identifier = "exp_minus_1",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_exp_minus_1,
			.takum16_function = takum16_exp_minus_1,
			.takum32_function = takum32_exp_minus_1,
			.takum64_function = takum64_exp_minus_1,
			.takum_linear8_function = takum_linear8_exp_minus_1,
			.takum_linear16_function = takum_linear16_exp_minus_1,
			.takum_linear32_function = takum_linear32_exp_minus_1,
			.takum_linear64_function = takum_linear64_exp_minus_1,
		},
	},
	{
		.identifier = "hypotenuse",
		.type = OPERATOR_TYPE_TAKUM_TAKUM_TAKUM,
		.implementation.takum_takum_takum = {
			.takum8_function = takum8_hypotenuse,
			.takum16_function = takum16_hypotenuse,
			.takum32_function = takum32_hypotenuse,
			.takum64_function = takum64_hypotenuse,
			.takum_linear8_function = takum_linear8_hypotenuse,
			.takum_linear16_function = takum_linear16_hypotenuse,
			.takum_linear32_function = takum_linear32_hypotenuse,
			.takum_linear64_function = takum_linear64_hypotenuse,
		},
	},
	{
		.identifier = "root",
		.type = OPERATOR_TYPE_TAKUM_INT64_TAKUM,
		.implementation.takum_int64_takum = {
			.takum8_function = takum8_root,
			.takum16_function = takum16_root,
			.takum32_function = takum32_root,
			.takum64_function = takum64_root,
			.takum_linear8_function = takum_linear8_root,
			.takum_linear16_function = takum_linear16_root,
			.takum_linear32_function = takum_linear32_root,
			.takum_linear64_function = takum_linear64_root,
		},
	},
	{
		.identifier = "inv",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_inversion,
			.takum16_function = takum16_inversion,
			.takum32_function = takum32_inversion,
			.takum64_function = takum64_inversion,
			.takum_linear8_function = takum_linear8_inversion,
			.takum_linear16_function = takum_linear16_inversion,
			.takum_linear32_function = takum_linear32_inversion,
			.takum_linear64_function = takum_linear64_inversion,
		},
	},
	{
		.identifier = "lb",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_lb,
			.takum16_function = takum16_lb,
			.takum32_function = takum32_lb,
			.takum64_function = takum64_lb,
			.takum_linear8_function = takum_linear8_lb,
			.takum_linear16_function = takum_linear16_lb,
			.takum_linear32_function = takum_linear32_lb,
			.takum_linear64_function = takum_linear64_lb,
		},
	},
	{
		.identifier = "lb_1_plus",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_lb_1_plus,
			.takum16_function = takum16_lb_1_plus,
			.takum32_function = takum32_lb_1_plus,
			.takum64_function = takum64_lb_1_plus,
			.takum_linear8_function = takum_linear8_lb_1_plus,
			.takum_linear16_function = takum_linear16_lb_1_plus,
			.takum_linear32_function = takum_linear32_lb_1_plus,
			.takum_linear64_function = takum_linear64_lb_1_plus,
		},
	},
	{
		.identifier = "lg",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_lg,
			.takum16_function = takum16_lg,
			.takum32_function = takum32_lg,
			.takum64_function = takum64_lg,
			.takum_linear8_function = takum_linear8_lg,
			.takum_linear16_function = takum_linear16_lg,
			.takum_linear32_function = takum_linear32_lg,
			.takum_linear64_function = takum_linear64_lg,
		},
	},
	{
		.identifier = "lg_1_plus",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_lg_1_plus,
			.takum16_function = takum16_lg_1_plus,
			.takum32_function = takum32_lg_1_plus,
			.takum64_function = takum64_lg_1_plus,
			.takum_linear8_function = takum_linear8_lg_1_plus,
			.takum_linear16_function = takum_linear16_lg_1_plus,
			.takum_linear32_function = takum_linear32_lg_1_plus,
			.takum_linear64_function = takum_linear64_lg_1_plus,
		},
	},
	{
		.identifier = "ln",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_ln,
			.takum16_function = takum16_ln,
			.takum32_function = takum32_ln,
			.takum64_function = takum64_ln,
			.takum_linear8_function = takum_linear8_ln,
			.takum_linear16_function = takum_linear16_ln,
			.takum_linear32_function = takum_linear32_ln,
			.takum_linear64_function = takum_linear64_ln,
		},
	},
	{
		.identifier = "ln_1_plus",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_ln_1_plus,
			.takum16_function = takum16_ln_1_plus,
			.takum32_function = takum32_ln_1_plus,
			.takum64_function = takum64_ln_1_plus,
			.takum_linear8_function = takum_linear8_ln_1_plus,
			.takum_linear16_function = takum_linear16_ln_1_plus,
			.takum_linear32_function = takum_linear32_ln_1_plus,
			.takum_linear64_function = takum_linear64_ln_1_plus,
		},
	},
	{
		.identifier = "precision",
		.type = OPERATOR_TYPE_PRECISION,
	},
	{
		.identifier = "sec",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sec,
			.takum16_function = takum16_sec,
			.takum32_function = takum32_sec,
			.takum64_function = takum64_sec,
			.takum_linear8_function = takum_linear8_sec,
			.takum_linear16_function = takum_linear16_sec,
			.takum_linear32_function = takum_linear32_sec,
			.takum_linear64_function = takum_linear64_sec,
		},
	},
	{
		.identifier = "sec_pi_times",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sec_pi_times,
			.takum16_function = takum16_sec_pi_times,
			.takum32_function = takum32_sec_pi_times,
			.takum64_function = takum64_sec_pi_times,
			.takum_linear8_function = takum_linear8_sec_pi_times,
			.takum_linear16_function = takum_linear16_sec_pi_times,
			.takum_linear32_function = takum_linear32_sec_pi_times,
			.takum_linear64_function = takum_linear64_sec_pi_times,
		},
	},
	{
		.identifier = "sech",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sech,
			.takum16_function = takum16_sech,
			.takum32_function = takum32_sech,
			.takum64_function = takum64_sech,
			.takum_linear8_function = takum_linear8_sech,
			.takum_linear16_function = takum_linear16_sech,
			.takum_linear32_function = takum_linear32_sech,
			.takum_linear64_function = takum_linear64_sech,
		},
	},
	{
		.identifier = "sign",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sign,
			.takum16_function = takum16_sign,
			.takum32_function = takum32_sign,
			.takum64_function = takum64_sign,
			.takum_linear8_function = takum_linear8_sign,
			.takum_linear16_function = takum_linear16_sign,
			.takum_linear32_function = takum_linear32_sign,
			.takum_linear64_function = takum_linear64_sign,
		},
	},
	{
		.identifier = "sin",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sin,
			.takum16_function = takum16_sin,
			.takum32_function = takum32_sin,
			.takum64_function = takum64_sin,
			.takum_linear8_function = takum_linear8_sin,
			.takum_linear16_function = takum_linear16_sin,
			.takum_linear32_function = takum_linear32_sin,
			.takum_linear64_function = takum_linear64_sin,
		},
	},
	{
		.identifier = "sin_pi_times",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sin_pi_times,
			.takum16_function = takum16_sin_pi_times,
			.takum32_function = takum32_sin_pi_times,
			.takum64_function = takum64_sin_pi_times,
			.takum_linear8_function = takum_linear8_sin_pi_times,
			.takum_linear16_function = takum_linear16_sin_pi_times,
			.takum_linear32_function = takum_linear32_sin_pi_times,
			.takum_linear64_function = takum_linear64_sin_pi_times,
		},
	},
	{
		.identifier = "sinh",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_sinh,
			.takum16_function = takum16_sinh,
			.takum32_function = takum32_sinh,
			.takum64_function = takum64_sinh,
			.takum_linear8_function = takum_linear8_sinh,
			.takum_linear16_function = takum_linear16_sinh,
			.takum_linear32_function = takum_linear32_sinh,
			.takum_linear64_function = takum_linear64_sinh,
		},
	},
	{
		.identifier = "sqrt",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_square_root,
			.takum16_function = takum16_square_root,
			.takum32_function = takum32_square_root,
			.takum64_function = takum64_square_root,
			.takum_linear8_function = takum_linear8_square_root,
			.takum_linear16_function = takum_linear16_square_root,
			.takum_linear32_function = takum_linear32_square_root,
			.takum_linear64_function = takum_linear64_square_root,
		},
	},
	{
		.identifier = "takum8",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM8,
		},
	},
	{
		.identifier = "takum16",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM16,
		},
	},
	{
		.identifier = "takum32",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM32,
		},
	},
	{
		.identifier = "takum64",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM64,
		},
	},
	{
		.identifier = "takum_linear8",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM_LINEAR8,
		},
	},
	{
		.identifier = "takum_linear16",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM_LINEAR16,
		},
	},
	{
		.identifier = "takum_linear32",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM_LINEAR32,
		},
	},
	{
		.identifier = "takum_linear64",
		.type = OPERATOR_TYPE_SWITCH_TAKUM_TYPE,
		.implementation.switch_takum_type = {
			.type = TAKUM_TYPE_TAKUM_LINEAR64,
		},
	},
	{
		.identifier = "tan",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_tan,
			.takum16_function = takum16_tan,
			.takum32_function = takum32_tan,
			.takum64_function = takum64_tan,
			.takum_linear8_function = takum_linear8_tan,
			.takum_linear16_function = takum_linear16_tan,
			.takum_linear32_function = takum_linear32_tan,
			.takum_linear64_function = takum_linear64_tan,
		},
	},
	{
		.identifier = "tan_pi_times",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_tan_pi_times,
			.takum16_function = takum16_tan_pi_times,
			.takum32_function = takum32_tan_pi_times,
			.takum64_function = takum64_tan_pi_times,
			.takum_linear8_function = takum_linear8_tan_pi_times,
			.takum_linear16_function = takum_linear16_tan_pi_times,
			.takum_linear32_function = takum_linear32_tan_pi_times,
			.takum_linear64_function = takum_linear64_tan_pi_times,
		},
	},
	{
		.identifier = "tanh",
		.type = OPERATOR_TYPE_TAKUM_TAKUM,
		.implementation.takum_takum = {
			.takum8_function = takum8_tanh,
			.takum16_function = takum16_tanh,
			.takum32_function = takum32_tanh,
			.takum64_function = takum64_tanh,
			.takum_linear8_function = takum_linear8_tanh,
			.takum_linear16_function = takum_linear16_tanh,
			.takum_linear32_function = takum_linear32_tanh,
			.takum_linear64_function = takum_linear64_tanh,
		},
	},
};

static int
process_token(const char *token, struct stack *stack,
              enum takum_type *takum_type, const struct number *results)
{
	size_t i;
	struct number *a = NULL, *b = NULL, result;

	/*
	 * First check if the token is a single lowercase letter, which
	 * means we just want to push the specified result on the stack.
	 */
	if (strlen(token) == 1 && token[0] >= 'a' && token[0] <= 'z') {
		if (stack_push(stack, &(results[token[0] - 'a']))) {
			return 1;
		}

		return 0;
	}

	/* next try matching the token against the defined operators */
	for (i = 0; i < LEN(operators); i++) {
		size_t j;
		bool first_iteration;

		/* try matching the token against the operator identifier */
		if (strcmp(token, operators[i].identifier)) {
			continue;
		}

		/* we matched an operator! */
		switch (operators[i].type) {
		case OPERATOR_TYPE_HELP:
			printf("This is an RPN (reverse polish notation) "
			       "calculator. Thus you would not write "
			       "'1 + 1' but '1 1 +', for example. Each "
			       "result is stored in registers 'a' to 'z', "
			       "which can be used in subsequent expressions."
			       "\n\nYou can switch between the different takum "
			       "types used for calculations using the "
			       "respective operators ");
			for (j = 0, first_iteration = true; j < LEN(operators);
			     j++) {
				if (operators[j].type !=
				    OPERATOR_TYPE_SWITCH_TAKUM_TYPE) {
					continue;
				}
				if (!first_iteration) {
					printf(", ");
				} else {
					first_iteration = false;
				}
				printf("%s", operators[j].identifier);
			}
			printf(". Registers retain their respective "
			       "precisions, but behave as if they were "
			       "casted to the respective takum type.\n\n"
			       "The following operators are implemented: ");
			for (j = 0, first_iteration = true; j < LEN(operators);
			     j++) {
				if (operators[j].type ==
				    OPERATOR_TYPE_SWITCH_TAKUM_TYPE) {
					/*
					 * Skip the type switcher operators,
					 * as they are listed separately
					 */
					continue;
				}
				if (!first_iteration) {
					printf(", ");
				} else {
					first_iteration = false;
				}
				printf("%s", operators[j].identifier);
			}
			printf("\n\nPress Ctrl+D to exit.\n");

			/* return 1 to abort further line processing */
			return 1;

			break;
		case OPERATOR_TYPE_POWER:
			if (stack_pop(stack, &b) || stack_pop(stack, &a)) {
				return 1;
			}

			result.takum_type = *takum_type;
			result.integer_value = INT64_MAX;

			/* Call integer_power or power depending on if b is
			 * integral or not */
			if (b->integer_value == INT64_MAX) {
				switch (*takum_type) {
				case TAKUM_TYPE_TAKUM8:
					number_from_takum8(
						takum8_power(a->takum8_value,
					                     b->takum8_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM16:
					number_from_takum16(
						takum16_power(a->takum16_value,
					                      b->takum16_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM32:
					number_from_takum32(
						takum32_power(a->takum32_value,
					                      b->takum32_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM64:
					number_from_takum64(
						takum64_power(a->takum64_value,
					                      b->takum64_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR8:
					number_from_takum_linear8(
						takum_linear8_power(
							a->takum_linear8_value,
							b->takum_linear8_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR16:
					number_from_takum_linear16(
						takum_linear16_power(
							a->takum_linear16_value,
							b->takum_linear16_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR32:
					number_from_takum_linear32(
						takum_linear32_power(
							a->takum_linear32_value,
							b->takum_linear32_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR64:
					number_from_takum_linear64(
						takum_linear64_power(
							a->takum_linear64_value,
							b->takum_linear64_value),
						&result);
					break;
				}
			} else {
				switch (*takum_type) {
				case TAKUM_TYPE_TAKUM8:
					number_from_takum8(
						takum8_integer_power(
							a->takum8_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM16:
					number_from_takum16(
						takum16_integer_power(
							a->takum16_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM32:
					number_from_takum32(
						takum32_integer_power(
							a->takum32_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM64:
					number_from_takum64(
						takum64_integer_power(
							a->takum64_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR8:
					number_from_takum_linear8(
						takum_linear8_integer_power(
							a->takum_linear8_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR16:
					number_from_takum_linear16(
						takum_linear16_integer_power(
							a->takum_linear16_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR32:
					number_from_takum_linear32(
						takum_linear32_integer_power(
							a->takum_linear32_value,
							b->integer_value),
						&result);
					break;
				case TAKUM_TYPE_TAKUM_LINEAR64:
					number_from_takum_linear64(
						takum_linear64_integer_power(
							a->takum_linear64_value,
							b->integer_value),
						&result);
					break;
				}
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_PRECISION:
			if (stack_pop(stack, &a)) {
				return 1;
			}

			result.takum_type = *takum_type;

			switch (*takum_type) {
			case TAKUM_TYPE_TAKUM8:
				result.integer_value =
					takum8_precision(a->takum8_value);
				number_from_takum8(
					takum8_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM16:
				result.integer_value =
					takum16_precision(a->takum16_value);
				number_from_takum16(
					takum16_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM32:
				result.integer_value =
					takum32_precision(a->takum32_value);
				number_from_takum32(
					takum32_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM64:
				result.integer_value =
					takum64_precision(a->takum64_value);
				number_from_takum64(
					takum64_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR8:
				result.integer_value = takum_linear8_precision(
					a->takum_linear8_value);
				number_from_takum_linear8(
					takum_linear8_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR16:
				result.integer_value = takum_linear16_precision(
					a->takum_linear16_value);
				number_from_takum_linear16(
					takum_linear16_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR32:
				result.integer_value = takum_linear32_precision(
					a->takum_linear32_value);
				number_from_takum_linear32(
					takum_linear32_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR64:
				result.integer_value = takum_linear64_precision(
					a->takum_linear64_value);
				number_from_takum_linear64(
					takum_linear64_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_SWITCH_TAKUM_TYPE:
			*takum_type =
				operators[i]
					.implementation.switch_takum_type.type;

			/* return 1 to abort further line processing */
			return 1;

			break;
		case OPERATOR_TYPE_TAKUM_INT64_TAKUM:
			if (stack_pop(stack, &b) || stack_pop(stack, &a) ||
			    b->integer_value == INT64_MAX) {
				return 1;
			}

			result.takum_type = *takum_type;
			result.integer_value = INT64_MAX;

			switch (*takum_type) {
			case TAKUM_TYPE_TAKUM8:
				number_from_takum8(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum8_function(
							a->takum8_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM16:
				number_from_takum16(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum16_function(
							a->takum16_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM32:
				number_from_takum32(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum32_function(
							a->takum32_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM64:
				number_from_takum64(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum64_function(
							a->takum64_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR8:
				number_from_takum_linear8(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum_linear8_function(
							a->takum_linear8_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR16:
				number_from_takum_linear16(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum_linear16_function(
							a->takum_linear16_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR32:
				number_from_takum_linear32(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum_linear32_function(
							a->takum_linear32_value,
							b->integer_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR64:
				number_from_takum_linear64(
					operators[i]
						.implementation
						.takum_int64_takum
						.takum_linear64_function(
							a->takum_linear64_value,
							b->integer_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_TAKUM_TAKUM:
			if (stack_pop(stack, &a)) {
				return 1;
			}

			result.takum_type = *takum_type;
			result.integer_value = INT64_MAX;

			switch (*takum_type) {
			case TAKUM_TYPE_TAKUM8:
				number_from_takum8(
					operators[i]
						.implementation.takum_takum
						.takum8_function(
							a->takum8_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM16:
				number_from_takum16(
					operators[i]
						.implementation.takum_takum
						.takum16_function(
							a->takum16_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM32:
				number_from_takum32(
					operators[i]
						.implementation.takum_takum
						.takum32_function(
							a->takum32_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM64:
				number_from_takum64(
					operators[i]
						.implementation.takum_takum
						.takum64_function(
							a->takum64_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR8:
				number_from_takum_linear8(
					operators[i]
						.implementation.takum_takum
						.takum_linear8_function(
							a->takum_linear8_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR16:
				number_from_takum_linear16(
					operators[i]
						.implementation.takum_takum
						.takum_linear16_function(
							a->takum_linear16_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR32:
				number_from_takum_linear32(
					operators[i]
						.implementation.takum_takum
						.takum_linear32_function(
							a->takum_linear32_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR64:
				number_from_takum_linear64(
					operators[i]
						.implementation.takum_takum
						.takum_linear64_function(
							a->takum_linear64_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_TAKUM_TAKUM_TAKUM:
			if (stack_pop(stack, &b) || stack_pop(stack, &a)) {
				return 1;
			}

			result.takum_type = *takum_type;
			result.integer_value = INT64_MAX;

			switch (*takum_type) {
			case TAKUM_TYPE_TAKUM8:
				number_from_takum8(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum8_function(
							a->takum8_value,
							b->takum8_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM16:
				number_from_takum16(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum16_function(
							a->takum16_value,
							b->takum16_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM32:
				number_from_takum32(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum32_function(
							a->takum32_value,
							b->takum32_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM64:
				number_from_takum64(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum64_function(
							a->takum64_value,
							b->takum64_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR8:
				number_from_takum_linear8(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum_linear8_function(
							a->takum_linear8_value,
							b->takum_linear8_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR16:
				number_from_takum_linear16(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum_linear16_function(
							a->takum_linear16_value,
							b->takum_linear16_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR32:
				number_from_takum_linear32(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum_linear32_function(
							a->takum_linear32_value,
							b->takum_linear32_value),
					&result);
				break;
			case TAKUM_TYPE_TAKUM_LINEAR64:
				number_from_takum_linear64(
					operators[i]
						.implementation
						.takum_takum_takum
						.takum_linear64_function(
							a->takum_linear64_value,
							b->takum_linear64_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		}

		/* we break out of the loop given we matched an operator */
		break;
	}

	if (i == LEN(operators)) {
		/* we matched no operator, so this must be a number */
		return number_from_string(token, *takum_type, &result) ||
		       stack_push(stack, &result);
	}

	return 0;
}

int
main(void)
{
	enum takum_type takum_type = TAKUM_TYPE_TAKUM64;
	struct stack stack;
	struct number results['z' - 'a' + 1] = { 0 };
	char *line = NULL;
	size_t result_offset, line_capacity = 0;

	/* print REPL symbol */
	printf("type '?' for help\n> ");

	/* initialise stack */
	stack_init(&stack);

	/* we start off with result 'a' */
	result_offset = 0;

	/* continuously read input lines */
	while (getline(&line, &line_capacity, stdin) != -1) {
		/* clear the stack but do not deallocate */
		stack.size = 0;

		/* tokenise the string by spaces */
		char *token = strtok(line, " \n");
		while (token != NULL) {
			if (process_token(token, &stack, &takum_type,
			                  results)) {
				break;
			}

			/* get next token */
			token = strtok(NULL, " \n");

			if (token == NULL) {
				/*
				 * End of line, check if stack has
				 * exactly one element and print it
				 */
				if (stack.size != 1) {
					fprintf(stderr,
					        "invalid expression, final "
					        "stack size is not one\n");
				} else {
					struct number *number;

					/* get the single number on the stack */
					stack_pop(&stack, &number);

					/* output the number */
					printf("%c ← ",
					       'a' + (char)result_offset);
					number_print(number);

					/*
					 * put it in a corresponding result slot
					 */
					memcpy(&(results[result_offset]),
					       number, sizeof(*number));

					/*
					 * increment the result offset, but
					 * wrap around properly
					 */
					result_offset = (result_offset + 1) %
					                LEN(results);
				}

				/* We are done with this line */
				break;
			}
		}

		/* print REPL symbol */
		printf("> ");
	}

	/* cleanup */
	free(line);
	stack_free(&stack);

	return 0;
}
