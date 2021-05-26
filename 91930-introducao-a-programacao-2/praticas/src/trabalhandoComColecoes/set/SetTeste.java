package trabalhandoComColecoes.set;

import java.util.*;

public class SetTeste {
    public static void main(String[] args) {
        Produto produto1 = new Produto("123","Laptop Dell",2000.0D);
        Produto produto2 = new Produto("321","Picanha",51.16D);
        Produto produto3 = new Produto("481","Teclado Logitech",599.99D);
        Produto produto4 = new Produto("589","Asus Zenfone 3",1899.8D);
        Produto produto5 = new Produto("999","Asus Zenfone 8",3899.8D);
        Produto produtoDuplicado = new Produto("999","Asus Zenfone 8",3899.8D);

        //Set/HashSet
        Set<Produto> produtos = new HashSet<>();
        produtos.add(produto1);
        produtos.add(produto2);
        produtos.add(produto3);
        produtos.add(produto4);
        produtos.add(produto5);
        produtos.add(produtoDuplicado);

        for (Produto p : produtos) {
            System.out.println(p);
        }

        System.out.println("----");

        //Set/LinkedHashSet
        Set<Produto> produtosLinked = new LinkedHashSet<>();
        produtosLinked.add(produto1);
        produtosLinked.add(produto2);
        produtosLinked.add(produto3);
        produtosLinked.add(produto4);
        produtosLinked.add(produto5);
        produtosLinked.add(produtoDuplicado);

        for (Produto p : produtosLinked) {
            System.out.println(p);
        }

    }
}
