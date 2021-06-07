package questao02;

import questao02.dados.RepositorioPessoas;
import questao02.model.Cliente;
import questao02.model.Funcionario;
import questao02.model.Gerente;
import questao02.model.Pessoa;

import java.time.LocalDate;
import java.util.ArrayList;

public class TesteQuestao02 {
    public static void main(String[] args) {
        RepositorioPessoas repoPessoas = new RepositorioPessoas();

        //Instanciar 5 clientes
        Pessoa jose = new Cliente("José", LocalDate.of(2000,07,21),1);
        Pessoa maria = new Cliente("Maria", LocalDate.of(1988,9,30),2);
        Pessoa fernando = new Cliente("Fernando", LocalDate.of(2000,4,03),3);
        Pessoa juliana = new Cliente("Juliana", LocalDate.of(1999,02,26),4);
        Pessoa jairson = new Cliente("Jairson", LocalDate.of(2005,5,5),5);
        //Adicionar os 5 clientes
        repoPessoas.cadastrarPessoa(jose);
        repoPessoas.cadastrarPessoa(maria);
        repoPessoas.cadastrarPessoa(fernando);
        repoPessoas.cadastrarPessoa(juliana);
        repoPessoas.cadastrarPessoa(jairson);

        //Instanciar e cadastrar um clone do cliente
        Pessoa fernando2 = new Cliente("Fernando", LocalDate.of(2000,4,03),3);
        repoPessoas.cadastrarPessoa(fernando2);

        //Instanciar 5 funcionários
        Pessoa mauricio = new Funcionario("Maurício", LocalDate.of(2000,07,21),1500);
        Pessoa fernanda = new Funcionario("Fernanda", LocalDate.of(1988,9,30),30000);
        Pessoa lucas = new Funcionario("Lucas", LocalDate.of(2000,4,03),31500);
        Pessoa ednilson = new Funcionario("Ednilson", LocalDate.of(1999,02,26),5000);
        Pessoa cleiton = new Funcionario("Cleiton", LocalDate.of(2005,5,5),10000);

        repoPessoas.cadastrarPessoa(mauricio);
        repoPessoas.cadastrarPessoa(fernanda);
        repoPessoas.cadastrarPessoa(lucas);
        repoPessoas.cadastrarPessoa(ednilson);
        repoPessoas.cadastrarPessoa(cleiton);

        //Instanciar e cadastrar um clone do funcionário
        Pessoa lucas2 = new Funcionario("Lucas", LocalDate.of(2000,4,03),31500);

        repoPessoas.cadastrarPessoa(lucas2);

        //Instanciar 5 gerentes
        Pessoa jeferson = new Gerente("Jeferson", LocalDate.of(2000,07,21),1500,"Engenharia");
        Pessoa malone = new Gerente("Malone", LocalDate.of(1988,9,30),30000,"Engenharia");
        Pessoa gustavo = new Gerente("Gustavo", LocalDate.of(2000,4,03),31500,"Saúde");
        Pessoa harry = new Gerente("Harry", LocalDate.of(1999,02,26),5000,"Computação");
        Pessoa bruno = new Gerente("Cleiton", LocalDate.of(2005,5,5),10001,"Computação");

        repoPessoas.cadastrarPessoa(jeferson);
        repoPessoas.cadastrarPessoa(malone);
        repoPessoas.cadastrarPessoa(gustavo);
        repoPessoas.cadastrarPessoa(harry);
        repoPessoas.cadastrarPessoa(bruno);

        //Instanciar e cadastrar um clone do funcionário
        Pessoa gustavo2 = new Gerente("Gustavo", LocalDate.of(2000,4,03),31500,"Saúde");

        repoPessoas.cadastrarPessoa(gustavo2);

        //Listar Pessoas maiores de Idade
        System.out.println("------------- Pessoas Maior de Idade --------------");
        ArrayList<Pessoa> pessoasMaioresIdade = repoPessoas.listarPessoasMaioresIdade();
        for (Pessoa p : pessoasMaioresIdade) {
            System.out.println(p.toString() + '\n');
        }

        //Listar Clientes maiores de Idade
        System.out.println("------------- Clientes Maior de Idade -------------");
        ArrayList<Cliente> clientesMaioresIdade = repoPessoas.listarClientesMaioresIdade();
        for (Cliente c : clientesMaioresIdade) {
            System.out.println(c.toString() + '\n');
        }

        //Listar Funcionarios com salários maior que 10000
        System.out.println("--------- Funcionários Salário Maior 10000 --------");
        ArrayList<Funcionario> funcionariosMaiorQue10000 = repoPessoas.listarFuncionariosComSalarioMaiorQue(10000);
        for (Funcionario f : funcionariosMaiorQue10000) {
            System.out.println(f.toString() + '\n');
        }

        //Listar Gerentes da área de Computação
        System.out.println("------------- Gerentes de Computação --------------");
        ArrayList<Gerente> gerentesComputacao = repoPessoas.listarGerentesDaArea("Computação");
        for (Gerente g : gerentesComputacao) {
            System.out.println(g.toString() + '\n');
        }

    }
}
