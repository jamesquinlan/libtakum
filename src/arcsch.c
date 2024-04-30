/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_arcsch(takum8 t)
{
	return takum8_arsinh(takum8_inversion(t));
}

takum16
takum16_arcsch(takum16 t)
{
	return takum16_arsinh(takum16_inversion(t));
}

takum32
takum32_arcsch(takum32 t)
{
	return takum32_arsinh(takum32_inversion(t));
}

takum64
takum64_arcsch(takum64 t)
{
	return takum64_arsinh(takum64_inversion(t));
}
