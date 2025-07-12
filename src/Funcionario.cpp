#include "Funcionario.h"

#include <iomanip>
#include <iostream>

// Construtor
Funcionario::Funcionario(const std::string& nome, int idade, double salario)
    : Pessoa(nome, idade), salario(salario) {}

// Método de acesso
double Funcionario::getSalario() const { return salario; }

// Sobrescrita do método apresentar
void Funcionario::apresentar() const {
  Pessoa::apresentar();
  std::cout << ", Salário: R$ " << std::fixed << std::setprecision(2)
            << salario;
}
