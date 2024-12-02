  //declara��o de bibliotecas
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  //////////////////////////////// �RVORE BIN�RIA ////////////////////////////////

  //ESTRUTURAS QUE COMP�EM A ARVORE
  typedef struct NoArvoreBin *PtrNoArvoreBin;

  typedef struct NoArvoreBin{
    int chave;
    PtrNoArvoreBin F_Direita;
    PtrNoArvoreBin F_Esquerda;
  } NoArvoreBin;

  // OPERA��ES EM UMA ARVORE BINARIA

  //iniciar arvore binaria
  void Inicar_ArvoreBinaria(PtrNoArvoreBin *raiz){
      *raiz = NULL;
  }//Inicar_ArvoreBinaria

  //verificar se a arvore est� vazia
  bool EstaVazia_ArvoreBinaria(PtrNoArvoreBin *raiz){
    return(*raiz == NULL);
  }//EstaVazia_ArvoreBinaria


  //fun��o main
  int main(){

  //declara��o de vari�veis

  //declarando e chamando a estrutura
  PtrNoArvoreBin raiz;

  //chamando a func�o que inicia a arvore
  Inicar_ArvoreBinaria(&raiz);

  //Verificando se a arvore tem elementos
  if(EstaVazia_ArvoreBinaria(&raiz)){
    printf("A arvore esta' vazia!!\n\n");
  } else {
    printf("A arvore nao est� vazia!!\n\n");
  }
  return 0;
  }//main
