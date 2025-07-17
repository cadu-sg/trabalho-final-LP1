#ifndef TURMA_H
#define TURMA_H

#include <string>
#include <vector>

class Aluno;
class Professor;

class Turma {
private:
  static int proximoId;
  int id;
  std::string nome;
  std::vector<Aluno*> alunos;
  std::vector<Professor*> professores;

public:
  // Construtor
  Turma(const std::string& nome);

  int getId() const;
  // void setId(int novoId); // Removido, id é automático

  void adicionarAluno(Aluno* aluno);
  void adicionarProfessor(Professor* professor);

  std::string getNome() const;
  const std::vector<Aluno*>& getAlunos() const;
  const std::vector<Professor*>& getProfessores() const;
};

#endif  // TURMA_H
