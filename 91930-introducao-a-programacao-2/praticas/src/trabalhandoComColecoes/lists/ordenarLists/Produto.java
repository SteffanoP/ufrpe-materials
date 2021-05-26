package trabalhandoComColecoes.lists.ordenarLists;

import java.util.Objects;

public class Produto implements Comparable<Produto> {
    private String serialNumber;
    private String nome;
    private double preco;

    public Produto(String serialNumber, String nome, double preco) {
        this.serialNumber = serialNumber;
        this.nome = nome;
        this.preco = preco;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Produto)) return false;
        Produto produto = (Produto) o;
        return Objects.equals(serialNumber, produto.serialNumber);
    }

    @Override
    public int hashCode() {
        return Objects.hash(serialNumber);
    }

    @Override
    public String toString() {
        return "Produto{" +
                "serialNumber='" + serialNumber + '\'' +
                ", nome='" + nome + '\'' +
                ", preco=" + preco +
                '}';
    }

    @Override
    public int compareTo(Produto outroObjeto) {
        /*return negativo se thisObject < outroObjeto
         *return 0 se thisObject == outroObjeto
         *return positivo se thisObject > outroObjeto */
        return Double.compare(this.preco,outroObjeto.getPreco());
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }
}
