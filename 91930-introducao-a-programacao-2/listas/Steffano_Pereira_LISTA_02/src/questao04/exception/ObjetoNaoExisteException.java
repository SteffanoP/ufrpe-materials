package questao04.exception;

public class ObjetoNaoExisteException extends Exception {

    private Object objeto;

    public ObjetoNaoExisteException(Object objeto) {
        super("Objeto não existe! Nada foi removido.");
        this.objeto = objeto;
    }

    @Override
    public String toString() {
        return "ObjetoNaoExisteException{" +
                "objeto=" + objeto +
                '}';
    }

    public Object getObjeto() {
        return objeto;
    }
}
