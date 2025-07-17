#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

#include "Materia.h"
#include "Pessoa.h"

class Professor : public Pessoa {
 private:
  static int proximoId;
  int id;
  double salario;
  Materia materia;

 public:
  // Construtor
  Professor(const std::string& nome, double salario, const Materia& materia);

  // Getters
  int getId() const;
  double getSalario() const;
  const Materia& getMateria() const;

  // Setters
  void setNome(const std::string& nome);
  void setSalario(double salario);
  void setMateria(const Materia& materia);
};

#endif  // PROFESSOR_H
