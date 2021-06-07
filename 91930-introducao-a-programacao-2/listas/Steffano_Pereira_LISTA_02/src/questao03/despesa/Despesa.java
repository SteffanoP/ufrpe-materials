package questao03.despesa;

import questao03.Transacao;

import java.time.LocalDateTime;

public abstract class Despesa implements Transacao {
    private LocalDateTime data;
    private String descricao;

    public Despesa(LocalDateTime data, String descricao) {
        this.setData(data);
        this.setDescricao(descricao);
    }

    public String getTipo() {
        return "DESPESA";
    }

    public abstract double calcularTotal();

    @Override
    public boolean equals(Object objDespesa) {
        if (this == objDespesa) return true;
        if (!(objDespesa instanceof Despesa)) return false;
        Despesa despesa = (Despesa) objDespesa;
        return data.equals(despesa.data) && descricao.equals(despesa.descricao);
    }

    @Override
    public String toString() {
        return "Despesa{" +
                "data=" + data +
                ", descricao='" + descricao + '\'' +
                '}';
    }

    @Override
    public LocalDateTime getData() {
        return data;
    }

    public void setData(LocalDateTime data) {
        this.data = data;
    }

    @Override
    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        if (descricao == null) return;
        this.descricao = descricao;
    }
}
