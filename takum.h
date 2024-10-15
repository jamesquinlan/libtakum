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

/* NaR (Not a Real) */
#define TAKUM8_NAR  (INT8_C(-127) - INT8_C(1))
#define TAKUM16_NAR (INT16_C(-32767) - INT16_C(1))
#define TAKUM32_NAR (INT32_C(-2147483647) - INT32_C(1))
#define TAKUM64_NAR (INT64_C(-9223372036854775807) - INT64_C(1))

/* Smallest Positive */
#define TAKUM8_POSITIVE_MINIMUM  INT8_C(1)
#define TAKUM16_POSITIVE_MINIMUM INT16_C(1)
#define TAKUM32_POSITIVE_MINIMUM INT32_C(1)
#define TAKUM64_POSITIVE_MINIMUM INT64_C(1)

/* Largest Positive */
#define TAKUM8_POSITIVE_MAXIMUM  INT8_MAX
#define TAKUM16_POSITIVE_MAXIMUM INT16_MAX
#define TAKUM32_POSITIVE_MAXIMUM INT32_MAX
#define TAKUM64_POSITIVE_MAXIMUM INT64_MAX

/* 2π */
#define TAKUM8_2_PI  INT8_C(81)
#define TAKUM16_2_PI INT16_C(20826)
#define TAKUM32_2_PI INT32_C(1364851826)
#define TAKUM64_2_PI INT64_C(5861993956978437418)

/* 2π/3 */
#define TAKUM8_2_PI_OVER_3  INT8_C(74)
#define TAKUM16_2_PI_OVER_3 INT16_C(18922)
#define TAKUM32_2_PI_OVER_3 INT32_C(1240073127)
#define TAKUM64_2_PI_OVER_3 INT64_C(5326073524507235592)

/* 2π/5 */
#define TAKUM8_2_PI_OVER_5  INT8_C(68)
#define TAKUM16_2_PI_OVER_5 INT16_C(17320)
#define TAKUM32_2_PI_OVER_5 INT32_C(1135062992)
#define TAKUM64_2_PI_OVER_5 INT64_C(4875058431539642684)

/* 3π */
#define TAKUM8_3_PI  INT8_C(83)
#define TAKUM16_3_PI INT16_C(21241)
#define TAKUM32_3_PI INT32_C(1392062129)
#define TAKUM64_3_PI INT64_C(5978861317604848105)

/* 3π/2 */
#define TAKUM8_3_PI_OVER_2  INT8_C(80)
#define TAKUM16_3_PI_OVER_2 INT16_C(20531)
#define TAKUM32_3_PI_OVER_2 INT32_C(1345545809)
#define TAKUM64_3_PI_OVER_2 INT64_C(5779075245023556610)

/* 3π/4 */
#define TAKUM8_3_PI_OVER_4  INT8_C(75)
#define TAKUM16_3_PI_OVER_4 INT16_C(19163)
#define TAKUM32_3_PI_OVER_4 INT32_C(1255881698)
#define TAKUM64_3_PI_OVER_4 INT64_C(5393970821850295351)

/* 3π/5 */
#define TAKUM8_3_PI_OVER_5  INT8_C(73)
#define TAKUM16_3_PI_OVER_5 INT16_C(18706)
#define TAKUM32_3_PI_OVER_5 INT32_C(1225931878)
#define TAKUM64_3_PI_OVER_5 INT64_C(5265337322388048412)

/* 4π */
#define TAKUM8_4_PI  INT8_C(84)
#define TAKUM16_4_PI INT16_C(21536)
#define TAKUM32_4_PI INT32_C(1411368146)
#define TAKUM64_4_PI INT64_C(6061780029559728912)

/* 4π/3 */
#define TAKUM8_4_PI_OVER_3  INT8_C(79)
#define TAKUM16_4_PI_OVER_3 INT16_C(20342)
#define TAKUM32_4_PI_OVER_3 INT32_C(1333105767)
#define TAKUM64_4_PI_OVER_3 INT64_C(5725645669669818581)

