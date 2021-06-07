package questao02.model;

import java.time.LocalDate;

public class Funcionario extends Pessoa {
    private static final double SALARIO_TETO_IMPOSTO = 28559.70F;
    private double salario;

    public Funcionario(String nome, LocalDate dataNascimento, double salario) {
        super(nome, dataNascimento);
        this.setSalario(salario);
    }

    public double calcularImpostoDevido() {
        double impostoDevido = 0;

        if (this.salario <= SALARIO_TETO_IMPOSTO)
            impostoDevido = this.salario*0.05F;
        else if (this.salario > SALARIO_TETO_IMPOSTO)
            impostoDevido = this.salario*0.075D;

        return impostoDevido;
    }

    @Override
    public String toString() {
        return String.format("%s\n%s: %,.2f\n%s: %,.2f",super.toString(),
                                "Salário",this.getSalario(),
                                "Imposto devido",this.calcularImpostoDevido());
    }

    @Override
    public boolean equals(Object objFuncionario) {
        if (this == objFuncionario) return true;
        if (!(objFuncionario instanceof Funcionario)) return false;
        if (!super.equals(objFuncionario)) return false;

        return ((Funcionario) objFuncionario).getSalario() == this.salario;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }
}
