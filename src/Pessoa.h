#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
 protected:
  std::string nome;

 public:
  // Construtor
  Pessoa(const std::string& nome);

  // Destrutor virtual para garantir a limpeza correta em classes derivadas
  virtual ~Pessoa();

  std::string getNome() const;
  void setNome(const std::string& nome);
};

#endif  // PESSOA_H
