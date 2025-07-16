#include "Professor.h"

Professor::Professor(const std::string& nome, double salario,
                     const Materia& materia)
    : Pessoa(nome), salario(salario), materia(materia) {}

double Professor::getSalario() const { return salario; }

const Materia& Professor::getMateria() const { return materia; }
