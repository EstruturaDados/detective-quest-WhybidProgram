#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// ------------------------------------------------------------
/// STRUCT: Representa uma sala da mansão (nó da árvore binária)
/// ------------------------------------------------------------
typedef struct Sala {
    char nome[50];          // Nome do cômodo
    struct Sala *esq;       // Caminho à esquerda
    struct Sala *dir;       // Caminho à direita
} Sala;


/// ------------------------------------------------------------
/// criarSala() - cria dinamicamente uma sala da mansão
/// ------------------------------------------------------------
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}


/// ------------------------------------------------------------
/// explorarSalas() - navegação interativa pela árvore
/// O jogador escolhe ir para esquerda (e), direita (d) ou sair (s)
/// A exploração termina ao chegar em sala sem caminhos (folha)
/// ------------------------------------------------------------
void explorarSalas(Sala *atual) {

    printf("\n---- EXPLORAÇÃO INICIADA ----\n");

    while (atual != NULL) {

        printf("\nVocê está em: ** %s **\n", atual->nome);

        // Se for um nó-folha, a exploração termina
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Você chegou a um beco-sem-saída. Fim da exploração.\n");
            return;
        }

        printf("Caminhos disponíveis:\n");

        if (atual->esq != NULL) printf("  (e) Ir para esquerda → %s\n", atual->esq->nome);
        if (atual->dir != NULL) printf("  (d) Ir para direita  → %s\n", atual->dir->nome);

        printf("  (s) Sair da exploração\n");

        printf("Escolha: ");
        char opcao;
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf("Não existe caminho à esquerda!\n");
            }
        }
        else if (opcao == 'd' || opcao == 'D') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf("Não existe caminho à direita!\n");
            }
        }
        else if (opcao == 's' || opcao == 'S') {
            printf("\nVocê decidiu parar a exploração.\n");
            return;
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}


/// ------------------------------------------------------------
/// main() - Monta a árvore da mansão e inicia a exploração
/// ------------------------------------------------------------
int main() {

    //
    // ESTRUTURA DA MANSÃO (ÁRVORE BINÁRIA)
    //
    //                      Hall de Entrada
    //                    /                 \
    //            Sala de Estar           Cozinha
    //             /        \              /      \
    //       Biblioteca   Jardim     Lavanderia   Porão
    //

    Sala *hall = criarSala("Hall de Entrada");

    hall->esq = criarSala("Sala de Estar");
    hall->dir = criarSala("Cozinha");

    hall->esq->esq = criarSala("Biblioteca");
    hall->esq->dir = criarSala("Jardim");

    hall->dir->esq = criarSala("Lavanderia");
    hall->dir->dir = criarSala("Porão");

    //
    // Inicia a exploração pelo Hall
    //
    explorarSalas(hall);

    return 0;
}