/* 4π/5 */
#define TAKUM8_4_PI_OVER_5  INT8_C(75)
#define TAKUM16_4_PI_OVER_5 INT16_C(19295)
#define TAKUM32_4_PI_OVER_5 INT32_C(1264543912)
#define TAKUM64_4_PI_OVER_5 INT64_C(5431174746297810027)

/* 5π */
#define TAKUM8_5_PI  INT8_C(85)
#define TAKUM16_5_PI INT16_C(21764)
#define TAKUM32_5_PI INT32_C(1426343056)
#define TAKUM64_5_PI INT64_C(6126096779290852382)

/* 5π/2 */
#define TAKUM8_5_PI_OVER_2  INT8_C(82)
#define TAKUM16_5_PI_OVER_2 INT16_C(21054)
#define TAKUM32_5_PI_OVER_2 INT32_C(1379826736)
#define TAKUM64_5_PI_OVER_2 INT64_C(5926310706709560887)

/* 5π/3 */
#define TAKUM8_5_PI_OVER_3  INT8_C(81)
#define TAKUM16_5_PI_OVER_3 INT16_C(20639)
#define TAKUM32_5_PI_OVER_3 INT32_C(1352616434)
#define TAKUM64_5_PI_OVER_3 INT64_C(5809443346083150200)

/* 5π/4 */
#define TAKUM8_5_PI_OVER_4  INT8_C(79)
#define TAKUM16_5_PI_OVER_4 INT16_C(20209)
#define TAKUM32_5_PI_OVER_4 INT32_C(1324443553)
#define TAKUM64_5_PI_OVER_4 INT64_C(5688441745222303905)

/* 5π/6 */
#define TAKUM8_5_PI_OVER_6  INT8_C(76)
#define TAKUM16_5_PI_OVER_6 INT16_C(19379)
#define TAKUM32_5_PI_OVER_6 INT32_C(1270022947)
#define TAKUM64_5_PI_OVER_6 INT64_C(5454707023969482530)

/* 6π */
#define TAKUM8_6_PI  INT8_C(86)
#define TAKUM16_6_PI INT16_C(21951)
#define TAKUM32_6_PI INT32_C(1438578449)
#define TAKUM64_6_PI INT64_C(6178647390186139600)

/* 6π/5 */
#define TAKUM8_6_PI_OVER_5  INT8_C(79)
#define TAKUM16_6_PI_OVER_5 INT16_C(20126)
#define TAKUM32_6_PI_OVER_5 INT32_C(1318964518)
#define TAKUM64_6_PI_OVER_5 INT64_C(5664909467550631402)

/* Euler-Mascheroni Constant γ */
#define TAKUM8_GAMMA  INT8_C(56)
#define TAKUM16_GAMMA INT16_C(14235)
#define TAKUM32_GAMMA INT32_C(932875042)
#define TAKUM64_GAMMA INT64_C(4006667796493970688)

/* lb(10) */
#define TAKUM8_LB_10  INT8_C(78)
#define TAKUM16_LB_10 INT16_C(19867)
#define TAKUM32_LB_10 INT32_C(1301985159)
#define TAKUM64_LB_10 INT64_C(5591983679339631233)

/* lb(e) */
#define TAKUM8_LB_E  INT8_C(70)
#define TAKUM16_LB_E INT16_C(17885)
#define TAKUM32_LB_E INT32_C(1172126887)
#define TAKUM64_LB_E INT64_C(5034246646282250152)

/* lg(2) */
#define TAKUM8_LG_2  INT8_C(50)
#define TAKUM16_LG_2 INT16_C(12901)
#define TAKUM32_LG_2 INT32_C(845498489)
#define TAKUM64_LG_2 INT64_C(3631388357515144575)

/* lg(e) */
#define TAKUM8_LG_E  INT8_C(53)
#define TAKUM16_LG_E INT16_C(13652)
#define TAKUM32_LG_E INT32_C(894691020)
#define TAKUM64_LG_E INT64_C(3842668671442575700)

/* ln(10) */
#define TAKUM8_LN_10  INT8_C(75)
#define TAKUM16_LN_10 INT16_C(19116)
#define TAKUM32_LN_10 INT32_C(1252792628)
#define TAKUM64_LN_10 INT64_C(5380703365412200108)

