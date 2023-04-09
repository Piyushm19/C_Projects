#include <stdio.h>

void print_it() {
  // TODO
  printf("Bit operations are fun!\n");
}

void print_int() {
  // TODO
  int x = 10;
  int y = 13;
  int add = x + y;
  int intType;
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("size of signed int in bytes is %zu.\n", sizeof(intType));
  printf("size of signed int in bits is %zu.\n", sizeof(intType) * 8);
  printf("%d + %d = %d.\n", x, y, add);
}

void print_float() {
  // TODO
  float x = 10;
  float y = 13;
  float add = (int)x + (int)y;
  printf("x = %.6f\n", x);
  printf("y = %.6f\n", y);
  printf("size of single float in bytes is %zu.\n", sizeof(float));
  printf("size of single float in bits is %zu.\n", sizeof(float) * 8);
  printf("%.6f + %.6f = %.6f.\n", x, y, add);
  printf("%.6f + %.6f = %i.\n", x, y, (int)add);
}

void print_char() {
  // TODO
  char c = 'C';
  char a = 65;
  char e, f, b;
  e = 'E';
  f = 'F';
  b = 'B';
  int numBits = sizeof(char) * 9;
  printf("c = %c\n", c);
  printf("a = %c\n", a);
  printf("%c%c%c%c%c%c%c%c\n", c, a, f, e, b, a, b, e);
  printf("number of bytes: %i.\n", numBits);
}

void packing_bytes() {
  // TODO
  unsigned char b3 = 202;
  unsigned char b2 = 254;
  unsigned char b1 = 186;
  unsigned char b0 = 190;
  int u = (b3 << 24) | (b2 << 16) | (b1 << 8) | b0; 
  printf("%X\n", u);
}
void unpacking_bytes() {
  // TODO
  unsigned int i1 = 1835098984u;
  unsigned int i2 = 1768842611u;
  char c1 = (i1 >> 24) << 0; 
  char c2 = (i1 << 8) >> 24; 
  char c3 = (i1 << 16) >> 24; 
  char c4 = (i1 << 24) >> 24;
  char c5 = (i2 >> 24) << 0; 
  char c6 = (i2 << 8) >> 24; 
  char c7 = (i2 << 16) >> 24; 
  char c8 = (i2 << 24) >> 24;
  printf("%c%c%c%c%c%c%c%c\n", c1, c2, c3, c4, c5, c6, c7, c8);
}

void print_bits() {
  // TODO
  unsigned char x = 181;
  signed char y = -75;
  char b7, b6, b5, b4, b3, b2, b1, b0;
  b7 = (x & 128) >> 7;
  b6 = (x & 64) >> 6;
  b5 = (x & 32) >> 5;
  b4 = (x & 16) >> 4;
  b3 = (x & 8) >> 3;
  b2 = (x & 4) >> 2;
  b1 = (x & 2) >> 1;
  b0 = (x & 1) >> 0;
  char c7, c6, c5, c4, c3, c2, c1, c0;
  c7 = (y & 128) >> 7;
  c6 = (y & 64) >> 6;
  c5 = (y & 32) >> 5;
  c4 = (y & 16) >> 4;
  c3 = (y & 8) >> 3;
  c2 = (y & 4) >> 2;
  c1 = (y & 2) >> 1;
  c0 = (y & 1) >> 0;
  printf("%d%d%d%d%d%d%d%d\n", (int)b7, (int)b6, (int)b5, (int)b4, (int)b3, (int)b2, (int)b1, (int)b0);
  printf("%d%d%d%d%d%d%d%d\n", (int)c7, (int)c6, (int)c5, (int)c4, (int)c3, (int)c2, (int)c1, (int)c0);
}

void extracting_fields() {
  // TODO
  unsigned int t = 0xCAFEBABE;
  unsigned int a, b, c, d, e, f, g, h, i, j;
  a = (t << 0) >> 29;
  b = (t << 3) >> 28;
  c = (t << 7) >> 28;
  d = (t << 11) >> 29;
  e = (t << 14) >> 29;
  f = (t << 17) >> 28;
  g = (t << 21) >> 28;
  h = (t << 25) >> 29;
  i = (t << 27) >> 30;
  j = (t << 30) >> 30;
  printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
}

void updating_fields() {
  // TODO
  unsigned int result = 17512807u; 
  int mask = ((1 << (21 - 18 + 1)) - 1) << 18;
  int newFld = (8 << 18) & mask;
  int newFull = result & (~mask);
  result = newFld | newFull;
  
  int mask2 = ((1 << (14 - 10 + 1)) - 1) << 10;
  int newFld2 = (17 << 10) & mask2;
  int newFull2 = result & (~mask2);
  int result2 = newFld2 | newFull2;
  printf("%08x\n", result2);
}
