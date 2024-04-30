/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "util.h"

#include "../takum.h"

takum8
takum8_arccot(takum8 t)
{
	if (t > 0) {
		return takum8_arctan(takum8_inversion(t));
	} else {
		return takum8_from_extended_float(atanl(takum8_to_extended_float(takum8_inversion(t))) + PI);
	}
}

takum16
takum16_arccot(takum16 t)
{
	if (t > 0) {
		return takum16_arctan(takum16_inversion(t));
	} else {
		return takum16_from_extended_float(atanl(takum16_to_extended_float(takum16_inversion(t))) + PI);
	}
}

takum32
takum32_arccot(takum32 t)
{
	if (t > 0) {
		return takum32_arctan(takum32_inversion(t));
	} else {
		return takum32_from_extended_float(atanl(takum32_to_extended_float(takum32_inversion(t))) + PI);
	}
}

takum64
takum64_arccot(takum64 t)
{
	if (t > 0) {
		return takum64_arctan(takum64_inversion(t));
	} else {
		return takum64_from_extended_float(atanl(takum64_to_extended_float(takum64_inversion(t))) + PI);
	}
}

takum8
takum8_arccot_over_pi(takum8 t)
{
	if (t > 0) {
		return takum8_arctan_over_pi(takum8_inversion(t));
	} else {
		return takum8_from_extended_float(atanl(takum8_to_extended_float(takum8_inversion(t))) / PI + 1.0L);
	}
}

takum16
takum16_arccot_over_pi(takum16 t)
{
	if (t > 0) {
		return takum16_arctan_over_pi(takum16_inversion(t));
	} else {
		return takum16_from_extended_float(atanl(takum16_to_extended_float(takum16_inversion(t))) / PI + 1.0L);
	}
}

takum32
takum32_arccot_over_pi(takum32 t)
{
	if (t > 0) {
		return takum32_arctan_over_pi(takum32_inversion(t));
	} else {
		return takum32_from_extended_float(atanl(takum32_to_extended_float(takum32_inversion(t))) / PI + 1.0L);
	}
}

takum64
takum64_arccot_over_pi(takum64 t)
{
	if (t > 0) {
		return takum64_arctan_over_pi(takum64_inversion(t));
	} else {
		return takum64_from_extended_float(atanl(takum64_to_extended_float(takum64_inversion(t))) / PI + 1.0L);
	}
}
