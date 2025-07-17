
#include "Turma.h"
#include "Aluno.h"
#include "Professor.h"

int Turma::proximoId = 1;

Turma::Turma(const std::string& nome) : id(proximoId++), nome(nome) {}

int Turma::getId() const {
  return id;
}

void Turma::adicionarAluno(Aluno* aluno) { alunos.push_back(aluno); }

void Turma::adicionarProfessor(Professor* professor) {
  professores.push_back(professor);
}

std::string Turma::getNome() const { return nome; }

const std::vector<Aluno*>& Turma::getAlunos() const { return alunos; }

const std::vector<Professor*>& Turma::getProfessores() const {
  return professores;
}
