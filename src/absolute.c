/* See LICENSE file for copyright and license details. */
#include "../takum.h"

#include "util.h"

takum8
takum8_absolute(takum8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum16
takum16_absolute(takum16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum32
takum32_absolute(takum32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum64
takum64_absolute(takum64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum_linear8
takum_linear8_absolute(takum_linear8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum_linear16
takum_linear16_absolute(takum_linear16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum_linear32
takum_linear32_absolute(takum_linear32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

takum_linear64
takum_linear64_absolute(takum_linear64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}
