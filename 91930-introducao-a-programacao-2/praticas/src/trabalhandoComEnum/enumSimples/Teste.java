package trabalhandoComEnum.enumSimples;

import trabalhandoComEnum.enumSimples.usoDeConstantes.DiaSemanaConstantes;
import trabalhandoComEnum.enumSimples.usoDeEnum.DiaSemana;

public class Teste {
    public static void main(String[] args) {
        usandoConstantes();

        System.out.println("---");

        usandoEnum();
    }

    private static void usandoConstantes() {
        int domingo = DiaSemanaConstantes.DOMINGO;
        int segunda = DiaSemanaConstantes.SEGUNDA;
        int terca = DiaSemanaConstantes.TERCA;
        int quarta = DiaSemanaConstantes.QUARTA;
        int quinta = DiaSemanaConstantes.QUINTA;
        int sexta = DiaSemanaConstantes.SEXTA;
        int sabado = DiaSemanaConstantes.SABADO;

        System.out.println("Teste utilizando constantes no Java");
        imprimeDiaSemana(domingo);
        imprimeDiaSemana(segunda);
        imprimeDiaSemana(terca);
        imprimeDiaSemana(quarta);
        imprimeDiaSemana(quinta);
        imprimeDiaSemana(sexta);
        imprimeDiaSemana(sabado);
    }

    private static void imprimeDiaSemana(int dia) {
        switch (dia) {
            case 1:
                System.out.println("Domingo");
                break;
            case 2:
                System.out.println("Segunda-Feira");
                break;
            case 3:
                System.out.println("Terça-Feira");
                break;
            case 4:
                System.out.println("Quarta-Feira");
                break;
            case 5:
                System.out.println("Quinta-Feira");
                break;
            case 6:
                System.out.println("Sexta-Feira");
                break;
            case 7:
                System.out.println("Sábado");
                break;
        }
    }

    private static void usandoEnum() {
        DiaSemana segunda = DiaSemana.SEGUNDA;
        DiaSemana terca = DiaSemana.TERCA;
        DiaSemana quarta = DiaSemana.QUARTA;
        DiaSemana quinta = DiaSemana.QUINTA;
        DiaSemana sexta = DiaSemana.SEXTA;
        DiaSemana sabado = DiaSemana.SABADO;

        System.out.println("Teste utilizando Classe Enum no Java");
        imprimeDiaSemanaEnum(DiaSemana.DOMINGO);
        imprimeDiaSemanaEnum(segunda);
        imprimeDiaSemanaEnum(terca);
        imprimeDiaSemanaEnum(quarta);
        imprimeDiaSemanaEnum(quinta);
        imprimeDiaSemanaEnum(sexta);
        imprimeDiaSemanaEnum(sabado);
    }

    private static void imprimeDiaSemanaEnum(DiaSemana diaSemana) {
        switch (diaSemana) {
            case DOMINGO:
                System.out.println("Domingo");
                break;
            case SEGUNDA:
                System.out.println("Segunda-Feira");
                break;
            case TERCA:
                System.out.println("Terça-Feira");
                break;
            case QUARTA:
                System.out.println("Quarta-Feira");
                break;
            case QUINTA:
                System.out.println("Quinta-Feira");
                break;
            case SEXTA:
                System.out.println("Sexta-Feira");
                break;
            case SABADO:
                System.out.println("Sábado");
                break;
        }
    }

}
