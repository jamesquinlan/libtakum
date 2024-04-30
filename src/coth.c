/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8 takum8_coth(takum8 t)
{
	return takum8_inversion(takum8_tanh(t));
}

takum16 takum16_coth(takum16 t)
{
	return takum16_inversion(takum16_tanh(t));
}

takum32 takum32_coth(takum32 t)
{
	return takum32_inversion(takum32_tanh(t));
}

takum64 takum64_coth(takum64 t)
{
	return takum64_inversion(takum64_tanh(t));
}
