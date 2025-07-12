#include <iostream>
#include "Pessoa.h"
#include "Aluno.h"
#include "Funcionario.h"
#include "Professor.h"
#include "Diretor.h"
#include "Materia.h"
#include "Boletim.h
#include "Turma.h"

template <typename T>

int main() {
  // Definindo o encoding de saída para UTF-8 para exibir acentos corretamente
  std::cout.imbue(std::locale(""));

  // Criando instâncias das classes
  Diretor diretor("Carlos Andrade", 50, 12000.00, "Pedagógica");
  Professor prof_mat("Maria Souza", 35, 6500.00, "Matemática");
  Aluno aluno1("João Silva", 15, 202401);
  Aluno aluno2("Ana Pereira", 16, 202402);

  // Apresentando as pessoas
  std::cout << "Apresentações Iniciais:" << std::endl;
  diretor.apresentar();
  prof_mat.apresentar();
  aluno1.apresentar();
  aluno2.apresentar();
  std::cout << std::endl;

  // Criando e exibindo uma turma
  Turma turma_101("Turma 101 - Matemática", prof_mat);
  turma_101.adicionarAluno(aluno1);
  turma_101.adicionarAluno(aluno2);
  turma_101.exibirDetalhes();
  std::cout << std::endl;

  // Criando matérias
  Materia matematica("Matemática");

  // Usando a classe de template Boletim com tipo float
  std::cout << "Demonstração do Boletim com notas do tipo 'float':"
            << std::endl;
  Boletim<float> boletim_joao(aluno1, matematica);
  boletim_joao.adicionarNota(8.5f);
  boletim_joao.adicionarNota(7.0f);
  boletim_joao.adicionarNota(9.2f);
  boletim_joao.exibirBoletim();

  // Usando a classe de template Boletim com tipo int
  std::cout << "\nDemonstração do Boletim com notas do tipo 'int':"
            << std::endl;
  Boletim<int> boletim_ana(aluno2, matematica);
  boletim_ana.adicionarNota(8);
  boletim_ana.adicionarNota(9);
  boletim_ana.adicionarNota(10);
  boletim_ana.exibirBoletim();

  return 0;
}