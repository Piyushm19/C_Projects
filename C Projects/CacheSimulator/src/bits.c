#include "bits.h"
#include "cache.h"

int get_set(Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //
  
  int tags = 32 - ((cache->set_bits) + (cache->block_bits));
  return ((address << tags) >> (tags + cache->block_bits));
}

int get_line(Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
  return (address >> (cache-> set_bits + cache-> block_bits));
}

int get_byte(Cache *cache, address_type address) {
  // TODO
  // Extract the block offset (byte index) bits from a 32-bit address.
  //
  int tags = 32 - ((cache->set_bits) + (cache->block_bits));
  return ((address << (tags + cache->set_bits)) >> (tags + cache->set_bits));
}
