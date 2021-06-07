package questao04.exception;

public class ObjetoDuplicadoException extends Exception {
    private Object objeto;

    public ObjetoDuplicadoException(Object objeto) {
        super("Objeto já existe e não pôde ser cadastrado");
        this.objeto = objeto;
    }

    @Override
    public String toString() {
        return "ObjetoDuplicadoException{" +
                "objeto=" + objeto +
                '}';
    }

    public Object getObjeto() {
        return objeto;
    }
}
