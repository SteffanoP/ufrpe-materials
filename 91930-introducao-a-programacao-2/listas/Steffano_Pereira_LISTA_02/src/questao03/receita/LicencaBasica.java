package questao03.receita;

import java.time.LocalDateTime;

public class LicencaBasica extends Receita {
    private static final double VALOR_LICENCA_BASICA = 20.00D;
    private int totalContas;

    public LicencaBasica(LocalDateTime data, String descricao, int totalContas) {
        super(data, descricao);
        this.setTotalContas(totalContas);
    }

    @Override
    public double calcularTotal() {
        return totalContas * VALOR_LICENCA_BASICA;
    }

    public void setTotalContas(int totalContas) {
        if (totalContas >= 0) {
            this.totalContas = totalContas;
        }
    }

    @Override
    public String toString() {
        return "LicencaBasica{" +
                "totalContas=" + totalContas +
                '}';
    }
}
