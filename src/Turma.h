#ifndef TURMA_H
#define TURMA_H

#include <string>
#include <vector>

#include "Aluno.h"
#include "Professor.h"

class Turma {
 private:
  std::string nomeTurma;
  Professor professor;
  std::vector<Aluno> alunos;

 public:
  // Construtor
  Turma(const std::string& nome, const Professor& prof);

  // Método para adicionar aluno
  void adicionarAluno(const Aluno& aluno);

  // Método para exibir detalhes da turma
  void exibirDetalhes() const;
};

#endif  // TURMA_H
