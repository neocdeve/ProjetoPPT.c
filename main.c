#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrarEscolha(int escolha) {
    switch (escolha) {
        case 1: printf("Pedra"); break;
        case 2: printf("Papel"); break;
        case 3: printf("Tesoura"); break;
    }
}

int verificarVencedor(int jogador, int maquina) {
    if (jogador == maquina)
        return 0; //empate
    else if ((jogador == 1 && maquina == 3) ||
             (jogador == 2 && maquina == 1) ||
             (jogador == 3 && maquina == 2))
        return 1; // jogador vence
    else
        return -1; // máquina vence
}

int main() {
    int rodada, escolhaJogador, escolhaMaquina;
    int pontosJogador = 0, pontosMaquina = 0;

    srand(time(NULL));

    printf("=== Jogo: Pedra, Papel e Tesoura ===\n");

    for (rodada = 1; rodada <= 5; rodada++) {
        printf("\n--- Rodada %d ---\n", rodada);

        // Entrada do jogador
        do {
            printf("Escolha uma opção:\n");
            printf("1 - Pedra\n2 - Papel\n3 - Tesoura\nSua escolha: ");
            scanf("%d", &escolhaJogador);
        } while (escolhaJogador < 1 || escolhaJogador > 3);

        // Escolha da máquina
        escolhaMaquina = (rand() % 3) + 1;

        // Exibindo escolhas
        printf("Você escolheu: ");
        mostrarEscolha(escolhaJogador);
        printf("\nMáquina escolheu: ");
        mostrarEscolha(escolhaMaquina);
        printf("\n");

        // Verificando resultado da rodada
        int resultado = verificarVencedor(escolhaJogador, escolhaMaquina);
        if (resultado == 1) {
            printf("Você venceu esta rodada!\n");
            pontosJogador++;
        } else if (resultado == -1) {
            printf("A máquina venceu esta rodada.\n");
            pontosMaquina++;
        } else {
            printf("Empate nesta rodada.\n");
        }
    }

    // Resultado final
    printf("\n=== Resultado Final ===\n");
    printf("Você: %d ponto(s) | Máquina: %d ponto(s)\n", pontosJogador, pontosMaquina);

    if (pontosJogador > pontosMaquina) {
        printf("Parabéns! Você venceu a partida!\n");
    } else if (pontosMaquina > pontosJogador) {
        printf("A máquina venceu a partida. Tente novamente!\n");
    } else {
        printf("A partida terminou empatada!\n");
    }

    return 0;
}
