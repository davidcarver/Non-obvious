#include <stdbool.h> // defines bool
#include <limits.h>  // defines CHAR_BIT
#include <stdio.h>


int my_abs(int a) {
   int mask = (a >> (sizeof(int) * CHAR_BIT - 1));
   return (a + mask) ^ mask;
}

bool my_is_power_of_two (unsigned int v) {
   return (v && !(v & (v - 1)));
}

bool my_oppisite_signs(int x,int y) {
   return (((x ^ y) < 0)); // true iff x and y have opposite signs
}

bool my_equal(int x, int y) 
{ 
   return ( x ^ y ); 
} 

int my_min(int x, int y) {
   return (y ^ ((x ^ y) & -(x < y))); // min(x, y)
}

int my_max(int x, int y) {
   return (x ^ ((x ^ y) & -(x < y))); // max(x, y)
}

void my_swap(int* xp, int* yp) {
   if (xp != yp) {
      *xp = *xp + *yp;
      *yp = *xp - *yp;
      *xp = *xp - *yp;
   }
}

void my_swapxor(int* xp, int* yp) {
   if (xp != yp) {
      *yp ^= *xp ^= *yp;
      *xp ^= *yp;
   }
}

