package trabalhandoComColecoes.lists.manipulandoLists;

import trabalhandoComEnum.enumMetodosAbstratos.Pessoa;

import java.util.ArrayList;
import java.util.List;

public class TesteList {
    public static void main(String[] args) {
        //Método para adicionar diversos tipos de dados em uma lista
        //Método feio!
        List nomes = new ArrayList();
        nomes.add("Steffano");
        nomes.add("Leandro");
        nomes.add("Vanilson");
        nomes.add(new Pessoa());


        for (Object nome : nomes) {
            System.out.println(nome);
        }

        System.out.println("---------");

        //Método para adicionar um tipo de dado específico em uma lista
        //Nesse caso só aceito tipos de objetos String
        List<String> nomes2 = new ArrayList<>();

        nomes2.add("Steffano");
        nomes2.add("Leandro");
        nomes2.add("Vanilson");

        //Observe o tipo String
        for (String nome : nomes2) {
            System.out.println(nome);
        }

        nomes2.clear();
    }
}
