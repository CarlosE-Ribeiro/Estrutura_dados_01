#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TAM 15

// Função de Conversão
/*----------------------------------------------------------------------------*/
// Função que Converte inteiro em decimal
void converte(int valor, FILE * saida){

  int resto, um = 1, zero = 0;

  resto = valor % 2;

  if(1 > valor){// Caso base
    return;
  }else{// Chamada recursiva
    if(resto == 0){
      converte(valor / 2, saida);
      fprintf(saida ,"%i", zero);
    }else{
      converte(valor / 2, saida);
      fprintf(saida ,"%i", um);
    }
  }
}
/*----------------------------------------------------------------------------*/
// Pilha Dinamica
/*----------------------------------------------------------------------------*/

typedef struct NoPilha *ptrPilha;

typedef struct NoPilha{

  int chave;
  ptrPilha proximo;

}NoPilha;

typedef struct{

  ptrPilha topo;
  int quant;

}PilhaDinamica;


// Inicia Pilha Dinâmica
void iniciaPilhaD(PilhaDinamica *p){
  p->topo = NULL;
  p->quant = 0;
}//iniciaPilhaD

// Verifica se a pilha está vazia
bool verificaVaziaPD(PilhaDinamica *p){
  return (p->topo == NULL);
}//verificaVaziaPD

// Inserção da pilha Dinâmica
void inserePilhaD(PilhaDinamica *p, int x){

  // Cria Nó
  ptrPilha no;
  no = malloc(sizeof(NoPilha));

  // O nó recebe o valor a ser inserido na chave e o proximo do nó recebe o endereço que o topo aponta
  no->chave = x;
  no->proximo = p->topo;

  // O topo aponta para o novo nó e incrementa 1 na quantidade nós
  p->topo = no;
  p->quant = p->quant + 1;

}//inserePilhaD

int quantidadePD(PilhaDinamica *p){
  return(p->quant);
}

// Remove valores da Pilha Dinâmica
int removePilhaD(PilhaDinamica *p, FILE * saida){
  int valor = -999;
  int tamanho = p->quant;

  for(int i = 0; i < tamanho; i++){
    // Condição para verificar se a pilha dinâmica está vazia
    if(!verificaVaziaPD(p)){
      ptrPilha noAux;
      noAux = p->topo;// Nó auxiliar recebe endereço de memória que o topo aponta
      valor = noAux->chave;

      if(valor == 0){
        fprintf(saida, "0");
      }// Caso o numero inteiro seja 0, então passar direto para arquivo final

      p->topo = p->topo->proximo;// O topo recebe o endereço que o próximo do nó auxiliar aponta
      p->quant--;

      free(noAux);

    }else{
      printf("Não é possivel remover mais\n\n");
    }

  // Chamar função que que converte os valores inteiro da pilha em binário
  converte(valor, saida);
  fprintf(saida, "\n");
  }
  return valor;
}//removePilhaD

// Destroi a Pilha Dinâmica
void destroiPD(PilhaDinamica *p){

  while(p->topo != NULL){
    ptrPilha noAux;

    noAux = p->topo;
    p->topo = noAux->proximo;

    free(noAux);
  }

  p->quant = 0;

}//destroiPd

/*----------------------------------------------------------------------------*/
// Pilha Estática
/*----------------------------------------------------------------------------*/

typedef struct{
  int vetor[TAM];
  int topo;
  int quantidade;
}PilhaEstatica;

/*----------------------------------------------------------------------------*/

void iniciaPilhaE(PilhaEstatica *p){
  p->topo = 0;
  p->quantidade = 0;
}
/*----------------------------------------------------------------------------*/

bool verificaVaziaPE(PilhaEstatica *p){
  return (p->topo == 0);
}
/*----------------------------------------------------------------------------*/

bool verificaCheiaPE(PilhaEstatica *p){
  return (p->topo == TAM);
}
/*----------------------------------------------------------------------------*/

int quantidadePE(PilhaEstatica *p){
  return (p->quantidade);
}
/*----------------------------------------------------------------------------*/

void inserePilhaE(PilhaEstatica *p, int x){
  if(!verificaCheiaPE(p)){
    p->vetor[p->topo] = x;
    p->topo++;
    p->quantidade++;
  }else{
    printf("Não é possivel inserir mais valores\n\n");
  }
}
/*----------------------------------------------------------------------------*/
//
void removePilhaE(PilhaEstatica *p, FILE *saida){
  int valor, tamanho;
  tamanho = p->quantidade;

  for(int i = 0; i < tamanho; i++){
    if(!verificaVaziaPE(p)){
      valor = p->vetor[p->topo-1];
      p->topo--;
      if(valor == 0){
        fprintf(saida, "0");
      }
    }else{
      printf("Não há elementos para serem removidos\n\n");
    }
    converte(valor, saida);
    fprintf(saida, "\n");
  }
}
/*----------------------------------------------------------------------------*/
// Função que lê os arquivo e converte usando uma pilha estática
void le_PilhaEstatica(FILE *entrada, FILE *saida){
  int numero, tamanho;
  char verificaFim;
  PilhaEstatica pilhaE;
  iniciaPilhaE(&pilhaE);

  while(!feof(entrada)){
    fscanf(entrada, "%i", &numero);
    inserePilhaE(&pilhaE, numero);
  }

  removePilhaE(&pilhaE, saida);
  fprintf(saida, "\n");

  fclose(entrada);
  fclose(saida);

}
/*----------------------------------------------------------------------------*/
//Função que lê os arquivos e converte usando uma pilha dinâmica
void le_PilhaDinamica(FILE *entrada, FILE *saida){

  int numero, tamanho;
  char verificaFim;
  PilhaDinamica pilhaD;

  iniciaPilhaD(&pilhaD);

  while((verificaFim = fgetc(entrada)) != EOF){

    fscanf(entrada, "%i", &numero);
    inserePilhaD(&pilhaD, numero);
  }

  removePilhaD(&pilhaD, saida);
  fprintf(saida, "\n");

  destroiPD(&pilhaD);
  fclose(entrada);
  fclose(saida);
}
/*----------------------------------------------------------------------------*/
int contaLinha(const char * argv[]){
  FILE *arquivo;
  arquivo = fopen(argv[1], "r");
  int contador = 1;
  char c;

  if(arquivo == NULL){
    printf("Erro ao abrir arquivo\n\n");
  }

  while((c = fgetc(arquivo)) != EOF){
    if(c == '\n'){
      contador++;
    }
  }

  fclose(arquivo);

  return contador;
}

int main(int argc, const char * argv[]){

  FILE * entrada, * saida;
  char c;
  int quantLinha;

  // Verifica se foram passados o número correto de parâmetros
  if(argc != 3){
    printf("Número inválido de parâmetros\n\n");
    exit(1);
  }else{// Abre os arquivos passados por parâmetro

    entrada = fopen(argv[1], "r");
    saida = fopen(argv[2], "w");

    if(entrada == NULL || saida == NULL){
     printf("Erro ao abrir arquivo!\nFechando Programa\n\n");
     exit(1);
    }
  }//else

  quantLinha = contaLinha(argv);
  printf("\n\n%i\n\n", quantLinha);

  c = fgetc(entrada);

  if(c == 'd' && quantLinha > 1){
    le_PilhaDinamica(entrada, saida);
  }else if(c == 'e' && quantLinha > 1){
    le_PilhaEstatica(entrada, saida);
  }else{
    fprintf(saida, "Arquivo Inválido!");
  }

  return 0;
}
