package classesAbstratasPagamentos;

public class EmpregadoComissionado extends Empregado {
    private double quantidadeVendas;
    private double comissaoVenda;
    private double salario;

    public EmpregadoComissionado (String primeiroNome, String sobrenome, String cpf,
                                    double quantidadeVendas, double comissaoVenda) {
        super(primeiroNome,sobrenome,cpf);
        this.quantidadeVendas = quantidadeVendas;
        this.comissaoVenda = comissaoVenda;
        this.setSalario(quantidadeVendas*comissaoVenda);
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

    public double getQuantidadeVendas() {
        return quantidadeVendas;
    }

    public void setQuantidadeVendas(double quantidadeVendas) {
        this.quantidadeVendas = quantidadeVendas;
    }

    public double getComissaoVenda() {
        return comissaoVenda;
    }

    public void setComissaoVenda(double comissaoVenda) {
        this.comissaoVenda = comissaoVenda;
    }
}
