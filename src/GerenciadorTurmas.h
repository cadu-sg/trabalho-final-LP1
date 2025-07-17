#ifndef GERENCIADORTURMAS_H
#define GERENCIADORTURMAS_H

#include "Turma.h"
#include <map>
#include <string>

class GerenciadorTurmas {
private:
    std::map<int, Turma> turmas;
public:
    // CRUD
    int criar(const std::string& nome);
    Turma* ler(int id);
    bool atualizar(int id, const Turma& novaTurma);
    bool deletar(int id);
    std::map<int, Turma> listar() const;
};

#endif // GERENCIADORTURMAS_H
