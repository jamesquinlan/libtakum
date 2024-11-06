/* See LICENSE file for copyright and license details. */
#include "../takum.h"

#include "util.h"

takum8
takum8_sign(takum8 t)
{
	return (t == TAKUM8_NAR) ? TAKUM8_NAR :
	       (t < 0)           ? -TAKUM8_ONE :
	       (t > 0)           ? TAKUM8_ONE :
	                           0;
}

takum16
takum16_sign(takum16 t)
{
	return (t == TAKUM16_NAR) ? TAKUM16_NAR :
	       (t < 0)            ? -TAKUM16_ONE :
	       (t > 0)            ? TAKUM16_ONE :
	                            0;
}

takum32
takum32_sign(takum32 t)
{
	return (t == TAKUM32_NAR) ? TAKUM32_NAR :
	       (t < 0)            ? -TAKUM32_ONE :
	       (t > 0)            ? TAKUM32_ONE :
	                            0;
}

takum64
takum64_sign(takum64 t)
{
	return (t == TAKUM64_NAR) ? TAKUM64_NAR :
	       (t < 0)            ? -TAKUM64_ONE :
	       (t > 0)            ? TAKUM64_ONE :
	                            0;
}

takum_linear8
takum_linear8_sign(takum_linear8 t)
{
	return (t == TAKUM_LINEAR8_NAR) ? TAKUM_LINEAR8_NAR :
	       (t < 0)                  ? -TAKUM_LINEAR8_ONE :
	       (t > 0)                  ? TAKUM_LINEAR8_ONE :
	                                  0;
}

takum_linear16
takum_linear16_sign(takum_linear16 t)
{
	return (t == TAKUM_LINEAR16_NAR) ? TAKUM_LINEAR16_NAR :
	       (t < 0)                   ? -TAKUM_LINEAR16_ONE :
	       (t > 0)                   ? TAKUM_LINEAR16_ONE :
	                                   0;
}

takum_linear32
takum_linear32_sign(takum_linear32 t)
{
	return (t == TAKUM_LINEAR32_NAR) ? TAKUM_LINEAR32_NAR :
	       (t < 0)                   ? -TAKUM_LINEAR32_ONE :
	       (t > 0)                   ? TAKUM_LINEAR32_ONE :
	                                   0;
}

takum_linear64
takum_linear64_sign(takum_linear64 t)
{
	return (t == TAKUM_LINEAR64_NAR) ? TAKUM_LINEAR64_NAR :
	       (t < 0)                   ? -TAKUM_LINEAR64_ONE :
	       (t > 0)                   ? TAKUM_LINEAR64_ONE :
	                                   0;
}
