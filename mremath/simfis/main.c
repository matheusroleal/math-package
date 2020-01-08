#include <stdio.h>

#include "pendulo.h"

int main(void) {

  printf("Angulo\tPeriodo\tPeriodo Simplificado\n");
  printf("- - -   - - - -  - - - - - - - - - -\n");

  printf("%d\t%f\t%f\n",1,periodo(1),periodo_simplificado(1));

  printf("%d\t%f\t%f\n",3,periodo(3),periodo_simplificado(3));

  printf("%d\t%f\t%f\n",5,periodo(5),periodo_simplificado(5));

  printf("%d\t%f\t%f\n",10,periodo(10),periodo_simplificado(10));

  printf("%d\t%f\t%f\n",30,periodo(30),periodo_simplificado(30));

  printf("%d\t%f\t%f\n",60,periodo(60),periodo_simplificado(60));

  printf("%d\t%f\t%f\n",90,periodo(90),periodo_simplificado(90));
  printf("- - -   - - - -  - - - - - - - - - -\n");

  return 0;
}
