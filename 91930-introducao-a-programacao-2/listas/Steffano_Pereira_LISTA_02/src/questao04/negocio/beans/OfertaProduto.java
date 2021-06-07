package questao04.negocio.beans;

import java.time.LocalDate;

public class OfertaProduto {
    private Produto produto;
    private float preco;
    private Loja loja;
    private LocalDate data;

    public OfertaProduto(Produto produto, float preco, Loja loja, LocalDate data) {
        this.setProduto(produto);
        this.setPreco(preco);
        this.setLoja(loja);
        this.setData(data);
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public Loja getLoja() {
        return loja;
    }

    public void setLoja(Loja loja) {
        this.loja = loja;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }
}
