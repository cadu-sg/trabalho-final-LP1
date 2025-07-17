#ifndef GERENCIADOR_RESPONSAVEIS_H
#define GERENCIADOR_RESPONSAVEIS_H

#include <map>
#include <string>
#include <vector>

#include "Responsavel.h"

class GerenciadorResponsaveis {
 private:
  std::map<int, Responsavel*> responsaveis;  // mapa de id -> responsável
  int proximoId;                            // para gerar IDs únicos

 public:
  // Construtor e Destrutor
  GerenciadorResponsaveis();
  ~GerenciadorResponsaveis();

  // CRUD
  Responsavel* criar(const std::string& nome, const std::string& contato);
  Responsavel* ler(int id);
  bool atualizar(int id, const std::string& novoNome, const std::string& novoContato);
  bool deletar(int id);
  std::vector<Responsavel*> listar() const;

  // Outros métodos úteis
  bool existe(int id) const;
  int total() const;
};

#endif  // GERENCIADOR_RESPONSAVEIS_H
