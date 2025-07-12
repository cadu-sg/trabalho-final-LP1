#include "Pessoa.h"
#include <iostream>

// Construtor
Pessoa::Pessoa(const std::string& nome, int idade) : nome(nome), idade(idade) {}

// Métodos de acesso (Encapsulamento)
std::string Pessoa::getNome() const {
    return nome;
}

int Pessoa::getIdade() const {
    return idade;
}

// Método virtual para ser sobrescrito
void Pessoa::apresentar() const {
    std::cout << "Nome: " << nome << ", Idade: " << idade;
}

// Destrutor virtual
Pessoa::~Pessoa() {}
