package classesAbstratasPagamentos;

public class EmpregadoComissionadoComBase extends EmpregadoComissionado {
    private double salarioBase;

    public EmpregadoComissionadoComBase(String primeiroNome, String sobrenome,
                                            String cpf, double quantidadeVendas,
                                            double comissaoVenda, double salarioBase) {
        super(primeiroNome,sobrenome,cpf,quantidadeVendas,comissaoVenda);
        setSalarioBase(salarioBase);
    }

    @Override
    public double ganhos() {
        return (super.getComissaoVenda() * super.getQuantidadeVendas()) +
                getSalarioBase();
    }

    @Override
    public String toString() {
        return String.format("Empregado Assalariado: %s\n%s: R$%,.2f", super.toString(),
                "Salário", this.getSalario());
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }

}
