#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

#include "Funcionario.h"

class Professor : public Funcionario {
 private:
  std::string disciplina;

 public:
  // Construtor
  Professor(const std::string& nome, int idade, double salario,
            const std::string& disciplina);

  // Método de acesso
  std::string getDisciplina() const;

  // Sobrescrita do método apresentar
  void apresentar() const override;
};

#endif  // PROFESSOR_H
