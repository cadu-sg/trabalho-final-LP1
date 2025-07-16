#include "Pessoa.h"

// Construtor
Pessoa::Pessoa(const std::string& nome) : nome(nome) {}

// Destrutor
Pessoa::~Pessoa() {}

// Métodos de acesso (encapsulamento)
std::string Pessoa::getNome() const { return nome; }

void Pessoa::setNome(const std::string& nome) { this->nome = nome; }
