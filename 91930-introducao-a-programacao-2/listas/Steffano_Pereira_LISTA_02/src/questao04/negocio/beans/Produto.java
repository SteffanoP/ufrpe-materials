package questao04.negocio.beans;

import java.util.Objects;

public class Produto {
    private long uid;
    private String nome;
    private String descricao;
    private CategoriaProduto categoria;

    public Produto(long uid, String nome, String descricao, CategoriaProduto categoria) {
        this.setUid(uid);
        this.setNome(nome);
        this.setDescricao(descricao);
        this.setCategoria(categoria);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Produto)) return false;
        Produto produto = (Produto) o;
        return uid == produto.uid && nome.equals(produto.nome) && descricao.equals(produto.descricao) && categoria == produto.categoria;
    }

    @Override
    public int hashCode() {
        return Objects.hash(uid, nome, descricao, categoria);
    }

    @Override
    public String toString() {
        return String.format("%s",this.getNome());
    }

    public long getUid() {
        return uid;
    }

    public void setUid(long uid) {
        this.uid = uid;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public CategoriaProduto getCategoria() {
        return categoria;
    }

    public void setCategoria(CategoriaProduto categoria) {
        this.categoria = categoria;
    }
}
