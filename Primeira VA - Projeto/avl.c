#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função auxiliar que calcula a altura de um nó
int alturaAVL(noAVL *noAVL) {
    if (noAVL == NULL) {
        return 0;
    }
    return noAVL->altura;
}

//Função que calcula o fator de balanceamento de um nó
int balanceamentoAVL(arvoreAVL noAVL) {
    if(noAVL != NULL){
        return (alturaAVL(noAVL->esquerdo) - alturaAVL(noAVL->direito));
    }else{
        return 0;
    }
}

noAVL *minimoAVL(noAVL *noAVLvonoAVL) {
    noAVL *atual = noAVLvonoAVL;

    while (atual->esquerdo != NULL) {
        atual = atual->esquerdo;
    }

    return atual;
}

//Função auxiliar que calcula o maior de dois números
int maiorAVL(int num1, int num2) {
    int maior;
    if (num1 > num2) {
        maior = num1;
    } else {
        maior = num2;
    }
}

arvoreAVL rotacaoSimplesDireitaAVL(arvoreAVL raiz) {
    noAVL *aux = raiz->esquerdo;
    noAVL *temp = aux->direito;

    aux->direito = raiz;
    raiz->esquerdo = temp;

    raiz->altura = 1 + maiorAVL(alturaAVL(raiz->esquerdo), alturaAVL(raiz->direito));
    aux->altura = 1 + maiorAVL(alturaAVL(aux->esquerdo), alturaAVL(aux->direito));

    return aux;
}

arvoreAVL rotacaoSimplesEsquerdaAVL(arvoreAVL raiz) {
    noAVL *aux = raiz->direito;
    noAVL *temp = aux->esquerdo;

    temp->esquerdo = aux;
    raiz->direito = temp;

    aux->esquerdo = raiz;
    raiz->direito = temp;

    raiz->altura = maiorAVL(alturaAVL(raiz->esquerdo), alturaAVL(raiz->direito)) + 1;
    aux->altura = maiorAVL(alturaAVL(aux->esquerdo), alturaAVL(aux->direito)) + 1;

    return aux;
}

arvoreAVL rotacaoDuplaDireitaAVL(arvoreAVL raiz){
    raiz->esquerdo = rotacaoSimplesEsquerdaAVL(raiz->esquerdo);
    return rotacaoSimplesDireitaAVL(raiz);
}

arvoreAVL rotacaoDuplaEsquerdaAVL(arvoreAVL raiz){
    raiz->direito = rotacaoSimplesDireitaAVL(raiz->direito);
    return rotacaoSimplesEsquerdaAVL(raiz);
}

arvoreAVL balancearAVL(arvoreAVL raiz) {
    int fatorBalanceamento = balanceamentoAVL(raiz);

    // Se o fator de balanceamento estiver fora do intervalo [-1, 1], a árvore precisa ser rebalanceada
    if (fatorBalanceamento > 1) {
        if (balanceamentoAVL(raiz->esquerdo) >= 0) {
            // Rotação simples direita
            return rotacaoSimplesDireitaAVL(raiz);
        } else {
            // Rotação dupla direita (esquerda-direita)
            return rotacaoDuplaDireitaAVL(raiz);
        }
    } else if (fatorBalanceamento < -1) {
        if (balanceamentoAVL(raiz->direito) <= 0) {
            // Rotação simples esquerda
            return rotacaoSimplesEsquerdaAVL(raiz);
        } else {
            // Rotação dupla esquerda (direita-esquerda)
            return rotacaoDuplaEsquerdaAVL(raiz);
        }
    }
    // Se o fator de balanceamento estiver dentro do intervalo, a árvore já está balanceada
    return raiz;
}

arvoreAVL inserirAVL(indiceAVL *valor, arvoreAVL raiz) {
    if (raiz == NULL) {
        arvoreAVL novo = (arvoreAVL)malloc(sizeof(noAVL));
        novo->dado = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
        return novo;
    }else{
        if(valor->chave > raiz->dado->chave){
           raiz->direito = inserirAVL(valor, raiz->direito);
        } 
        else{
          raiz->esquerdo = inserirAVL(valor, raiz->esquerdo);
        }
    }

    raiz->altura = maiorAVL(alturaAVL(raiz->esquerdo), alturaAVL(raiz->direito)) + 1;
    balancearAVL(raiz);

    return raiz;
}

void buscarAVL(arvoreAVL raiz, int elemento) {
    if (raiz == NULL) {
        printf("Elemento %d nao encontrado na arvore.\n", elemento);
        return;
    }

    if (raiz->chave == elemento) {
        printf("Elemento %d encontrado na arvore.\n", elemento);
        return;
    }

    if (elemento < raiz->chave) {
        buscarAVL(raiz->esquerdo, elemento);
    } else {
        buscarAVL(raiz->direito, elemento);
    }
}

arvoreAVL removerAVL(arvoreAVL raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->chave) {
        raiz->esquerdo = removerAVL(raiz->esquerdo, valor);
    }
     
    else if (valor > raiz->chave) {
        raiz->direito = removerAVL(raiz->direito, valor);
    }

    else {
        if ((raiz->esquerdo == NULL) || (raiz->direito == NULL)) {
            noAVL *temp;
            if (raiz->esquerdo != NULL) {
                temp = raiz->esquerdo;
            } else {
                temp = raiz->direito;
            }

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else { 
                *raiz = *temp;
            }
            free(temp);
        } else {
            noAVL *temp = minimoAVL(raiz->direito);

            raiz->chave = temp->chave;

            raiz->direito = removerAVL(raiz->direito, temp->chave);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura = 1 + maiorAVL(alturaAVL(raiz->esquerdo), alturaAVL(raiz->direito));
    int fatorBalanceamento = balanceamentoAVL(raiz);

    if (fatorBalanceamento > 1 && balanceamentoAVL(raiz->esquerdo) >= 0) {
        return rotacaoSimplesDireitaAVL(raiz);
    }

    if (fatorBalanceamento < -1 && balanceamentoAVL(raiz->direito) <= 0) {
        return rotacaoSimplesEsquerdaAVL(raiz);
    }

    if (fatorBalanceamento > 1 && balanceamentoAVL(raiz->esquerdo) < 0) {
        return rotacaoDuplaDireitaAVL(raiz);
    }

    if (fatorBalanceamento < -1 && balanceamentoAVL(raiz->direito) > 0) {
        return rotacaoDuplaEsquerdaAVL(raiz);
    }

    return raiz;
}

void exibirEmOrdemAVL(arvoreAVL raiz) {
    if (raiz != NULL) {
        exibirEmOrdemAVL(raiz->esquerdo);
        printf("%d ", raiz->dado);
        exibirEmOrdemAVL(raiz->direito);
    }
}