/* ln(2) */
#define TAKUM8_LN_2  INT8_C(58)
#define TAKUM16_LN_2 INT16_C(14883)
#define TAKUM32_LN_2 INT32_C(975356761)
#define TAKUM64_LN_2 INT64_C(4189125390572525656)

/* constant 1 */
#define TAKUM8_ONE  INT8_C(64)
#define TAKUM16_ONE INT16_C(16384)
#define TAKUM32_ONE INT32_C(1073741824)
#define TAKUM64_ONE INT64_C(4611686018427387904)

/* Golden Ratio φ */
#define TAKUM8_PHI  INT8_C(72)
#define TAKUM16_PHI INT16_C(18355)
#define TAKUM32_PHI INT32_C(1202916140)
#define TAKUM64_PHI INT64_C(5166485479809712741)

/* π */
#define TAKUM8_PI  INT8_C(77)
#define TAKUM16_PI INT16_C(19752)
#define TAKUM32_PI INT32_C(1294493732)
#define TAKUM64_PI INT64_C(5559808245760056966)

/* π/2 */
#define TAKUM8_PI_OVER_2  INT8_C(71)
#define TAKUM16_PI_OVER_2 INT16_C(18234)
#define TAKUM32_PI_OVER_2 INT32_C(1194962633)
#define TAKUM64_PI_OVER_2 INT64_C(5132325430464136561)

/* π/3 */
#define TAKUM8_PI_OVER_3  INT8_C(65)
#define TAKUM16_PI_OVER_3 INT16_C(16573)
#define TAKUM32_PI_OVER_3 INT32_C(1086121422)
#define TAKUM64_PI_OVER_3 INT64_C(4664855987958493812)

/* π/4 */
#define TAKUM8_PI_OVER_4  INT8_C(60)
#define TAKUM16_PI_OVER_4 INT16_C(15395)
#define TAKUM32_PI_OVER_4 INT32_C(1008897354)
#define TAKUM64_PI_OVER_4 INT64_C(4333181140138970582)

/* π/5 */
#define TAKUM8_PI_OVER_5  INT8_C(57)
#define TAKUM16_PI_OVER_5 INT16_C(14481)
#define TAKUM32_PI_OVER_5 INT32_C(948997713)
#define TAKUM64_PI_OVER_5 INT64_C(4075914141214476705)

/* π/6 */
#define TAKUM8_PI_OVER_6  INT8_C(55)
#define TAKUM16_PI_OVER_6 INT16_C(14035)
#define TAKUM32_PI_OVER_6 INT32_C(919790119)
#define TAKUM64_PI_OVER_6 INT64_C(3950468481878646125)

/* √2 */
#define TAKUM8_SQUARE_ROOT_2  INT8_C(70)
#define TAKUM16_SQUARE_ROOT_2 INT16_C(17804)
#define TAKUM32_SQUARE_ROOT_2 INT32_C(1166774464)
#define TAKUM64_SQUARE_ROOT_2 INT64_C(5011258163589970893)

/* √3 */
#define TAKUM8_SQUARE_ROOT_3  INT8_C(72)
#define TAKUM16_SQUARE_ROOT_3 INT16_C(18533)
#define TAKUM32_SQUARE_ROOT_3 INT32_C(1214577311)
#define TAKUM64_SQUARE_ROOT_3 INT64_C(5216569827786801830)

/* √5 */
#define TAKUM8_SQUARE_ROOT_5  INT8_C(74)
#define TAKUM16_SQUARE_ROOT_5 INT16_C(19056)
#define TAKUM32_SQUARE_ROOT_5 INT32_C(1248858238)
#define TAKUM64_SQUARE_ROOT_5 INT64_C(5363805289472806107)

/* √6 */
#define TAKUM8_SQUARE_ROOT_6  INT8_C(75)
#define TAKUM16_SQUARE_ROOT_6 INT16_C(19243)
#define TAKUM32_SQUARE_ROOT_6 INT32_C(1261093631)
#define TAKUM64_SQUARE_ROOT_6 INT64_C(5416355900368093325)

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

