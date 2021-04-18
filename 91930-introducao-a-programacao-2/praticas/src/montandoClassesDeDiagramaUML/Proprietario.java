package montandoClassesDeDiagramaUML;

public class Proprietario {
    //Atributos
    private String cpf;
    private String nome;

    //Construtor
    public Proprietario (String cpf, String nome) {
        this.cpf = cpf;
        this.nome = nome;
    }

    //Métodos Getters/Setters
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
}
