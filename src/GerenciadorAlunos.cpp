#include "GerenciadorAlunos.h"

#include <algorithm>
#include <iostream>

// Construtor
GerenciadorAlunos::GerenciadorAlunos() {}

// Destrutor
GerenciadorAlunos::~GerenciadorAlunos() {
  // Libera a memória de todos os alunos
  for (auto& par : alunos) {
    delete par.second;
  }
  alunos.clear();
}

// Create
Aluno* GerenciadorAlunos::criar(const std::string& nome) {
  Aluno* novoAluno = new Aluno(nome);
  alunos[novoAluno->getMatricula()] = novoAluno;
  return novoAluno;
}

// Read
Aluno* GerenciadorAlunos::ler(int matricula) {
  auto it = alunos.find(matricula);
  return (it != alunos.end()) ? it->second : nullptr;
}

std::vector<Aluno*> GerenciadorAlunos::listar() const {
  std::vector<Aluno*> listaAlunos;
  for (const auto& par : alunos) {
    listaAlunos.push_back(par.second);
  }
  return listaAlunos;
}

// Update
bool GerenciadorAlunos::atualizar(int matricula, const std::string& novoNome) {
  Aluno* aluno = ler(matricula);
  if (aluno) {
    aluno->setNome(novoNome);
    return true;
  }
  return false;
}

// Delete
bool GerenciadorAlunos::deletar(int matricula) {
  return alunos.erase(matricula) > 0;
}

// Outros métodos úteis
bool GerenciadorAlunos::existe(int matricula) const {
  return alunos.find(matricula) != alunos.end();
}

int GerenciadorAlunos::total() const { return alunos.size(); }
