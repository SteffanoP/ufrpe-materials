package trabalhandoComColecoes.map;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ConsumidorMapTeste {
    public static void main(String[] args) {
        Consumidor steffano = new Consumidor("Steffano","123");
        Consumidor empresa = new Consumidor("Empresa A", "1245");

        Produto produto1 = new Produto("123","Laptop Dell",2000.0D);
        Produto produto2 = new Produto("321","Picanha",51.16D);
        Produto produto3 = new Produto("481","Teclado Logitech",599.99D);
        Produto produto4 = new Produto("589","Asus Zenfone 3",1899.8D);
        Produto produto5 = new Produto("999","Asus Zenfone 8",3899.8D);
        Produto produtoDuplicado = new Produto("999","Asus Zenfone 8",3899.8D);

        Map<Consumidor, List<Produto>> map = new HashMap<>();
        List<Produto> produtosSteffano = new ArrayList<>();
        produtosSteffano.add(produto1);
        produtosSteffano.add(produto2);

        List<Produto> produtosEmpresa = new ArrayList<>();
        produtosEmpresa.add(produto3);
        produtosEmpresa.add(produto4);
        produtosEmpresa.add(produto5);
        produtosEmpresa.add(produtoDuplicado); //irá adicionar duplicado

        map.put(steffano,produtosSteffano);
        map.put(empresa,produtosEmpresa);

        for (Map.Entry<Consumidor, List<Produto>> entry : map.entrySet()){
            System.out.println("----");
            System.out.println(entry.getKey().getNome() + " comprou:\n");
            for (Produto p : entry.getValue()) {
                System.out.println(p.getNome());
            }
        }
    }
}
