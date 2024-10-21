# See LICENSE file for copyright and license details
# libtakum - takum arithmetic C99 reference implementation
.POSIX:
.SUFFIXES:

VERSION_MAJOR = 0
VERSION_MINOR = 5
VERSION_PATCH = 0
MAN_DATE = 2024-10-21

include config.mk

VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

BENCHMARK =\
	benchmark/float_to_takum\

EXAMPLE =\
	example/calculator\

GEN =\
	gen/addition\

SRC =\
	src/10_raised\
	src/2_raised\
	src/addition\
	src/arccos\
	src/arccot\
	src/arccsc\
	src/arcosh\
	src/arcoth\
	src/arcsch\
	src/arcsec\
	src/arcsin\
	src/arctan\
	src/arctan2\
	src/arsech\
	src/arsinh\
	src/artanh\
	src/codec\
	src/conversion\
	src/cos\
	src/cosh\
	src/cot\
	src/coth\
	src/csc\
	src/csch\
	src/integer_power\
	src/division\
	src/exp\
	src/hypotenuse\
	src/inversion\
	src/lb\
	src/lg\
	src/ln\
	src/multiplication\
	src/power\
	src/precision\
	src/root\
	src/sec\
	src/sech\
	src/sin\
	src/sinh\
	src/square_root\
	src/subtraction\
	src/tan\
	src/tanh\

TEST =\
	test/10_raised\
	test/2_raised\
	test/absolute\
	test/addition\
	test/arccos\
	test/arccot\
	test/arccsc\
	test/arcosh\
	test/arcoth\
	test/arcsch\
	test/arcsec\
	test/arcsin\
	test/arctan\
	test/arctan2\
	test/arsech\
	test/arsinh\
	test/artanh\
	test/codec\
	test/constants\
	test/conversion\
	test/cos\
	test/cosh\
	test/cot\
	test/coth\
	test/csc\
	test/csch\
	test/division\
	test/exp\
	test/hypotenuse\
	test/integer_power\
	test/inversion\
	test/lb\
	test/lg\
	test/ln\
	test/multiplication\
	test/power\
	test/precision\
	test/root\
	test/sec\
	test/sech\
	test/sign\
	test/sin\
	test/sinh\
	test/square_root\
	test/subtraction\
	test/tan\
	test/tanh\

MAN_TEMPLATE =\
	man/template/conversion_from_float.sh\
	man/template/conversion_to_float.sh\
	man/template/math_function.sh\

