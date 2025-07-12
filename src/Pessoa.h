#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
private:
    std::string nome;
    int idade;

public:
    // Construtor
    Pessoa(const std::string& nome, int idade);

    // Métodos de acesso (Encapsulamento)
    std::string getNome() const;
    int getIdade() const;

    // Método virtual para ser sobrescrito
    virtual void apresentar() const;
    
    // Destrutor virtual para garantir a limpeza correta em classes derivadas
    virtual ~Pessoa();
};

#endif // PESSOA_H
