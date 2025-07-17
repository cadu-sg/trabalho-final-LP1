#include "GerenciadorTurmas.h"


int GerenciadorTurmas::criar(const std::string& nome) {
    Turma turma(nome);
    int id = turma.getId();
    turmas[id] = turma;
    return id;
}

Turma* GerenciadorTurmas::ler(int id) {
    auto it = turmas.find(id);
    if (it != turmas.end()) {
        return &it->second;
    }
    return nullptr;
}

bool GerenciadorTurmas::atualizar(int id, const Turma& novaTurma) {
    auto it = turmas.find(id);
    if (it != turmas.end()) {
        it->second = novaTurma;
        return true;
    }
    return false;
}

bool GerenciadorTurmas::deletar(int id) {
    return turmas.erase(id) > 0;
}

std::map<int, Turma> GerenciadorTurmas::listar() const {
    return turmas;
}
