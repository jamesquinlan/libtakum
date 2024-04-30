/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_csc(takum8 t)
{
	return takum8_inversion(takum8_sin(t));
}

takum16
takum16_csc(takum16 t)
{
	return takum16_inversion(takum16_sin(t));
}

takum32
takum32_csc(takum32 t)
{
	return takum32_inversion(takum32_sin(t));
}

takum64
takum64_csc(takum64 t)
{
	return takum64_inversion(takum64_sin(t));
}

takum8
takum8_csc_pi_times(takum8 t)
{
	return takum8_inversion(takum8_sin_pi_times(t));
}

takum16
takum16_csc_pi_times(takum16 t)
{
	return takum16_inversion(takum16_sin_pi_times(t));
}

takum32
takum32_csc_pi_times(takum32 t)
{
	return takum32_inversion(takum32_sin_pi_times(t));
}

takum64
takum64_csc_pi_times(takum64 t)
{
	return takum64_inversion(takum64_sin_pi_times(t));
}
