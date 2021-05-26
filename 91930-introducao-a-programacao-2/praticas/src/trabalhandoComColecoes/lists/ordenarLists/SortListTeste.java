package trabalhandoComColecoes.lists.ordenarLists;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SortListTeste {
    public static void main(String[] args) {

        List<String> nomes = new ArrayList<>();
        nomes.add("Steffano");
        nomes.add("Vanilson");
        nomes.add("Leandro");
        nomes.add("Adriano");
        nomes.add(0,"Helena");

        Collections.sort(nomes);

        for (String nome : nomes) {
            System.out.println(nome);
        }

        List<Double> numeros = new ArrayList<>();
        numeros.add(5.9);
        numeros.add(8.7);
        numeros.add(8.4);
        numeros.add(8.5);
        numeros.add(10.4);

        Collections.sort(numeros);

        for (double numero : numeros) {
            System.out.println(numero);
        }
    }


}
