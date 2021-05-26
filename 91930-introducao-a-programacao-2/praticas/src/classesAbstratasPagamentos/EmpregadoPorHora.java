package classesAbstratasPagamentos;

public class EmpregadoPorHora extends Empregado {
    private double salarioHora;
    private double horasTrabalhadas;
    private double salario;

    public EmpregadoPorHora (String primeiroNome, String sobrenome, String cpf,
                                double salarioHora, double horasTrabalhadas) {
        super(primeiroNome,sobrenome,cpf);
        this.salarioHora = salarioHora;
        this.horasTrabalhadas = horasTrabalhadas;
        this.setSalario(definirGanhos(salarioHora,horasTrabalhadas));
    }

    private double definirGanhos(double salarioHora, double horasTrabalhadas) {
        double ganhos = 0;

        if (horasTrabalhadas <= 40) {
            ganhos = salarioHora * horasTrabalhadas;
        } else if (horasTrabalhadas > 40) {
            ganhos = 40 * salarioHora + (horasTrabalhadas - 40) * salarioHora * 1.5D;
        }

        return ganhos;
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
        this.salario = salario;
    }
}
