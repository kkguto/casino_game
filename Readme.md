# Jogo de Casino de Adivinhação de Número

## Descrição 

Esse programa é uma simulação de que jogo de aposta simples desenvolvido na linguagem C, onde o usuário deve tentar adivinhar um numero de 1 a 10. Caso acerte, ganhará 10 vezes mais do valor apostado. Se errar, perderá o valor da aposta.

## Funcionalidade

- **Inserir dados**: Usuário coloca seu nome e valor de entrada.
- **Apostar um número**: O usuário escolhe um número entre 1 e 10 para fazer sua aposta.
- **Gerar número aleatório**: O programa gera um número aleatório entre 1 e 10 usando a função rand().
- **Comparar números**: O programa verifica se o número escolhido pelo usuário é igual ao número aleatório gerado.
**Repetição do jogo**: O usuário pode decidir se deseja continuar jogando ou encerrar a sessão.
**Exibir saldo**: O programa mostra o saldo atualizado do usuário após cada rodada.

## Regras

1. O número apostado deve estar entre 1 e 10. Caso contrário, o programa solicita ao usuário que insira novamente.
2. O valor da aposta não pode ser maior que o saldo disponível do jogador.
3. O jogador começa com um saldo inicial (definido no início do programa).