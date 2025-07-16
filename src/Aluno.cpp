#include "Aluno.h"

#include <algorithm>
#include <iostream>

#include "Responsavel.h"

// Construtor
Aluno::Aluno(const std::string& nome, int matricula)
    : Pessoa(nome), matricula(matricula) {}

// Destrutor
Aluno::~Aluno() {
  // Remove este aluno de todos os responsáveis antes de destruir
  for (auto responsavel : responsaveis) {
    if (responsavel) {
      responsavel->removerAluno(this);
    }
  }
}

// Getters

int Aluno::getMatricula() const { return matricula; }

std::vector<Responsavel*> Aluno::getResponsaveis() const {
  return responsaveis;
}

// Métodos para gerenciar responsáveis

void Aluno::adicionarResponsavel(Responsavel* responsavel) {
  if (responsavel && !temResponsavel(responsavel)) {
    responsaveis.push_back(responsavel);
    // Adiciona este aluno ao responsável (relação bidirecional)
    if (!responsavel->temAluno(this)) {
      responsavel->adicionarAluno(this);
    }
  }
}

void Aluno::removerResponsavel(Responsavel* responsavel) {
  auto it = std::find(responsaveis.begin(), responsaveis.end(), responsavel);
  if (it != responsaveis.end()) {
    responsaveis.erase(it);
    // Remove este aluno do responsável (relação bidirecional)
    if (responsavel && responsavel->temAluno(this)) {
      responsavel->removerAluno(this);
    }
  }
}

bool Aluno::temResponsavel(Responsavel* responsavel) const {
  return std::find(responsaveis.begin(), responsaveis.end(), responsavel) !=
         responsaveis.end();
}

// Método para exibir informações
void Aluno::exibirInformacoes() const {
  std::cout << "=== INFORMAÇÕES DO ALUNO ===" << std::endl;
  std::cout << "Nome: " << getNome() << std::endl;
  std::cout << "Matrícula: " << matricula << std::endl;
  std::cout << "Responsáveis:" << std::endl;

  if (responsaveis.empty()) {
    std::cout << "  Nenhum responsável cadastrado." << std::endl;
  } else {
    for (const auto& resp : responsaveis) {
      std::cout << "  - " << resp->getNome() << " (" << resp->getContato()
                << ")" << std::endl;
    }
  }
  std::cout << std::endl;
}
