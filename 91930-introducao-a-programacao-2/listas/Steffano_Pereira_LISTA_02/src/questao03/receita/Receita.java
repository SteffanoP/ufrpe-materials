package questao03.receita;

import questao03.Transacao;

import java.time.LocalDateTime;

public abstract class Receita implements Transacao {
    private LocalDateTime data;
    private String descricao;

    public Receita(LocalDateTime data,String descricao) {
        this.setData(data);
        this.setDescricao(descricao);
    }

    public String getTipo() {
        return "RECEITA";
    }

    public abstract double calcularTotal();

    @Override
    public boolean equals(Object objReceita) {
        if (this == objReceita) return true;
        if (!(objReceita instanceof Receita)) return false;
        Receita receita = (Receita) objReceita;
        return data.equals(receita.data) && descricao.equals(receita.descricao);
    }

    @Override
    public String toString() {
        return "Receita{" +
                "data=" + data +
                ", descricao='" + descricao + '\'' +
                '}';
    }

    @Override
    public LocalDateTime getData() {
        return data;
    }

    public void setData(LocalDateTime data) {
        if (data != null)
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
