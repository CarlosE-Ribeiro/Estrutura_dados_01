//declara��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//////////////////////////////PILHA EST�TICA//////////////////////////////

  #define TAM_MAX 10 //definindo o tamanho maximo do vetor (tamanho da pilha)

/*Defini��o dos tipo de Estrutura de dados
  array (vetor) s�o os elementos
  topo (indexador)*/

  typedef struct{
    int vetor[TAM_MAX];
    int topo;
  }PilhaEstatica;


//Opera��o de modifica��o ou adi��o em uma Estrutura de dados

  //1 - inicializa��o
  void Inicia_PilhaEstatica(PilhaEstatica *pilha){
    //A primeira posi��o de inser��o em uma pilha e deve ser na posi��o zerp (0).
    pilha->topo = 0;
  }//Inicia_PilhaEstatica

  //5 - est� vazia?
  bool EstaVazia_PilhaEstatica(PilhaEstatica *pilha){
    //se o topo estiver igual a zero, a fun��o retornar� verdadeiro
    return(pilha->topo == 0);
  }//EstaVazia_PilhaEstatica

  //6 - est� cheia?
  bool EstaCheia_PilhaEstatica(PilhaEstatica *pilha){
    //se o topo estiver igual ao tamanho m�ximo do vetor, a fun��o retornar� verdadeiro
    return(pilha->topo == TAM_MAX);
  }//EstaCheia_PilhaEstatica

  //2 - inser��o (push ou empilha)
  void Empilha_PilhaEstatica(PilhaEstatica *pilha, int valor){
    //Se a pilha n�o estiver cheia
    if(EstaCheia_PilhaEstatica(pilha) == false){
      //acessa o localiza��o do topo no vetor e adiciona um valor
      pilha->vetor[pilha->topo] = valor;
      //passa para o espa�o seguinte do vetor
      pilha->topo++;
    } else
      printf("Erro, a pilha esta cheia...\n\n");
  }//Empilha_PilhaEstatica

  //3 - remo��o (pop ou desempilha)
  int Desempiha_PilhaEstatica(PilhaEstatica *pilha){
    int auxiliar = -999;
    if(EstaVazia_PilhaEstatica){
      auxiliar = pilha->vetor[pilha->topo];
      pilha->topo -= 1;
    } else {
      printf("Nao e possivel retirar elementos da pilha\n\n");
    }//else
    return(auxiliar);
  }//Empilha_PilhaEstatica

  //4 - perquisar/consultar (mostra o topo/top)
  int Pesquisar_PilhaEstetica(PilhaEstatica *pilha){
    int auxiliar;
    auxiliar = pilha->vetor[pilha->topo];
    return(auxiliar);
  }//Pesquisar_PilhaEstetica

  //7 - qunatidade de elementos na estrutura (tamanho)
  int Tamanho_PilhaEstatica(PilhaEstatica *pilha){
    return (pilha->topo);
  }//Tamanho_PilhaEstatica

  //8 - imprimir a estrutura (print na tela)
  void Imprimir_PilhaEstatica(PilhaEstatica *pilha){
    printf("Pilha {");
    for(int i = 0; i < pilha->topo; i++){
      printf(" %i ", pilha->vetor[i]);
    }//for
    printf("}\n");
  }//Imprimir_PilhaEstatica

  //fun��o main
  int main(int argc, const char *argv[]){
    //declara��o de vari�veis
    PilhaEstatica pilha;
    int tamanho_pilha, valor_desempilha, valor_acessot;

    //chamando as fun��es
    Inicia_PilhaEstatica(&pilha);

    //verificando se a pilha est� vazia
    if(EstaVazia_PilhaEstatica(&pilha)){
      printf("A pilha esta vazia!!\n\n");
    } else
      printf("A pilha nao esta vazia!!\n\n");

    //verificando se a pilha est� cheia
    if(EstaCheia_PilhaEstatica(&pilha)){
      printf("A pilha esta cheia!!\n\n");
    } else
      printf("A pilha nao esta cheia!!\n\n");

    //verificando o tamanho da pilha est�tica
    tamanho_pilha = Tamanho_PilhaEstatica(&pilha);
    printf("O tamanho da pilha e: %i \n\n", tamanho_pilha);

    //Inserindo valores na pilha e imprimindo
    Empilha_PilhaEstatica(&pilha, 1);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 2);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 3);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 4);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 5);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 6);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 7);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 8);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 9);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 10);
    Imprimir_PilhaEstatica(&pilha);
    Empilha_PilhaEstatica(&pilha, 11);
    Imprimir_PilhaEstatica(&pilha);

    //tirando valores da pilha e imprimindo (em loop)
    for(int i = 0; i < 10; i++){
      valor_desempilha = Desempiha_PilhaEstatica(&pilha);
      Imprimir_PilhaEstatica(&pilha);
    }//for

    //acessar/pesquisar topo
    valor_acessot = Pesquisar_PilhaEstetica(&pilha);
    printf("%i\n",valor_acessot);


    return 0;
  }//main
