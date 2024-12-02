  //declaração de bibliotecas
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  //////////////////////////////// ÁRVORE BINÁRIA ////////////////////////////////

  //ESTRUTURAS QUE COMPÕEM A ARVORE
  typedef struct NoArvoreBin *PtrNoArvoreBin;

  typedef struct NoArvoreBin{
    int chave;
    PtrNoArvoreBin F_Direita;
    PtrNoArvoreBin F_Esquerda;
  } NoArvoreBin;

  // OPERAÇÕES EM UMA ARVORE BINARIA

  //iniciar arvore binaria
  void Inicar_ArvoreBinaria(PtrNoArvoreBin *raiz){
      *raiz = NULL;
  }//Inicar_ArvoreBinaria

  //verificar se a arvore está vazia
  bool EstaVazia_ArvoreBinaria(PtrNoArvoreBin *raiz){
    return(*raiz == NULL);
  }//EstaVazia_ArvoreBinaria


  //função main
  int main(){

  //declaração de variáveis

  //declarando e chamando a estrutura
  PtrNoArvoreBin raiz;

  //chamando a funcão que inicia a arvore
  Inicar_ArvoreBinaria(&raiz);

  //Verificando se a arvore tem elementos
  if(EstaVazia_ArvoreBinaria(&raiz)){
    printf("A arvore esta' vazia!!\n\n");
  } else {
    printf("A arvore nao está vazia!!\n\n");
  }
  return 0;
  }//main