/* Addition */
takum8 takum8_addition(takum8, takum8);
takum16 takum16_addition(takum16, takum16);
takum32 takum32_addition(takum32, takum32);
takum64 takum64_addition(takum64, takum64);

/* Arccosine */
takum8 takum8_arccos(takum8);
takum16 takum16_arccos(takum16);
takum32 takum32_arccos(takum32);
takum64 takum64_arccos(takum64);

/* Arccosine Over π */
takum8 takum8_arccos_over_pi(takum8);
takum16 takum16_arccos_over_pi(takum16);
takum32 takum32_arccos_over_pi(takum32);
takum64 takum64_arccos_over_pi(takum64);

/* Arccotangent */
takum8 takum8_arccot(takum8);
takum16 takum16_arccot(takum16);
takum32 takum32_arccot(takum32);
takum64 takum64_arccot(takum64);

/* Arccotangent Over π */
takum8 takum8_arccot_over_pi(takum8);
takum16 takum16_arccot_over_pi(takum16);
takum32 takum32_arccot_over_pi(takum32);
takum64 takum64_arccot_over_pi(takum64);

/* Arccosecant */
takum8 takum8_arccsc(takum8);
takum16 takum16_arccsc(takum16);
takum32 takum32_arccsc(takum32);
takum64 takum64_arccsc(takum64);

/* Arccosecant Over π */
takum8 takum8_arccsc_over_pi(takum8);
takum16 takum16_arccsc_over_pi(takum16);
takum32 takum32_arccsc_over_pi(takum32);
takum64 takum64_arccsc_over_pi(takum64);

/* Area Hyperbolic Cosine */
takum8 takum8_arcosh(takum8);
takum16 takum16_arcosh(takum16);
takum32 takum32_arcosh(takum32);
takum64 takum64_arcosh(takum64);

/* Area Hyperbolic Cotangent */
takum8 takum8_arcoth(takum8);
takum16 takum16_arcoth(takum16);
takum32 takum32_arcoth(takum32);
takum64 takum64_arcoth(takum64);

/* Area Hyperbolic Cosecant */
takum8 takum8_arcsch(takum8);
takum16 takum16_arcsch(takum16);
takum32 takum32_arcsch(takum32);
takum64 takum64_arcsch(takum64);

/* Arcsecant */
takum8 takum8_arcsec(takum8);
takum16 takum16_arcsec(takum16);
takum32 takum32_arcsec(takum32);
takum64 takum64_arcsec(takum64);

/* Arcsecant Over π */
takum8 takum8_arcsec_over_pi(takum8);
takum16 takum16_arcsec_over_pi(takum16);
takum32 takum32_arcsec_over_pi(takum32);
takum64 takum64_arcsec_over_pi(takum64);

/* Arcsine */
takum8 takum8_arcsin(takum8);
takum16 takum16_arcsin(takum16);
takum32 takum32_arcsin(takum32);
takum64 takum64_arcsin(takum64);

/* Arcsine Over π */
takum8 takum8_arcsin_over_pi(takum8);
takum16 takum16_arcsin_over_pi(takum16);
takum32 takum32_arcsin_over_pi(takum32);
takum64 takum64_arcsin_over_pi(takum64);

/* 2-Argument Arctangent */
takum8 takum8_arctan2(takum8, takum8);
takum16 takum16_arctan2(takum16, takum16);
takum32 takum32_arctan2(takum32, takum32);
takum64 takum64_arctan2(takum64, takum64);

/* 2-Argument Arctangent Over π */
takum8 takum8_arctan2_over_pi(takum8, takum8);
takum16 takum16_arctan2_over_pi(takum16, takum16);
takum32 takum32_arctan2_over_pi(takum32, takum32);
takum64 takum64_arctan2_over_pi(takum64, takum64);

/* Arctangent */
takum8 takum8_arctan(takum8);
takum16 takum16_arctan(takum16);
takum32 takum32_arctan(takum32);
takum64 takum64_arctan(takum64);

