#include "Professor.h"

int Professor::proximoId = 1;

Professor::Professor(const std::string& nome, double salario,
                     const Materia& materia)
    : Pessoa(nome), id(proximoId++), salario(salario), materia(materia) {}

double Professor::getSalario() const { return salario; }

const Materia& Professor::getMateria() const { return materia; }

int Professor::getId() const { return id; }
