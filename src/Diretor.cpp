#include "Diretor.h"
#include <iostream>

// Construtor
Diretor::Diretor(const std::string& nome, int idade, double salario, const std::string& area)
    : Funcionario(nome, idade, salario), areaGestao(area) {}

// Método de acesso
std::string Diretor::getAreaGestao() const {
    return areaGestao;
}

// Sobrescrita do método apresentar
void Diretor::apresentar() const {
    Funcionario::apresentar();
    std::cout << ", Área de Gestão: " << areaGestao << std::endl;
}
