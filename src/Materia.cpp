#include "Materia.h"

Materia::Materia(const std::string& nome, const std::string& horarios,
                 int horas)
    : nome(nome), horariosSemanais(horarios), horasTotais(horas) {}

std::string Materia::getNome() const { return nome; }

std::string Materia::getHorarios() const { return horariosSemanais; }

int Materia::getHorasTotais() const { return horasTotais; }
