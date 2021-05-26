package trabalhandoComColecoes.lists.manipulandoLists;

import java.util.ArrayList;
import java.util.List;

public class CelularTeste {
    public static void main(String[] args) {
        Celular celular1 = new Celular("Asus Zenfone 3","1234");
        Celular celular2 = new Celular("Asus Zenfone 3","8146");
        Celular celular3 = new Celular("Asus Zenfone 3","8476");

        List<Celular> celulares = new ArrayList<>();

        celulares.add(celular1);
        celulares.add(celular2);
        celulares.add(celular3);

        for (Celular celular : celulares) {
            System.out.println(celular);
        }
        Celular celular4 = new Celular("Asus Zenfone 3", "1234");

        System.out.println(celulares.contains(celular4));
    }
}
