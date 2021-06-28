#include<bits/stdc++.h>

float subtract(float in1, float in2)
  {
    float ret = 0.0;
    asm ("fsubr %2, %0" : "=&t" (ret) : "%0" (in1), "u" (in2));
    return ret;
  }

int main() 
  { 
  float in1, in2, out;

  // Did not read the data from a file. Plan on implementing it later.
  in1 = 12.2;
  in2 = 16.4;

  out = subtract(in1, in2);
  printf("%f\n", out);
  }