MAN3 =\
	man/takum8_10_raised\
	man/takum16_10_raised\
	man/takum32_10_raised\
	man/takum64_10_raised\
	man/takum_linear8_10_raised\
	man/takum_linear16_10_raised\
	man/takum_linear32_10_raised\
	man/takum_linear64_10_raised\
	man/takum8_10_raised_minus_1\
	man/takum16_10_raised_minus_1\
	man/takum32_10_raised_minus_1\
	man/takum64_10_raised_minus_1\
	man/takum_linear8_10_raised_minus_1\
	man/takum_linear16_10_raised_minus_1\
	man/takum_linear32_10_raised_minus_1\
	man/takum_linear64_10_raised_minus_1\
	man/takum8_2_raised\
	man/takum16_2_raised\
	man/takum32_2_raised\
	man/takum64_2_raised\
	man/takum_linear8_2_raised\
	man/takum_linear16_2_raised\
	man/takum_linear32_2_raised\
	man/takum_linear64_2_raised\
	man/takum8_2_raised_minus_1\
	man/takum16_2_raised_minus_1\
	man/takum32_2_raised_minus_1\
	man/takum64_2_raised_minus_1\
	man/takum_linear8_2_raised_minus_1\
	man/takum_linear16_2_raised_minus_1\
	man/takum_linear32_2_raised_minus_1\
	man/takum_linear64_2_raised_minus_1\
	man/takum8_absolute\
	man/takum16_absolute\
	man/takum32_absolute\
	man/takum64_absolute\
	man/takum_linear8_absolute\
	man/takum_linear16_absolute\
	man/takum_linear32_absolute\
	man/takum_linear64_absolute\
	man/takum8_addition\
	man/takum16_addition\
	man/takum32_addition\
	man/takum64_addition\
	man/takum_linear8_addition\
	man/takum_linear16_addition\
	man/takum_linear32_addition\
	man/takum_linear64_addition\
	man/takum8_arccos\
	man/takum16_arccos\
	man/takum32_arccos\
	man/takum64_arccos\
	man/takum_linear8_arccos\
	man/takum_linear16_arccos\
	man/takum_linear32_arccos\
	man/takum_linear64_arccos\
	man/takum8_arccos_over_pi\
	man/takum16_arccos_over_pi\
	man/takum32_arccos_over_pi\
	man/takum64_arccos_over_pi\
	man/takum_linear8_arccos_over_pi\
	man/takum_linear16_arccos_over_pi\
	man/takum_linear32_arccos_over_pi\
	man/takum_linear64_arccos_over_pi\
	man/takum8_arccot\
	man/takum16_arccot\
	man/takum32_arccot\
	man/takum64_arccot\
	man/takum_linear8_arccot\
	man/takum_linear16_arccot\
	man/takum_linear32_arccot\
	man/takum_linear64_arccot\
	man/takum8_arccot_over_pi\
	man/takum16_arccot_over_pi\
	man/takum32_arccot_over_pi\
	man/takum64_arccot_over_pi\
	man/takum_linear8_arccot_over_pi\
	man/takum_linear16_arccot_over_pi\
	man/takum_linear32_arccot_over_pi\
	man/takum_linear64_arccot_over_pi\
	man/takum8_arccsc\
	man/takum16_arccsc\
	man/takum32_arccsc\
	man/takum64_arccsc\
	man/takum_linear8_arccsc\
	man/takum_linear16_arccsc\
	man/takum_linear32_arccsc\
	man/takum_linear64_arccsc\
	man/takum8_arccsc_over_pi\
	man/takum16_arccsc_over_pi\
	man/takum32_arccsc_over_pi\
	man/takum64_arccsc_over_pi\
	man/takum_linear8_arccsc_over_pi\
	man/takum_linear16_arccsc_over_pi\
	man/takum_linear32_arccsc_over_pi\
	man/takum_linear64_arccsc_over_pi\
	man/takum8_arcosh\
	man/takum16_arcosh\
	man/takum32_arcosh\
	man/takum64_arcosh\
	man/takum_linear8_arcosh\
	man/takum_linear16_arcosh\
	man/takum_linear32_arcosh\
	man/takum_linear64_arcosh\
	man/takum8_arcoth\
	man/takum16_arcoth\
	man/takum32_arcoth\
	man/takum64_arcoth\
	man/takum_linear8_arcoth\
	man/takum_linear16_arcoth\
	man/takum_linear32_arcoth\
	man/takum_linear64_arcoth\
	man/takum8_arcsch\
	man/takum16_arcsch\
	man/takum32_arcsch\
	man/takum64_arcsch\
	man/takum_linear8_arcsch\
	man/takum_linear16_arcsch\
	man/takum_linear32_arcsch\
	man/takum_linear64_arcsch\
	man/takum8_arcsec\
	man/takum16_arcsec\
	man/takum32_arcsec\
	man/takum64_arcsec\
	man/takum_linear8_arcsec\
	man/takum_linear16_arcsec\
	man/takum_linear32_arcsec\
	man/takum_linear64_arcsec\
	man/takum8_arcsec_over_pi\
	man/takum16_arcsec_over_pi\
	man/takum32_arcsec_over_pi\
	man/takum64_arcsec_over_pi\
	man/takum_linear8_arcsec_over_pi\
	man/takum_linear16_arcsec_over_pi\
	man/takum_linear32_arcsec_over_pi\
	man/takum_linear64_arcsec_over_pi\
	man/takum8_arcsin\
	man/takum16_arcsin\
	man/takum32_arcsin\
	man/takum64_arcsin\
	man/takum_linear8_arcsin\
	man/takum_linear16_arcsin\
	man/takum_linear32_arcsin\
	man/takum_linear64_arcsin\
	man/takum8_arcsin_over_pi\
	man/takum16_arcsin_over_pi\
	man/takum32_arcsin_over_pi\
	man/takum64_arcsin_over_pi\
	man/takum_linear8_arcsin_over_pi\
	man/takum_linear16_arcsin_over_pi\
	man/takum_linear32_arcsin_over_pi\
	man/takum_linear64_arcsin_over_pi\
	man/takum8_arctan2\
	man/takum16_arctan2\
	man/takum32_arctan2\
	man/takum64_arctan2\
	man/takum_linear8_arctan2\
	man/takum_linear16_arctan2\
	man/takum_linear32_arctan2\
	man/takum_linear64_arctan2\
	man/takum8_arctan2_over_pi\
	man/takum16_arctan2_over_pi\
	man/takum32_arctan2_over_pi\
	man/takum64_arctan2_over_pi\
	man/takum_linear8_arctan2_over_pi\
	man/takum_linear16_arctan2_over_pi\
	man/takum_linear32_arctan2_over_pi\
	man/takum_linear64_arctan2_over_pi\
	man/takum8_arctan\
	man/takum16_arctan\
	man/takum32_arctan\
	man/takum64_arctan\
	man/takum_linear8_arctan\
	man/takum_linear16_arctan\
	man/takum_linear32_arctan\
	man/takum_linear64_arctan\
	man/takum8_arctan_over_pi\
	man/takum16_arctan_over_pi\
	man/takum32_arctan_over_pi\
	man/takum64_arctan_over_pi\
	man/takum_linear8_arctan_over_pi\
	man/takum_linear16_arctan_over_pi\
	man/takum_linear32_arctan_over_pi\
	man/takum_linear64_arctan_over_pi\
	man/takum8_arsech\
	man/takum16_arsech\
	man/takum32_arsech\
	man/takum64_arsech\
	man/takum_linear8_arsech\
	man/takum_linear16_arsech\
	man/takum_linear32_arsech\
	man/takum_linear64_arsech\
	man/takum8_arsinh\
	man/takum16_arsinh\
	man/takum32_arsinh\
	man/takum64_arsinh\
	man/takum_linear8_arsinh\
	man/takum_linear16_arsinh\
	man/takum_linear32_arsinh\
	man/takum_linear64_arsinh\
	man/takum8_artanh\
	man/takum16_artanh\
	man/takum32_artanh\
	man/takum64_artanh\
	man/takum_linear8_artanh\
	man/takum_linear16_artanh\
	man/takum_linear32_artanh\
	man/takum_linear64_artanh\
	man/takum8_cos\
	man/takum16_cos\
	man/takum32_cos\
	man/takum64_cos\
	man/takum_linear8_cos\
	man/takum_linear16_cos\
	man/takum_linear32_cos\
	man/takum_linear64_cos\
	man/takum8_cos_pi_times\
	man/takum16_cos_pi_times\
	man/takum32_cos_pi_times\
	man/takum64_cos_pi_times\
	man/takum_linear8_cos_pi_times\
	man/takum_linear16_cos_pi_times\
	man/takum_linear32_cos_pi_times\
	man/takum_linear64_cos_pi_times\
	man/takum8_cosh\
	man/takum16_cosh\
	man/takum32_cosh\
	man/takum64_cosh\
	man/takum_linear8_cosh\
	man/takum_linear16_cosh\
	man/takum_linear32_cosh\
	man/takum_linear64_cosh\
	man/takum8_cot\
	man/takum16_cot\
	man/takum32_cot\
	man/takum64_cot\
	man/takum_linear8_cot\
	man/takum_linear16_cot\
	man/takum_linear32_cot\
	man/takum_linear64_cot\
	man/takum8_cot_pi_times\
	man/takum16_cot_pi_times\
	man/takum32_cot_pi_times\
	man/takum64_cot_pi_times\
	man/takum_linear8_cot_pi_times\
	man/takum_linear16_cot_pi_times\
	man/takum_linear32_cot_pi_times\
	man/takum_linear64_cot_pi_times\
	man/takum8_coth\
	man/takum16_coth\
	man/takum32_coth\
	man/takum64_coth\
	man/takum_linear8_coth\
	man/takum_linear16_coth\
	man/takum_linear32_coth\
	man/takum_linear64_coth\
	man/takum8_csc\
	man/takum16_csc\
	man/takum32_csc\
	man/takum64_csc\
	man/takum_linear8_csc\
	man/takum_linear16_csc\
	man/takum_linear32_csc\
	man/takum_linear64_csc\
	man/takum8_csc_pi_times\
	man/takum16_csc_pi_times\
	man/takum32_csc_pi_times\
	man/takum64_csc_pi_times\
	man/takum_linear8_csc_pi_times\
	man/takum_linear16_csc_pi_times\
	man/takum_linear32_csc_pi_times\
	man/takum_linear64_csc_pi_times\
	man/takum8_csch\
	man/takum16_csch\
	man/takum32_csch\
	man/takum64_csch\
	man/takum_linear8_csch\
	man/takum_linear16_csch\
	man/takum_linear32_csch\
	man/takum_linear64_csch\
	man/takum8_division\
	man/takum16_division\
	man/takum32_division\
	man/takum64_division\
	man/takum_linear8_division\
	man/takum_linear16_division\
	man/takum_linear32_division\
	man/takum_linear64_division\
	man/takum8_exp\
	man/takum16_exp\
	man/takum32_exp\
	man/takum64_exp\
	man/takum_linear8_exp\
	man/takum_linear16_exp\
	man/takum_linear32_exp\
	man/takum_linear64_exp\
	man/takum8_exp_minus_1\
	man/takum16_exp_minus_1\
	man/takum32_exp_minus_1\
	man/takum64_exp_minus_1\
	man/takum_linear8_exp_minus_1\
	man/takum_linear16_exp_minus_1\
	man/takum_linear32_exp_minus_1\
	man/takum_linear64_exp_minus_1\
	man/takum8_from_extended_float\
	man/takum16_from_extended_float\
	man/takum32_from_extended_float\
	man/takum64_from_extended_float\
	man/takum_linear8_from_extended_float\
	man/takum_linear16_from_extended_float\
	man/takum_linear32_from_extended_float\
	man/takum_linear64_from_extended_float\
	man/takum8_from_float32\
	man/takum16_from_float32\
	man/takum32_from_float32\
	man/takum64_from_float32\
	man/takum_linear8_from_float32\
	man/takum_linear16_from_float32\
	man/takum_linear32_from_float32\
	man/takum_linear64_from_float32\
	man/takum8_from_float64\
	man/takum16_from_float64\
	man/takum32_from_float64\
	man/takum64_from_float64\
	man/takum_linear8_from_float64\
	man/takum_linear16_from_float64\
	man/takum_linear32_from_float64\
	man/takum_linear64_from_float64\
	man/takum16_from_takum8\
	man/takum32_from_takum8\
	man/takum64_from_takum8\
	man/takum_linear8_from_takum8\
	man/takum_linear16_from_takum8\
	man/takum_linear32_from_takum8\
	man/takum_linear64_from_takum8\
	man/takum8_from_takum16\
	man/takum32_from_takum16\
	man/takum64_from_takum16\
	man/takum_linear8_from_takum16\
	man/takum_linear16_from_takum16\
	man/takum_linear32_from_takum16\
	man/takum_linear64_from_takum16\
	man/takum8_from_takum32\
	man/takum16_from_takum32\
	man/takum64_from_takum32\
	man/takum_linear8_from_takum32\
	man/takum_linear16_from_takum32\
	man/takum_linear32_from_takum32\
	man/takum_linear64_from_takum32\
	man/takum8_from_takum64\
	man/takum16_from_takum64\
	man/takum32_from_takum64\
	man/takum_linear8_from_takum64\
	man/takum_linear16_from_takum64\
	man/takum_linear32_from_takum64\
	man/takum_linear64_from_takum64\
	man/takum8_from_takum_linear8\
	man/takum16_from_takum_linear8\
	man/takum32_from_takum_linear8\
	man/takum64_from_takum_linear8\
	man/takum_linear16_from_takum_linear8\
	man/takum_linear32_from_takum_linear8\
	man/takum_linear64_from_takum_linear8\
	man/takum8_from_takum_linear16\
	man/takum16_from_takum_linear16\
	man/takum32_from_takum_linear16\
	man/takum64_from_takum_linear16\
	man/takum_linear8_from_takum_linear16\
	man/takum_linear32_from_takum_linear16\
	man/takum_linear64_from_takum_linear16\
	man/takum8_from_takum_linear32\
	man/takum16_from_takum_linear32\
	man/takum32_from_takum_linear32\
	man/takum64_from_takum_linear32\
	man/takum_linear8_from_takum_linear32\
	man/takum_linear16_from_takum_linear32\
	man/takum_linear64_from_takum_linear32\
	man/takum8_from_takum_linear64\
	man/takum16_from_takum_linear64\
	man/takum32_from_takum_linear64\
	man/takum64_from_takum_linear64\
	man/takum_linear8_from_takum_linear64\
	man/takum_linear16_from_takum_linear64\
	man/takum_linear32_from_takum_linear64\
	man/takum8_hypotenuse\
	man/takum16_hypotenuse\
	man/takum32_hypotenuse\
	man/takum64_hypotenuse\
	man/takum_linear8_hypotenuse\
	man/takum_linear16_hypotenuse\
	man/takum_linear32_hypotenuse\
	man/takum_linear64_hypotenuse\
	man/takum8_integer_power\
	man/takum16_integer_power\
	man/takum32_integer_power\
	man/takum64_integer_power\
	man/takum_linear8_integer_power\
	man/takum_linear16_integer_power\
	man/takum_linear32_integer_power\
	man/takum_linear64_integer_power\
	man/takum8_inversion\
	man/takum16_inversion\
	man/takum32_inversion\
	man/takum64_inversion\
	man/takum_linear8_inversion\
	man/takum_linear16_inversion\
	man/takum_linear32_inversion\
	man/takum_linear64_inversion\
	man/takum8_lb\
	man/takum16_lb\
	man/takum32_lb\
	man/takum64_lb\
	man/takum_linear8_lb\
	man/takum_linear16_lb\
	man/takum_linear32_lb\
	man/takum_linear64_lb\
	man/takum8_lb_1_plus\
	man/takum16_lb_1_plus\
	man/takum32_lb_1_plus\
	man/takum64_lb_1_plus\
	man/takum_linear8_lb_1_plus\
	man/takum_linear16_lb_1_plus\
	man/takum_linear32_lb_1_plus\
	man/takum_linear64_lb_1_plus\
	man/takum8_lg\
	man/takum16_lg\
	man/takum32_lg\
	man/takum64_lg\
	man/takum_linear8_lg\
	man/takum_linear16_lg\
	man/takum_linear32_lg\
	man/takum_linear64_lg\
	man/takum8_lg_1_plus\
	man/takum16_lg_1_plus\
	man/takum32_lg_1_plus\
	man/takum64_lg_1_plus\
	man/takum_linear8_lg_1_plus\
	man/takum_linear16_lg_1_plus\
	man/takum_linear32_lg_1_plus\
	man/takum_linear64_lg_1_plus\
	man/takum8_ln\
	man/takum16_ln\
	man/takum32_ln\
	man/takum64_ln\
	man/takum_linear8_ln\
	man/takum_linear16_ln\
	man/takum_linear32_ln\
	man/takum_linear64_ln\
	man/takum8_ln_1_plus\
	man/takum16_ln_1_plus\
	man/takum32_ln_1_plus\
	man/takum64_ln_1_plus\
	man/takum_linear8_ln_1_plus\
	man/takum_linear16_ln_1_plus\
	man/takum_linear32_ln_1_plus\
	man/takum_linear64_ln_1_plus\
	man/takum8_multiplication\
	man/takum16_multiplication\
	man/takum32_multiplication\
	man/takum64_multiplication\
	man/takum_linear8_multiplication\
	man/takum_linear16_multiplication\
	man/takum_linear32_multiplication\
	man/takum_linear64_multiplication\
	man/takum8_power\
	man/takum16_power\
	man/takum32_power\
	man/takum64_power\
	man/takum_linear8_power\
	man/takum_linear16_power\
	man/takum_linear32_power\
	man/takum_linear64_power\
	man/takum8_precision\
	man/takum16_precision\
	man/takum32_precision\
	man/takum64_precision\
	man/takum_linear8_precision\
	man/takum_linear16_precision\
	man/takum_linear32_precision\
	man/takum_linear64_precision\
	man/takum8_root\
	man/takum16_root\
	man/takum32_root\
	man/takum64_root\
	man/takum_linear8_root\
	man/takum_linear16_root\
	man/takum_linear32_root\
	man/takum_linear64_root\
	man/takum8_sec\
	man/takum16_sec\
	man/takum32_sec\
	man/takum64_sec\
	man/takum_linear8_sec\
	man/takum_linear16_sec\
	man/takum_linear32_sec\
	man/takum_linear64_sec\
	man/takum8_sec_pi_times\
	man/takum16_sec_pi_times\
	man/takum32_sec_pi_times\
	man/takum64_sec_pi_times\
	man/takum_linear8_sec_pi_times\
	man/takum_linear16_sec_pi_times\
	man/takum_linear32_sec_pi_times\
	man/takum_linear64_sec_pi_times\
	man/takum8_sech\
	man/takum16_sech\
	man/takum32_sech\
	man/takum64_sech\
	man/takum_linear8_sech\
	man/takum_linear16_sech\
	man/takum_linear32_sech\
	man/takum_linear64_sech\
	man/takum8_sign\
	man/takum16_sign\
	man/takum32_sign\
	man/takum64_sign\
	man/takum_linear8_sign\
	man/takum_linear16_sign\
	man/takum_linear32_sign\
	man/takum_linear64_sign\
	man/takum8_sin\
	man/takum16_sin\
	man/takum32_sin\
	man/takum64_sin\
	man/takum_linear8_sin\
	man/takum_linear16_sin\
	man/takum_linear32_sin\
	man/takum_linear64_sin\
	man/takum8_sin_pi_times\
	man/takum16_sin_pi_times\
	man/takum32_sin_pi_times\
	man/takum64_sin_pi_times\
	man/takum_linear8_sin_pi_times\
	man/takum_linear16_sin_pi_times\
	man/takum_linear32_sin_pi_times\
	man/takum_linear64_sin_pi_times\
	man/takum8_sinh\
	man/takum16_sinh\
	man/takum32_sinh\
	man/takum64_sinh\
	man/takum_linear8_sinh\
	man/takum_linear16_sinh\
	man/takum_linear32_sinh\
	man/takum_linear64_sinh\
	man/takum8_square_root\
	man/takum16_square_root\
	man/takum32_square_root\
	man/takum64_square_root\
	man/takum_linear8_square_root\
	man/takum_linear16_square_root\
	man/takum_linear32_square_root\
	man/takum_linear64_square_root\
	man/takum8_subtraction\
	man/takum16_subtraction\
	man/takum32_subtraction\
	man/takum64_subtraction\
	man/takum_linear8_subtraction\
	man/takum_linear16_subtraction\
	man/takum_linear32_subtraction\
	man/takum_linear64_subtraction\
	man/takum8_tan\
	man/takum16_tan\
	man/takum32_tan\
	man/takum64_tan\
	man/takum_linear8_tan\
	man/takum_linear16_tan\
	man/takum_linear32_tan\
	man/takum_linear64_tan\
	man/takum8_tan_pi_times\
	man/takum16_tan_pi_times\
	man/takum32_tan_pi_times\
	man/takum64_tan_pi_times\
	man/takum_linear8_tan_pi_times\
	man/takum_linear16_tan_pi_times\
	man/takum_linear32_tan_pi_times\
	man/takum_linear64_tan_pi_times\
	man/takum8_tanh\
	man/takum16_tanh\
	man/takum32_tanh\
	man/takum64_tanh\
	man/takum_linear8_tanh\
	man/takum_linear16_tanh\
	man/takum_linear32_tanh\
	man/takum_linear64_tanh\
	man/takum8_to_extended_float\
	man/takum16_to_extended_float\
	man/takum32_to_extended_float\
	man/takum64_to_extended_float\
	man/takum_linear8_to_extended_float\
	man/takum_linear16_to_extended_float\
	man/takum_linear32_to_extended_float\
	man/takum_linear64_to_extended_float\
	man/takum8_to_float32\
	man/takum16_to_float32\
	man/takum32_to_float32\
	man/takum64_to_float32\
	man/takum_linear8_to_float32\
	man/takum_linear16_to_float32\
	man/takum_linear32_to_float32\
	man/takum_linear64_to_float32\
	man/takum8_to_float64\
	man/takum16_to_float64\
	man/takum32_to_float64\
	man/takum64_to_float64\
	man/takum_linear8_to_float64\
	man/takum_linear16_to_float64\
	man/takum_linear32_to_float64\
	man/takum_linear64_to_float64\

