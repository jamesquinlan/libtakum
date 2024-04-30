/* See LICENSE file for copyright and license details. */
#include <math.h>
#include <stdio.h>

#include "../takum.h"

#include "util.h"

int
main(void)
{
	takum32 twentyseven, ten, euler, pi, two, three, sixtyseven, sixteen, res1, res2, res3;

	twentyseven = takum32_from_float32(27.0);
	ten = takum32_from_float32(10.0);
	euler = takum32_from_float32(expf(1.0f));
	pi = takum32_from_float32(3.141592653589793238f);
	two = takum32_from_float32(2.0);
	three = takum32_from_float32(3.0);
	sixtyseven = takum32_from_float32(67.0);
	sixteen = takum32_from_float32(16.0);

	res1 = takum32_division(twentyseven, ten);
	res1 = takum32_subtraction(res1, euler);

	res2 = takum32_square_root(two);

	res3 = takum32_square_root(three);

	res2 = takum32_addition(res2, res3);

	res2 = takum32_subtraction(pi, res2);

	res1 = takum32_division(res1, res2);

	res2 = takum32_division(sixtyseven, sixteen);

	res1 = takum32_power(res1, res2);
	
	printf("res=%.8f\n", takum32_to_float32(res1));

#if 0
	takum32 a, b, res;

	a = takum32_from_float32(0.3);
	b = takum32_from_float32(-0.4);
	res = takum32_addition(a, b);

	printf("a=%.4f, b=%.4f, res=%.4f\n", takum32_to_float32(a), takum32_to_float32(b), takum32_to_float32(res));
#endif

#if 0
	takum32 a, b, c, two, bdiv2a, res1, res2;

	a = takum32_from_float32(3.0);
	b = takum32_from_float32(100.0);
	c = takum32_from_float32(2.0);
	two = takum32_from_float32(2.0);
	bdiv2a = takum32_division(b, takum32_multiplication(two, a));

	res1 = takum32_addition(
			-bdiv2a,
			takum32_square_root(
				takum32_subtraction(
					takum32_multiplication(bdiv2a, bdiv2a),
					takum32_division(c, a)
				)
			)
		);
	res2 = takum32_subtraction(
			-bdiv2a,
			takum32_square_root(
				takum32_subtraction(
					takum32_multiplication(bdiv2a, bdiv2a),
					takum32_division(c, a)
				)
			)
		);

	printf("a=%.8f, b=%.8f, c=%.8f, x1=%.8f, x2=%.8f\n", takum32_to_float64(a), takum32_to_float64(b), takum32_to_float64(c), takum32_to_float64(res1), takum32_to_float64(res2));

	return 0;
#endif
}
