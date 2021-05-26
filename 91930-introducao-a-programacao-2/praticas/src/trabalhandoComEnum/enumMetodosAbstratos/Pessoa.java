package trabalhandoComEnum.enumMetodosAbstratos;

public class Pessoa {
    private TipoDocumento tipoDocumento;
    private String numDocumento;

    public Pessoa() {
    }

    public Pessoa(TipoDocumento tipoDocumento, String numDocumento) {
        this.tipoDocumento = tipoDocumento;
        this.numDocumento = numDocumento;
    }

    @Override
    public String toString() {
        return "Pessoa{" +
                "tipoDocumento=" + tipoDocumento +
                ", numDocumento='" + numDocumento + '\'' +
                '}';
    }

    public TipoDocumento getTipoDocumento() {
        return tipoDocumento;
    }

    public void setTipoDocumento(TipoDocumento tipoDocumento) {
        this.tipoDocumento = tipoDocumento;
    }

    public String getNumDocumento() {
        return numDocumento;
    }

    public void setNumDocumento(String numDocumento) {
        this.numDocumento = numDocumento;
    }
}
