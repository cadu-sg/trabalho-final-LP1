#ifndef GERENCIADORPROFESSORES_H
#define GERENCIADORPROFESSORES_H

#include "Professor.h"
#include <map>
#include <string>

class GerenciadorProfessores {
private:
    std::map<int, Professor> professores;
public:
    // CRUD
    void criar(int id, const Professor& professor);
    Professor* ler(int id);
    bool atualizar(int id, const Professor& novoProfessor);
    bool deletar(int id);
    std::map<int, Professor> listar() const;
};

#endif // GERENCIADORPROFESSORES_H
