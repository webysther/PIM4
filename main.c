/**
 * Programa que realiza o cadastro de pacientes com COVID-19
 *
 * @link      https://github.com/webysther/PIM4
 * @author    Webysther Nunes <webysther@gmail.com>
 * @license   https://github.com/webysther/PIM4/blob/master/LICENSE MIT
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  char usuario[256];
  char senha[32];

  printf("\nDica: usuário e senha é admin");

  // login do sistema
  for (;;){
    printf("\nDigite seu usuário e senha para acessar o sistema:");

    // usuário
    printf("\nUsuário: ");
    scanf("%255s", usuario);

    // senha
    printf("\nSenha: ");
    scanf("%31s", senha);
	
    // pode ser alterado por um sistema de login e senha melhor
    if (strcmp(usuario, "admin") != 0 || strcmp(senha, "admin") != 0){
      printf("\nUsuário e senha incorretos");
      continue;
    }

    break;
	}

  char nome[1024];
  int cpf;
  int telefone;
  char nascimento[] = "01/01/1970";
  int ano_nascimento, mes_nascimento, dia_nascimento; 
  char email[1024];
  char diagnostico[] = "01/01/1970";
  int ano_diagnostico, mes_diagnostico, dia_diagnostico; 
  char comorbidade[1024];

  // endereço
  char rua[1024];
  int numero;
  char bairro[1024];
  char cidade[1024];
  char estado[1024];
  int cep;

  // cadastro de pacientes
  printf("\nDigite as informações do paciente:");

  printf("\nNome: ");
  scanf("%1023s", nome);

  printf("\nCPF: ");
  scanf("%d", &cpf);

  printf("\nTelefone: ");
  scanf("%d", &telefone);

  // Endereço
  printf("\nEndereço");

  printf("\nRua: ");
  scanf("%1023s", rua);

  printf("\nNúmero: ");
  scanf("%d", &numero);

  printf("\nBairro: ");
  scanf("%1023s", bairro);

  printf("\nCidade: ");
  scanf("%1023s", cidade);

  printf("\nEstado: ");
  scanf("%1023s", estado);

  printf("\nCEP: ");
  scanf("%d", &cep);

  printf("\nData de nascimento: ");
  sscanf(
    nascimento, 
    "%d/%d/%d", 
    &dia_nascimento,
    &mes_nascimento,
    &ano_nascimento
  );

  printf("\nE-mail: ");
  scanf("%1023s", email);

  printf("\nData de diagnóstico: ");
  sscanf(
    diagnostico, 
    "%d/%d/%d", 
    &dia_diagnostico,
    &mes_diagnostico,
    &ano_diagnostico
  );

  printf("\nComorbidade: ");
  scanf("%1023s", comorbidade);

  FILE *covid;
  covid = fopen("covid.txt", "a");
  fprintf(
    covid,
    "%s,%d,%d,%s,%d,%s,%s,%s,%d,%d,%d,%d,%s,%d,%d,%d,%s",
    nome, 
    cpf, 
    telefone,
    rua, numero, bairro, cidade, estado, cep,
    ano_nascimento, mes_nascimento, dia_nascimento,
    email,
    ano_diagnostico, mes_nascimento, dia_diagnostico,
    comorbidade
  );
  fclose(covid);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if(tm.tm_year + 1900 - ano_nascimento > 65){
    FILE *risco;
    risco = fopen("risco.txt", "a");
    fprintf(
      risco,
      "%s,%d,%d,%s,%d,%s,%s,%s,%d,%d,%d,%d,%s,%d,%d,%d,%s",
      nome, 
      cpf, 
      telefone,
      rua, numero, bairro, cidade, estado, cep,
      ano_nascimento, mes_nascimento, dia_nascimento,
      email,
      ano_diagnostico, mes_nascimento, dia_diagnostico,
      comorbidade
    );
    fclose(risco);
  }
  
  return 0;
}