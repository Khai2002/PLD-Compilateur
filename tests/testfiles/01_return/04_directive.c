#pragma once
#include <stdio.h>
#define a A
#if 0
#else
#endif
#ifdef a
#undef a
#endif

int main() {
   return 0;
}
