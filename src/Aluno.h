#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

#include "Pessoa.h"

class Responsavel;

class Aluno : public Pessoa {
 private:
  int matricula;
  std::vector<Responsavel*> responsaveis;
  static int proximaMatricula;

 public:
  // Construtor
  Aluno(const std::string& nome);

  // Destrutor
  ~Aluno();

  // Getters
  int getMatricula() const;
  std::vector<Responsavel*> getResponsaveis() const;

  // Métodos para gerenciar responsáveis
  void adicionarResponsavel(Responsavel* responsavel);
  void removerResponsavel(Responsavel* responsavel);
  bool temResponsavel(Responsavel* responsavel) const;

  // Método para exibir informações
  void exibirInformacoes() const;
};

#endif  // ALUNO_H
