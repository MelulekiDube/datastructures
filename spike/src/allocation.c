#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *x = malloc(sizeof(int));
  int *y = calloc(1, sizeof(int));

int i, j , k;
  printf("i = %i j = %i k = %i\n", i, j, k);
  printf("x is pointing to %p and its value is %d\n", x, *x);
  printf("y is pointing to %p and its value is %d\n", y, *y);
}