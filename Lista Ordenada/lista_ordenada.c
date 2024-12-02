  //declaração de bibliotecas
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  //////////////////////////////// LISTA ORDENADA ////////////////////////////////

    //Definindo as estruturas que irão conter na criação e manipulação da lista ordenada
    typedef struct NoLista* PtrNoLista;

    typedef struct NoLista{
      int chave;
      PtrNoLista proximo;
    } NoLista;

    typedef struct{
      PtrNoLista inicio;
      int quantidade;
    } ListaOrdenada;


    // Opereções em uma lista ordenada

    // Inicialização da lista ordenada
    void Iniciar_ListaOrdenada(ListaOrdenada *lista){
      lista->inicio = NULL;
      lista->quantidade = 0;
    } //;Iniciar_ListaOrdenada

    // Verficando se a lista está vazia
    bool EstaVaia_ListaOrdenada(ListaOrdenada *lista){
      return(lista->inicio == NULL);
    }//EstaVaia_ListaOrdenada

    // Verificando a quantidade de elemeto na lista
    int Tamanho_ListaOrdenada(ListaOrdenada *lista){
      return(lista->quantidade);
    }//Tamanho_ListaOrdenada

    //Inserindo valores na lista
    void Inserir_ListaOrdenada(ListaOrdenada *lista, int valor){
      PtrNoLista novo_elemento;
      novo_elemento = (PtrNoLista)malloc(sizeof(NoLista));
      novo_elemento->chave = valor;
      if(EstaVaia_ListaOrdenada(lista) || valor < lista->inicio->chave){
        novo_elemento->proximo = lista->inicio;
        lista->inicio = novo_elemento;
      }else{
        PtrNoLista auxiliar;
        auxiliar = lista->inicio;
        while (auxiliar->proximo!= NULL && valor > auxiliar->proximo->chave){
          auxiliar = auxiliar->proximo;
        }
        novo_elemento->proximo = auxiliar->proximo;
        auxiliar->proximo = novo_elemento;
      }
      lista->quantidade ++;
    }// Inserir_ListaOrdenada/

    //Imprimindo os valores que foram inserindos na lista
    void Imprimir_ListaOrdenada(ListaOrdenada *lista){
      PtrNoLista percorre;
      printf("lista = {");
      for(percorre = lista->inicio; percorre != NULL; percorre = percorre->proximo){
        printf(" %d ", percorre->chave);
      }
      printf("}\n\n");
    } //Imprimir_ListaOrdenada

    // Perquisar um elemento(valor) na lista
    bool Pesquisar_ListaOrdenada(ListaOrdenada *lista, int consulta){
      if(EstaVaia_ListaOrdenada(lista)){
        return false;
      }
      PtrNoLista auxiliar;
      auxiliar = lista->inicio;
      while (auxiliar != NULL && consulta > auxiliar->chave){
        auxiliar = auxiliar->proximo;
      }
      if(auxiliar == NULL || auxiliar->chave > consulta){
        return false;
      }
      return true;
    }//Pesquisar_ListaOrdenada

    //Remover um elemento da lista ordenada
    int Remover_ListaOrdenada(ListaOrdenada *lista, int remocao){
      int retorno = -999;
      if(EstaVaia_ListaOrdenada(lista) || remocao > lista->inicio->chave){
        return (retorno);
      }
      if(remocao = lista->inicio->chave){
        PtrNoLista auxiliar;
        auxiliar = lista->inicio;
        retorno = auxiliar->chave;
        lista->inicio = lista->inicio->proximo;
        free(auxiliar);
        lista->quantidade--;
        return(retorno);
      }
      PtrNoLista percorre;
      percorre = lista->inicio;
      while(percorre->proximo != NULL && remocao > percorre->proximo->chave){
        percorre = percorre->proximo;
      }
      if(percorre->proximo == NULL || remocao < percorre->proximo->chave){
      printf("O elemento não foi encontrado!!\n\n");
      return (retorno);
    } else {
      printf("O elemento foi removido");
      PtrNoLista auxiliar;
      auxiliar = percorre->proximo;
      retorno = auxiliar->chave;
      percorre->proximo = percorre->proximo->proximo;
      free(auxiliar);
      lista->quantidade--;
      return(retorno);
    }


    }//Remover_ListaOrdenada


  //função main
  int main(){

  //declaração de variáveis
  int tamanhoLista, removeLista;

  //declarando a estrutura da fila e chamando ela
  ListaOrdenada lista;

  //Inicializando a lista
  Iniciar_ListaOrdenada(&lista);

  //Verificando se a lista está vazia
  if(EstaVaia_ListaOrdenada(&lista)){
    printf("A lista ordenada esta' vazia!!\n\n");
  } else{
    printf("A lista contem elemento(s)!!\n\n");
  }

  //Verificando a quantidade de elementos na lista
  tamanhoLista = Tamanho_ListaOrdenada(&lista);
  printf("A lista tem %d elementos\n\n", tamanhoLista);

  //Inserindo e imprimindo elementos na lista
  Inserir_ListaOrdenada(&lista,23);
  Imprimir_ListaOrdenada(&lista);
  Inserir_ListaOrdenada(&lista,20);
  Imprimir_ListaOrdenada(&lista);
  Inserir_ListaOrdenada(&lista,21);
  Imprimir_ListaOrdenada(&lista);
  Inserir_ListaOrdenada(&lista,40);
  Imprimir_ListaOrdenada(&lista);

  //Verificando a quantidade de elementos na lista
  tamanhoLista = Tamanho_ListaOrdenada(&lista);
  printf("A lista tem %d elementos\n\n", tamanhoLista);

  //Pesquisando elemento na lista
  if(Pesquisar_ListaOrdenada(&lista,77)){
    printf("O elemento foi localizado na lista!!\n\n");
  } else {
    printf("O elemento nao foi localizado na lista!!\n\n");
  }

  //Removendo e imprimindo elementos da lista
  removeLista = Remover_ListaOrdenada(&lista,21);
  Imprimir_ListaOrdenada(&lista);
  removeLista = Remover_ListaOrdenada(&lista,40);
  Imprimir_ListaOrdenada(&lista);

  //Verificando a quantidade de elementos na lista
  tamanhoLista = Tamanho_ListaOrdenada(&lista);
  printf("A lista tem %d elementos\n\n", tamanhoLista);

  return 0;
  }//main
