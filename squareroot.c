#include <stdint.h>

double dinvsqrt( double number )
{
      double y = number;
      double x2 = y * 0.5;
      uint64_t i = *(uint64_t *) &y;
      // The magic number is for doubles is from https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
      i = 0x5fe6eb50c7b537a9 - (i >> 1);
      y = *(double *) &i;
      y = y * (1.5 - (x2 * y * y));   // 1st iteration
      //      y  = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
      return y;
}

double dsqrt( double number )
{
      double y = 1.0 / number;
      double x2 = y * 0.5;
      uint64_t i = *(uint64_t *) &y;
      // The magic number is for doubles is from https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
      i = 0x5fe6eb50c7b537a9 - (i >> 1);
      y = *(double *) &i;
      y = y * (1.5 - (x2 * y * y));   // 1st iteration
      //      y  = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
      return y;
}

float Q_rsqrt( float number )
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;
  i  = 0x5f3759df - ( i >> 1 );
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );

  return y;
}

float finvsqrt(float x)
{
  float xhalf = 0.5f * x;
  int i = *(int*)&x;            // store floating-point bits in integer
  i = 0x5f3759df - (i >> 1);    // initial guess for Newton's method
  x = *(float*)&i;              // convert new bits into float
  x = x*(1.5f - xhalf*x*x);     // One round of Newton's method
  return x;
}
