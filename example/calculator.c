/* See LICENSE file for copyright and license details. */
#include <math.h>
#include <stdio.h>

#include "../takum.h"

#include "util.h"

int
main(void)
{
	takum32 a, b, res;

	a = takum32_from_float64(0.5);
	b = takum32_from_float64(3.5);

	res = takum32_root(takum32_addition(a, b), 3);

	printf("a=%f, b=%f, res=%f\n", takum32_to_float64(a), takum32_to_float64(b), takum32_to_float64(res));

	return 0;
}
