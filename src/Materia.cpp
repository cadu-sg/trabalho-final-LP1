#include "Materia.h"

int Materia::proximoId = 1;

Materia::Materia() : id(proximoId++), nome(""), horariosSemanais(""), horasTotais(0) {}

Materia::Materia(const std::string& nome, const std::string& horarios,
                 int horas)
    : id(proximoId++),
      nome(nome),
      horariosSemanais(horarios),
      horasTotais(horas) {}

std::string Materia::getNome() const { return nome; }

std::string Materia::getHorarios() const { return horariosSemanais; }

int Materia::getHorasTotais() const { return horasTotais; }

int Materia::getId() const { return id; }
