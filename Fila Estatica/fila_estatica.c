//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

  ///////////////////////// Fila Estática /////////////////////////

  //Definindo o tamanho o tamanho da Fila Estática (array/vetor)
  #define TAM_MAX 5

  //Definindo as estruturas que irão conter na criação e manipulação da Fila Estatica
  typedef struct{
    int inicio;
    int final;
    int vetor[TAM_MAX];
    int quantidade;
  } FilaEstatica;

  //Função auxiliar para poder utilizar a fila circular
  int Incrementa_Indice(int x){
    int NovoValor = (x+1) % TAM_MAX;
    return (NovoValor);
  }//Incrementa_Indice

  // Operações em uma Fila Estática

  // Iniciar Fila Estática
  void Inicia_FilaEstatica(FilaEstatica *fila){
    fila->inicio = 0;
    fila->final = -1;
    fila->quantidade = 0;
  }//Inicia_FilaEstatica

  // Verificar se a Fila Estática está vazia
  bool EstaVazia_FilaEstatica(FilaEstatica *fila){
    return(fila->quantidade == 0);
  }//EstaVazia_FilaEstatica

  // Verificar se a Fila Estática está cheia
  bool EstaCheia_FilaEstatica(FilaEstatica *fila){
    return(fila->quantidade == TAM_MAX);
  }//EstaCheia_FilaEstatica

  // Inserir um elemento na Fila Estática
  void Enfileirar_FilaEstatica(FilaEstatica *fila, int valor){
    if(!EstaCheia_FilaEstatica(fila)){
      fila->final  = Incrementa_Indice(fila->final);
      fila->vetor[fila->final] = valor;
      fila->quantidade ++;
    } else{
      printf("Erro, a fila estatica esta cheia!!\n\n");
    }
  }//Emfileirar_FilaEstatica

  // Retorna o tamanho da Fila Estática
  int Tamanho_FilaEstatica(FilaEstatica *fila){
    return(fila->quantidade);
  }//Tamanho_FilaEstatica

  //Imprimir a Fila estatica
  void Impimir_FilaEstatica(FilaEstatica *fila){
    int aux_tamanho = Tamanho_FilaEstatica(fila);
    printf("Fila ={");
    for(int i = fila->inicio; i < aux_tamanho; i++){
      int indice = (fila->inicio + i) % TAM_MAX;
      printf(" %i ",fila->vetor[i]);
    }
    printf("}\n\n");
  }//Impimir_FilaEstatica

  // Remover um elemento na Fila Estática
  int Desenfileirar_FilaEstatica(FilaEstatica *fila){
    int auxiliar = -999;
    if(!EstaVazia_FilaEstatica(fila)){
      auxiliar = fila->vetor[fila->inicio];
      fila->inicio = Incrementa_Indice(fila->inicio);
      fila->quantidade --;
    } else{
      printf("Erro!! A fila ja' esta' vazia!!\n\n");
    }
    return(auxiliar);
  }//Desenfileirar_FilaEstatica

  // Cosultar o primeiro elemento da Fila Estática
  int PrimeiroElemento_FilaEstatica(FilaEstatica *fila){
    return(fila->inicio);
  }//PrimeiroElemento_FilaEstatica

  // Cosultar o último elemento da Fila Estática
  int UltimoElemento_FilaEstatica(FilaEstatica *fila){
    return(fila->final);
  }//UltimoElemento_FilaEstatica


  // função main
  int main(int argc, char **argv){

    //declaração de variáveis
    int tamanhoFila, primeiroFila, ultimoFila;

    //Chamando e declarando a estrutura da Fila Estatica
    FilaEstatica fila;

    //Chamando a função para iniciar a Fila Estática
    Inicia_FilaEstatica(&fila);

    //Funcão para verificar se a fila está vazia
    if (!EstaVazia_FilaEstatica(&fila)) {
      printf("A fila estatica nao esta vazia!!\n\n");
    } else{
      printf("A fila estatica esta vazia!!\n\n");
    }

    //Função para verificar se a fila está cheia
    if (!EstaCheia_FilaEstatica(&fila)) {
      printf("A fila estatica nao esta cheia!!\n\n");
    } else{
      printf("A fila estatica esta cheia!!\n\n");
    }

    //Inserindo e imprimindo elementos na Fila Estatica
    Enfileirar_FilaEstatica(&fila,23);
    Impimir_FilaEstatica(&fila);
    Enfileirar_FilaEstatica(&fila,06);
    Impimir_FilaEstatica(&fila);
    Enfileirar_FilaEstatica(&fila,91);
    Impimir_FilaEstatica(&fila);

    //Verificando o tamanho da Fila Estatica (quantidade de elementos)
    tamanhoFila = Tamanho_FilaEstatica(&fila);
    printf("O tamanho da fila e' %d \n\n", tamanhoFila);

    //Chamando e exibindo o primeiro valor da Fila Estatica
    primeiroFila = PrimeiroElemento_FilaEstatica(&fila);
    printf("O primeiro valor da fila e': %i \n", primeiroFila);

    //Chamando e exibindo o último valor da Fila Estática
    ultimoFila = UltimoElemento_FilaEstatica(&fila);
    printf("O ultimo valor da fila e': %i \n", ultimoFila);

  return 0;
  }//main
