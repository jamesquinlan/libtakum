/* See LICENSE file for copyright and license details. */
#ifndef TAKUM_H
#define TAKUM_H

#include <stdint.h>

/* Type definitions (presence of int*_t infers two's complement) */
typedef int8_t takum8;
typedef int16_t takum16;
typedef int32_t takum32;
typedef int64_t takum64;

/* type punning unions */
union takum_internal_takum8_union {
	takum8 value;
	uint8_t bits;
};

union takum_internal_takum16_union {
	takum16 value;
	uint16_t bits;
};

union takum_internal_takum32_union {
	takum32 value;
	uint32_t bits;
};

union takum_internal_takum64_union {
	takum64 value;
	uint64_t bits;
};

/* NaR definitions */
#define TAKUM8_NAR  (INT8_C(-127) - INT8_C(1))
#define TAKUM16_NAR (INT16_C(-32767) - INT16_C(1))
#define TAKUM32_NAR (INT32_C(-2147483647) - INT32_C(1))
#define TAKUM64_NAR (INT64_C(-9223372036854775807) - INT64_C(1))

/* Negation */
static inline takum8
takum8_negation(takum8 t)
{
	return -t;
}

static inline takum16
takum16_negation(takum16 t)
{
	return -t;
}

static inline takum32
takum32_negation(takum32 t)
{
	return -t;
}

static inline takum64
takum64_negation(takum64 t)
{
	return -t;
}

/* Inversion */
static inline takum8
takum8_inversion(takum8 t)
{
	union takum_internal_takum8_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT8_C(0x7f)) + 1;

	return out.value;
}

static inline takum16
takum16_inversion(takum16 t)
{
	union takum_internal_takum16_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT16_C(0x7fff)) + 1;

	return out.value;
}

static inline takum32
takum32_inversion(takum32 t)
{
	union takum_internal_takum32_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT32_C(0x7fffffff)) + 1;

	return out.value;
}

static inline takum64
takum64_inversion(takum64 t)
{
	union takum_internal_takum64_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT64_C(0x7fffffffffffffff)) + 1;

	return out.value;
}

