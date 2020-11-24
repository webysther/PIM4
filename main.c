/**
 * Programa que realiza o cadastro de pacientes com COVID-19
 *
 * @link      https://github.com/webysther/PIM4
 * @author    Webysther Nunes <webysther@gmail.com>
 * @license   https://github.com/webysther/PIM4/blob/master/LICENSE MIT
 */

#include <stdio.h>

int main(void) {
  FILE *Ponteiro;
  Ponteiro = fopen("covid.txt", "a");
  fclose(Ponteiro);
  return 0;
}