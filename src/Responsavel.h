#ifndef RESPONSAVEL_H
#define RESPONSAVEL_H

#include <string>
#include <vector>

class Aluno;  // Forward declaration

class Responsavel : public Pessoa {
 private:
  int id;
  std::string contato;
  std::vector<Aluno*> alunos;

 public:
  // Construtor
  Responsavel(const std::string& nome, const std::string& contato);

  // Destrutor
  ~Responsavel();

  // Getters
  std::string getContato() const;
  std::vector<Aluno*> getAlunos() const;
  int getId() const;

  // Setters
  void setContato(const std::string& contato);

  // Métodos para gerenciar alunos
  void adicionarAluno(Aluno* aluno);
  void removerAluno(Aluno* aluno);
  bool temAluno(Aluno* aluno) const;

  // Método para exibir informações
  void exibirInformacoes() const;
};

#endif  // RESPONSAVEL_H
