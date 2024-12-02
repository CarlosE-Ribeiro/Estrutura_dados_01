//declara��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//////////////////////////////PILHA DIN�MICA//////////////////////////////


  // 1 - Definir os tipos usados na pilha din�mica

  //Definindo um tipo de ponteiro para as estruturas da pilha din�mica
  typedef struct Nopilha *ptrNopilha;

  //Estruturas da pilha din�mica
  typedef struct Nopilha{
    int chave;
    ptrNopilha proximo;
  }Nopilha;

  typedef struct{
    ptrNopilha topo;
    int quantidade;
  }PilhaDinamica;

  //2 - Fun��es e opera��es de uma pilha din�mica

  //Iniciar a pilha din�mica
  void Inicia_PilhaDinamica (PilhaDinamica *pilha){
    pilha->topo = NULL;
    pilha->quantidade = 0;
  }//iniciar_pilha

  //Verificar se a pilha din�mica est� vazia
  bool EstaVazia_PilhaDinamica (PilhaDinamica *pilha){
    return(pilha->topo == NULL);
  }//verifica_vazia

  //Tamanho da pilha din�mica (quantidade de elementos)
  int Tamanho_PilhaDinamica (PilhaDinamica *pilha){
    return(pilha->quantidade);
  }//qunatidade_elem

  //Inser��o de um elemento na pilha din�mica (push ou empilha)
  void Empilha_PilhaDinamica (PilhaDinamica *pilha, int valor){
    ptrNopilha no = malloc(sizeof (Nopilha));
    no->proximo = pilha->topo;
    no->chave = valor;
    pilha->topo = no;
    pilha->quantidade ++;
  }//insercao_pilha

  //Remove um elemento da pilha din�mica (pop ou desempilha)
  int Desempilha_PilhaDinamica (PilhaDinamica *pilha){
    int valor = 9999;
    if(!EstaVazia_PilhaDinamica(pilha)){
      ptrNopilha auxiliar;
      auxiliar = pilha->topo;
      pilha->topo = auxiliar->proximo; //pilha->topo = pilha->topo->proximo
      valor = auxiliar->chave;
      pilha->quantidade --;
      free(auxiliar);
        } else {
          printf("Pilha est� vazia!!! \n");
        }//else
    return(valor);
  }//remocao_pilha

  //Imprimir pilha din�mica
  void Imprimir_PilhaDinamica (PilhaDinamica *pilha){
    ptrNopilha ponteiro;
    printf("[ ");
    for(ponteiro = pilha->topo; ponteiro != NULL; ponteiro = ponteiro->proximo){
      printf("%i ", ponteiro->chave);
    }//for
    printf("]\n\n");
  }//imprimi_pilha

  //pesquisar/consultar para qual elemento o topo est� apontando
  int Pesquisar_PilhaDinamica (PilhaDinamica *pilha, int valor_pesquisa){
    valor_pesquisa = pilha->topo;
    return(valor_pesquisa);
  }//consulta_pilha

  void destruir_pilha (PilhaDinamica *pilha){

  }//destruir_pilha

  //fun��o main
  int main(){

    //declara��o da struct
    PilhaDinamica pilha;

    //Iniciando a pilha din�mica
    Inicia_PilhaDinamica(&pilha);

    //vereficando se a pilha din�mica est� vazia
    if(EstaVazia_PilhaDinamica(&pilha)){
      printf("A pilha dinamica esta vazia!!\n\n");
    } else {
      printf("A pilha dinamica contem elementos!!\n\n");
    }

    //inserindo  e imprimondo os valores na pilha din�mica
    Empilha_PilhaDinamica(&pilha,18);
    Imprimir_PilhaDinamica(&pilha);
    Empilha_PilhaDinamica(&pilha,23);
    Imprimir_PilhaDinamica(&pilha);
    Desempilha_PilhaDinamica(&pilha);
    Imprimir_PilhaDinamica(&pilha);


    return 0;
  }//main
