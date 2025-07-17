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
  // Construtor
  Materia(const std::string& nome, const std::string& horarios, int horas);

  // Getters
  int getId() const;
  std::string getNome() const;
  std::string getHorarios() const;
  int getHorasTotais() const;

  // Setters
  void setNome(const std::string& nome);
  void setHorariosSemanais(const std::string& horariosSemanais);
  void setHorasTotais(int horasTotais);
};

#endif  // MATERIA_H
