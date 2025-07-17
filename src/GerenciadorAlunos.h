#ifndef GERENCIADOR_ALUNOS_H
#define GERENCIADOR_ALUNOS_H

#include <map>
#include <string>
#include <vector>

#include "Aluno.h"

class GerenciadorAlunos {
 private:
  std::map<int, Aluno*> alunos;  // mapa de matrícula -> aluno

 public:
  // Construtor
  GerenciadorAlunos();
  // Destrutor
  ~GerenciadorAlunos();

  // CRUD
  Aluno* criar(const std::string& nome);
  Aluno* ler(int matricula);
  bool atualizar(int matricula, const std::string& novoNome);
  bool deletar(int matricula);
  std::vector<Aluno*> listar() const;

  // Outros métodos úteis
  bool existe(int matricula) const;
  int total() const;
};

#endif  // GERENCIADOR_ALUNOS_H
