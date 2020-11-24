#include <stdio.h>

int main(void) {
  FILE *Ponteiro;
  Ponteiro = fopen("covid.txt", "a");
  fclose(Ponteiro);
  return 0;
}