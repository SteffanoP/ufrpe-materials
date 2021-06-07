package questao03.despesa;

import java.time.LocalDateTime;

public class DespesaComAgua extends Despesa {
    private static final double TARIFA_MINIMA_COMERCIAL = 45.00D;
    private static final double TARIFA_EXCEDENTE_11_20 = 5.00D;
    private static final double TARIFA_EXCEDENTE_20 = 6.00D;

    private double totalM3;

    public DespesaComAgua(LocalDateTime data,String descricao, double totalM3) {
        super(data, descricao);
        this.setTotalM3(totalM3);
    }

    @Override
    public double calcularTotal() {
        if (totalM3 <= 10) return TARIFA_MINIMA_COMERCIAL;
        else if (totalM3 <= 20) return TARIFA_MINIMA_COMERCIAL+((totalM3-10)*TARIFA_EXCEDENTE_11_20);
        else return TARIFA_MINIMA_COMERCIAL+(TARIFA_EXCEDENTE_11_20*10)+((totalM3-20)*TARIFA_EXCEDENTE_20);
    }

    public void setTotalM3(double totalM3) {
        if (totalM3 >= 0) {
            this.totalM3 = totalM3;
        }
    }

    @Override
    public String toString() {
        return "DespesaComAgua{" +
                "totalM3=" + totalM3 +
                '}';
    }
}
