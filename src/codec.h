/* See LICENSE file for copyright and license details. */
#ifndef CODEC_H
#define CODEC_H

#include <stdbool.h>

#include "../takum.h"

float codec_takum8_to_l(takum8);
float codec_takum16_to_l(takum16);
double codec_takum32_to_l(takum32);
long double codec_takum64_to_l(takum64);

double codec_s_and_linear_l_to_float64(bool, double);
long double codec_s_and_linear_l_to_extended_float(bool, long double);

float codec_linear_l_from_float32(float);
double codec_linear_l_from_float64(double);
long double codec_linear_l_from_extended_float(long double);

takum8 codec_takum8_from_s_and_l(bool, float);
takum16 codec_takum16_from_s_and_l(bool, float);
takum32 codec_takum32_from_s_and_l(bool, double);
takum64 codec_takum64_from_s_and_l(bool, long double);

#endif /* CODEC_H */
