/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8 takum8_csch(takum8 t)
{
	return takum8_inversion(takum8_sinh(t));
}

takum16 takum16_csch(takum16 t)
{
	return takum16_inversion(takum16_sinh(t));
}

takum32 takum32_csch(takum32 t)
{
	return takum32_inversion(takum32_sinh(t));
}

takum64 takum64_csch(takum64 t)
{
	return takum64_inversion(takum64_sinh(t));
}
