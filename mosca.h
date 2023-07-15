#pragma once
#include <iostream>

using namespace std;

struct Cor {
    int red;
    int green;
    int blue;
};

struct Ponto {
    float x;
    float y;
};

struct Vetor {
    float magnitude;
    float angulo;
};

struct Mosca {
    char nome[20];
    Ponto posicao;
    Cor cor;
    bool status;
    int contpassos;
};

//operador para ler Cor
istream& operator>>(istream& in, Cor& cor);
//operador para mostrar Cor
ostream& operator<<(ostream& out, const Cor& cor);

//operador para ler Mosca
istream& operator>>(istream& in, Mosca& mosca);
//operador para mostrar Mosca
ostream& operator<<(ostream& out, const Mosca& mosca);

Ponto Deslocar(Ponto, Vetor);
bool FuncaoInativas(Mosca[], int);
float FuncaoMagnitude(Ponto);