/* Arctangent Over π */
takum8 takum8_arctan_over_pi(takum8);
takum16 takum16_arctan_over_pi(takum16);
takum32 takum32_arctan_over_pi(takum32);
takum64 takum64_arctan_over_pi(takum64);

/* Area Hyperbolic Secant */
takum8 takum8_arsech(takum8);
takum16 takum16_arsech(takum16);
takum32 takum32_arsech(takum32);
takum64 takum64_arsech(takum64);

/* Area Hyperbolic Sine */
takum8 takum8_arsinh(takum8);
takum16 takum16_arsinh(takum16);
takum32 takum32_arsinh(takum32);
takum64 takum64_arsinh(takum64);

/* Area Hyperbolic Tangent */
takum8 takum8_artanh(takum8);
takum16 takum16_artanh(takum16);
takum32 takum32_artanh(takum32);
takum64 takum64_artanh(takum64);

/* Cosine */
takum8 takum8_cos(takum8);
takum16 takum16_cos(takum16);
takum32 takum32_cos(takum32);
takum64 takum64_cos(takum64);

/* Cosine π Times */
takum8 takum8_cos_pi_times(takum8);
takum16 takum16_cos_pi_times(takum16);
takum32 takum32_cos_pi_times(takum32);
takum64 takum64_cos_pi_times(takum64);

/* Hyperbolic Cosine */
takum8 takum8_cosh(takum8);
takum16 takum16_cosh(takum16);
takum32 takum32_cosh(takum32);
takum64 takum64_cosh(takum64);

/* Cotangent */
takum8 takum8_cot(takum8);
takum16 takum16_cot(takum16);
takum32 takum32_cot(takum32);
takum64 takum64_cot(takum64);

/* Cotangent π Times */
takum8 takum8_cot_pi_times(takum8);
takum16 takum16_cot_pi_times(takum16);
takum32 takum32_cot_pi_times(takum32);
takum64 takum64_cot_pi_times(takum64);

/* Hyperbolic Cotangent */
takum8 takum8_coth(takum8);
takum16 takum16_coth(takum16);
takum32 takum32_coth(takum32);
takum64 takum64_coth(takum64);

/* Cosecant */
takum8 takum8_csc(takum8);
takum16 takum16_csc(takum16);
takum32 takum32_csc(takum32);
takum64 takum64_csc(takum64);

/* Cosecant π Times */
takum8 takum8_csc_pi_times(takum8);
takum16 takum16_csc_pi_times(takum16);
takum32 takum32_csc_pi_times(takum32);
takum64 takum64_csc_pi_times(takum64);

/* Hyperbolic Cosecant */
takum8 takum8_csch(takum8);
takum16 takum16_csch(takum16);
takum32 takum32_csch(takum32);
takum64 takum64_csch(takum64);

/* Division */
takum8 takum8_division(takum8, takum8);
takum16 takum16_division(takum16, takum16);
takum32 takum32_division(takum32, takum32);
takum64 takum64_division(takum64, takum64);

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

/* Conversion from extended float */
takum8 takum8_from_extended_float(long double);
takum16 takum16_from_extended_float(long double);
takum32 takum32_from_extended_float(long double);
takum64 takum64_from_extended_float(long double);

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
		            (1 - 2 * (in.value < 0));                          \
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

/* Hypotenuse sqrt(a^2+b^2) */
takum8 takum8_hypotenuse(takum8, takum8);
takum16 takum16_hypotenuse(takum16, takum16);
takum32 takum32_hypotenuse(takum32, takum32);
takum64 takum64_hypotenuse(takum64, takum64);

/* Integer Power */
takum8 takum8_integer_power(takum8, int64_t);
takum16 takum16_integer_power(takum16, int64_t);
takum32 takum32_integer_power(takum32, int64_t);
takum64 takum64_integer_power(takum64, int64_t);

/* Integer Root */
takum8 takum8_root(takum8, int64_t);
takum16 takum16_root(takum16, int64_t);
takum32 takum32_root(takum32, int64_t);
takum64 takum64_root(takum64, int64_t);

