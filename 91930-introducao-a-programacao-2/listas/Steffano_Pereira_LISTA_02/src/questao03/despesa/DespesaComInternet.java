package questao03.despesa;

import java.time.LocalDateTime;

public class DespesaComInternet extends Despesa {
    private static final double TARIFA_CONSUMO_20 = 90.90D;
    private static final double TARIFA_CONSUMO_100 = 240.90D;
    private static final double TARIFA_CONSUMO_500 = 590.90D;
    private static final double TARIFA_EXCEDENTE_20 = 3.90D;
    private static final double TARIFA_EXCEDENTE_100 = 4.40D;
    private static final double TARIFA_EXCEDENTE_500 = 5.10D;

    private double dadosTrafegados;

    public DespesaComInternet(LocalDateTime data, String descricao, double dadosTrafegados) {
        super(data, descricao);
        this.setDadosTrafegados(dadosTrafegados);
    }

    @Override
    public double calcularTotal() {
        if (dadosTrafegados >= 500)
            return TARIFA_CONSUMO_500 + ((dadosTrafegados-500) * TARIFA_EXCEDENTE_500);
        else if (dadosTrafegados >= 100)
            return TARIFA_CONSUMO_100 + ((dadosTrafegados-100) * TARIFA_EXCEDENTE_100);
        else if (dadosTrafegados >= 20)
            return TARIFA_CONSUMO_20 + ((dadosTrafegados-20) * TARIFA_EXCEDENTE_20);
        else //NÃO EXISTE UMA CONDIÇÃO PADRÃO PARA O CONSUMO ABAIXO DE 20 GB!
            return TARIFA_CONSUMO_20; //APLIQUEI A TARIFA BÁSICA PARA NÃO FICAR ZERADO
    }

    public void setDadosTrafegados(double dadosTrafegados) {
        if (dadosTrafegados >= 0) {
            this.dadosTrafegados = dadosTrafegados;
        }
    }

    @Override
    public String toString() {
        return "DespesaComInternet{" +
                "dadosTrafegados=" + dadosTrafegados +
                '}';
    }
}
