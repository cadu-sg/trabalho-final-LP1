#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include <string>

#include "GerenciadorAlunos.h"
#include "GerenciadorMaterias.h"
#include "GerenciadorProfessores.h"
#include "GerenciadorResponsaveis.h"
#include "GerenciadorTurmas.h"

using namespace std;

string vectorParaString(const vector<int>& v) {
  ostringstream oss;
  auto it = v.begin();
  if (it == v.end()) return "";
  oss << *it;
  for (it = ++it; it != v.end(); ++it) {
    oss << ", " << *it;
  }
  return oss.str();
}

int selecionarNumero(const vector<int>& opcoesValidas) {
  int escolha;
  while (true) {
    cin >> escolha;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (find(opcoesValidas.begin(), opcoesValidas.end(), escolha) != opcoesValidas.end()) {
      return escolha;
    }
    cout << "Opcao invalida. Escolha entre: " << vectorParaString(opcoesValidas) << endl;
  }
}

void menuAlunos(GerenciadorAlunos& gerAlunos) {
  while (true) {
    cout << "\n--- MENU ALUNOS ---\n"
         << "1) Cadastrar aluno\n"
         << "2) Listar alunos\n"
         << "3) Remover aluno\n"
         << "4) Voltar\n";
    int escolha = selecionarNumero({1,2,3,4});
    if (escolha == 1) {
      cout << "Nome do aluno: ";
      string nome;
      cin.ignore(); getline(cin, nome);
      Aluno* a = gerAlunos.criar(nome);
      cout << "Aluno cadastrado com matricula " << a->getMatricula() << endl;
    } else if (escolha == 2) {
      auto lista = gerAlunos.listar();
      cout << "Alunos cadastrados:\n";
      for (auto* a : lista) {
        cout << "Matricula: " << a->getMatricula() << " | Nome: " << a->getNome() << endl;
      }
    } else if (escolha == 3) {
      cout << "Matricula do aluno a remover: ";
      int mat; cin >> mat;
      if (gerAlunos.deletar(mat)) cout << "Removido!\n";
      else cout << "Matricula nao encontrada.\n";
    } else {
      break;
    }
  }
}

void menuMaterias(GerenciadorMaterias& gerMaterias) {
  while (true) {
    cout << "\n--- MENU MATERIAS ---\n"
         << "1) Cadastrar materia\n"
         << "2) Listar materias\n"
         << "3) Atualizar materia\n"
         << "4) Remover materia\n"
         << "5) Voltar\n";
    int escolha = selecionarNumero({1,2,3,4,5});
    if (escolha == 1) {
      cout << "Nome da materia: "; string nome; cin.ignore(); getline(cin, nome);
      cout << "Horarios semanais: "; string horarios; getline(cin, horarios);
      cout << "Horas totais: "; int horas; cin >> horas;
      Materia* m = gerMaterias.criar(nome, horarios, horas);
      cout << "Materia cadastrada com id " << m->getId() << "!\n";
    } else if (escolha == 2) {
      auto lista = gerMaterias.listar();
      cout << "Materias cadastradas:\n";
      for (auto* m : lista) {
        cout << "ID: " << m->getId() << " | Nome: " << m->getNome() << endl;
      }
    } else if (escolha == 3) {
      cout << "ID da materia a atualizar: "; int id; cin >> id;
      Materia* m = gerMaterias.ler(id);
      if (m) {
        cout << "Novo nome: "; string nome; cin.ignore(); getline(cin, nome);
        cout << "Novos horarios semanais: "; string horarios; getline(cin, horarios);
        cout << "Novas horas totais: "; int horas; cin >> horas;
        if (gerMaterias.atualizar(id, nome, horarios, horas))
          cout << "Materia atualizada!\n";
        else
          cout << "Falha ao atualizar.\n";
      } else {
        cout << "ID nao encontrado.\n";
      }
    } else if (escolha == 4) {
      cout << "ID da materia a remover: "; int id; cin >> id;
      if (gerMaterias.deletar(id)) cout << "Removida!\n";
      else cout << "ID nao encontrado.\n";
    } else {
      break;
    }
  }
}

