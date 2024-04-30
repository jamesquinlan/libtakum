/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_arcoth(takum8 t)
{
	return takum8_artanh(takum8_inversion(t));
}

takum16
takum16_arcoth(takum16 t)
{
	return takum16_artanh(takum16_inversion(t));
}

takum32
takum32_arcoth(takum32 t)
{
	return takum32_artanh(takum32_inversion(t));
}

takum64
takum64_arcoth(takum64 t)
{
	return takum64_artanh(takum64_inversion(t));
}
