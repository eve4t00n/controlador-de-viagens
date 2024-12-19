#include "ControladorDeTransito.h"

void exibirMenu() {
    std::cout << "\n===== Sistema Controlador de Viagens =====\n";
    std::cout << "1. Cadastrar Cidade\n";
    std::cout << "2. Cadastrar Trajeto\n";
    std::cout << "3. Cadastrar Transporte\n";
    std::cout << "4. Cadastrar Passageiro\n";
    std::cout << "5. Exibir Informações Cadastradas\n";
    std::cout << "6. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    ControladorDeTransito controlador;
    int opcao;

    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string nomeCidade;
                std::cout << "Digite o nome da cidade: ";
                std::cin.ignore();
                std::getline(std::cin, nomeCidade);
                controlador.cadastrarCidade(nomeCidade);
                std::cout << "Cidade cadastrada com sucesso!\n";
                break;
            }
            case 2: {
                std::string origem, destino;
                char tipo;
                int distancia;

                std::cout << "Digite o nome da cidade de origem: ";
                std::cin.ignore();
                std::getline(std::cin, origem);

                std::cout << "Digite o nome da cidade de destino: ";
                std::getline(std::cin, destino);

                std::cout << "Digite o tipo de trajeto (A para Aquático, T para Terrestre): ";
                std::cin >> tipo;

                std::cout << "Digite a distância em km: ";
                std::cin >> distancia;

                controlador.cadastrarTrajeto(origem, destino, tipo, distancia);
                std::cout << "Trajeto cadastrado com sucesso!\n";
                break;
            }
            case 3: {
                std::string nomeTransporte, localAtual;
                char tipo;
                int capacidade, velocidade;

                std::cout << "Digite o nome do transporte: ";
                std::cin.ignore();
                std::getline(std::cin, nomeTransporte);

                std::cout << "Digite o tipo do transporte (A para Aquático, T para Terrestre): ";
                std::cin >> tipo;

                std::cout << "Digite a capacidade de passageiros: ";
                std::cin >> capacidade;

                std::cout << "Digite a velocidade em km/h: ";
                std::cin >> velocidade;

                std::cout << "Digite o nome da cidade onde o transporte está atualmente: ";
                std::cin.ignore();
                std::getline(std::cin, localAtual);

                controlador.cadastrarTransporte(nomeTransporte, tipo, capacidade, velocidade, localAtual);
                std::cout << "Transporte cadastrado com sucesso!\n";
                break;
            }
            case 4: {
                std::string nomePassageiro, localAtual;

                std::cout << "Digite o nome do passageiro: ";
                std::cin.ignore();
                std::getline(std::cin, nomePassageiro);

                std::cout << "Digite o nome da cidade onde o passageiro está atualmente: ";
                std::getline(std::cin, localAtual);

                controlador.cadastrarPassageiro(nomePassageiro, localAtual);
                std::cout << "Passageiro cadastrado com sucesso!\n";
                break;
            }
            case 5:
                controlador.exibirInformacoes();
                break;
            case 6:
                std::cout << "Saindo do sistema. Até mais!\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 6);

    return 0;
}
