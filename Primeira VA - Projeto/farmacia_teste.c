#include <stdio.h>
#include <stdlib.h>
#include "farmacia.h"

int main(int argc, char * argv[]) {
    produto *p;
    tabela tab;
    int opcao, valor;
    inicializarTabela(&tab);

    while(1) {
        printf("----------------------\n");
        printf("        FARMACIA      \n");
        printf("----------------------\n");
        printf("----------------------\n");
        printf("1 - ADICIONAR         \n");
        printf("2 - PROCURAR          \n");
        printf("3 - REMOVER           \n");
        printf("4 - EM ORDEM          \n");
        printf("99 - SAIR             \n");
        printf("----------------------\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarProduto(&tab, ler_dados());
                break;
            case 2:
                printf("--------------------------\n");
                printf("1 - BUSCAR POR ID         \n");
                printf("2 - BUSCAR POR LOTE       \n");
                printf("3 - BUSCAR POR DOSAGEM    \n");
                printf("--------------------------\n");
                scanf("%d", &opcao);
                switch(opcao){
                    case 1:
                        printf("--------------------------\n");
                        printf("         FARMACIA         \n");
                        printf("--------------------------\n");
                        printf("\nInforme o ID que deseja buscar: ");
                        scanf("%d", &valor);
                        p = procurarMedicamentoBST(&tab, valor);
                        break;
                    case 2:
                        printf("--------------------------\n");
                        printf("         FARMACIA         \n");
                        printf("--------------------------\n");
                        printf("\nInforme o lote do medicamento que deseja buscar: ");
                        scanf("%d", &valor);
                        p = procurarMedicamentoAVL(&tab, valor);
                        break;
                    case 3:
                        printf("--------------------------\n");
                        printf("         FARMACIA         \n");
                        printf("--------------------------\n");
                        printf("\nInforme a dosagem do medicamento que deseja buscar: ");
                        scanf("%d", &valor);
                        buscarRb(valor, tab.arvoreRbIndice, &tab);
                        break;
                }
                break;
            case 3:
                printf("--------------------------\n");
                printf("         FARMACIA         \n");
                printf("--------------------------\n");
                printf("\nInforme o ID que deseja remover: ");
                scanf("%d", &valor);
                removerProduto(&tab, valor);
                break;
            case 4:
                printf("--------------------------\n");
                printf("         FARMACIA         \n");
                printf("--------------------------\n");
                printf("\nInorder da Arvore BST - (ID):\n");
                inOrderBst(tab.arvoreBstIndice, &tab);
                printf("\n");
                printf("\nInorder da Arvore AVL - (Lote):\n");
                inOrderAvl(tab.arvoreAvlIndice, &tab);
                printf("\n");
                printf("\nInorder da Arvore RB - (Dosagem):\n");
                inOrderRb(tab.arvoreRbIndice, &tab);
                printf("\n");
                break;
            case 99:
                finalizar(&tab);
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente");
        }
    }
}
