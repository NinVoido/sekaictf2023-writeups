#include <stdio.h>

#define uint unsigned int

_Bool test(char* buffer) {
      uint uVar1 = (uint)(*(uint*)buffer * 0x193482ba) >> 0xf |  *(uint*)buffer * 0x5740000;
      uint uVar2 = (uint)buffer[4] ^ (uint)buffer[6] << 0x10 ^ ( uint)buffer[5] << 8;
      uVar1 = (uVar2 * 0x193482ba >> 0xf | uVar2 * 0x5740000) * 0x59d87c3f ^
              (uVar1 * -0x3c1e0800 | uVar1 * 0x59d87c3f >> 0x15) * 7 + 0x47c8ac62;
      uVar1 = (uVar1 >> 0x10 ^ uVar1 ^ 7) * 0x764521f9;
      uVar1 = (uVar1 ^ uVar1 >> 0xd) * -0x6c53e18a;
      if ((uVar1 ^ uVar1 >> 0x10) == 0xf99c821) {
        return 1;
      }
      return 0;
}

int main() {
  for (char a = '0'; a <= '9'; ++a) {
  for (char b = '0'; b <= '9'; ++b) {
  for (char c = '0'; c <= '9'; ++c) {
  for (char d = '0'; d <= '9'; ++d) {
  for (char e = '0'; e <= '9'; ++e) {
  for (char f = '0'; f <= '9'; ++f) {
  for (char g = '0'; g <= '9'; ++g) {
    char buf[8] = {a, b, c, d, e, f, g, 0};
    if (test(buf)) {
      printf("%s\n", buf);
      return 0;
    }
  }

  }

  }

  }

  }

  }

  }
}

/*
 *       00100127 0f b6 0d      MOVZX     ECX,byte ptr [UCHAR_ARRAY_001008e0+6]      = ??
               b8 07 00 
               00
      0010012e c1 e1 10      SHL       ECX,0x10
      00100131 c1 c8 0f      ROR       str,0xf
      00100134 69 c0 3f      IMUL      str,str,0x59d87c3f
               7c d8 59
      0010013a c1 c0 0b      ROL       str,0xb
      0010013d 8d 14 c5      LEA       from,[str*0x8]
               00 00 00 
               00
      00100144 29 c2         SUB       from,str
      00100146 0f b6 05      MOVZX     str,byte ptr [UCHAR_ARRAY_001008e0+5]      = ??
               98 07 00 
               00
      0010014d 81 c2 62      ADD       from,0x47c8ac62
               ac c8 47
      00100153 c1 e0 08      SHL       str,0x8
      00100156 31 c1         XOR       ECX,str
      00100158 0f b6 05      MOVZX     str,byte ptr [UCHAR_ARRAY_001008e0+4]      = ??
               85 07 00 
               00
      0010015f 31 c8         XOR       str,ECX
      00100161 69 c0 ba      IMUL      str,str,0x193482ba
               82 34 19
      00100167 c1 c8 0f      ROR       str,0xf
      0010016a 69 c0 3f      IMUL      str,str,0x59d87c3f
               7c d8 59
      00100170 31 d0         XOR       str,from
      00100172 89 c2         MOV       from,str
      00100174 c1 e8 10      SHR       str,0x10
      00100177 83 f2 07      XOR       from,0x7
      0010017a 31 d0         XOR       str,from
      0010017c 69 c0 f9      IMUL      str,str,0x764521f9
               21 45 76
      00100182 89 c2         MOV       from,str
      00100184 c1 ea 0d      SHR       from,0xd
      00100187 31 d0         XOR       str,from
      00100189 69 c0 76      IMUL      str,str,-0x6c53e18a
               1e ac 93
*/
