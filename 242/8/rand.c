#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  int i;
  long int max = strtol(argv[1],NULL,10);
  for(i = 0; i < max;i++){
    printf("%d\n" ,rand());
  }
  return EXIT_SUCCESS;
}
