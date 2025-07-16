#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
 private:
  std::string nome;

 public:
  // Construtor
  Pessoa(const std::string& nome);

  // Destrutor virtual para garantir a limpeza correta em classes derivadas
  virtual ~Pessoa();

  // Métodos de acesso (encapsulamento)
  std::string getNome() const;
};

#endif  // PESSOA_H
