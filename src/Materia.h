#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia {
 private:
  static int proximoId;
  int id;
  std::string nome;
  std::string horariosSemanais;
  int horasTotais;

public:
  // Construtor padrão
  Materia();
  Materia(const std::string& nome, const std::string& horarios, int horas);
  int getId() const;
  // Métodos de acesso
  std::string getNome() const;
  std::string getHorarios() const;
  int getHorasTotais() const;
};

#endif  // MATERIA_H
