#include "GerenciadorMaterias.h"

// Construtor
GerenciadorMaterias::GerenciadorMaterias() {}

// Destrutor
GerenciadorMaterias::~GerenciadorMaterias() {
  for (auto& par : materias) {
    delete par.second;
  }
  materias.clear();
}

// Create
Materia* GerenciadorMaterias::criar(const std::string& nome,
                                    const std::string& horarios, int horas) {
  Materia* materia = new Materia(nome, horarios, horas);
  materias[materia->getId()] = materia;
  return materia;
}

// Read

Materia* GerenciadorMaterias::ler(int id) {
  auto it = materias.find(id);
  if (it != materias.end()) {
    return it->second;
  }
  return nullptr;
}

std::vector<Materia*> GerenciadorMaterias::listar() const {
  std::vector<Materia*> listaMaterias;
  for (const auto& par : materias) {
    listaMaterias.push_back(par.second);
  }
  return listaMaterias;
}

// Update
bool GerenciadorMaterias::atualizar(int id, const std::string& nome,
                                    const std::string& horarios, int horas) {
  Materia* materia = ler(id);
  if (!materia) return false;
  materia->setNome(nome);
  materia->setHorariosSemanais(horarios);
  materia->setHorasTotais(horas);
  return true;
}

// Delete
bool GerenciadorMaterias::deletar(int id) { return materias.erase(id) > 0; }

int GerenciadorMaterias::total() const { return materias.size(); }
