/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_arccsc(takum8 t)
{
	return takum8_arcsin(takum8_inversion(t));
}

takum16
takum16_arccsc(takum16 t)
{
	return takum16_arcsin(takum16_inversion(t));
}

takum32
takum32_arccsc(takum32 t)
{
	return takum32_arcsin(takum32_inversion(t));
}

takum64
takum64_arccsc(takum64 t)
{
	return takum64_arcsin(takum64_inversion(t));
}

takum8
takum8_arccsc_over_pi(takum8 t)
{
	return takum8_arcsin_over_pi(takum8_inversion(t));
}

takum16
takum16_arccsc_over_pi(takum16 t)
{
	return takum16_arcsin_over_pi(takum16_inversion(t));
}

takum32
takum32_arccsc_over_pi(takum32 t)
{
	return takum32_arcsin_over_pi(takum32_inversion(t));
}

takum64
takum64_arccsc_over_pi(takum64 t)
{
	return takum64_arcsin_over_pi(takum64_inversion(t));
}
