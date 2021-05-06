package trabalhandoComArrayList;

import java.util.ArrayList;

public class ArrayListSamples {
    public static void main(String[] args) {
        //ArrayLists - criação e manipulação
        ArrayList<String> nomes = new ArrayList<>();

        //Métodos de ArrayList - Adicionar
        nomes.add("Maria");
        nomes.add("Beatriz");
        nomes.add("Lima");

        String n = nomes.get(1);
        System.out.println(n);

        //Métodos de ArrayList - Remover

        if(nomes.contains("Beatriz"))
            nomes.remove("Beatriz");

        n = nomes.get(1);

        System.out.println(n);

        System.out.println(nomes.size());
        System.out.println(nomes);

        //Métodos de ArrayList - Concatenar
        ArrayList<String> nomes2 = new ArrayList<>();
        nomes2.add("João");
        nomes2.add("Carvalho");

        nomes.addAll(nomes2);

        System.out.println(nomes);

        //foreach com ArrayList
        for (int i = 0; i < nomes.size(); i++) {
            System.out.print(nomes.get(i));
            if (!(i % 2 == 0)) {
                System.out.println();
            } else {
                System.out.print(" ");
            }
        }

        System.out.println("---");

        for (String elemento : nomes) {
            System.out.println(elemento);
        }

        //Métodos de ArrayList - Wrapper
        ArrayList<Integer> numeros = new ArrayList<>();
        numeros.add(872641); //Boxing automático
        Integer outroNumero = 42;
        numeros.add(outroNumero);

        System.out.println("---");
        System.out.println(numeros);
        System.out.println("---");

    }
}
