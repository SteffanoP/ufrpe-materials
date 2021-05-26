package trabalhandoComEnum.enumValueOf;

public class TesteEnum {
    public static void main(String[] args) {

        System.out.println(Enum.valueOf(DiaSemana.class, "DOMINGO"));

        DiaSemana domingo = Enum.valueOf(DiaSemana.class, "DOMINGO");

        System.out.println(domingo);
    }
}
