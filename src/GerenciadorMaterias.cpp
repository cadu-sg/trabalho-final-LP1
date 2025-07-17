#include "GerenciadorMaterias.h"

void GerenciadorMaterias::criar(int id, const Materia& materia) {
    materias[id] = materia;
}

Materia* GerenciadorMaterias::ler(int id) {
    auto it = materias.find(id);
    if (it != materias.end()) {
        return &it->second;
    }
    return nullptr;
}

bool GerenciadorMaterias::atualizar(int id, const Materia& novaMateria) {
    auto it = materias.find(id);
    if (it != materias.end()) {
        it->second = novaMateria;
        return true;
    }
    return false;
}

bool GerenciadorMaterias::deletar(int id) {
    return materias.erase(id) > 0;
}

std::map<int, Materia> GerenciadorMaterias::listar() const {
    return materias;
}
