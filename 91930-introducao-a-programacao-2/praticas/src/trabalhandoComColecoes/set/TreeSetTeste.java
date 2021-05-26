package trabalhandoComColecoes.set;

import java.util.Comparator;
import java.util.NavigableSet;
import java.util.TreeSet;

public class TreeSetTeste {
    public static void main(String[] args) {

        Produto produto1 = new Produto("123","Laptop Dell",2000.0D);
        Produto produto2 = new Produto("321","Picanha",51.16D);
        Produto produto3 = new Produto("481","Teclado Logitech",599.99D);
        Produto produto4 = new Produto("589","Asus Zenfone 3",1899.8D);
        Produto produto5 = new Produto("999","Asus Zenfone 8",3899.8D);
        Produto produtoDuplicado = new Produto("999","Asus Zenfone 8",3899.8D);

        NavigableSet<Produto> produtoNavigableSet = new TreeSet<>();
        produtoNavigableSet.add(produto1);
        produtoNavigableSet.add(produto2);
        produtoNavigableSet.add(produto3);
        produtoNavigableSet.add(produto4);
        produtoNavigableSet.add(produto5);
        produtoNavigableSet.add(produtoDuplicado);

        for (Produto p : produtoNavigableSet) {
            System.out.println(p);
        }

        for (Produto p : produtoNavigableSet.descendingSet()) {
            System.out.println(p);
        }

        System.out.println("-------");
        //lower <
        //floor <=
        //higher >
        //ceiling >=

        System.out.println(produtoNavigableSet.lower(produto4));
        System.out.println(produtoNavigableSet.floor(produto4));
        System.out.println(produtoNavigableSet.higher(produto4));
        System.out.println(produtoNavigableSet.ceiling(produto4));

    }

}