MAN7 = man/libtakum

all: $(MAN3:=.3) $(MAN7:=.7) $(ANAME) $(SONAME)

benchmark/float_to_takum.o: benchmark/float_to_takum.c Makefile config.mk takum.h benchmark/util.h
benchmark/util.o: benchmark/util.c Makefile config.mk takum.h benchmark/util.h
example/calculator.o: example/calculator.c Makefile config.mk takum.h example/util.h
example/util.o: example/util.c Makefile config.mk takum.h example/util.h
gen/addition.o: gen/addition.c Makefile config.mk gen/util.h
gen/util.o: gen/util.c Makefile config.mk gen/util.h
src/addition.o: src/addition.c Makefile config.mk takum.h src/util.h
src/arccos.o: src/arccos.c Makefile config.mk takum.h src/util.h
src/arccot.o: src/arccot.c Makefile config.mk takum.h src/util.h
src/arccsc.o: src/arccsc.c Makefile config.mk takum.h src/util.h
src/arcosh.o: src/arcosh.c Makefile config.mk takum.h src/util.h
src/arcoth.o: src/arcoth.c Makefile config.mk takum.h src/util.h
src/arcsch.o: src/arcsch.c Makefile config.mk takum.h src/util.h
src/arcsec.o: src/arcsec.c Makefile config.mk takum.h src/util.h
src/arcsin.o: src/arcsin.c Makefile config.mk takum.h src/util.h
src/arctan.o: src/arctan.c Makefile config.mk takum.h src/util.h
src/arctan2.o: src/arctan2.c Makefile config.mk takum.h src/util.h
src/arsech.o: src/arsech.c Makefile config.mk takum.h src/util.h
src/arsinh.o: src/arsinh.c Makefile config.mk takum.h src/util.h
src/artanh.o: src/artanh.c Makefile config.mk takum.h src/util.h
src/codec.o: src/codec.c Makefile config.mk takum.h src/util.h
src/conversion.o: src/conversion.c Makefile config.mk takum.h src/util.h
src/cos.o: src/cos.c Makefile config.mk takum.h src/util.h
src/cot.o: src/cot.c Makefile config.mk takum.h src/util.h
src/cosh.o: src/cosh.c Makefile config.mk takum.h src/util.h
src/coth.o: src/coth.c Makefile config.mk takum.h src/util.h
src/csc.o: src/csc.c Makefile config.mk takum.h src/util.h
src/csch.o: src/csch.c Makefile config.mk takum.h src/util.h
src/division.o: src/division.c Makefile config.mk takum.h src/util.h
src/exp.o: src/exp.c Makefile config.mk takum.h src/util.h
src/exp2.o: src/exp2.c Makefile config.mk takum.h src/util.h
src/exp10.o: src/exp10.c Makefile config.mk takum.h src/util.h
src/hypotenuse.o: src/hypotenuse.c Makefile config.mk takum.h src/util.h
src/inversion.o: src/inversion.c Makefile config.mk takum.h src/util.h
src/lb.o: src/lb.c Makefile config.mk takum.h src/util.h
src/lg.o: src/lg.c Makefile config.mk takum.h src/util.h
src/ln.o: src/ln.c Makefile config.mk takum.h src/util.h
src/multiplication.o: src/multiplication.c Makefile config.mk takum.h src/util.h
src/power.o: src/power.c Makefile config.mk takum.h src/util.h
src/sec.o: src/sec.c Makefile config.mk takum.h src/util.h
src/sech.o: src/sech.c Makefile config.mk takum.h src/util.h
src/sin.o: src/sin.c Makefile config.mk takum.h src/util.h
src/sinh.o: src/sinh.c Makefile config.mk takum.h src/util.h
src/square_root.o: src/square_root.c Makefile config.mk takum.h src/util.h
src/subtraction.o: src/subtraction.c Makefile config.mk takum.h src/util.h
src/tan.o: src/tan.c Makefile config.mk takum.h src/util.h
src/tanh.o: src/tanh.c Makefile config.mk takum.h src/util.h
src/util.o: src/util.c Makefile config.mk takum.h src/util.h
test/10_raised.o: test/10_raised.c Makefile config.mk takum.h test/util.h
test/2_raised.o: test/2_raised.c Makefile config.mk takum.h test/util.h
test/absolute.o: test/absolute.c Makefile config.mk takum.h test/util.h
test/addition.o: test/addition.c Makefile config.mk takum.h test/util.h
test/arccos.o: test/arccos.c Makefile config.mk takum.h test/util.h
test/arccot.o: test/arccot.c Makefile config.mk takum.h test/util.h
test/arccsc.o: test/arccsc.c Makefile config.mk takum.h test/util.h
test/arcosh.o: test/arcosh.c Makefile config.mk takum.h test/util.h
test/arcoth.o: test/arcoth.c Makefile config.mk takum.h test/util.h
test/arcsch.o: test/arcsch.c Makefile config.mk takum.h test/util.h
test/arcsec.o: test/arcsec.c Makefile config.mk takum.h test/util.h
test/arcsin.o: test/arcsin.c Makefile config.mk takum.h test/util.h
test/arctan.o: test/arctan.c Makefile config.mk takum.h test/util.h
test/arctan2.o: test/arctan2.c Makefile config.mk takum.h test/util.h
test/arsech.o: test/arsech.c Makefile config.mk takum.h test/util.h
test/arsinh.o: test/arsinh.c Makefile config.mk takum.h test/util.h
test/artanh.o: test/artanh.c Makefile config.mk takum.h test/util.h
test/codec.o: test/codec.c Makefile config.mk takum.h test/util.h
test/constants.o: test/constants.c Makefile config.mk takum.h test/util.h
test/conversion.o: test/conversion.c Makefile config.mk takum.h test/util.h
test/cos.o: test/cos.c Makefile config.mk takum.h test/util.h
test/cosh.o: test/cosh.c Makefile config.mk takum.h test/util.h
test/cot.o: test/cot.c Makefile config.mk takum.h test/util.h
test/coth.o: test/coth.c Makefile config.mk takum.h test/util.h
test/csc.o: test/csc.c Makefile config.mk takum.h test/util.h
test/csch.o: test/csch.c Makefile config.mk takum.h test/util.h
test/division.o: test/division.c Makefile config.mk takum.h test/util.h
test/exp.o: test/exp.c Makefile config.mk takum.h test/util.h
test/hypotenuse.o: test/hypotenuse.c Makefile config.mk takum.h test/util.h
test/integer_power.o: test/integer_power.c Makefile config.mk takum.h test/util.h
test/inversion.o: test/inversion.c Makefile config.mk takum.h test/util.h
test/lb.o: test/lb.c Makefile config.mk takum.h test/util.h
test/lg.o: test/lg.c Makefile config.mk takum.h test/util.h
test/ln.o: test/ln.c Makefile config.mk takum.h test/util.h
test/multiplication.o: test/multiplication.c Makefile config.mk takum.h test/util.h
test/power.o: test/power.c Makefile config.mk takum.h test/util.h
test/precision.o: test/precision.c Makefile config.mk takum.h test/util.h
test/root.o: test/root.c Makefile config.mk takum.h test/util.h
test/sec.o: test/sec.c Makefile config.mk takum.h test/util.h
test/sech.o: test/sech.c Makefile config.mk takum.h test/util.h
test/sign.o: test/sign.c Makefile config.mk takum.h test/util.h
test/sin.o: test/sin.c Makefile config.mk takum.h test/util.h
test/sinh.o: test/sinh.c Makefile config.mk takum.h test/util.h
test/square_root.o: test/square_root.c Makefile config.mk takum.h test/util.h
test/subtraction.o: test/subtraction.c Makefile config.mk takum.h test/util.h
test/tan.o: test/tan.c Makefile config.mk takum.h test/util.h
test/tanh.o: test/tanh.c Makefile config.mk takum.h test/util.h
test/util.o: test/util.c Makefile config.mk takum.h test/util.h

