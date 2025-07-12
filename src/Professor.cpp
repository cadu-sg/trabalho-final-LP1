#include "Professor.h"

#include <iostream>

// Construtor
Professor::Professor(const std::string& nome, int idade, double salario,
                     const std::string& disciplina)
    : Funcionario(nome, idade, salario), disciplina(disciplina) {}

// Método de acesso
std::string Professor::getDisciplina() const { return disciplina; }

// Sobrescrita do método apresentar
void Professor::apresentar() const {
  Funcionario::apresentar();
  std::cout << ", Disciplina: " << disciplina << std::endl;
}
