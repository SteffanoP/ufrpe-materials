package trabalhandoComInterface;

public class Conta implements Pagavel {
    private String numero;
    private String descricao;
    private int quantidade;
    private double precoItem;

    public Conta(String numero, String descricao, int quantidade, double precoItem) {
        this.numero = numero;
        this.descricao = descricao;
        setQuantidade(quantidade);
        setPrecoItem(precoItem);
    }

    public double getValorPagamento() {
        return getQuantidade() * getPrecoItem();
    }

    @Override
    public String toString() {
        return "Conta{" +
                "numero='" + numero + '\'' +
                ", descricao='" + descricao + '\'' +
                ", quantidade=" + quantidade +
                ", precoItem=" + precoItem +
                '}';
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPrecoItem() {
        return precoItem;
    }

    public void setPrecoItem(double precoItem) {
        this.precoItem = precoItem;
    }
}
