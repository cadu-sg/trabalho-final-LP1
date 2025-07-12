#ifndef BOLETIM_H
#define BOLETIM_H

#include "Aluno.h"
#include "Materia.h"
#include <vector>
#include <iostream>

template <typename T>
class Boletim {
private:
    const Aluno& aluno;
    const Materia& materia;
    std::vector<T> notas;

public:
    // Construtor
    Boletim(const Aluno& al, const Materia& mat);

    // Método para adicionar nota
    void adicionarNota(T nota);

    // Método para exibir boletim
    void exibirBoletim() const;
};

// Implementação dos métodos template no arquivo .h
template <typename T>
Boletim<T>::Boletim(const Aluno& al, const Materia& mat) : aluno(al), materia(mat) {}

template <typename T>
void Boletim<T>::adicionarNota(T nota) {
    notas.push_back(nota);
}

template <typename T>
void Boletim<T>::exibirBoletim() const {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Boletim do Aluno: " << aluno.getNome() << std::endl;
    std::cout << "Matéria: " << materia.getNome() << std::endl;
    std::cout << "Notas: ";
    for (const T& nota : notas) {
        std::cout << nota << " | ";
    }
    std::cout << "\n--------------------------------------" << std::endl;
}

#endif // BOLETIM_H
