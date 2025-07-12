#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"

class Funcionario : public Pessoa {
 private:
  double salario;

 public:
  // Construtor
  Funcionario(const std::string& nome, int idade, double salario);

  // Método de acesso
  double getSalario() const;

  // Sobrescrita do método apresentar
  void apresentar() const override;
};

#endif  // FUNCIONARIO_H
