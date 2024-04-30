/* See LICENSE file for copyright and license details. */
#include <stdio.h>

#include "../takum.h"

#include "../src/codec.h"

int
main(void)
{
	fprintf(stderr, "%.20f\n",
	        codec_takum32_to_l(codec_takum32_from_s_and_l(0, 200.0)));

	return 0;
}
