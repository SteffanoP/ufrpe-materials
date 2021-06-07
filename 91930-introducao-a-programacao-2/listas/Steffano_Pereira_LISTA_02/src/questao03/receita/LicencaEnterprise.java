package questao03.receita;

import java.time.LocalDateTime;

public class LicencaEnterprise extends Receita {
    private static final double VALOR_LICENCA_ENTERPRISE = 150.00D;
    private int totalContas;

    public LicencaEnterprise(LocalDateTime data, String descricao, int totalContas) {
        super(data, descricao);
        this.setTotalContas(totalContas);
    }

    @Override
    public double calcularTotal() {
        return totalContas * VALOR_LICENCA_ENTERPRISE;
    }

    public void setTotalContas(int totalContas) {
        if (totalContas >= 0) {
            this.totalContas = totalContas;
        }
    }

    @Override
    public String toString() {
        return "LicencaEnterprise{" +
                "totalContas=" + totalContas +
                '}';
    }
}