benchmark/float_to_takum$(BINSUFFIX): benchmark/float_to_takum.o benchmark/util.o $(ANAME)
example/calculator$(BINSUFFIX): example/calculator.o example/util.o $(ANAME)
gen/addition$(BINSUFFIX): gen/addition.o gen/util.o $(ANAME)
test/10_raised$(BINSUFFIX): test/10_raised.o test/util.o $(ANAME)
test/2_raised$(BINSUFFIX): test/2_raised.o test/util.o $(ANAME)
test/absolute$(BINSUFFIX): test/absolute.o test/util.o $(ANAME)
test/addition$(BINSUFFIX): test/addition.o test/util.o $(ANAME)
test/arccos$(BINSUFFIX): test/arccos.o test/util.o $(ANAME)
test/arccot$(BINSUFFIX): test/arccot.o test/util.o $(ANAME)
test/arccsc$(BINSUFFIX): test/arccsc.o test/util.o $(ANAME)
test/arcosh$(BINSUFFIX): test/arcosh.o test/util.o $(ANAME)
test/arcoth$(BINSUFFIX): test/arcoth.o test/util.o $(ANAME)
test/arcsch$(BINSUFFIX): test/arcsch.o test/util.o $(ANAME)
test/arcsec$(BINSUFFIX): test/arcsec.o test/util.o $(ANAME)
test/arcsin$(BINSUFFIX): test/arcsin.o test/util.o $(ANAME)
test/arctan$(BINSUFFIX): test/arctan.o test/util.o $(ANAME)
test/arctan2$(BINSUFFIX): test/arctan2.o test/util.o $(ANAME)
test/arsech$(BINSUFFIX): test/arsech.o test/util.o $(ANAME)
test/arsinh$(BINSUFFIX): test/arsinh.o test/util.o $(ANAME)
test/artanh$(BINSUFFIX): test/artanh.o test/util.o $(ANAME)
test/codec$(BINSUFFIX): test/codec.o test/util.o $(ANAME)
test/constants$(BINSUFFIX): test/constants.o test/util.o $(ANAME)
test/conversion$(BINSUFFIX): test/conversion.o test/util.o $(ANAME)
test/cos$(BINSUFFIX): test/cos.o test/util.o $(ANAME)
test/cosh$(BINSUFFIX): test/cosh.o test/util.o $(ANAME)
test/cot$(BINSUFFIX): test/cot.o test/util.o $(ANAME)
test/coth$(BINSUFFIX): test/coth.o test/util.o $(ANAME)
test/csc$(BINSUFFIX): test/csc.o test/util.o $(ANAME)
test/csch$(BINSUFFIX): test/csch.o test/util.o $(ANAME)
test/division$(BINSUFFIX): test/division.o test/util.o $(ANAME)
test/exp$(BINSUFFIX): test/exp.o test/util.o $(ANAME)
test/hypotenuse$(BINSUFFIX): test/hypotenuse.o test/util.o $(ANAME)
test/integer_power$(BINSUFFIX): test/integer_power.o test/util.o $(ANAME)
test/inversion$(BINSUFFIX): test/inversion.o test/util.o $(ANAME)
test/lb$(BINSUFFIX): test/lb.o test/util.o $(ANAME)
test/lg$(BINSUFFIX): test/lg.o test/util.o $(ANAME)
test/ln$(BINSUFFIX): test/ln.o test/util.o $(ANAME)
test/multiplication$(BINSUFFIX): test/multiplication.o test/util.o $(ANAME)
test/power$(BINSUFFIX): test/power.o test/util.o $(ANAME)
test/precision$(BINSUFFIX): test/precision.o test/util.o $(ANAME)
test/root$(BINSUFFIX): test/root.o test/util.o $(ANAME)
test/sec$(BINSUFFIX): test/sec.o test/util.o $(ANAME)
test/sech$(BINSUFFIX): test/sech.o test/util.o $(ANAME)
test/sign$(BINSUFFIX): test/sign.o test/util.o $(ANAME)
test/sin$(BINSUFFIX): test/sin.o test/util.o $(ANAME)
test/sinh$(BINSUFFIX): test/sinh.o test/util.o $(ANAME)
test/square_root$(BINSUFFIX): test/square_root.o test/util.o $(ANAME)
test/subtraction$(BINSUFFIX): test/subtraction.o test/util.o $(ANAME)
test/tan$(BINSUFFIX): test/tan.o test/util.o $(ANAME)
test/tanh$(BINSUFFIX): test/tanh.o test/util.o $(ANAME)

