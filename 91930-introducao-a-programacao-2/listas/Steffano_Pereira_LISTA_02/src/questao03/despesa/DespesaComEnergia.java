package questao03.despesa;

import java.time.LocalDateTime;

public class DespesaComEnergia extends Despesa {
    private static final double CUSTO_VALOR_KWH = 0.50D;
    private static final double CUSTO_ADICIONAL_100KWH = 1.20D;
    private static final double CUSTO_ADICIONAL_ILUMINACAO_0_50 = 2.00D;
    private static final double CUSTO_ADICIONAL_ILUMINACAO_51_200 = 15.00D;
    private static final double CUSTO_ADICIONAL_ILUMINACAO_201 = 35.00D;

    private double kWh;

    public DespesaComEnergia(LocalDateTime data,String descricao,double kWh) {
        super(data, descricao);
        this.setkWh(kWh);
    }

    @Override
    public double calcularTotal() {
        double valorTotal = 0;

        //Valor kWh
        valorTotal += kWh * CUSTO_VALOR_KWH;

        //Adicional por 100 kWh
        //Foi usado um artifício de cast aqui, para não utilizar condição
        valorTotal += ((int) (kWh/100)) * CUSTO_ADICIONAL_100KWH;

        //Taxa de iluminação pública
        if (kWh <= 50)
            valorTotal += CUSTO_ADICIONAL_ILUMINACAO_0_50;
        else if (kWh <= 200)
            valorTotal += CUSTO_ADICIONAL_ILUMINACAO_51_200;
        else
            valorTotal += CUSTO_ADICIONAL_ILUMINACAO_201;

        return valorTotal;
    }

    public void setkWh(double kWh) {
        if (kWh >= 0) {
            this.kWh = kWh;
        }
    }

    @Override
    public String toString() {
        return "DespesaComEnergia{" +
                "kWh=" + kWh +
                '}';
    }
}
