package trabalhandoComColecoes.lists.ordenarLists;

import java.util.*;

class ProdutoNomeComparator implements Comparator<Produto> {
    @Override
    public int compare(Produto o1, Produto o2) {
        return o1.getNome().compareTo(o2.getNome());
    }
}

public class SortProdutoTeste {
    public static void main(String[] args) {
        List<Produto> produtos = new ArrayList<>();
        Produto[] produtosArray = new Produto[4];

        Produto produto1 = new Produto("123","Laptop Dell",2000.0D);
        Produto produto2 = new Produto("321","Picanha",51.16D);
        Produto produto3 = new Produto("481","Teclado Logitech",599.99D);
        Produto produto4 = new Produto("589","Asus Zenfone 3",1899.8D);
        produtosArray[0] = produto1;
        produtosArray[1] = produto2;
        produtosArray[2] = produto3;
        produtosArray[3] = produto4;

        produtos.add(produto1);
        produtos.add(produto2);
        produtos.add(produto3);
        produtos.add(produto4);

        Collections.sort(produtos,new ProdutoNomeComparator());
        Arrays.sort(produtosArray, new ProdutoNomeComparator());

        for (Produto produto : produtos) {
            System.out.println(produto);
        }
        System.out.println(Arrays.toString(produtosArray));
    }
}