/* Absolute */
static inline takum8
takum8_absolute(takum8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum16
takum16_absolute(takum16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum32
takum32_absolute(takum32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum64
takum64_absolute(takum64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

/* Sign */
static inline takum8
takum8_sign(takum8 t)
{
	/* TODO simplify! */
	return (t != 0) * ((t < 0) * UINT8_C(0xc0) + (t >= 0) * UINT8_C(0x40));
}

static inline takum16
takum16_sign(takum16 t)
{
	return (t != 0) *
	       ((t < 0) * UINT16_C(0xc000) + (t >= 0) * UINT16_C(0x4000));
}

static inline takum32
takum32_sign(takum32 t)
{
	return (t != 0) * ((t < 0) * UINT32_C(0xc0000000) +
	                   (t >= 0) * UINT32_C(0x40000000));
}

static inline takum64
takum64_sign(takum64 t)
{
	return (t != 0) * ((t < 0) * UINT64_C(0xc000000000000000) +
	                   (t >= 0) * UINT64_C(0x4000000000000000));
}

/* Addition */
takum8 takum8_addition(takum8, takum8);
takum16 takum16_addition(takum16, takum16);
takum32 takum32_addition(takum32, takum32);
takum64 takum64_addition(takum64, takum64);

/* Subtraction */
takum8 takum8_subtraction(takum8, takum8);
takum16 takum16_subtraction(takum16, takum16);
takum32 takum32_subtraction(takum32, takum32);
takum64 takum64_subtraction(takum64, takum64);

/* Multiplication */
takum8 takum8_multiplication(takum8, takum8);
takum16 takum16_multiplication(takum16, takum16);
takum32 takum32_multiplication(takum32, takum32);
takum64 takum64_multiplication(takum64, takum64);

/* Division */
takum8 takum8_division(takum8, takum8);
takum16 takum16_division(takum16, takum16);
takum32 takum32_division(takum32, takum32);
takum64 takum64_division(takum64, takum64);

/* Square Root */
takum8 takum8_square_root(takum8);
takum16 takum16_square_root(takum16);
takum32 takum32_square_root(takum32);
takum64 takum64_square_root(takum64);

/* Power */
takum8 takum8_power(takum8, takum8);
takum16 takum16_power(takum16, takum16);
takum32 takum32_power(takum32, takum32);
takum64 takum64_power(takum64, takum64);

/* Exponential Function */
takum8 takum8_exp(takum8);
takum16 takum16_exp(takum16);
takum32 takum32_exp(takum32);
takum64 takum64_exp(takum64);

/* Exponential Function Minus 1 */
takum8 takum8_exp_minus_1(takum8);
takum16 takum16_exp_minus_1(takum16);
takum32 takum32_exp_minus_1(takum32);
takum64 takum64_exp_minus_1(takum64);

/* Base 2 Exponential Function */
takum8 takum8_2_raised(takum8);
takum16 takum16_2_raised(takum16);
takum32 takum32_2_raised(takum32);
takum64 takum64_2_raised(takum64);

/* Base 2 Exponential Function Minus 1 */
takum8 takum8_2_raised_minus_1(takum8);
takum16 takum16_2_raised_minus_1(takum16);
takum32 takum32_2_raised_minus_1(takum32);
takum64 takum64_2_raised_minus_1(takum64);

/* Base 10 Exponential Function */
takum8 takum8_10_raised(takum8);
takum16 takum16_10_raised(takum16);
takum32 takum32_10_raised(takum32);
takum64 takum64_10_raised(takum64);

/* Base 10 Exponential Function Minus 1 */
takum8 takum8_10_raised_minus_1(takum8);
takum16 takum16_10_raised_minus_1(takum16);
takum32 takum32_10_raised_minus_1(takum32);
takum64 takum64_10_raised_minus_1(takum64);

/* Natural Logarithm (following ISO 80000) */
takum8 takum8_ln(takum8);
takum16 takum16_ln(takum16);
takum32 takum32_ln(takum32);
takum64 takum64_ln(takum64);

/* Natural Logarithm 1 Plus (following ISO 80000) */
takum8 takum8_ln_1_plus(takum8);
takum16 takum16_ln_1_plus(takum16);
takum32 takum32_ln_1_plus(takum32);
takum64 takum64_ln_1_plus(takum64);

/* Binary Logarithm (following ISO 80000) */
takum8 takum8_lb(takum8);
takum16 takum16_lb(takum16);
takum32 takum32_lb(takum32);
takum64 takum64_lb(takum64);

/* Binary Logarithm 1 Plus (following ISO 80000) */
takum8 takum8_lb_1_plus(takum8);
takum16 takum16_lb_1_plus(takum16);
takum32 takum32_lb_1_plus(takum32);
takum64 takum64_lb_1_plus(takum64);

/* Decadic Logarithm (following ISO 80000) */
takum8 takum8_lg(takum8);
takum16 takum16_lg(takum16);
takum32 takum32_lg(takum32);
takum64 takum64_lg(takum64);

/* Decadic Logarithm 1 Plus (following ISO 80000) */
takum8 takum8_lg_1_plus(takum8);
takum16 takum16_lg_1_plus(takum16);
takum32 takum32_lg_1_plus(takum32);
takum64 takum64_lg_1_plus(takum64);

/* Sine */
takum8 takum8_sin(takum8);
takum16 takum16_sin(takum16);
takum32 takum32_sin(takum32);
takum64 takum64_sin(takum64);

/* Sine Pi Times */
takum8 takum8_sin_pi_times(takum8);
takum16 takum16_sin_pi_times(takum16);
takum32 takum32_sin_pi_times(takum32);
takum64 takum64_sin_pi_times(takum64);

/* Cosecant */
takum8 takum8_csc(takum8);
takum16 takum16_csc(takum16);
takum32 takum32_csc(takum32);
takum64 takum64_csc(takum64);

/* Cosecant Pi Times */
takum8 takum8_csc_pi_times(takum8);
takum16 takum16_csc_pi_times(takum16);
takum32 takum32_csc_pi_times(takum32);
takum64 takum64_csc_pi_times(takum64);

/* Cosine */
takum8 takum8_cos(takum8);
takum16 takum16_cos(takum16);
takum32 takum32_cos(takum32);
takum64 takum64_cos(takum64);

/* Cosine Pi Times */
takum8 takum8_cos_pi_times(takum8);
takum16 takum16_cos_pi_times(takum16);
takum32 takum32_cos_pi_times(takum32);
takum64 takum64_cos_pi_times(takum64);

/* Secant */
takum8 takum8_sec(takum8);
takum16 takum16_sec(takum16);
takum32 takum32_sec(takum32);
takum64 takum64_sec(takum64);

/* Secant Pi Times */
takum8 takum8_sec_pi_times(takum8);
takum16 takum16_sec_pi_times(takum16);
takum32 takum32_sec_pi_times(takum32);
takum64 takum64_sec_pi_times(takum64);

/* Tangent */
takum8 takum8_tan(takum8);
takum16 takum16_tan(takum16);
takum32 takum32_tan(takum32);
takum64 takum64_tan(takum64);

/* Tangent Pi Times */
takum8 takum8_tan_pi_times(takum8);
takum16 takum16_tan_pi_times(takum16);
takum32 takum32_tan_pi_times(takum32);
takum64 takum64_tan_pi_times(takum64);

/* Cotangent */
takum8 takum8_cot(takum8);
takum16 takum16_cot(takum16);
takum32 takum32_cot(takum32);
takum64 takum64_cot(takum64);

/* Cotangent Pi Times */
takum8 takum8_cot_pi_times(takum8);
takum16 takum16_cot_pi_times(takum16);
takum32 takum32_cot_pi_times(takum32);
takum64 takum64_cot_pi_times(takum64);

/* Arcsine */
takum8 takum8_arcsin(takum8);
takum16 takum16_arcsin(takum16);
takum32 takum32_arcsin(takum32);
takum64 takum64_arcsin(takum64);

/* Arcsine Over Pi */
takum8 takum8_arcsin_over_pi(takum8);
takum16 takum16_arcsin_over_pi(takum16);
takum32 takum32_arcsin_over_pi(takum32);
takum64 takum64_arcsin_over_pi(takum64);

/* Arccosecant */
takum8 takum8_arccsc(takum8);
takum16 takum16_arccsc(takum16);
takum32 takum32_arccsc(takum32);
takum64 takum64_arccsc(takum64);

/* Arccosecant Over Pi */
takum8 takum8_arccsc_over_pi(takum8);
takum16 takum16_arccsc_over_pi(takum16);
takum32 takum32_arccsc_over_pi(takum32);
takum64 takum64_arccsc_over_pi(takum64);

/* Arccosine */
takum8 takum8_arccos(takum8);
takum16 takum16_arccos(takum16);
takum32 takum32_arccos(takum32);
takum64 takum64_arccos(takum64);

/* Arccosine Over Pi */
takum8 takum8_arccos_over_pi(takum8);
takum16 takum16_arccos_over_pi(takum16);
takum32 takum32_arccos_over_pi(takum32);
takum64 takum64_arccos_over_pi(takum64);

/* Arcsecant */
takum8 takum8_arcsec(takum8);
takum16 takum16_arcsec(takum16);
takum32 takum32_arcsec(takum32);
takum64 takum64_arcsec(takum64);

/* Arcsecant Over Pi */
takum8 takum8_arcsec_over_pi(takum8);
takum16 takum16_arcsec_over_pi(takum16);
takum32 takum32_arcsec_over_pi(takum32);
takum64 takum64_arcsec_over_pi(takum64);

/* Arctangent */
takum8 takum8_arctan(takum8);
takum16 takum16_arctan(takum16);
takum32 takum32_arctan(takum32);
takum64 takum64_arctan(takum64);

/* Arctangent Over Pi */
takum8 takum8_arctan_over_pi(takum8);
takum16 takum16_arctan_over_pi(takum16);
takum32 takum32_arctan_over_pi(takum32);
takum64 takum64_arctan_over_pi(takum64);

/* 2-Argument Arctangent */
takum8 takum8_arctan2(takum8, takum8);
takum16 takum16_arctan2(takum16, takum16);
takum32 takum32_arctan2(takum32, takum32);
takum64 takum64_arctan2(takum64, takum64);

/* 2-Argument Arctangent Over Pi */
takum8 takum8_arctan2_over_pi(takum8, takum8);
takum16 takum16_arctan2_over_pi(takum16, takum16);
takum32 takum32_arctan2_over_pi(takum32, takum32);
takum64 takum64_arctan2_over_pi(takum64, takum64);

/* Arccotangent */
takum8 takum8_arccot(takum8);
takum16 takum16_arccot(takum16);
takum32 takum32_arccot(takum32);
takum64 takum64_arccot(takum64);

/* Arccotangent Over Pi */
takum8 takum8_arccot_over_pi(takum8);
takum16 takum16_arccot_over_pi(takum16);
takum32 takum32_arccot_over_pi(takum32);
takum64 takum64_arccot_over_pi(takum64);

/* Hyperbolic Sine */
takum8 takum8_sinh(takum8);
takum16 takum16_sinh(takum16);
takum32 takum32_sinh(takum32);
takum64 takum64_sinh(takum64);

/* Hyperbolic Cosecant */
takum8 takum8_csch(takum8);
takum16 takum16_csch(takum16);
takum32 takum32_csch(takum32);
takum64 takum64_csch(takum64);

/* Hyperbolic Cosine */
takum8 takum8_cosh(takum8);
takum16 takum16_cosh(takum16);
takum32 takum32_cosh(takum32);
takum64 takum64_cosh(takum64);

/* Hyperbolic Secant */
takum8 takum8_sech(takum8);
takum16 takum16_sech(takum16);
takum32 takum32_sech(takum32);
takum64 takum64_sech(takum64);

/* Hyperbolic Tangent */
takum8 takum8_tanh(takum8);
takum16 takum16_tanh(takum16);
takum32 takum32_tanh(takum32);
takum64 takum64_tanh(takum64);

/* Hyperbolic Cotangent */
takum8 takum8_coth(takum8);
takum16 takum16_coth(takum16);
takum32 takum32_coth(takum32);
takum64 takum64_coth(takum64);

/* Area Hyperbolic Sine */
takum8 takum8_arsinh(takum8);
takum16 takum16_arsinh(takum16);
takum32 takum32_arsinh(takum32);
takum64 takum64_arsinh(takum64);

/* Area Hyperbolic Cosecant */
takum8 takum8_arcsch(takum8);
takum16 takum16_arcsch(takum16);
takum32 takum32_arcsch(takum32);
takum64 takum64_arcsch(takum64);

/* Area Hyperbolic Cosine */
takum8 takum8_arcosh(takum8);
takum16 takum16_arcosh(takum16);
takum32 takum32_arcosh(takum32);
takum64 takum64_arcosh(takum64);

/* Area Hyperbolic Secant */
takum8 takum8_arsech(takum8);
takum16 takum16_arsech(takum16);
takum32 takum32_arsech(takum32);
takum64 takum64_arsech(takum64);

/* Area Hyperbolic Tangent */
takum8 takum8_artanh(takum8);
takum16 takum16_artanh(takum16);
takum32 takum32_artanh(takum32);
takum64 takum64_artanh(takum64);

/* Area Hyperbolic Cotangent */
takum8 takum8_arcoth(takum8);
takum16 takum16_arcoth(takum16);
takum32 takum32_arcoth(takum32);
takum64 takum64_arcoth(takum64);

/* Hypotenuse sqrt(a^2+b^2) */
takum8 takum8_hypotenuse(takum8, takum8);
takum16 takum16_hypotenuse(takum16, takum16);
takum32 takum32_hypotenuse(takum32, takum32);
takum64 takum64_hypotenuse(takum64, takum64);

/* Takum conversion helper macros */
#define TAKUM_INTERNAL_CONVERT_EXPAND(FROM, TO)                                \
	do {                                                                   \
		const union takum_internal_takum##FROM##_union in = {          \
			.value = t,                                            \
		};                                                             \
		union takum_internal_takum##TO##_union out = {                 \
			.bits = ((uint##TO##_t)in.bits) << (TO - FROM),        \
		};                                                             \
                                                                               \
		return out.value;                                              \
	} while (0);

#define TAKUM_INTERNAL_CONVERT_REDUCE(FROM, TO)                                \
	do {                                                                   \
		const union takum_internal_takum##FROM##_union in = {          \
			.value = t,                                            \
		};                                                             \
		union takum_internal_takum##TO##_union out = {                 \
			.bits = (in.bits >> (FROM - TO)) +                     \
			        ((in.bits & UINT##FROM##_C(0x80)               \
			                            << (FROM - TO - 8)) ==     \
			         UINT##FROM##_C(0x80) << (FROM - TO - 8)),     \
		};                                                             \
		                                                               \
		/* saturate over-/underflows */                                \
		out.bits += (((out.bits == 0) & (in.bits != 0)) -              \
		             ((out.value == TAKUM##TO##_NAR) &                 \
		              (in.value != TAKUM##FROM##_NAR))) *              \
		            (1 - 2 * (out.bits & (UINT##TO##_C(0x80) != 0)));  \
                                                                               \
		return out.value;                                              \
	} while (0);

/* Conversion from takum8 */
static inline takum16
takum16_from_takum8(takum8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 16);
}

static inline takum32
takum32_from_takum8(takum8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 32);
}

static inline takum64
takum64_from_takum8(takum8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 64);
}

/* Conversion from takum16 */
static inline takum8
takum8_from_takum16(takum16 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(16, 8);
}

static inline takum32
takum32_from_takum16(takum16 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(16, 32);
}

static inline takum64
takum64_from_takum16(takum16 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(16, 64);
}

/* Conversion from takum32 */
static inline takum8
takum8_from_takum32(takum32 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(32, 8);
}

static inline takum16
takum16_from_takum32(takum32 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(32, 16);
}

static inline takum64
takum64_from_takum32(takum32 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(32, 64);
}

/* Conversion from takum64 */
static inline takum8
takum8_from_takum64(takum64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 8);
}

static inline takum16
takum16_from_takum64(takum64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 16);
}

static inline takum32
takum32_from_takum64(takum64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 32);
}

/* Conversion from float32 */
takum8 takum8_from_float32(float);
takum16 takum16_from_float32(float);
takum32 takum32_from_float32(float);
takum64 takum64_from_float32(float);

/* Conversion from float64 */
takum8 takum8_from_float64(double);
takum16 takum16_from_float64(double);
takum32 takum32_from_float64(double);
takum64 takum64_from_float64(double);

/* Conversion from extended float */
takum8 takum8_from_extended_float(long double);
takum16 takum16_from_extended_float(long double);
takum32 takum32_from_extended_float(long double);
takum64 takum64_from_extended_float(long double);

/* Conversion to float32 */
float takum8_to_float32(takum8);
float takum16_to_float32(takum16);
float takum32_to_float32(takum32);
float takum64_to_float32(takum64);

/* Conversion to float64 */
double takum8_to_float64(takum8);
double takum16_to_float64(takum16);
double takum32_to_float64(takum32);
double takum64_to_float64(takum64);

/* Conversion to extended float */
long double takum8_to_extended_float(takum8);
long double takum16_to_extended_float(takum16);
long double takum32_to_extended_float(takum32);
long double takum64_to_extended_float(takum64);

#endif /* TAKUM_H */