test/10_raised.success: test/10_raised$(BINSUFFIX)
test/2_raised.success: test/2_raised$(BINSUFFIX)
test/absolute.success: test/absolute$(BINSUFFIX)
test/addition.success: test/addition$(BINSUFFIX)
test/arccos.success: test/arccos$(BINSUFFIX)
test/arccot.success: test/arccot$(BINSUFFIX)
test/arccsc.success: test/arccsc$(BINSUFFIX)
test/arcosh.success: test/arcosh$(BINSUFFIX)
test/arcoth.success: test/arcoth$(BINSUFFIX)
test/arcsch.success: test/arcsch$(BINSUFFIX)
test/arcsec.success: test/arcsec$(BINSUFFIX)
test/arcsin.success: test/arcsin$(BINSUFFIX)
test/arctan.success: test/arctan$(BINSUFFIX)
test/arctan2.success: test/arctan2$(BINSUFFIX)
test/arsech.success: test/arsech$(BINSUFFIX)
test/arsinh.success: test/arsinh$(BINSUFFIX)
test/artanh.success: test/artanh$(BINSUFFIX)
test/codec.success: test/codec$(BINSUFFIX)
test/constants.success: test/constants$(BINSUFFIX)
test/conversion.success: test/conversion$(BINSUFFIX)
test/cos.success: test/cos$(BINSUFFIX)
test/cosh.success: test/cosh$(BINSUFFIX)
test/cot.success: test/cot$(BINSUFFIX)
test/coth.success: test/coth$(BINSUFFIX)
test/csc.success: test/csc$(BINSUFFIX)
test/csch.success: test/csch$(BINSUFFIX)
test/division.success: test/division$(BINSUFFIX)
test/exp.success: test/exp$(BINSUFFIX)
test/hypotenuse.success: test/hypotenuse$(BINSUFFIX)
test/integer_power.success: test/integer_power$(BINSUFFIX)
test/inversion.success: test/inversion$(BINSUFFIX)
test/lb.success: test/lb$(BINSUFFIX)
test/lg.success: test/lg$(BINSUFFIX)
test/ln.success: test/ln$(BINSUFFIX)
test/multiplication.success: test/multiplication$(BINSUFFIX)
test/power.success: test/power$(BINSUFFIX)
test/precision.success: test/precision$(BINSUFFIX)
test/root.success: test/root$(BINSUFFIX)
test/sec.success: test/sec$(BINSUFFIX)
test/sech.success: test/sech$(BINSUFFIX)
test/sign.success: test/sign$(BINSUFFIX)
test/sin.success: test/sin$(BINSUFFIX)
test/sinh.success: test/sinh$(BINSUFFIX)
test/square_root.success: test/square_root$(BINSUFFIX)
test/subtraction.success: test/subtraction$(BINSUFFIX)
test/tan.success: test/tan$(BINSUFFIX)
test/tanh.success: test/tanh$(BINSUFFIX)

gen/addition.h: gen/addition$(BINSUFFIX)

