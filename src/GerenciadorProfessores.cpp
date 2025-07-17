#include "GerenciadorProfessores.h"

void GerenciadorProfessores::criar(int id, const Professor& professor) {
    professores[id] = professor;
}

Professor* GerenciadorProfessores::ler(int id) {
    auto it = professores.find(id);
    if (it != professores.end()) {
        return &it->second;
    }
    return nullptr;
}

bool GerenciadorProfessores::atualizar(int id, const Professor& novoProfessor) {
    auto it = professores.find(id);
    if (it != professores.end()) {
        it->second = novoProfessor;
        return true;
    }
    return false;
}

bool GerenciadorProfessores::deletar(int id) {
    return professores.erase(id) > 0;
}

std::map<int, Professor> GerenciadorProfessores::listar() const {
    return professores;
}
