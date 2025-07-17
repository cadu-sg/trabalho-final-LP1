#include "Materia.h"

int Materia::proximoId = 1;

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

void Materia::setNome(const std::string& nome) { this->nome = nome; }

void Materia::setHorariosSemanais(const std::string& horariosSemanais) {
  this->horariosSemanais = horariosSemanais;
}

void Materia::setHorasTotais(int horasTotais) {
  this->horasTotais = horasTotais;
}
