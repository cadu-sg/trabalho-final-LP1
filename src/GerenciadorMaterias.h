#ifndef GERENCIADORMATERIAS_H
#define GERENCIADORMATERIAS_H

#include <map>
#include <string>
#include <vector>

#include "Materia.h"

class GerenciadorMaterias {
 private:
  std::map<int, Materia*> materias;

 public:
  // Construtor
  GerenciadorMaterias();
  // Destrutor
  ~GerenciadorMaterias();

  // CRUD
  Materia* criar(const std::string& nome, const std::string& horarios,
                 int horas);
  Materia* ler(int id);
  std::vector<Materia*> listar() const;
  bool atualizar(int id, const std::string& nome,
                                      const std::string& horarios, int horas);
  bool deletar(int id);

  int total() const;
};

#endif  // GERENCIADORMATERIAS_H
