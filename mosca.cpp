#include <iostream>
#include "mosca.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

//Operator (cin) que ler os valores de COR
istream& operator>>(istream& in, Cor& cor) {
    in >> cor.red >> cor.green >> cor.blue;
    return in;
}

//Operator (cout) que exibe os valores de COR
ostream& operator<<(ostream& out, const Cor& cor) {
    out << "\033[38;2;" << cor.red << ";" << cor.green << ";" << cor.blue << "m";
    return out;
}

//Operator (in) que ler os valores de Mosca, (O COR já foi impletado)
istream& operator>>(istream& in, Mosca& mosca) {
    in >> mosca.nome >> mosca.cor;
    return in;
}

//Operator (cout) que exibe os valores de Mosca, (O COR já foi impletado)
ostream& operator<<(ostream& out, const Mosca& mosca) {
    //out << mosca.cor << mosca.nome << "\033[0m" << " está em (" << mosca.posicao.x << ", " << mosca.posicao.y << ")";
    out << mosca.cor << mosca.nome << "\033[0m";
    return out;

    //depois que eu imprimo o nome eu coloco o terminal de volta a cor padrão utilizando o [0m
}


float FuncaoMagnitude(Ponto ponto) {
    return sqrt(pow(ponto.x, 2)) + sqrt(pow(ponto.y, 2));
}


Ponto Deslocar(Ponto posAtual, Vetor v) {
    // Calcula a nova posição somando as coordenadas da posição atual com as do vetor de deslocamento
    Ponto novaPos;

    // Calcula as coordenadas cartesianas do vetor de deslocamento
    float dx = v.magnitude * cos(v.angulo * 3.14 / 180);
    float dy = v.magnitude * sin(v.angulo * 3.14 / 180);
    //double dx = vetor.magnitude * cos(para_radianos(vetor.angulo));
    //double dy = vetor.magnitude * sin(para_radianos(vetor.angulo));

    //dx = m * cos(theta);
    //dy = m * sin(theta);

    novaPos.x = posAtual.x + dx;
    novaPos.y = posAtual.y + dy;

    return novaPos;
}

bool FuncaoInativas(Mosca moscas[], int tamanho) {
    int ativas = 10; //pressupomos que todas estão ativas e vamos verificar no laço
    for (int i = 0; i < tamanho; i++)
    {
        if (FuncaoMagnitude(moscas[i].posicao) >= 100) { //se a magnitude delas for igual ou maior que 100 elas ultrapassaram o limite
            ativas--;
        }
    }
    return ativas; //retornara verdadeiro quando for 0
}