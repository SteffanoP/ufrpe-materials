package trabalhandoComEnum.enumComoClasses.genero;

public enum Genero {
    FEMININO('F'),
    MASCULINO('m'),
    OUTRO('O');

    private char valor;

    Genero (char valor) {
        this.valor = valor;
    }
}
