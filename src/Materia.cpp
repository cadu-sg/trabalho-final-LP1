#include "Materia.h"

// Construtor
Materia::Materia(const std::string& nome) : nomeMateria(nome) {}

// Método de acesso
std::string Materia::getNome() const {
    return nomeMateria;
}
