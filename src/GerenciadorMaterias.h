#ifndef GERENCIADORMATERIAS_H
#define GERENCIADORMATERIAS_H

#include "Materia.h"
#include <map>
#include <string>

class GerenciadorMaterias {
private:
    std::map<int, Materia> materias;
public:
    // CRUD
    void criar(int id, const Materia& materia);
    Materia* ler(int id);
    bool atualizar(int id, const Materia& novaMateria);
    bool deletar(int id);
    std::map<int, Materia> listar() const;
};

#endif // GERENCIADORMATERIAS_H
