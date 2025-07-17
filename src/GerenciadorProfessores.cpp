
#include "GerenciadorProfessores.h"

#include <map>
#include <string>
#include <vector>

// Construtor
GerenciadorProfessores::GerenciadorProfessores() {}

// Destrutor
GerenciadorProfessores::~GerenciadorProfessores() {
  for (auto& par : professores) {
    delete par.second;
  }
  professores.clear();
}

Professor* GerenciadorProfessores::criar(const std::string& nome,
                                         double salario,
                                         const Materia& materia) {
  Professor* professor = new Professor(nome, salario, materia);
  professores[professor->getId()] = professor;
  return professor;
}

Professor* GerenciadorProfessores::ler(int id) {
  auto it = professores.find(id);
  return (it != professores.end()) ? it->second : nullptr;
}

bool GerenciadorProfessores::atualizar(int id, const std::string& nome,
                                       double salario, const Materia& materia) {
  Professor* professor = ler(id);
  if (!professor) return false;
  professor->setNome(nome);
  professor->setSalario(salario);
  professor->setMateria(materia);
  return true;
}

bool GerenciadorProfessores::deletar(int id) {
  auto it = professores.find(id);
  if (it != professores.end()) {
    delete it->second;
    professores.erase(it);
    return true;
  }
  return false;
}

std::vector<Professor*> GerenciadorProfessores::listar() const {
  std::vector<Professor*> listaProfessores;
  for (const auto& par : professores) {
    listaProfessores.push_back(par.second);
  }
  return listaProfessores;
}
