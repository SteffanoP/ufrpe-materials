package questao04.negocio.beans;

public class AlertaPreco {
    private Usuario usuario;
    private Produto produto;
    private float precoDesejado;

    public AlertaPreco(Usuario usuario, Produto produto, float precoDesejado) {
        this.setUsuario(usuario);
        this.setProduto(produto);
        this.setPrecoDesejado(precoDesejado);
    }

    @Override
    public String toString() {
        return String.format("%s, seu alerta acabou de ser atingido e o produto tá naquele precinho que você queria. " +
                "%s está com um menor preço agora!",this.getUsuario().toString(),this.getProduto().toString());
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }

    public float getPrecoDesejado() {
        return precoDesejado;
    }

    public void setPrecoDesejado(float precoDesejado) {
        this.precoDesejado = precoDesejado;
    }
}