/* Inversion */
static inline takum8
takum8_inversion(takum8 t)
{
	union takum_internal_takum8_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT8_C(0x7f)) + 1;

	return (t == TAKUM8_NAR) ? TAKUM8_NAR : out.value;
}

static inline takum16
takum16_inversion(takum16 t)
{
	union takum_internal_takum16_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT16_C(0x7fff)) + 1;

	return (t == TAKUM16_NAR) ? TAKUM16_NAR : out.value;
}

static inline takum32
takum32_inversion(takum32 t)
{
	union takum_internal_takum32_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT32_C(0x7fffffff)) + 1;

	return (t == TAKUM32_NAR) ? TAKUM32_NAR : out.value;
}

static inline takum64
takum64_inversion(takum64 t)
{
	union takum_internal_takum64_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT64_C(0x7fffffffffffffff)) + 1;

	return (t == TAKUM64_NAR) ? TAKUM64_NAR : out.value;
}

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

/* Multiplication */
takum8 takum8_multiplication(takum8, takum8);
takum16 takum16_multiplication(takum16, takum16);
takum32 takum32_multiplication(takum32, takum32);
takum64 takum64_multiplication(takum64, takum64);

/* Power */
takum8 takum8_power(takum8, takum8);
takum16 takum16_power(takum16, takum16);
takum32 takum32_power(takum32, takum32);
takum64 takum64_power(takum64, takum64);

/* Precision */
uint8_t takum8_precision(takum8);
uint8_t takum16_precision(takum16);
uint8_t takum32_precision(takum32);
uint8_t takum64_precision(takum64);

/* Secant */
takum8 takum8_sec(takum8);
takum16 takum16_sec(takum16);
takum32 takum32_sec(takum32);
takum64 takum64_sec(takum64);

/* Secant π Times */
takum8 takum8_sec_pi_times(takum8);
takum16 takum16_sec_pi_times(takum16);
takum32 takum32_sec_pi_times(takum32);
takum64 takum64_sec_pi_times(takum64);

/* Hyperbolic Secant */
takum8 takum8_sech(takum8);
takum16 takum16_sech(takum16);
takum32 takum32_sech(takum32);
takum64 takum64_sech(takum64);

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

/* Sine */
takum8 takum8_sin(takum8);
takum16 takum16_sin(takum16);
takum32 takum32_sin(takum32);
takum64 takum64_sin(takum64);

/* Sine π Times */
takum8 takum8_sin_pi_times(takum8);
takum16 takum16_sin_pi_times(takum16);
takum32 takum32_sin_pi_times(takum32);
takum64 takum64_sin_pi_times(takum64);

/* Hyperbolic Sine */
takum8 takum8_sinh(takum8);
takum16 takum16_sinh(takum16);
takum32 takum32_sinh(takum32);
takum64 takum64_sinh(takum64);

/* Square Root */
takum8 takum8_square_root(takum8);
takum16 takum16_square_root(takum16);
takum32 takum32_square_root(takum32);
takum64 takum64_square_root(takum64);

/* Subtraction */
takum8 takum8_subtraction(takum8, takum8);
takum16 takum16_subtraction(takum16, takum16);
takum32 takum32_subtraction(takum32, takum32);
takum64 takum64_subtraction(takum64, takum64);

/* Tangent */
takum8 takum8_tan(takum8);
takum16 takum16_tan(takum16);
takum32 takum32_tan(takum32);
takum64 takum64_tan(takum64);

/* Tangent π Times */
takum8 takum8_tan_pi_times(takum8);
takum16 takum16_tan_pi_times(takum16);
takum32 takum32_tan_pi_times(takum32);
takum64 takum64_tan_pi_times(takum64);

/* Hyperbolic Tangent */
takum8 takum8_tanh(takum8);
takum16 takum16_tanh(takum16);
takum32 takum32_tanh(takum32);
takum64 takum64_tanh(takum64);

/* Conversion to extended float */
long double takum8_to_extended_float(takum8);
long double takum16_to_extended_float(takum16);
long double takum32_to_extended_float(takum32);
long double takum64_to_extended_float(takum64);

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

#endif /* TAKUM_H */
