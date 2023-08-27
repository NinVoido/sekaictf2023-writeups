#include <stdint.h>
#include <stdio.h>

#define byte uint8_t

int main() {
  char buffer[13] = {'\x0e', '\xaf', '\x88', '\x1d', '\xb9', '\x88', '\x8c', '\x78', '\xec', '\x11', '\xf3', '\x7d', 0};

  for (long i = 11; i > -1; --i) {
    buffer[i] -= ~(byte)i * buffer[i + 1];
  }

  printf("%s\n", buffer);
}
