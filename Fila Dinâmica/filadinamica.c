  //declaração de bibliotecas
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  ///////////////////////// Fila Dinâmica /////////////////////////

  //Definindo as estruturas que irão conter na criação e manipulação da Fila Dinâmica
  typedef struct NoFilaDinamica* PtrNoFila;

  typedef struct NoFilaDinamica{
    int chave;
    PtrNoFila proximo;
  } NofilaDinamica;

  typedef struct {
    PtrNoFila inicio;
    PtrNoFila final;
    int quantidade;
  } FilaDinamica;

  // Operações em uma fila dinâmica

  // Iniciar fila dinamica
  void Inicia_FilaDinamica(FilaDinamica *fila){
    fila->inicio = NULL;
    fila->final = NULL;
    fila->quantidade = 0;
  }//Inicia_FilaDinamica

  // Retorna o tamanho da fila dinamica
  int Tamanho_FilaDinamica(FilaDinamica *fila){
    return(fila->quantidade);
  }//Tamanho_FilaDinamica

  // Verificando se a fila dinamica está vazia
  bool EstaVazia_FilaDinamica(FilaDinamica *fila){
    return(fila->final == NULL);
  }//EstaVazia_FilaDinamica

  // Inserindo elementos na fila dinamica
  void Enfileirar_FilaDinamica(FilaDinamica *fila, int valor){
    PtrNoFila NoAuxiliar = malloc(sizeof(FilaDinamica));
    NoAuxiliar->chave = valor;
    if(EstaVazia_FilaDinamica(fila)){
      fila->inicio = fila->final = NoAuxiliar;
      NoAuxiliar->proximo = NULL;
    } else {
      fila->final->proximo = NoAuxiliar;
      fila->final = NoAuxiliar;
      NoAuxiliar->proximo = NULL;
    }
    fila->quantidade ++;
  }//Enfileirar_FilaDinamica

  // Retirando eleme da fila dinamica
  int Desenfileirar_FilaDinamica(FilaDinamica *fila){
    int retorno = -999;
    if(!EstaVazia_FilaDinamica(fila)){
      PtrNoFila auxiliar;
      auxiliar = fila->inicio;
      fila->inicio = fila->inicio->proximo;
      retorno = auxiliar->chave;
      free(auxiliar);
      fila->quantidade --;
    } else {
      printf("Erro!! A fila dinamica está vazia!!\n\n");
    }
  }//Desenfileirar_FilaDinamica

  // Imprimindo os elementos da fila dinamica
  void Imprimir_FilaDinamica(FilaDinamica *fila){
    printf("Fila {");
    PtrNoFila percorre;
    for(percorre = fila->inicio; percorre != NULL; percorre = percorre->proximo){
      printf(" %i ", percorre->chave);
    }
    printf("}\n\n");
  }//Imprimir_FilaDinamica

  // Imprimindo o primeiro valor da fila dinaminica
  


  //função main
  int main(){

  //declaração de variáveis
  int tamanhoFila;
  //chamando e declarando a fila dinamica
  FilaDinamica fila;

  //iniciando chamando as funções da fila dinamica
  Inicia_FilaDinamica(&fila);

  //imprimindo o tamanho da fila
  tamanhoFila = Tamanho_FilaDinamica(&fila);
  printf("O tamanho da fila dinamica e': %d\n\n", tamanhoFila);

  //verificando se a fila está vazia
  if(EstaVazia_FilaDinamica(&fila)){
    printf("A fila dinamica esta' vazia\n\n");
  } else {
    printf("A fila dinamica nao esta' vazia, contem %d elementos\n\n", tamanhoFila);
  }

  //inserindo e printando elementos na fila dinamica
  Enfileirar_FilaDinamica(&fila,23);
  Imprimir_FilaDinamica(&fila);
  Enfileirar_FilaDinamica(&fila,06);
  Imprimir_FilaDinamica(&fila);
  Enfileirar_FilaDinamica(&fila,33);
  Imprimir_FilaDinamica(&fila);
  Enfileirar_FilaDinamica(&fila,30);
  Imprimir_FilaDinamica(&fila);
  Enfileirar_FilaDinamica(&fila,34);
  Imprimir_FilaDinamica(&fila);

  //imprimindo o tamanho da fila
  tamanhoFila = Tamanho_FilaDinamica(&fila);
  printf("O tamanho da fila dinamica e': %d\n\n", tamanhoFila);

  // Retirando e imprimindo elementos da fila dinamica
  Desenfileirar_FilaDinamica(&fila);
  Imprimir_FilaDinamica(&fila);
  Desenfileirar_FilaDinamica(&fila);
  Imprimir_FilaDinamica(&fila);
  Desenfileirar_FilaDinamica(&fila);
  Imprimir_FilaDinamica(&fila);

return 0;
  }//main
