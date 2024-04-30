/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8 takum8_sech(takum8 t)
{
	return takum8_inversion(takum8_cosh(t));
}

takum16 takum16_sech(takum16 t)
{
	return takum16_inversion(takum16_cosh(t));
}

takum32 takum32_sech(takum32 t)
{
	return takum32_inversion(takum32_cosh(t));
}

takum64 takum64_sech(takum64 t)
{
	return takum64_inversion(takum64_cosh(t));
}
