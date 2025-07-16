#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

#include "Materia.h"
#include "Pessoa.h"

class Professor : public Pessoa {
 private:
  double salario;
  Materia materia;

 public:
  // Construtor
  Professor(const std::string& nome, double salario, const Materia& materia);

  double getSalario() const;

  // Retorna uma referência constante ao objeto Matéria,
  // permitindo a leitura dos seus dados sem permitir modificação.
  const Materia& getMateria() const;
};

#endif  // PROFESSOR_H
