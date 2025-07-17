#include "GerenciadorResponsaveis.h"
#include "Pessoa.h"

#include <algorithm>
#include <iostream>

// Construtor
GerenciadorResponsaveis::GerenciadorResponsaveis() : proximoId(1) {}

// Destrutor
GerenciadorResponsaveis::~GerenciadorResponsaveis() {
  // Libera a memória de todos os responsáveis
  for (auto& par : responsaveis) {
    delete par.second;
  }
  responsaveis.clear();
}

// Create
Responsavel* GerenciadorResponsaveis::criar(const std::string& nome,
                                           const std::string& contato) {
  Responsavel* novoResponsavel = new Responsavel(nome, contato);
  responsaveis[proximoId] = novoResponsavel;
  proximoId++;
  return novoResponsavel;
}

// Read
Responsavel* GerenciadorResponsaveis::ler(int id) {
  auto it = responsaveis.find(id);
  return (it != responsaveis.end()) ? it->second : nullptr;
}

std::vector<Responsavel*> GerenciadorResponsaveis::listar() const {
  std::vector<Responsavel*> listaResponsaveis;
  for (const auto& par : responsaveis) {
    listaResponsaveis.push_back(par.second);
  }
  return listaResponsaveis;
}

// Update
bool GerenciadorResponsaveis::atualizar(int id, const std::string& novoNome,
                                        const std::string& novoContato) {
  Responsavel* responsavel = ler(id);
  if (responsavel) {
    responsavel->setNome(novoNome);
    responsavel->setContato(novoContato);
    return true;
  }
  return false;
}

// Delete
bool GerenciadorResponsaveis::deletar(int id) {
  auto it = responsaveis.find(id);
  if (it != responsaveis.end()) {
    delete it->second;
    responsaveis.erase(it);
    return true;
  }
  return false;
}

// Outros métodos úteis
bool GerenciadorResponsaveis::existe(int id) const {
  return responsaveis.find(id) != responsaveis.end();
}

int GerenciadorResponsaveis::total() const {
  return responsaveis.size();
}
