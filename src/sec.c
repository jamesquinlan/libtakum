/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_sec(takum8 t)
{
	return takum8_inversion(takum8_cos(t));
}

takum16
takum16_sec(takum16 t)
{
	return takum16_inversion(takum16_cos(t));
}

takum32
takum32_sec(takum32 t)
{
	return takum32_inversion(takum32_cos(t));
}

takum64
takum64_sec(takum64 t)
{
	return takum64_inversion(takum64_cos(t));
}

takum8
takum8_sec_pi_times(takum8 t)
{
	return takum8_inversion(takum8_cos_pi_times(t));
}

takum16
takum16_sec_pi_times(takum16 t)
{
	return takum16_inversion(takum16_cos_pi_times(t));
}

takum32
takum32_sec_pi_times(takum32 t)
{
	return takum32_inversion(takum32_cos_pi_times(t));
}

takum64
takum64_sec_pi_times(takum64 t)
{
	return takum64_inversion(takum64_cos_pi_times(t));
}