man/takum8_10_raised.3: man/takum8_10_raised.sh man/takum64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/takum16_10_raised.3: man/takum16_10_raised.sh man/takum64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/takum32_10_raised.3: man/takum32_10_raised.sh man/takum64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/takum64_10_raised.3: man/takum64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/takum8_10_raised_minus_1.3: man/takum8_10_raised_minus_1.sh man/takum64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum16_10_raised_minus_1.3: man/takum16_10_raised_minus_1.sh man/takum64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum32_10_raised_minus_1.3: man/takum32_10_raised_minus_1.sh man/takum64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum64_10_raised_minus_1.3: man/takum64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum8_2_raised.3: man/takum8_2_raised.sh man/takum64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/takum16_2_raised.3: man/takum16_2_raised.sh man/takum64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/takum32_2_raised.3: man/takum32_2_raised.sh man/takum64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/takum64_2_raised.3: man/takum64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/takum8_2_raised_minus_1.3: man/takum8_2_raised_minus_1.sh man/takum64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum16_2_raised_minus_1.3: man/takum16_2_raised_minus_1.sh man/takum64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum32_2_raised_minus_1.3: man/takum32_2_raised_minus_1.sh man/takum64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum64_2_raised_minus_1.3: man/takum64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum8_absolute.3: man/takum8_absolute.sh man/takum64_absolute.sh man/template/math_function.sh Makefile config.mk
man/takum16_absolute.3: man/takum16_absolute.sh man/takum64_absolute.sh man/template/math_function.sh Makefile config.mk
man/takum32_absolute.3: man/takum32_absolute.sh man/takum64_absolute.sh man/template/math_function.sh Makefile config.mk
man/takum64_absolute.3: man/takum64_absolute.sh man/template/math_function.sh Makefile config.mk
man/takum8_addition.3: man/takum8_addition.sh man/takum64_addition.sh man/template/math_function.sh Makefile config.mk
man/takum16_addition.3: man/takum16_addition.sh man/takum64_addition.sh man/template/math_function.sh Makefile config.mk
man/takum32_addition.3: man/takum32_addition.sh man/takum64_addition.sh man/template/math_function.sh Makefile config.mk
man/takum64_addition.3: man/takum64_addition.sh man/template/math_function.sh Makefile config.mk
man/takum8_arccos.3: man/takum8_arccos.sh man/takum64_arccos.sh man/template/math_function.sh Makefile config.mk
man/takum16_arccos.3: man/takum16_arccos.sh man/takum64_arccos.sh man/template/math_function.sh Makefile config.mk
man/takum32_arccos.3: man/takum32_arccos.sh man/takum64_arccos.sh man/template/math_function.sh Makefile config.mk
man/takum64_arccos.3: man/takum64_arccos.sh man/template/math_function.sh Makefile config.mk
man/takum8_arccos_over_pi.3: man/takum8_arccos_over_pi.sh man/takum64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arccos_over_pi.3: man/takum16_arccos_over_pi.sh man/takum64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arccos_over_pi.3: man/takum32_arccos_over_pi.sh man/takum64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arccos_over_pi.3: man/takum64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arccot.3: man/takum8_arccot.sh man/takum64_arccot.sh man/template/math_function.sh Makefile config.mk
man/takum16_arccot.3: man/takum16_arccot.sh man/takum64_arccot.sh man/template/math_function.sh Makefile config.mk
man/takum32_arccot.3: man/takum32_arccot.sh man/takum64_arccot.sh man/template/math_function.sh Makefile config.mk
man/takum64_arccot.3: man/takum64_arccot.sh man/template/math_function.sh Makefile config.mk
man/takum8_arccot_over_pi.3: man/takum8_arccot_over_pi.sh man/takum64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arccot_over_pi.3: man/takum16_arccot_over_pi.sh man/takum64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arccot_over_pi.3: man/takum32_arccot_over_pi.sh man/takum64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arccot_over_pi.3: man/takum64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arccsc.3: man/takum8_arccsc.sh man/takum64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/takum16_arccsc.3: man/takum16_arccsc.sh man/takum64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/takum32_arccsc.3: man/takum32_arccsc.sh man/takum64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/takum64_arccsc.3: man/takum64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/takum8_arccsc_over_pi.3: man/takum8_arccsc_over_pi.sh man/takum64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arccsc_over_pi.3: man/takum16_arccsc_over_pi.sh man/takum64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arccsc_over_pi.3: man/takum32_arccsc_over_pi.sh man/takum64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arccsc_over_pi.3: man/takum64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcosh.3: man/takum8_arcosh.sh man/takum64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcosh.3: man/takum16_arcosh.sh man/takum64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcosh.3: man/takum32_arcosh.sh man/takum64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcosh.3: man/takum64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcoth.3: man/takum8_arcoth.sh man/takum64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcoth.3: man/takum16_arcoth.sh man/takum64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcoth.3: man/takum32_arcoth.sh man/takum64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcoth.3: man/takum64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcsch.3: man/takum8_arcsch.sh man/takum64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcsch.3: man/takum16_arcsch.sh man/takum64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcsch.3: man/takum32_arcsch.sh man/takum64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcsch.3: man/takum64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcsec.3: man/takum8_arcsec.sh man/takum64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcsec.3: man/takum16_arcsec.sh man/takum64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcsec.3: man/takum32_arcsec.sh man/takum64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcsec.3: man/takum64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcsec_over_pi.3: man/takum8_arcsec_over_pi.sh man/takum64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcsec_over_pi.3: man/takum16_arcsec_over_pi.sh man/takum64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcsec_over_pi.3: man/takum32_arcsec_over_pi.sh man/takum64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcsec_over_pi.3: man/takum64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcsin.3: man/takum8_arcsin.sh man/takum64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcsin.3: man/takum16_arcsin.sh man/takum64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcsin.3: man/takum32_arcsin.sh man/takum64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcsin.3: man/takum64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/takum8_arcsin_over_pi.3: man/takum8_arcsin_over_pi.sh man/takum64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arcsin_over_pi.3: man/takum16_arcsin_over_pi.sh man/takum64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arcsin_over_pi.3: man/takum32_arcsin_over_pi.sh man/takum64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arcsin_over_pi.3: man/takum64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arctan2.3: man/takum8_arctan2.sh man/takum64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/takum16_arctan2.3: man/takum16_arctan2.sh man/takum64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/takum32_arctan2.3: man/takum32_arctan2.sh man/takum64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/takum64_arctan2.3: man/takum64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/takum8_arctan2_over_pi.3: man/takum8_arctan2_over_pi.sh man/takum64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arctan2_over_pi.3: man/takum16_arctan2_over_pi.sh man/takum64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arctan2_over_pi.3: man/takum32_arctan2_over_pi.sh man/takum64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arctan2_over_pi.3: man/takum64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arctan.3: man/takum8_arctan.sh man/takum64_arctan.sh man/template/math_function.sh Makefile config.mk
man/takum16_arctan.3: man/takum16_arctan.sh man/takum64_arctan.sh man/template/math_function.sh Makefile config.mk
man/takum32_arctan.3: man/takum32_arctan.sh man/takum64_arctan.sh man/template/math_function.sh Makefile config.mk
man/takum64_arctan.3: man/takum64_arctan.sh man/template/math_function.sh Makefile config.mk
man/takum8_arctan_over_pi.3: man/takum8_arctan_over_pi.sh man/takum64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum16_arctan_over_pi.3: man/takum16_arctan_over_pi.sh man/takum64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum32_arctan_over_pi.3: man/takum32_arctan_over_pi.sh man/takum64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum64_arctan_over_pi.3: man/takum64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/takum8_arsech.3: man/takum8_arsech.sh man/takum64_arsech.sh man/template/math_function.sh Makefile config.mk
man/takum16_arsech.3: man/takum16_arsech.sh man/takum64_arsech.sh man/template/math_function.sh Makefile config.mk
man/takum32_arsech.3: man/takum32_arsech.sh man/takum64_arsech.sh man/template/math_function.sh Makefile config.mk
man/takum64_arsech.3: man/takum64_arsech.sh man/template/math_function.sh Makefile config.mk
man/takum8_arsinh.3: man/takum8_arsinh.sh man/takum64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/takum16_arsinh.3: man/takum16_arsinh.sh man/takum64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/takum32_arsinh.3: man/takum32_arsinh.sh man/takum64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/takum64_arsinh.3: man/takum64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/takum8_artanh.3: man/takum8_artanh.sh man/takum64_artanh.sh man/template/math_function.sh Makefile config.mk
man/takum16_artanh.3: man/takum16_artanh.sh man/takum64_artanh.sh man/template/math_function.sh Makefile config.mk
man/takum32_artanh.3: man/takum32_artanh.sh man/takum64_artanh.sh man/template/math_function.sh Makefile config.mk
man/takum64_artanh.3: man/takum64_artanh.sh man/template/math_function.sh Makefile config.mk
man/takum8_cos.3: man/takum8_cos.sh man/takum64_cos.sh man/template/math_function.sh Makefile config.mk
man/takum16_cos.3: man/takum16_cos.sh man/takum64_cos.sh man/template/math_function.sh Makefile config.mk
man/takum32_cos.3: man/takum32_cos.sh man/takum64_cos.sh man/template/math_function.sh Makefile config.mk
man/takum64_cos.3: man/takum64_cos.sh man/template/math_function.sh Makefile config.mk
man/takum8_cos_pi_times.3: man/takum8_cos_pi_times.sh man/takum64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum16_cos_pi_times.3: man/takum16_cos_pi_times.sh man/takum64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum32_cos_pi_times.3: man/takum32_cos_pi_times.sh man/takum64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum64_cos_pi_times.3: man/takum64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum8_cosh.3: man/takum8_cosh.sh man/takum64_cosh.sh man/template/math_function.sh Makefile config.mk
man/takum16_cosh.3: man/takum16_cosh.sh man/takum64_cosh.sh man/template/math_function.sh Makefile config.mk
man/takum32_cosh.3: man/takum32_cosh.sh man/takum64_cosh.sh man/template/math_function.sh Makefile config.mk
man/takum64_cosh.3: man/takum64_cosh.sh man/template/math_function.sh Makefile config.mk
man/takum8_cot.3: man/takum8_cot.sh man/takum64_cot.sh man/template/math_function.sh Makefile config.mk
man/takum16_cot.3: man/takum16_cot.sh man/takum64_cot.sh man/template/math_function.sh Makefile config.mk
man/takum32_cot.3: man/takum32_cot.sh man/takum64_cot.sh man/template/math_function.sh Makefile config.mk
man/takum64_cot.3: man/takum64_cot.sh man/template/math_function.sh Makefile config.mk
man/takum8_cot_pi_times.3: man/takum8_cot_pi_times.sh man/takum64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum16_cot_pi_times.3: man/takum16_cot_pi_times.sh man/takum64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum32_cot_pi_times.3: man/takum32_cot_pi_times.sh man/takum64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum64_cot_pi_times.3: man/takum64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum8_coth.3: man/takum8_coth.sh man/takum64_coth.sh man/template/math_function.sh Makefile config.mk
man/takum16_coth.3: man/takum16_coth.sh man/takum64_coth.sh man/template/math_function.sh Makefile config.mk
man/takum32_coth.3: man/takum32_coth.sh man/takum64_coth.sh man/template/math_function.sh Makefile config.mk
man/takum64_coth.3: man/takum64_coth.sh man/template/math_function.sh Makefile config.mk
man/takum8_csc.3: man/takum8_csc.sh man/takum64_csc.sh man/template/math_function.sh Makefile config.mk
man/takum16_csc.3: man/takum16_csc.sh man/takum64_csc.sh man/template/math_function.sh Makefile config.mk
man/takum32_csc.3: man/takum32_csc.sh man/takum64_csc.sh man/template/math_function.sh Makefile config.mk
man/takum64_csc.3: man/takum64_csc.sh man/template/math_function.sh Makefile config.mk
man/takum8_csc_pi_times.3: man/takum8_csc_pi_times.sh man/takum64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum16_csc_pi_times.3: man/takum16_csc_pi_times.sh man/takum64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum32_csc_pi_times.3: man/takum32_csc_pi_times.sh man/takum64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum64_csc_pi_times.3: man/takum64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum8_csch.3: man/takum8_csch.sh man/takum64_csch.sh man/template/math_function.sh Makefile config.mk
man/takum16_csch.3: man/takum16_csch.sh man/takum64_csch.sh man/template/math_function.sh Makefile config.mk
man/takum32_csch.3: man/takum32_csch.sh man/takum64_csch.sh man/template/math_function.sh Makefile config.mk
man/takum64_csch.3: man/takum64_csch.sh man/template/math_function.sh Makefile config.mk
man/takum8_division.3: man/takum8_division.sh man/takum64_division.sh man/template/math_function.sh Makefile config.mk
man/takum16_division.3: man/takum16_division.sh man/takum64_division.sh man/template/math_function.sh Makefile config.mk
man/takum32_division.3: man/takum32_division.sh man/takum64_division.sh man/template/math_function.sh Makefile config.mk
man/takum64_division.3: man/takum64_division.sh man/template/math_function.sh Makefile config.mk
man/takum8_exp.3: man/takum8_exp.sh man/takum64_exp.sh man/template/math_function.sh Makefile config.mk
man/takum16_exp.3: man/takum16_exp.sh man/takum64_exp.sh man/template/math_function.sh Makefile config.mk
man/takum32_exp.3: man/takum32_exp.sh man/takum64_exp.sh man/template/math_function.sh Makefile config.mk
man/takum64_exp.3: man/takum64_exp.sh man/template/math_function.sh Makefile config.mk
man/takum8_exp_minus_1.3: man/takum8_exp_minus_1.sh man/takum64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum16_exp_minus_1.3: man/takum16_exp_minus_1.sh man/takum64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum32_exp_minus_1.3: man/takum32_exp_minus_1.sh man/takum64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum64_exp_minus_1.3: man/takum64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/takum8_from_extended_float.3: man/takum8_from_extended_float.sh man/takum64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum16_from_extended_float.3: man/takum16_from_extended_float.sh man/takum64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum32_from_extended_float.3: man/takum32_from_extended_float.sh man/takum64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum64_from_extended_float.3: man/takum64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum8_from_float32.3: man/takum8_from_float32.sh man/takum64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum16_from_float32.3: man/takum16_from_float32.sh man/takum64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum32_from_float32.3: man/takum32_from_float32.sh man/takum64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum64_from_float32.3: man/takum64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum8_from_float64.3: man/takum8_from_float64.sh man/takum64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum16_from_float64.3: man/takum16_from_float64.sh man/takum64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum32_from_float64.3: man/takum32_from_float64.sh man/takum64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum64_from_float64.3: man/takum64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/takum16_from_takum8.3: man/takum16_from_takum8.sh man/takum64_from_takum8.sh man/template/conversion.sh Makefile config.mk
man/takum32_from_takum8.3: man/takum32_from_takum8.sh man/takum64_from_takum8.sh man/template/conversion.sh Makefile config.mk
man/takum64_from_takum8.3: man/takum64_from_takum8.sh man/template/conversion.sh Makefile config.mk
man/takum8_from_takum16.3: man/takum8_from_takum16.sh man/takum64_from_takum16.sh man/template/conversion.sh Makefile config.mk
man/takum32_from_takum16.3: man/takum32_from_takum16.sh man/takum64_from_takum16.sh man/template/conversion.sh Makefile config.mk
man/takum64_from_takum16.3: man/takum64_from_takum16.sh man/template/conversion.sh Makefile config.mk
man/takum8_from_takum32.3: man/takum8_from_takum32.sh man/takum64_from_takum32.sh man/template/conversion.sh Makefile config.mk
man/takum16_from_takum32.3: man/takum16_from_takum32.sh man/takum64_from_takum32.sh man/template/conversion.sh Makefile config.mk
man/takum64_from_takum32.3: man/takum64_from_takum32.sh man/template/conversion.sh Makefile config.mk
man/takum8_from_takum64.3: man/takum8_from_takum64.sh man/takum32_from_takum64.sh man/template/conversion.sh Makefile config.mk
man/takum16_from_takum64.3: man/takum16_from_takum64.sh man/takum32_from_takum64.sh man/template/conversion.sh Makefile config.mk
man/takum32_from_takum64.3: man/takum32_from_takum64.sh man/template/conversion.sh Makefile config.mk
man/takum8_hypotenuse.3: man/takum8_hypotenuse.sh man/takum64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/takum16_hypotenuse.3: man/takum16_hypotenuse.sh man/takum64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/takum32_hypotenuse.3: man/takum32_hypotenuse.sh man/takum64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/takum64_hypotenuse.3: man/takum64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/takum8_integer_power.3: man/takum8_integer_power.sh man/takum64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/takum16_integer_power.3: man/takum16_integer_power.sh man/takum64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/takum32_integer_power.3: man/takum32_integer_power.sh man/takum64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/takum64_integer_power.3: man/takum64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/takum8_inversion.3: man/takum8_inversion.sh man/takum64_inversion.sh man/template/math_function.sh Makefile config.mk
man/takum16_inversion.3: man/takum16_inversion.sh man/takum64_inversion.sh man/template/math_function.sh Makefile config.mk
man/takum32_inversion.3: man/takum32_inversion.sh man/takum64_inversion.sh man/template/math_function.sh Makefile config.mk
man/takum64_inversion.3: man/takum64_inversion.sh man/template/math_function.sh Makefile config.mk
man/takum8_lb.3: man/takum8_lb.sh man/takum64_lb.sh man/template/math_function.sh Makefile config.mk
man/takum16_lb.3: man/takum16_lb.sh man/takum64_lb.sh man/template/math_function.sh Makefile config.mk
man/takum32_lb.3: man/takum32_lb.sh man/takum64_lb.sh man/template/math_function.sh Makefile config.mk
man/takum64_lb.3: man/takum64_lb.sh man/template/math_function.sh Makefile config.mk
man/takum8_lb_1_plus.3: man/takum8_lb_1_plus.sh man/takum64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum16_lb_1_plus.3: man/takum16_lb_1_plus.sh man/takum64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum32_lb_1_plus.3: man/takum32_lb_1_plus.sh man/takum64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum64_lb_1_plus.3: man/takum64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum8_lg.3: man/takum8_lg.sh man/takum64_lg.sh man/template/math_function.sh Makefile config.mk
man/takum16_lg.3: man/takum16_lg.sh man/takum64_lg.sh man/template/math_function.sh Makefile config.mk
man/takum32_lg.3: man/takum32_lg.sh man/takum64_lg.sh man/template/math_function.sh Makefile config.mk
man/takum64_lg.3: man/takum64_lg.sh man/template/math_function.sh Makefile config.mk
man/takum8_lg_1_plus.3: man/takum8_lg_1_plus.sh man/takum64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum16_lg_1_plus.3: man/takum16_lg_1_plus.sh man/takum64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum32_lg_1_plus.3: man/takum32_lg_1_plus.sh man/takum64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum64_lg_1_plus.3: man/takum64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum8_ln.3: man/takum8_ln.sh man/takum64_ln.sh man/template/math_function.sh Makefile config.mk
man/takum16_ln.3: man/takum16_ln.sh man/takum64_ln.sh man/template/math_function.sh Makefile config.mk
man/takum32_ln.3: man/takum32_ln.sh man/takum64_ln.sh man/template/math_function.sh Makefile config.mk
man/takum64_ln.3: man/takum64_ln.sh man/template/math_function.sh Makefile config.mk
man/takum8_ln_1_plus.3: man/takum8_ln_1_plus.sh man/takum64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum16_ln_1_plus.3: man/takum16_ln_1_plus.sh man/takum64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum32_ln_1_plus.3: man/takum32_ln_1_plus.sh man/takum64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum64_ln_1_plus.3: man/takum64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/takum8_multiplication.3: man/takum8_multiplication.sh man/takum64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/takum16_multiplication.3: man/takum16_multiplication.sh man/takum64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/takum32_multiplication.3: man/takum32_multiplication.sh man/takum64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/takum64_multiplication.3: man/takum64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/takum8_power.3: man/takum8_power.sh man/takum64_power.sh man/template/math_function.sh Makefile config.mk
man/takum16_power.3: man/takum16_power.sh man/takum64_power.sh man/template/math_function.sh Makefile config.mk
man/takum32_power.3: man/takum32_power.sh man/takum64_power.sh man/template/math_function.sh Makefile config.mk
man/takum64_power.3: man/takum64_power.sh man/template/math_function.sh Makefile config.mk
man/takum8_precision.3: man/takum8_precision.sh man/takum64_precision.sh man/template/math_function.sh Makefile config.mk
man/takum16_precision.3: man/takum16_precision.sh man/takum64_precision.sh man/template/math_function.sh Makefile config.mk
man/takum32_precision.3: man/takum32_precision.sh man/takum64_precision.sh man/template/math_function.sh Makefile config.mk
man/takum64_precision.3: man/takum64_precision.sh man/template/math_function.sh Makefile config.mk
man/takum8_root.3: man/takum8_root.sh man/takum64_root.sh man/template/math_function.sh Makefile config.mk
man/takum16_root.3: man/takum16_root.sh man/takum64_root.sh man/template/math_function.sh Makefile config.mk
man/takum32_root.3: man/takum32_root.sh man/takum64_root.sh man/template/math_function.sh Makefile config.mk
man/takum64_root.3: man/takum64_root.sh man/template/math_function.sh Makefile config.mk
man/takum8_sec.3: man/takum8_sec.sh man/takum64_sec.sh man/template/math_function.sh Makefile config.mk
man/takum16_sec.3: man/takum16_sec.sh man/takum64_sec.sh man/template/math_function.sh Makefile config.mk
man/takum32_sec.3: man/takum32_sec.sh man/takum64_sec.sh man/template/math_function.sh Makefile config.mk
man/takum64_sec.3: man/takum64_sec.sh man/template/math_function.sh Makefile config.mk
man/takum8_sec_pi_times.3: man/takum8_sec_pi_times.sh man/takum64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum16_sec_pi_times.3: man/takum16_sec_pi_times.sh man/takum64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum32_sec_pi_times.3: man/takum32_sec_pi_times.sh man/takum64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum64_sec_pi_times.3: man/takum64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum8_sech.3: man/takum8_sech.sh man/takum64_sech.sh man/template/math_function.sh Makefile config.mk
man/takum16_sech.3: man/takum16_sech.sh man/takum64_sech.sh man/template/math_function.sh Makefile config.mk
man/takum32_sech.3: man/takum32_sech.sh man/takum64_sech.sh man/template/math_function.sh Makefile config.mk
man/takum64_sech.3: man/takum64_sech.sh man/template/math_function.sh Makefile config.mk
man/takum8_sign.3: man/takum8_sign.sh man/takum64_sign.sh man/template/math_function.sh Makefile config.mk
man/takum16_sign.3: man/takum16_sign.sh man/takum64_sign.sh man/template/math_function.sh Makefile config.mk
man/takum32_sign.3: man/takum32_sign.sh man/takum64_sign.sh man/template/math_function.sh Makefile config.mk
man/takum64_sign.3: man/takum64_sign.sh man/template/math_function.sh Makefile config.mk
man/takum8_sin.3: man/takum8_sin.sh man/takum64_sin.sh man/template/math_function.sh Makefile config.mk
man/takum16_sin.3: man/takum16_sin.sh man/takum64_sin.sh man/template/math_function.sh Makefile config.mk
man/takum32_sin.3: man/takum32_sin.sh man/takum64_sin.sh man/template/math_function.sh Makefile config.mk
man/takum64_sin.3: man/takum64_sin.sh man/template/math_function.sh Makefile config.mk
man/takum8_sin_pi_times.3: man/takum8_sin_pi_times.sh man/takum64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum16_sin_pi_times.3: man/takum16_sin_pi_times.sh man/takum64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum32_sin_pi_times.3: man/takum32_sin_pi_times.sh man/takum64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum64_sin_pi_times.3: man/takum64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum8_sinh.3: man/takum8_sinh.sh man/takum64_sinh.sh man/template/math_function.sh Makefile config.mk
man/takum16_sinh.3: man/takum16_sinh.sh man/takum64_sinh.sh man/template/math_function.sh Makefile config.mk
man/takum32_sinh.3: man/takum32_sinh.sh man/takum64_sinh.sh man/template/math_function.sh Makefile config.mk
man/takum64_sinh.3: man/takum64_sinh.sh man/template/math_function.sh Makefile config.mk
man/takum8_square_root.3: man/takum8_square_root.sh man/takum64_square_root.sh man/template/math_function.sh Makefile config.mk
man/takum16_square_root.3: man/takum16_square_root.sh man/takum64_square_root.sh man/template/math_function.sh Makefile config.mk
man/takum32_square_root.3: man/takum32_square_root.sh man/takum64_square_root.sh man/template/math_function.sh Makefile config.mk
man/takum64_square_root.3: man/takum64_square_root.sh man/template/math_function.sh Makefile config.mk
man/takum8_subtraction.3: man/takum8_subtraction.sh man/takum64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/takum16_subtraction.3: man/takum16_subtraction.sh man/takum64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/takum32_subtraction.3: man/takum32_subtraction.sh man/takum64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/takum64_subtraction.3: man/takum64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/takum8_tan.3: man/takum8_tan.sh man/takum64_tan.sh man/template/math_function.sh Makefile config.mk
man/takum16_tan.3: man/takum16_tan.sh man/takum64_tan.sh man/template/math_function.sh Makefile config.mk
man/takum32_tan.3: man/takum32_tan.sh man/takum64_tan.sh man/template/math_function.sh Makefile config.mk
man/takum64_tan.3: man/takum64_tan.sh man/template/math_function.sh Makefile config.mk
man/takum8_tan_pi_times.3: man/takum8_tan_pi_times.sh man/takum64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum16_tan_pi_times.3: man/takum16_tan_pi_times.sh man/takum64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum32_tan_pi_times.3: man/takum32_tan_pi_times.sh man/takum64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum64_tan_pi_times.3: man/takum64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/takum8_tanh.3: man/takum8_tanh.sh man/takum64_tanh.sh man/template/math_function.sh Makefile config.mk
man/takum16_tanh.3: man/takum16_tanh.sh man/takum64_tanh.sh man/template/math_function.sh Makefile config.mk
man/takum32_tanh.3: man/takum32_tanh.sh man/takum64_tanh.sh man/template/math_function.sh Makefile config.mk
man/takum64_tanh.3: man/takum64_tanh.sh man/template/math_function.sh Makefile config.mk
man/takum8_to_extended_float.3: man/takum8_to_extended_float.sh man/takum64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum16_to_extended_float.3: man/takum16_to_extended_float.sh man/takum64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum32_to_extended_float.3: man/takum32_to_extended_float.sh man/takum64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum64_to_extended_float.3: man/takum64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum8_to_float32.3: man/takum8_to_float32.sh man/takum64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum16_to_float32.3: man/takum16_to_float32.sh man/takum64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum32_to_float32.3: man/takum32_to_float32.sh man/takum64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum64_to_float32.3: man/takum64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum8_to_float64.3: man/takum8_to_float64.sh man/takum64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum16_to_float64.3: man/takum16_to_float64.sh man/takum64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum32_to_float64.3: man/takum32_to_float64.sh man/takum64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk
man/takum64_to_float64.3: man/takum64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk

