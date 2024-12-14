#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void casino_rules(){
    printf("\n\t\t   ============ Regras do Jogo ============");
    printf("\n\t   1. Escolha um numero entre 1 a 10");
    printf("\n\t   2. Vencedor ganha 10 vezes o valor da aposta");
    printf("\n\t   3. Perdeu, entao voce perde a quantia que apostou");
}

void entrada(char *nome, float *valor){
    system("cls");
    printf("\n\t   ============ CASINO ============\n");
    printf("\t   Digite seu nome: ");
    scanf(" %s", nome);

    do {
        printf("\t   Digite a quantia para iniciar (valor positivo): ");
        scanf("%f", valor);

        if (*valor <= 0) {
            printf("\t   Por favor, insira um valor válido!\n");
        }

    } while (*valor <= 0);

}

void jogo(){
    float valor = 0;
    char nome[30];

    while (valor == 0 || valor < 0){
        entrada(nome, &valor);
    }

    srand(time(NULL));

    while(true){
        float quant_aposta;
        int num_random = 1 + rand() % 10;
        int chute;

        system("cls");
        casino_rules();
        printf("\n\nValor atual: R$ %.2f", valor);
        printf("\nOpa %s, Nos fale sua Aposta: ", nome);
        scanf("%f", &quant_aposta);
        
        if (quant_aposta > valor){
            printf("\nVocê não pode apostar mais do que possui!\n");
            continue;
        }

        printf("\nAdivinhe o numero certo que esta entre 1 a 10: ");
        scanf("%d", &chute);

        if(chute < 1 || chute > 10){
            printf("Por favor, digite um número entre 1 e 10.\n");
            continue;
        }

        if(chute == num_random){
            printf("\nParabens voce Venceu");
            valor += 10*quant_aposta;
        }else{
            printf("\nPutzz, boa sorte na proxima vez!! O numero era %d. Voce perdeu R$ %.2f", num_random, quant_aposta);
            valor -= quant_aposta;
        }

        if (valor <= 0) {
            printf("\nVocê ficou sem saldo! Jogo encerrado.\n");
            break;
        }
        
        char continuar;
        printf("\nVoce deseja continuar (s/n): ");
        scanf(" %c", &continuar);

        if(continuar == 's' || continuar == 'S'){
            continue;
        }else if(continuar == 'n' || continuar == 'N'){
            printf("\nJogo encerrado! Seu saldo final: R$ %.2f\n", valor);
            break;
        }
    }
}

int main(){
    jogo();
    return 0;
}