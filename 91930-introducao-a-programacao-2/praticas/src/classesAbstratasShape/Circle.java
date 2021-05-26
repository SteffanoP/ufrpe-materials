package classesAbstratasShape;

public class Circle extends TwoDimensionsShape {

    public Circle (double raio) {
        super("Círculo");
        sideDimensions = new double[] {raio};
    }

    @Override
    public double calculateArea() {
        return Math.PI * Math.pow(sideDimensions[0],2);
    }
}
