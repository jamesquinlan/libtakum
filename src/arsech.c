/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_arsech(takum8 t)
{
	return takum8_arcosh(takum8_inversion(t));
}

takum16
takum16_arsech(takum16 t)
{
	return takum16_arcosh(takum16_inversion(t));
}

takum32
takum32_arsech(takum32 t)
{
	return takum32_arcosh(takum32_inversion(t));
}

takum64
takum64_arsech(takum64 t)
{
	return takum64_arcosh(takum64_inversion(t));
}