void menuProfessores(GerenciadorProfessores& gerProfessores) {
  while (true) {
    cout << "\n--- MENU PROFESSORES ---\n"
         << "1) Cadastrar professor\n"
         << "2) Listar professores\n"
         << "3) Atualizar professor\n"
         << "4) Remover professor\n"
         << "5) Voltar\n";
    int escolha = selecionarNumero({1,2,3,4,5});
    if (escolha == 1) {
      cout << "Nome do professor: "; string nome; cin.ignore(); getline(cin, nome);
      cout << "Salario: "; double salario; cin >> salario;
      cout << "--- Dados da materia do professor ---\n";
      cout << "Nome da materia: "; string nomeMat; cin.ignore(); getline(cin, nomeMat);
      cout << "Horarios semanais: "; string horariosMat; getline(cin, horariosMat);
      cout << "Horas totais: "; int horasMat; cin >> horasMat;
      Materia m(nomeMat, horariosMat, horasMat);
      Professor* p = gerProfessores.criar(nome, salario, m);
      cout << "Professor cadastrado com id " << p->getId() << "!\n";
    } else if (escolha == 2) {
      auto lista = gerProfessores.listar();
      cout << "Professores cadastrados:\n";
      for (auto* p : lista) {
        cout << "ID: " << p->getId() << " | Nome: " << p->getNome() << endl;
      }
    } else if (escolha == 3) {
      cout << "ID do professor a atualizar: "; int id; cin >> id;
      Professor* p = gerProfessores.ler(id);
      if (p) {
        cout << "Novo nome: "; string nome; cin.ignore(); getline(cin, nome);
        cout << "Novo salario: "; double salario; cin >> salario;
        cout << "--- Novos dados da materia ---\n";
        cout << "Nome da materia: "; string nomeMat; cin.ignore(); getline(cin, nomeMat);
        cout << "Horarios semanais: "; string horariosMat; getline(cin, horariosMat);
        cout << "Horas totais: "; int horasMat; cin >> horasMat;
        Materia m(nomeMat, horariosMat, horasMat);
        if (gerProfessores.atualizar(id, nome, salario, m))
          cout << "Professor atualizado!\n";
        else
          cout << "Falha ao atualizar.\n";
      } else {
        cout << "ID nao encontrado.\n";
      }
    } else if (escolha == 4) {
      cout << "ID do professor a remover: "; int id; cin >> id;
      if (gerProfessores.deletar(id)) cout << "Removido!\n";
      else cout << "ID nao encontrado.\n";
    } else {
      break;
    }
  }
}

void menuResponsaveis(GerenciadorResponsaveis& gerResponsaveis) {
  while (true) {
    cout << "\n--- MENU RESPONSAVEIS ---\n"
         << "1) Cadastrar responsavel\n"
         << "2) Listar responsaveis\n"
         << "3) Remover responsavel\n"
         << "4) Voltar\n";
    int escolha = selecionarNumero({1,2,3,4});
    if (escolha == 1) {
      cout << "Nome do responsavel: "; string nome; cin.ignore(); getline(cin, nome);
      cout << "Contato: "; string contato; getline(cin, contato);
      Responsavel* r = gerResponsaveis.criar(nome, contato);
      cout << "Responsavel cadastrado com id " << r->getId() << endl;
    } else if (escolha == 2) {
      auto lista = gerResponsaveis.listar();
      cout << "Responsaveis cadastrados:\n";
      for (auto* r : lista) {
        cout << "ID: " << r->getId() << " | Nome: " << r->getNome() << " | Contato: " << r->getContato() << endl;
      }
    } else if (escolha == 3) {
      cout << "ID do responsavel a remover: "; int id; cin >> id;
      if (gerResponsaveis.deletar(id)) cout << "Removido!\n";
      else cout << "ID nao encontrado.\n";
    } else {
      break;
    }
  }
}

void menuTurmas(GerenciadorTurmas& gerTurmas) {
  while (true) {
    cout << "\n--- MENU TURMAS ---\n"
         << "1) Cadastrar turma\n"
         << "2) Listar turmas\n"
         << "3) Remover turma\n"
         << "4) Voltar\n";
    int escolha = selecionarNumero({1,2,3,4});
    if (escolha == 1) {
      cout << "Nome da turma: "; string nome; cin.ignore(); getline(cin, nome);
      int id = gerTurmas.criar(nome);
      cout << "Turma cadastrada com id " << id << endl;
    } else if (escolha == 2) {
      auto lista = gerTurmas.listar();
      cout << "Turmas cadastradas:\n";
      for (const auto& par : lista) {
        cout << "ID: " << par.first << " | Nome: " << par.second.getNome() << endl;
      }
    } else if (escolha == 3) {
      cout << "ID da turma a remover: "; int id; cin >> id;
      if (gerTurmas.deletar(id)) cout << "Removida!\n";
      else cout << "ID nao encontrado.\n";
    } else {
      break;
    }
  }
}

int main() {
  GerenciadorAlunos gerAlunos;
  GerenciadorMaterias gerMaterias;
  GerenciadorProfessores gerProfessores;
  GerenciadorResponsaveis gerResponsaveis;
  GerenciadorTurmas gerTurmas;

  while (true) {
    cout << "\n----------------------\n"
         << "SISTEMA ESCOLAR\n"
         << "----------------------\n"
         << "Digite uma opção e pressione Enter:\n"
         << "1) Gerenciar alunos\n"
         << "2) Gerenciar materias\n"
         << "3) Gerenciar professores\n"
         << "4) Gerenciar responsaveis\n"
         << "5) Gerenciar turmas\n"
         << "6) Sair\n";
    int escolha = selecionarNumero({1,2,3,4,5,6});
    if (escolha == 1) menuAlunos(gerAlunos);
    else if (escolha == 2) menuMaterias(gerMaterias);
    else if (escolha == 3) menuProfessores(gerProfessores);
    else if (escolha == 4) menuResponsaveis(gerResponsaveis);
    else if (escolha == 5) menuTurmas(gerTurmas);
    else if (escolha == 6) break;
  }
  cout << "Saindo...\n";
  return 0;
}
