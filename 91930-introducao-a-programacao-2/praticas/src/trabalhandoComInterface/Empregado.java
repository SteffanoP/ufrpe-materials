package trabalhandoComInterface;

public abstract class Empregado implements Pagavel {
    protected String primeiroNome;
    protected String sobrenome;
    protected String cpf;

    public Empregado(String pNome, String sobrenome, String cpf) {
        this.primeiroNome = pNome;
        this.sobrenome = sobrenome;
        this.cpf = cpf;
    }

    @Override
    public String toString() {
        return "Empregado{" +
                "primeiroNome='" + primeiroNome + '\'' +
                ", sobrenome='" + sobrenome + '\'' +
                ", cpf='" + cpf + '\'' +
                '}';
    }
}
