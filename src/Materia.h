#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia {
private:
    std::string nomeMateria;

public:
    // Construtor
    Materia(const std::string& nome);

    // Método de acesso
    std::string getNome() const;
};

#endif // MATERIA_H
