//declara��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//fun��o que far� a convers�o de minutos inserida pela usu�ria
void converteMinutos (int *totalMinutos, int *horas, int *minutos){

 *horas = *totalMinutos / 60;
 *minutos = *totalMinutos % 60;
 printf("%i horas e %i minutos\n",*horas,*minutos);

}//converteMinutos

//fun��o main
int main(){
    //para poder utilizar pontua��es
    setlocale(LC_ALL, "");
//declara��o de vari�veis
int totalMinutos, horas = 0, minutos;

//pedindo para o usu�rio entrar com o total de minutos para ser feita a convers�o
printf("Digite a total de minutos para ser feito a convers�o: ");
scanf("%i", &totalMinutos);

converteMinutos(&totalMinutos, &horas, &minutos);

return 0;
}//main
