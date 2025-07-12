#include "Aluno.h"

#include <iostream>

// Construtor
Aluno::Aluno(const std::string& nome, int idade, int matricula)
    : Pessoa(nome, idade), matricula(matricula) {}

// Método de acesso
int Aluno::getMatricula() const { return matricula; }

// Sobrescrita do método apresentar
void Aluno::apresentar() const {
  Pessoa::apresentar();
  std::cout << ", Matrícula: " << matricula << std::endl;
}