man/libtakum.7: man/libtakum.sh Makefile config.mk

$(GEN:=.o) gen/util.o:
	$(BUILD_CC) -c -o $@ $(BUILD_CPPFLAGS) $(BUILD_CFLAGS) $(@:.o=.c)

$(BENCHMARK:=.o) benchmark/util.o $(EXAMPLE:=.o) example/util.o $(TEST:=.o) test/util.o:
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $(@:.o=.c)

$(SRC:=.o) src/util.o:
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $(SHFLAGS) $(@:.o=.c)

$(BENCHMARK:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) benchmark/util.o $(ANAME) $(LDLIBS)

$(EXAMPLE:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) example/util.o $(ANAME) $(LDLIBS)

$(GEN:=$(BINSUFFIX)):
	$(BUILD_CC) -o $@ $(BUILD_LDFLAGS) $(@:$(BINSUFFIX)=.o) gen/util.o $(BUILD_LDLIBS)

$(TEST:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) test/util.o $(ANAME) $(LDLIBS)

$(TEST:=.success):
	./$(@:.success=$(BINSUFFIX)) && touch $@

$(GEN:=.h):
	$(@:.h=$(BINSUFFIX)) > $@

$(ANAME): $(SRC:=.o) src/util.o
	$(AR) -rc $@ $?
	$(RANLIB) $@

