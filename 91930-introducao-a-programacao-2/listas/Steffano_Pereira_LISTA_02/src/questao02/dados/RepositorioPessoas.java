package questao02.dados;

import questao02.model.Cliente;
import questao02.model.Funcionario;
import questao02.model.Gerente;
import questao02.model.Pessoa;

import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;

public class RepositorioPessoas {
    private static final int IDADE_MAIORIDADE = 18;
    private ArrayList<Pessoa> pessoas;

    public RepositorioPessoas() {
        this.pessoas = new ArrayList<>();
    }

    public RepositorioPessoas(int capacidadeInicial) {
        this.pessoas = new ArrayList<>(capacidadeInicial);
    }

    public void cadastrarPessoa(Pessoa pessoa) {
        boolean pessoaDuplicada = false;

        for (Pessoa p : pessoas) {
            if (pessoa != null) {
                if (pessoa.equals(p)) {
                    pessoaDuplicada = true;
                    break;
                }
            }
        }

        if (!pessoaDuplicada)
            this.pessoas.add(pessoa);
        else System.out.println("Pessoa já cadastrada!");
    }

    public ArrayList<Pessoa> listarPessoasMaioresIdade() {
        ArrayList<Pessoa> pessoasMaioresIdade = new ArrayList<>();

        for (Pessoa pessoa : pessoas) {
            if (verificarPessoaDeMaior(pessoa)) pessoasMaioresIdade.add(pessoa);
        }

        return pessoasMaioresIdade;
    }

    public ArrayList<Cliente> listarClientesMaioresIdade() {
        ArrayList<Cliente> clientesMaioresIdade = new ArrayList<>();

        for (Pessoa cliente : pessoas) {
            if (cliente instanceof Cliente) {
                if (verificarPessoaDeMaior(cliente)) clientesMaioresIdade.add((Cliente) cliente);
            }
        }

        return clientesMaioresIdade;
    }

    public ArrayList<Funcionario> listarFuncionariosComSalarioMaiorQue(double salario) {
        ArrayList<Funcionario> funcionariosSalarioMaior = new ArrayList<>();

        for (Pessoa funcionario : pessoas) {
            if (funcionario instanceof Funcionario) {
                if (((Funcionario) funcionario).getSalario() > salario)
                    funcionariosSalarioMaior.add((Funcionario) funcionario);
            }
        }

        return funcionariosSalarioMaior;
    }

    public ArrayList<Gerente> listarGerentesDaArea(String area) {
        ArrayList<Gerente> gerentesArea = new ArrayList<>();

        for (Pessoa gerente : pessoas) {
            if (gerente instanceof Gerente) {
                if (((Gerente) gerente).getArea().equals(area))
                    gerentesArea.add((Gerente) gerente);
            }
        }
        return gerentesArea;
    }

    private boolean verificarPessoaDeMaior(Pessoa pessoa) {
        if (pessoa == null) return false;
        Period idade = Period.between(pessoa.getDataNascimento(),LocalDate.now());

        return idade.getYears() >= IDADE_MAIORIDADE;
    }
}
