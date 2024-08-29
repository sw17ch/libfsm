/*
 * Copyright 2021 Scott Vokes
 *
 * See LICENCE for the full copyright terms.
 */

#ifndef U64BITSET_H
#define U64BITSET_H

/* Various inline functions for using a bare uint64_t array
 * as a bitset. The size should be managed by the caller. */

#include <stdint.h>
#include <stddef.h>

#include "adt/common.h"

static INLINE uint64_t
u64bitset_get(const uint64_t *s, size_t id)
{
	return s[id/64] & ((uint64_t)1 << (id & 63));
}

static INLINE void
u64bitset_set(uint64_t *s, size_t id)
{
	s[id/64] |= ((uint64_t)1 << (id & 63));
}

static INLINE void
u64bitset_clear(uint64_t *s, size_t id)
{
	s[id/64] &=~ ((uint64_t)1 << (id & 63));
}

/* Calculate how many 64-bit words would be necessary
 * to store COUNT bits, rounding up. */
static INLINE size_t
u64bitset_words(size_t count)
{
	return count/64 + ((count & 63) ? 1 : 0);
}

/* Count '1' bits in s. */
static INLINE uint8_t
u64bitset_popcount(uint64_t s)
{
	return (uint8_t)POPCOUNT(s);
}

#endif
