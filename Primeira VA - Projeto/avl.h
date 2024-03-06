#ifndef AVL_H
#define AVL_H
#include <stdio.h>

typedef struct indiceAVL {
    int chave;
    int indice; 
} indiceAVL;

typedef struct noAVL {
    indiceAVL *dado;
    int chave;
    int altura;
    struct noAVL *esquerdo, *direito;
} noAVL;

typedef noAVL *arvoreAVL;

void inicializarAVL(arvoreAVL *raiz);
int alturaAVL(noAVL *noAVL);
int balanceamentoAVL(arvoreAVL noAVL);
noAVL *minimoAVL(noAVL *novoNo);
int maiorAVL(int num1, int num2);
arvoreAVL rotacaoSimplesDireitaAVL(arvoreAVL raiz);
arvoreAVL rotacaoSimplesEsquerdaAVL(arvoreAVL raiz);
arvoreAVL rotacaoDuplaDireitaAVL(arvoreAVL raiz);
arvoreAVL rotacaoDuplaEsquerdaAVL(arvoreAVL raiz);
arvoreAVL balancearAVL(arvoreAVL raiz);
arvoreAVL inserirAVL(indiceAVL *valor, arvoreAVL raiz);
void buscarAVL(arvoreAVL raiz, int elemento);
arvoreAVL removerAVL(arvoreAVL raiz, int valor);
void exibirEmOrdemAVL(arvoreAVL raiz);

#endif