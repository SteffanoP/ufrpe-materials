package questao03;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Pessoa {
    //Atributos
    private String cpf;
    private String grupo;
    private LocalDate dataNascimento;
    
    //Extras
    private String nome;

    //Construtores
    public Pessoa () {

    }

    public Pessoa(String nome, String cpf, String grupo, LocalDate dataNascimento) {
    	if (nome == null || cpf == null || grupo == null) {
			System.out.println("Há campos nulos!");
		} else {			
			this.nome = nome;
			this.cpf = cpf;
			this.grupo = grupo;
			this.dataNascimento = dataNascimento;
		}
	}

	//Métodos
    public int calcularIdade() {
        int idade = 0;
        LocalDate dataHoje = LocalDate.now();
        
        idade = (int) dataNascimento.until(dataHoje, ChronoUnit.YEARS);

        return idade;
    }
    
    public boolean isValid() {
    	return !(cpf.isEmpty());
    }

    //Getters/Setters
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getGrupo() {
        return grupo;
    }

    public void setGrupo(String grupo) {
        this.grupo = grupo;
    }

    public LocalDate getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(LocalDate dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
}
