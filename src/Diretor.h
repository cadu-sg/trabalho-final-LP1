#ifndef DIRETOR_H
#define DIRETOR_H

#include <string>

#include "Funcionario.h"

class Diretor : public Funcionario {
 private:
  std::string areaGestao;

 public:
  // Construtor
  Diretor(const std::string& nome, int idade, double salario,
          const std::string& area);

  // Método de acesso
  std::string getAreaGestao() const;

  // Sobrescrita do método apresentar
  void apresentar() const override;
};

#endif  // DIRETOR_H
