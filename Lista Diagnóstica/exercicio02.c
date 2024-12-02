//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

//função main
int main(){
    //para poder utilizar pontuações
    setlocale(LC_ALL, "");

// declaração de variáveis
char analise_caracter;
int conta_linhas = 0;

//declaração dos arquivos
FILE *arquivo_entrada = fopen("arquivo_entrada.txt", "r");
//verificando se o arquivo está no diretório
if(arquivo_entrada == NULL){
  perror("Erro ao abrir arquivo! ");
  printf("\n");
  exit(1);
}//if

//declaração dos arquivos
FILE *arquivo_saida = fopen("arquivo_saida.txt", "w");
//verificando se o arquivo está no diretório
if(arquivo_saida == NULL){
  perror("Erro ao abrir arquivo! ");
  printf("\n");
  exit(1);
}//if

//looping para percorrer o que esta digitado no arquivo e contar qunatidade de enter(\n)
while((analise_caracter = fgetc(arquivo_entrada))!=EOF){
  //função que analisa as letras minusculas e maisculo
  analise_caracter = toupper(analise_caracter);

  if(analise_caracter == '\n'){
    conta_linhas++;
  }//if

  if(analise_caracter == 'A' || analise_caracter == 'E'|| analise_caracter == 'I'|| analise_caracter == 'O'|| analise_caracter == 'U'){
    analise_caracter = '*';
  }//if
    fputc(analise_caracter, arquivo_saida);
}//while

printf("O numero de linhas é:%i\n",conta_linhas );

//fechando arquivos
fclose(arquivo_entrada);
fclose(arquivo_saida);

return 0;
}//main
