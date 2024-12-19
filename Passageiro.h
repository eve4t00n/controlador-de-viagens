#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Cidade.h"

class Passageiro {
private:
    std::string nome;
    Cidade* localAtual;
public:
    Passageiro(std::string nome, Cidade* localAtual);
    std::string getNome();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};

#endif
