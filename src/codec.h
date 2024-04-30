/* See LICENSE file for copyright and license details. */
#ifndef CODEC_H
#define CODEC_H

#include <stdbool.h>

#include "../takum.h"

float codec_takum8_to_l(takum8);
float codec_takum16_to_l(takum16);
double codec_takum32_to_l(takum32);
long double codec_takum64_to_l(takum64);

takum8 codec_takum8_from_s_and_l(bool, float);
takum16 codec_takum16_from_s_and_l(bool, float);
takum32 codec_takum32_from_s_and_l(bool, double);
takum64 codec_takum64_from_s_and_l(bool, long double);

#endif /* CODEC_H */
