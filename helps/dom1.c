#include <stdio.h>
#include <stdlib.h>


#define func( x, y )  (x >= y ? (x == y ? x*y : x + y) : (x*x*x - x*y))

int main(void)
{
  printf(" %d",func(1, 2));
  printf(" %d",func(2, 2));
  printf(" %d",func(3, 2));
}