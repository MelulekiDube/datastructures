#include <stdio.h>

double foo (double a, double b)
{
  double square (double z) { return a * a; }

  return square (a);
}

int main(void){
	printf("%f\n", foo(9, 4));
}