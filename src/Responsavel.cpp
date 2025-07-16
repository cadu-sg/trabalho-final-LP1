#include "Responsavel.h"

#include <algorithm>
#include <iostream>

#include "Aluno.h"

// Construtor
Responsavel::Responsavel(const std::string& nome, const std::string& contato)
    : Pessoa(nome), contato(contato) {}

// Destrutor
Responsavel::~Responsavel() {
  // Remove este responsável de todos os alunos antes de destruir
  for (auto aluno : alunos) {
    if (aluno) {
      aluno->removerResponsavel(this);
    }
  }
}

// Getters

int Responsavel::getId() const { return id; }

std::string Responsavel::getContato() const { return contato; }

std::vector<Aluno*> Responsavel::getAlunos() const { return alunos; }

// Setters

void Responsavel::setContato(const std::string& contato) {
  this->contato = contato;
}

// Métodos para gerenciar alunos

void Responsavel::adicionarAluno(Aluno* aluno) {
  if (aluno && !temAluno(aluno)) {
    alunos.push_back(aluno);
    // Adiciona este responsável ao aluno (relação bidirecional)
    if (!aluno->temResponsavel(this)) {
      aluno->adicionarResponsavel(this);
    }
  }
}

void Responsavel::removerAluno(Aluno* aluno) {
  auto it = std::find(alunos.begin(), alunos.end(), aluno);
  if (it != alunos.end()) {
    alunos.erase(it);
    // Remove este responsável do aluno (relação bidirecional)
    if (aluno && aluno->temResponsavel(this)) {
      aluno->removerResponsavel(this);
    }
  }
}

bool Responsavel::temAluno(Aluno* aluno) const {
  return std::find(alunos.begin(), alunos.end(), aluno) != alunos.end();
}

// Método para exibir informações
void Responsavel::exibirInformacoes() const {
  std::cout << "=== INFORMAÇÕES DO RESPONSÁVEL ===" << std::endl;
  std::cout << "Nome: " << getNome() << std::endl;
  std::cout << "Contato: " << contato << std::endl;
  std::cout << "Alunos:" << std::endl;

  if (alunos.empty()) {
    std::cout << "  Nenhum aluno cadastrado." << std::endl;
  } else {
    for (const auto& aluno : alunos) {
      std::cout << "  - " << aluno->getNome()
                << " (Matrícula: " << aluno->getMatricula() << ")" << std::endl;
    }
  }
  std::cout << std::endl;
}
