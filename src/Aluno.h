#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

#include "Pessoa.h"

class Responsavel;

class Aluno: public Pessoa {
 private:
  int numeroMatricula;
  std::vector<Responsavel*> responsaveis;

 public:
  // Construtor
  Aluno(const std::string& nome, int numeroMatricula);

  // Destrutor
  ~Aluno();

  // Getters
  int getNumeroMatricula() const;
  std::vector<Responsavel*> getResponsaveis() const;

  // Setters
  void setNumeroMatricula(int numeroMatricula);

  // Métodos para gerenciar responsáveis
  void adicionarResponsavel(Responsavel* responsavel);
  void removerResponsavel(Responsavel* responsavel);
  bool temResponsavel(Responsavel* responsavel) const;

  // Método para exibir informações
  void exibirInformacoes() const;
};

#endif  // ALUNO_H
