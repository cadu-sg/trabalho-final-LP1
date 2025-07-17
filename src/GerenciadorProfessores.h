#ifndef GERENCIADORPROFESSORES_H
#define GERENCIADORPROFESSORES_H

#include <map>
#include <string>
#include <vector>

#include "Professor.h"

class GerenciadorProfessores {
 private:
  std::map<int, Professor*> professores;

 public:
  GerenciadorProfessores();
  ~GerenciadorProfessores();

  // CRUD
  Professor* criar(const std::string& nome, double salario,
                   const Materia& materia);
  Professor* ler(int id);
  bool atualizar(int id, const std::string& nome, double salario,
                 const Materia& materia);
  bool deletar(int id);
  std::vector<Professor*> listar() const;
};

#endif  // GERENCIADORPROFESSORES_H
