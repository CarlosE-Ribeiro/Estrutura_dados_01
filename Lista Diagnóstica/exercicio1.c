//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//função que fará a conversão de minutos inserida pela usuária
void converteMinutos (int *totalMinutos, int *horas, int *minutos){

 *horas = *totalMinutos / 60;
 *minutos = *totalMinutos % 60;
 printf("%i horas e %i minutos\n",*horas,*minutos);

}//converteMinutos

//função main
int main(){
    //para poder utilizar pontuações
    setlocale(LC_ALL, "");
//declaração de variáveis
int totalMinutos, horas = 0, minutos;

//pedindo para o usuário entrar com o total de minutos para ser feita a conversão
printf("Digite a total de minutos para ser feito a conversão: ");
scanf("%i", &totalMinutos);

converteMinutos(&totalMinutos, &horas, &minutos);

return 0;
}//main
