#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

class Aluno : public Pessoa {
private:
    int matricula;

public:
    // Construtor
    Aluno(const std::string& nome, int idade, int matricula);

    // Método de acesso
    int getMatricula() const;

    // Sobrescrita do método apresentar
    void apresentar() const override;
};

#endif // ALUNO_H
