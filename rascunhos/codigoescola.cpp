#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Para std::fixed e std::setprecision

// --- CLASSE 1: Classe Base ---
class Pessoa {
private:
    std::string nome;
    int idade;

public:
    // Construtor
    Pessoa(const std::string& nome, int idade) : nome(nome), idade(idade) {}

    // Métodos de acesso (Encapsulamento)
    std::string getNome() const {
        return nome;
    }

    int getIdade() const {
        return idade;
    }

    // Método virtual para ser sobrescrito
    virtual void apresentar() const {
        std::cout << "Nome: " << nome << ", Idade: " << idade;
    }
    
    // Destrutor virtual para garantir a limpeza correta em classes derivadas
    virtual ~Pessoa() {}
};

// --- CLASSE 2: Herança Simples ---
class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno(const std::string& nome, int idade, int matricula)
        : Pessoa(nome, idade), matricula(matricula) {}

    int getMatricula() const {
        return matricula;
    }

    void apresentar() const override {
        Pessoa::apresentar();
        std::cout << ", Matrícula: " << matricula << std::endl;
    }
};

// --- CLASSE 3: Herança Simples ---
class Funcionario : public Pessoa {
private:
    double salario;

public:
    Funcionario(const std::string& nome, int idade, double salario)
        : Pessoa(nome, idade), salario(salario) {}

    double getSalario() const {
        return salario;
    }

    void apresentar() const override {
        Pessoa::apresentar();
        std::cout << ", Salário: R$ " << std::fixed << std::setprecision(2) << salario;
    }
};

// --- CLASSE 4: Herança Multinível (Professor herda de Funcionario) ---
class Professor : public Funcionario {
private:
    std::string disciplina;

public:
    Professor(const std::string& nome, int idade, double salario, const std::string& disciplina)
        : Funcionario(nome, idade, salario), disciplina(disciplina) {}

    std::string getDisciplina() const {
        return disciplina;
    }

    void apresentar() const override {
        Funcionario::apresentar();
        std::cout << ", Disciplina: " << disciplina << std::endl;
    }
};

// --- CLASSE 5: Herança Multinível (Diretor herda de Funcionario) ---
class Diretor : public Funcionario {
private:
    std::string areaGestao;

public:
    Diretor(const std::string& nome, int idade, double salario, const std::string& area)
        : Funcionario(nome, idade, salario), areaGestao(area) {}

    std::string getAreaGestao() const {
        return areaGestao;
    }
    
    void apresentar() const override {
        Funcionario::apresentar();
        std::cout << ", Área de Gestão: " << areaGestao << std::endl;
    }
};

// --- CLASSE 6: Classe Simples ---
class Materia {
private:
    std::string nomeMateria;

public:
    Materia(const std::string& nome) : nomeMateria(nome) {}

    std::string getNome() const {
        return nomeMateria;
    }
};

// --- CLASSE 7: Classe com Template ---
template <typename T>
class Boletim {
private:
    const Aluno& aluno;
    const Materia& materia;
    std::vector<T> notas;

public:
    Boletim(const Aluno& al, const Materia& mat) : aluno(al), materia(mat) {}

    void adicionarNota(T nota) {
        notas.push_back(nota);
    }

    void exibirBoletim() const {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Boletim do Aluno: " << aluno.getNome() << std::endl;
        std::cout << "Matéria: " << materia.getNome() << std::endl;
        std::cout << "Notas: ";
        for (const T& nota : notas) {
            std::cout << nota << " | ";
        }
        std::cout << "\n--------------------------------------" << std::endl;
    }
};


// --- CLASSE 8: Classe de Agregação ---
class Turma {
private:
    std::string nomeTurma;
    Professor professor;
    std::vector<Aluno> alunos;

public:
    Turma(const std::string& nome, const Professor& prof)
        : nomeTurma(nome), professor(prof) {}

    void adicionarAluno(const Aluno& aluno) {
        alunos.push_back(aluno);
    }

    void exibirDetalhes() const {
        std::cout << "======================================" << std::endl;
        std::cout << "Detalhes da Turma: " << nomeTurma << std::endl;
        std::cout << "Professor Responsável: " << professor.getNome() << std::endl;
        std::cout << "Alunos na Turma:" << std::endl;
        for (const auto& aluno : alunos) {
            std::cout << "- " << aluno.getNome() << std::endl;
        }
        std::cout << "======================================" << std::endl;
    }
};


// --- Função Principal para Demonstrar o Uso ---
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
    std::cout << "Demonstração do Boletim com notas do tipo 'float':" << std::endl;
    Boletim<float> boletim_joao(aluno1, matematica);
    boletim_joao.adicionarNota(8.5f);
    boletim_joao.adicionarNota(7.0f);
    boletim_joao.adicionarNota(9.2f);
    boletim_joao.exibirBoletim();

    // Usando a classe de template Boletim com tipo int
    std::cout << "\nDemonstração do Boletim com notas do tipo 'int':" << std::endl;
    Boletim<int> boletim_ana(aluno2, matematica);
    boletim_ana.adicionarNota(8);
    boletim_ana.adicionarNota(9);
    boletim_ana.adicionarNota(10);
    boletim_ana.exibirBoletim();

    return 0;
}