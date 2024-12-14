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

    printf("\n\t   ============ CASINO ============");
    printf("\n\t   Digite seu nome: ");
    scanf(" %s", nome);
    printf("\n\t   Digite o a quantia para Iniciar: ");
    scanf("%f", &*valor);

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

        printf("\nAdivinhe o numero certo que esta entre 1 a 10: ");
        scanf("%d", &chute);

        if(chute == num_random){
            printf("\nParabens voce Venceu");
            valor += 10*quant_aposta;
        }else{
            printf("\nPutzz, boa sorte na proxima vez!! O numero era %d. Voce perdeu R$ %.2f", num_random, quant_aposta);
            valor -= quant_aposta;
        }
        
        char continuar;
        printf("\nVoce deseja continuar (s/n): ");
        scanf(" %c", &continuar);

        if(continuar == 's' || continuar == 'S'){
            continue;
        }else if(continuar == 'n' || continuar == 'N'){
            printf("\nJogo Encerrado!");
            break;
        }
    }
}

int main(){
    jogo();
}