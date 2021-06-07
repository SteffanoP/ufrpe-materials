package questao03.receita;

import java.time.LocalDateTime;

public class LicencaPlus extends Receita {
    private static final double VALOR_LICENCA_PLUS = 35.00D;
    private int totalContas;

    public LicencaPlus(LocalDateTime data, String descricao, int totalContas) {
        super(data, descricao);
        this.setTotalContas(totalContas);
    }

    @Override
    public double calcularTotal() {
        return totalContas * VALOR_LICENCA_PLUS;
    }

    public void setTotalContas(int totalContas) {
        if (totalContas >= 0) {
            this.totalContas = totalContas;
        }
    }

    @Override
    public String toString() {
        return "LicencaPlus{" +
                "totalContas=" + totalContas +
                '}';
    }
}
