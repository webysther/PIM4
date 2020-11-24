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

  // login do sistema
  for (;;){
    printf("\nDigite seu usuario e senha para acessar o sistema:");

    // usuário
    printf("\n\nUsuario: ");
    fgets(usuario, sizeof usuario, stdin);
    usuario[strcspn(usuario, "\n")] = 0;

    // senha
    printf("Senha: ");
    int p=0;
    do{
        senha[p]=getch();
        if(senha[p]!='\r'){
            printf("*");
        }
        p++;
    }while(senha[p-1]!='\r');
    senha[p-1]='\0';

    // pode ser alterado por um sistema de login e senha melhor
    if (strcmp(usuario, "admin") != 0 || strcmp(senha, "admin") != 0){
      printf("\nUsuario e senha incorretos");
      continue;
    }

    break;
  }

  char nome[1024];
  char cpf[16];
  char telefone[16];
  char nascimento[16];
  int ano_nascimento, mes_nascimento, dia_nascimento;
  char email[1024];
  char diagnostico[16];
  int ano_diagnostico, mes_diagnostico, dia_diagnostico;
  char comorbidade[1024];

  // endereço
  char rua[1024];
  char numero[16];
  char bairro[1024];
  char cidade[1024];
  char estado[1024];
  char cep[16];

  // cadastro de pacientes
  printf("\n\nDigite as informacoes do paciente:");

  printf("\n\nNome: ");
  fgets(nome, sizeof nome, stdin);
  nome[strcspn(nome, "\n")] = 0;

  printf("CPF (xxx.xxx.xxx-xx): ");
  fgets(cpf, sizeof cpf, stdin);
  cpf[strcspn(cpf, "\n")] = 0;

  printf("Telefone (xx xxxxx-xxxx): ");
  fgets(telefone, sizeof telefone, stdin);
  telefone[strcspn(telefone, "\n")] = 0;

  // Endereço
  printf("\nEndereco");

  printf("\n\nRua: ");
  fgets(rua, sizeof rua, stdin);
  rua[strcspn(rua, "\n")] = 0;

  printf("Numero: ");
  fgets(numero, sizeof numero, stdin);
  numero[strcspn(numero, "\n")] = 0;

  printf("Bairro: ");
  fgets(bairro, sizeof bairro, stdin);
  bairro[strcspn(bairro, "\n")] = 0;

  printf("Cidade: ");
  fgets(cidade, sizeof cidade, stdin);
  cidade[strcspn(cidade, "\n")] = 0;

  printf("Estado: ");
  fgets(estado, sizeof estado, stdin);
  estado[strcspn(estado, "\n")] = 0;

  printf("CEP (xxxxx-xxx): ");
  fgets(cep, sizeof cep, stdin);
  cep[strcspn(cep, "\n")] = 0;

  printf("Data de nascimento (xx/xx/xxxx): ");
  fgets(nascimento, sizeof nascimento, stdin);
  nascimento[strcspn(nascimento, "\n")] = 0;
  sscanf(
    nascimento,
    "%d/%d/%d",
    &dia_nascimento,
    &mes_nascimento,
    &ano_nascimento
  );

  printf("Email: ");
  fgets(email, sizeof email, stdin);
  email[strcspn(email, "\n")] = 0;

  printf("Data de diagnostico (xx/xx/xxxx): ");
  fgets(diagnostico, sizeof diagnostico, stdin);
  diagnostico[strcspn(diagnostico, "\n")] = 0;

  printf("Comorbidade: ");
  fgets(comorbidade, sizeof comorbidade, stdin);
  comorbidade[strcspn(comorbidade, "\n")] = 0;

  FILE *covid;
  covid = fopen("covid.txt", "a");
  // csv separado por |
  fprintf(
    covid,
    "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
    nome,
    cpf,
    telefone,
    rua, numero, bairro, cidade, estado, cep,
    nascimento,
    email,
    diagnostico,
    comorbidade
  );
  fclose(covid);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int idade = tm.tm_year + 1900 - ano_nascimento;

  if(idade > 65){
    printf("\nPaciente pertence ao grupo de risco!");

    FILE *risco;
    risco = fopen("risco.txt", "a");
    fprintf(risco, "%s,%d\n", cep, idade);
    fclose(risco);
    return 0;
  }

  printf("\nPaciente sem risco, cadastro finalizado!");

  return 0;
}
