/* See LICENSE file for copyright and license details. */
#include <stdbool.h>

#include "../takum.h"

#include "util.h"

/*
 * Assume the input is a left-aligned fixed-point representation of a
 * value [0,1) with N bits. This function rounds the value to a right-aligned
 * representation with exactly the given number of bits; any more
 * significant bits are zero. Round to the nearest value and break
 * ties by rounding to the respective even value.
 */
#define GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(N)                         \
	uint##N##_t util_round_uint##N##_to_number_of_bits(                    \
		uint##N##_t input, uint8_t number_of_bits)                     \
	{                                                                      \
		bool rounding_bit, is_tied;                                    \
		uint##N##_t rounding_bit_mask, filter_mask, result;            \
                                                                               \
		/* We assume number of bits is within the proper range 0..N-1  \
		 * and have the following bitwise representation of the input: \
		 *                                                             \
		 *                         R                                   \
		 *                         |                                   \
		 *                         v                                   \
		 * |xxxxxxxxxxxxxxxxxxxxxxx.............................|      \
		 *                                                             \
		 * <--- number_of_bits ---><--- (N - number_of_bits) --->      \
		 * <---------------------- N --------------------------->      \
		 *                                                             \
		 * where R marks the position of the rounding bit.             \
		 */                                                            \
                                                                               \
		/*                                                             \
		 * Obtain the rounding bit by using a mask 10...0 of length    \
		 * (N - number_of_bits)                                        \
		 */                                                            \
		rounding_bit_mask = UINT##N##_C(1)                             \
		                    << (N - number_of_bits - 1);               \
		rounding_bit = ((input & rounding_bit_mask) != 0);             \
                                                                               \
		/*                                                             \
		 * Check if we have a tie, which is the case when the lowest   \
		 * (N - number_of_bits) bits are 10...0. We do this by         \
		 * removing all more significant bits with a filter mask and   \
		 * checking equality with the rounding bit mask.               \
		 */                                                            \
		filter_mask = (UINT##N##_C(1) << (N - number_of_bits)) - 1;    \
		is_tied = ((input & filter_mask) == rounding_bit_mask);        \
                                                                               \
		/*                                                             \
		 * Shift the input (N - number_of_bits) to the right such that \
		 * it has the desired number of bits.                          \
		 */                                                            \
		result = input >> (N - number_of_bits);                        \
                                                                               \
		/*                                                             \
		 * Round up if the rounding bit is set, but treat a tie by     \
		 * rounding to even                                            \
		 */                                                            \
		result += rounding_bit && (!is_tied || (result % 2 == 1));     \
                                                                               \
		return result;                                                 \
	}

GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(8)
GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(16)
GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(32)
GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(64)
