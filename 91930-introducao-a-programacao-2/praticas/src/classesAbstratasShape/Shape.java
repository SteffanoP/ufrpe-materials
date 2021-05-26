package classesAbstratasShape;

public abstract class Shape {
    protected String nome;

    public Shape(String nome) {
        this.nome = nome;
    }

    public abstract double calculateArea();
}
