/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_cot(takum8 t)
{
	return takum8_inversion(takum8_tan(t));
}

takum16
takum16_cot(takum16 t)
{
	return takum16_inversion(takum16_tan(t));
}

takum32
takum32_cot(takum32 t)
{
	return takum32_inversion(takum32_tan(t));
}

takum64
takum64_cot(takum64 t)
{
	return takum64_inversion(takum64_tan(t));
}

takum8
takum8_cot_pi_times(takum8 t)
{
	return takum8_inversion(takum8_tan_pi_times(t));
}

takum16
takum16_cot_pi_times(takum16 t)
{
	return takum16_inversion(takum16_tan_pi_times(t));
}

takum32
takum32_cot_pi_times(takum32 t)
{
	return takum32_inversion(takum32_tan_pi_times(t));
}

takum64
takum64_cot_pi_times(takum64 t)
{
	return takum64_inversion(takum64_tan_pi_times(t));
}
