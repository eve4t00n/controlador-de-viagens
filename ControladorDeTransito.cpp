#include "ControladorDeTransito.h"

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    cidades.push_back(new Cidade(nome));
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia) {
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    for (auto cidade : cidades) {
        if (cidade->getNome() == nomeOrigem) origem = cidade;
        if (cidade->getNome() == nomeDestino) destino = cidade;
    }

    if (origem && destino) {
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
    } else {
        std::cout << "Erro: Cidade de origem ou destino não encontrada.\n";
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, std::string localAtual) {
    Cidade* local = nullptr;

    for (auto cidade : cidades) {
        if (cidade->getNome() == localAtual) {
            local = cidade;
            break;
        }
    }

    if (local) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, local));
    } else {
        std::cout << "Erro: Cidade para transporte não encontrada.\n";
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* local = nullptr;

    for (auto cidade : cidades) {
        if (cidade->getNome() == localAtual) {
            local = cidade;
            break;
        }
    }

    if (local) {
        passageiros.push_back(new Passageiro(nome, local));
    } else {
        std::cout << "Erro: Cidade para passageiro não encontrada.\n";
    }
}

void ControladorDeTransito::exibirInformacoes() {
    std::cout << "\n=== Informações Cadastradas ===\n";

    // Exibir cidades
    std::cout << "\nCidades:\n";
    for (Cidade* cidade : cidades) {
        std::cout << "- " << cidade->getNome() << "\n";
    }

    // Exibir trajetos
    std::cout << "\nTrajetos:\n";
    for (Trajeto* trajeto : trajetos) {
        std::cout << "- De " << trajeto->getOrigem()->getNome()
                  << " para " << trajeto->getDestino()->getNome()
                  << " (" << (trajeto->getTipo() == 'A' ? "Aquático" : "Terrestre") << ") - "
                  << trajeto->getDistancia() << " km\n";
    }

    // Exibir transportes
    std::cout << "\nTransportes:\n";
    for (Transporte* transporte : transportes) {
        std::cout << "- " << transporte->getNome()
                  << " (" << (transporte->getTipo() == 'A' ? "Aquático" : "Terrestre") << ") - Capacidade: "
                  << transporte->getCapacidade() << ", Local Atual: "
                  << transporte->getLocalAtual()->getNome() << "\n";
    }

    // Exibir passageiros
    std::cout << "\nPassageiros:\n";
    for (Passageiro* passageiro : passageiros) {
        std::cout << "- " << passageiro->getNome()
                  << " (Local Atual: " << passageiro->getLocalAtual()->getNome() << ")\n";
    }
    std::cout << "================================\n";
}
