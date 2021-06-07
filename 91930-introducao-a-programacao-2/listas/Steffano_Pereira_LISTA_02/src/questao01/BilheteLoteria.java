package questao01;

import java.util.Arrays;
import java.util.Random;

public class BilheteLoteria {
    private static final int RANDOM_LIMITE = 61;
    private int[] numeros;

    public BilheteLoteria(int quantidadeNumeros) {
        numeros = new int[quantidadeNumeros];

        Random random = new Random();
        for (int i = 0; i < quantidadeNumeros; i++) {
            int num_aleatorio;
            do {
                num_aleatorio = random.nextInt(RANDOM_LIMITE);
            } while (!(num_aleatorio > 0) || isRepeated(num_aleatorio)); //Só para ter certeza que o número 0 é anulado
            numeros[i] = num_aleatorio;
        }
        Arrays.sort(numeros);
    }

    public int qtdNumerosContidos(BilheteLoteria bilhete) {
        if (bilhete == null) return 0;
        int qtdNumeros = 0;
        int[] numerosBilhete = bilhete.getNumeros();

        for (int a : this.numeros) {
            for (int b : numerosBilhete) {
                if (a == b)
                    qtdNumeros += 1;
            }
        }

        return qtdNumeros;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();

        str.append('[');
        for (int i = 0; i < numeros.length; i++) {
            str.append(numeros[i] < 10 ? "0" : "");
            str.append(numeros[i]);
            if (!(i == numeros.length-1))
                str.append(", ");
        }
        str.append(']');
        return str.toString();
    }

    private boolean isRepeated(int numero) {
        for (int numeroSorte : numeros) {
            if (numeroSorte == numero)
                return true;
        }
        return false;
    }

    public int[] getNumeros() {
        return numeros;
    }
}

