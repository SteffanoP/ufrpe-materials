package questao01;

public class TesteEstoqueMain {

	public static void main(String[] args) {
		Produto produto01 = new Produto("1","Teclado");
		Produto produto02 = new Produto("2","Mouse");
		Estoque estoque1 = new Estoque(produto01, 20, 15);
		Estoque estoque2 = new Estoque(produto02, 30, 10);
		
		//1� opera��o
		estoque1.darBaixa(10);
		
		//2� opera��o
		estoque2.reporEstoque(19);
		
		//3� opera��o
		estoque1.relatorio();
		estoque2.relatorio();
		
		//4� opera��o
		produto01.mudarNome("Teclado Virtual");
		
		//5� opera��o
		estoque1.relatorio();

	}

}
