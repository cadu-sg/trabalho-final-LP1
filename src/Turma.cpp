#include "Turma.h"

#include <iostream>

// Construtor
Turma::Turma(const std::string& nome, const Professor& prof)
    : nomeTurma(nome), professor(prof) {}

// Método para adicionar aluno
void Turma::adicionarAluno(const Aluno& aluno) { alunos.push_back(aluno); }

// Método para exibir detalhes da turma
void Turma::exibirDetalhes() const {
  std::cout << "======================================" << std::endl;
  std::cout << "Detalhes da Turma: " << nomeTurma << std::endl;
  std::cout << "Professor Responsável: " << professor.getNome() << std::endl;
  std::cout << "Alunos na Turma:" << std::endl;
  for (const auto& aluno : alunos) {
    std::cout << "- " << aluno.getNome() << std::endl;
  }
  std::cout << "======================================" << std::endl;
}