$(SONAME): $(SRC:=.o) src/util.o
	$(CC) -o $@ $(SOFLAGS) $(LDFLAGS) $(SRC:=.o) src/util.o $(LDLIBS)

$(MAN3:=.3):
	env -i SH="$(SH)" MAN_DATE="$(MAN_DATE)" $(SH) $(@:.3=.sh) > $@

$(MAN7:=.7):
	env -i SH="$(SH)" MAN_DATE="$(MAN_DATE)" MAN3_LIST="$(MAN3)" $(SH) $(@:.7=.sh) > $@

benchmark: $(BENCHMARK:=$(BINSUFFIX))
	for m in $(BENCHMARK:=$(BINSUFFIX)); do ./$$m; done

example: $(EXAMPLE:=$(BINSUFFIX))

check: test

test: $(TEST:=.success)

install: all
	mkdir -p "$(DESTDIR)$(LIBPREFIX)"
	mkdir -p "$(DESTDIR)$(LICPREFIX)/libtakum"
	mkdir -p "$(DESTDIR)$(INCPREFIX)"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man3"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man7"
	cp -f LICENSE "$(DESTDIR)$(LICPREFIX)/libtakum"
	cp -f $(MAN3:=.3) "$(DESTDIR)$(MANPREFIX)/man3"
	cp -f $(MAN7:=.7) "$(DESTDIR)$(MANPREFIX)/man7"
	cp -f $(ANAME) "$(DESTDIR)$(LIBPREFIX)"
	cp -f $(SONAME) "$(DESTDIR)$(LIBPREFIX)"
	if [ "$(SOSYMLINK)" = "true" ]; then i=0; while [ "$$i" -le $(VERSION_MINOR) ]; do ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR).$$i"; i=$$((i+1)); done; fi
	if [ "$(SOSYMLINK)" = "true" ]; then ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR)"; fi
	if [ "$(SOSYMLINK)" = "true" ]; then ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libtakum.so"; fi
	cp -f takum.h "$(DESTDIR)$(INCPREFIX)"
	if ! [ -z "$(LDCONFIG)" ]; then $(SHELL) -c "$(LDCONFIG)"; fi
	if ! [ -z "$(PCPREFIX)" ]; then mkdir -p "$(DESTDIR)$(PCPREFIX)"; printf "Name: libtakum\nDescription: Takum arithmetic reference implementation\nURL: https://takum.org/\nVersion: $(VERSION)\nCflags: -I$(INCPREFIX)\nLibs: -L$(LIBPREFIX) -ltakum -lm\n" > "$(DESTDIR)$(PCPREFIX)/libtakum.pc"; fi

uninstall:
	for m in $(MAN3:=.3); do rm -f "$(DESTDIR)$(MANPREFIX)/man3/`basename $$m`"; done
	for m in $(MAN7:=.7); do rm -f "$(DESTDIR)$(MANPREFIX)/man7/`basename $$m`"; done
	rm -f "$(DESTDIR)$(LICPREFIX)/libtakum/LICENSE"
	rmdir "$(DESTDIR)$(LICPREFIX)/libtakum"
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(ANAME)"
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(SONAME)"
	if [ "$(SOSYMLINK)" = "true" ]; then i=0; while [ "$$i" -le $(VERSION_MINOR) ]; do rm -f "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR).$$i"; i=$$((i+1)); done; fi
	if [ "$(SOSYMLINK)" = "true" ]; then rm -f "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR)"; fi
	if [ "$(SOSYMLINK)" = "true" ]; then rm -f "$(DESTDIR)$(LIBPREFIX)/libtakum.so"; fi
	rm -f "$(DESTDIR)$(INCPREFIX)/takum.h"
	if ! [ -z "$(LDCONFIG)" ]; then $(SHELL) -c "$(LDCONFIG)"; fi
	if ! [ -z "$(PCPREFIX)" ]; then rm -f "$(DESTDIR)$(PCPREFIX)/libtakum.pc"; fi

clean:
	rm -f $(BENCHMARK:=.o) benchmark/util.o $(BENCHMARK:=$(BINSUFFIX)) $(EXAMPLE:=.o) example/util.o $(EXAMPLE:=$(BINSUFFIX)) $(GEN:=.h) $(GEN:=.o) gen/util.o $(GEN:=$(BINSUFFIX)) $(SRC:=.o) src/util.o $(TEST:=.o) test/util.o $(TEST:=$(BINSUFFIX)) $(TEST:=.success) $(ANAME) $(SONAME) $(MAN3:=.3) $(MAN7:=.7)

dist:
	rm -rf "libtakum-$(VERSION)"
	mkdir "libtakum-$(VERSION)"
	for m in benchmark example gen man man/template src test; do mkdir "libtakum-$(VERSION)/$$m"; done
	cp config.mk configure takum.h LICENSE Makefile README "libtakum-$(VERSION)"
	cp $(BENCHMARK:=.c) benchmark/util.c benchmark/util.h "libtakum-$(VERSION)/benchmark"
	cp $(DATA) "libtakum-$(VERSION)/data"
	cp $(EXAMPLE:=.c) example/util.c example/util.h "libtakum-$(VERSION)/example"
	cp $(GEN:=.c) gen/util.c gen/types.h gen/util.h "libtakum-$(VERSION)/gen"
	cp $(MAN3:=.sh) $(MAN7:=.sh) "libtakum-$(VERSION)/man"
	cp $(MAN_TEMPLATE) "libtakum-$(VERSION)/man/template"
	cp $(SRC:=.c) src/util.h "libtakum-$(VERSION)/src"
	cp $(TEST:=.c) test/util.c test/util.h "libtakum-$(VERSION)/test"
	tar -cf - "libtakum-$(VERSION)" | gzip -c > "libtakum-$(VERSION).tar.gz"
	rm -rf "libtakum-$(VERSION)"

format:
	clang-format -i takum.h $(BENCHMARK:=.c) benchmark/util.c benchmark/util.h $(EXAMPLE:=.c) example/util.c example/util.h $(GEN:=.c) gen/util.c gen/util.h $(SRC:=.c) src/util.h $(TEST:=.c) test/util.c test/util.h

.PHONY: all benchmark check clean dist example format install test uninstall
