#include <iostream>
#include "mosca.h"

using namespace std;

void main() {
    Mosca moscas[10];
    Vetor deslocamento;

    for (int i = 0; i < 10; i++) {
        cin >> moscas[i];

        //colocando posições, passos e status padrões
        moscas[i].posicao.x = 0;
        moscas[i].posicao.y = 0;
        moscas[i].status = 1;
        moscas[i].contpassos = 0;
    }

    //for (int i = 0; i < 10; i++) {
   //     cout << moscas[i] << endl;
   // }

    int distanciaAlvo = 100;
    int passo = 1;
    bool zerador = true;

    srand(time(NULL)); //semente
    
    cout << "SIMULAÇÃO" << endl;
    cout << "_________" << endl;

    do{
        cout << endl << "# " << passo << ": "; 

        int numMoscasSorteadas = rand() % 10 + 1; // sortear quantidade de moscas a mover
        cout <<  numMoscasSorteadas << " ( ";
        Mosca** moscasAMover = new Mosca * [numMoscasSorteadas]; // vetor dinâmico para armazenar as moscas sorteadas
        //Mosca* moscasAMover = new Mosca[numMoscasSorteadas]; //vetor dinamico com tamanho do numero sorteado

        for (int i = 0; i < numMoscasSorteadas; i++) {
            int indiceSorteado = rand() % 10; // sortear qual mosca mover
            moscasAMover[i] = &moscas[indiceSorteado];
          
            deslocamento.magnitude = (rand() % 10) + 1;
            deslocamento.angulo = rand() % 359;

            if (FuncaoMagnitude(moscasAMover[i]->posicao) <= 100) {
                moscasAMover[i]->posicao = Deslocar(moscasAMover[i]->posicao, deslocamento);
                //moscasAMover[i]->contpassos = moscasAMover[i]->contpassos + 1;
                //cout << endl << "A";
                //cout << "Sorteada da vez foi: ";
                //cout << *moscasAMover[i];
                cout << indiceSorteado << " ";
                //cout << FuncaoMagnitude(moscasAMover[i]->posicao);
            }
            else {
                //cout << endl << "A";
                //cout << "Sorteada da vez foi: ";
                cout << "\x1b[31m" << "X " << "\033[0m";
                //cout << FuncaoMagnitude(moscasAMover[i]->posicao);
            }
        }

        //Contando um passo das moscas que não estão inativas
        for (int i = 0; i < 10; i++) {
            if (FuncaoMagnitude(moscas[i].posicao) <= 100) {
                moscas[i].contpassos = moscas[i].contpassos + 1;
            }
        }

        cout << ")";

        //Inativando Mosca e exibindo ela na tela
        for (int i = 0; i < numMoscasSorteadas; i++){
            if ((moscasAMover[i]->status == 1) && FuncaoMagnitude(moscasAMover[i]->posicao) >= 100) {
                cout << " = " << *moscasAMover[i];
                moscasAMover[i]->status = 0; //Inativando mosca
                moscasAMover[i]->contpassos = moscasAMover[i]->contpassos + 1; //como ela está sendo inativada ela não entrará no laço acima, então aqui seu ultimo passo será contado
                zerador = false;
            }
        }

        if (zerador)
            cout << " = 0 ";

        zerador = true;
        passo++;
        delete[] moscasAMover;

    } while (FuncaoInativas(moscas, 10));

    cout << endl << endl << "RESULTADOS: " << endl;
    cout << "_________________" << endl;

    int totalpassos = 0;

    //VER QUAL FOI A MOSCA MAIS RÁPIDA
    int menor = moscas[0].contpassos; //menor é a quantidade de passos do mais rapido, ou seja, do MENOR
    int indice = 0;
    for (int i = 0; i < 10; i++) {
        if (moscas[i].contpassos < menor) {
            menor = moscas[i].contpassos;
            indice = i;
        }

    }

    for (int i = 0; i < 10; i++) {
        cout << moscas[i] << " = " << moscas[i].contpassos << endl;
        totalpassos += moscas[i].contpassos;
    }
    cout << "_________________" << endl;
    cout << "Total de Passos: " << moscas[indice].cor <<  (passo-1) << "\033[0m" << endl;

    float totalizador = 0;
    for (int i = 0; i < 10; i++){
        totalizador += moscas[i].contpassos;
    }
    cout << "Em média as moscas levaram " << moscas[indice].cor << totalizador/10 << "\033[0m" << " passos" << endl;

    cout << "A mosca mais rápida foi: " << moscas[indice] << " com " << moscas[indice].cor << menor << "\033[0m" << " passos" << endl;

    float magnitudetemp = FuncaoMagnitude(moscas[indice].posicao);

    cout << "O que equivale a voar " << moscas[indice].cor << magnitudetemp/menor << " cm" << "\033[0m" << " por passos";

}