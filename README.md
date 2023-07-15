# Simulação do Voo de Moscas

Este projeto implementa uma simulação do voo de moscas no plano cartesiano, usando conceitos de Geometria Analítica e Álgebra Linear. A ideia principal é simular o deslocamento aleatório das moscas, representado por vetores, até que elas atinjam uma distância total de 100 centímetros a partir da posição inicial (0,0).

## Funcionamento da Simulação

As moscas são identificadas por um nome e uma cor RGB, que são lidos no início do programa e armazenados em um vetor. A cada passo da simulação, é sorteado um número entre 1 e 10 para determinar quantas moscas serão movidas nesse passo. Essas moscas são escolhidas aleatoriamente e têm seu deslocamento calculado com base em vetores também gerados aleatoriamente.

A simulação continua até que todas as 10 moscas atinjam uma distância total de 100 centímetros. Quando uma mosca atinge essa marca, ela é considerada inativa e não é mais movida. A simulação é encerrada quando todas as moscas estão inativas.

## Organização do Código

O código foi organizado em bibliotecas para uma melhor modularização e reutilização de código. As principais bibliotecas são:

- `Mosca.h` e `Mosca.cpp`: Implementa as estruturas e funções relacionadas às moscas, como leitura de dados, exibição e movimentação.
- `Cor.h` e `Cor.cpp`: Implementa a estrutura de cor RGB e funções relacionadas à manipulação de cores no terminal.
- `Ponto.h` e `Ponto.cpp`: Implementa a estrutura de ponto no plano cartesiano.

## Utilização do Programa

Ao executar o programa, será solicitada a entrada dos dados das moscas, como nome e cor RGB. Esses dados são armazenados em um vetor estático. Em seguida, a simulação do voo das moscas é iniciada, exibindo os passos da simulação e o resumo final.

## Resultado da Simulação

Ao final da simulação, são exibidos os seguintes resultados (Exemplo):

Moscas | Total de Passos
------ | ---------------
Turing | 182
Lovelace | 208
Knuth | 880
Naur | 405
Thompson | 439
Neumann | 286
Ritchie | 1025
Stroustrup | 131
Kernighan | 493
Lamport | 238
- Total de passos: 1025
- Média de passos: 428.7
- Mosca mais rápida: Stroustrup com 131 passos
- Distância média por passo da mosca mais rápida: 0.763359 cm
- Total de passos: número total de passos necessários para todas as moscas alcançarem 100 centímetros de deslocamento.
- Média de passos: média do número de passos necessários por mosca para alcançar a distância alvo.
- Mosca mais rápida: nome da mosca que atingiu a distância alvo em menos passos.
- Distância média por passo da mosca mais rápida: média da distância percorrida por cada passo da mosca mais rápida.

  Além disso as cores usadas no resumo final são as cores da mosca mais rápida!

*Nota: As moscas usadas neste projeto são virtuais e não causam incômodo real.*
