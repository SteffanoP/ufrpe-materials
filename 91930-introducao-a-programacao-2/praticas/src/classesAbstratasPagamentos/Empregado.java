package classesAbstratasPagamentos;

public abstract class Empregado {
    protected String primeiroNome;
    protected String sobrenome;
    protected String cpf;

    public Empregado(String pNome, String sobrenome, String cpf) {
        this.primeiroNome = pNome;
        this.sobrenome = sobrenome;
        this.cpf = cpf;
    }

    public abstract double ganhos();

    @Override
    public String toString() {
        return "Empregado{" +
                "primeiroNome='" + primeiroNome + '\'' +
                ", sobrenome='" + sobrenome + '\'' +
                ", cpf='" + cpf + '\'' +
                '}';
    }
}
