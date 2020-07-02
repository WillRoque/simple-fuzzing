#include <stddef.h>
#include <stdint.h>

extern "C" int FUZZ(const uint8_t *Data, size_t Size)
{
  return 0; // Non-zero return values are reserved for future use.
}
