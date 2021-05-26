package classesAbstratasPagamentos;

public class EmpregadoAssalariado extends Empregado {
    private double salario;

    public EmpregadoAssalariado (String primeiroNome, String sobrenome, String cpf,double salario) {
        super(primeiroNome,sobrenome,cpf);
        this.setSalario(salario);
    }

    @Override
    public double ganhos() {
        return getSalario();
    }

    @Override
    public String toString() {
        return String.format("Empregado Assalariado: %s\n%s: R$%,.2f", super.toString(),
                                "Salário", this.getSalario());
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario < 0 ? 0 : salario;
    }
}
