/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_arcsec(takum8 t)
{
	return takum8_arccos(takum8_inversion(t));
}

takum16
takum16_arcsec(takum16 t)
{
	return takum16_arccos(takum16_inversion(t));
}

takum32
takum32_arcsec(takum32 t)
{
	return takum32_arccos(takum32_inversion(t));
}

takum64
takum64_arcsec(takum64 t)
{
	return takum64_arccos(takum64_inversion(t));
}

takum8
takum8_arcsec_over_pi(takum8 t)
{
	return takum8_arccos_over_pi(takum8_inversion(t));
}

takum16
takum16_arcsec_over_pi(takum16 t)
{
	return takum16_arccos_over_pi(takum16_inversion(t));
}

takum32
takum32_arcsec_over_pi(takum32 t)
{
	return takum32_arccos_over_pi(takum32_inversion(t));
}

takum64
takum64_arcsec_over_pi(takum64 t)
{
	return takum64_arccos_over_pi(takum64_inversion(t));
}
