#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include "Cidade.h"

class Transporte {
private:
    std::string nome;
    char tipo;
    int capacidade;
    int velocidade;
    Cidade* localAtual;
public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade, Cidade* localAtual);
    std::string getNome();
    char getTipo();
    int getCapacidade();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};

#endif
