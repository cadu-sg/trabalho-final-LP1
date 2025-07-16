#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia {
 private:
  std::string nome;
  std::string horariosSemanais;
  int horasTotais;

 public:
  // Construtor
  Materia(const std::string& nome, const std::string& horarios, int horas);

  // Métodos de acesso
  std::string getNome() const;
  std::string getHorarios() const;
  int getHorasTotais() const;
};

#endif  // MATERIA_H
