package classesAbstratasShape;

import java.util.ArrayList;

public class TesteComArrayList {
    public static void main(String[] args) {
        Shape quadrado = new Square(5);
        Shape circulo = new Circle(6);
        Shape retangulo = new Rectangle(5,6);

        ArrayList<Shape> shapes = new ArrayList<>();
        shapes.add(quadrado);
        shapes.add(circulo);
        shapes.add(retangulo);

        shapes.add(new Cube(8));

        for (Shape s : shapes) {
            System.out.println(s.calculateArea());

            if (s instanceof ThreeDimensionsShape) {
                System.out.println("Volume eh:" + ((ThreeDimensionsShape) s).calculateVolume());
            }
        }

    }
}
