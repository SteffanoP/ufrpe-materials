package questao01;

public class Estoque {
	private Produto produto;
	private int qtdAtual;
	private int qtdMinima;
	
	public Estoque() {
		
	}
	
	public Estoque(Produto produtoInicial, int qtdAtual, int qtdMinima) {
		this.produto = produtoInicial;
		this.qtdAtual = qtdAtual;
		this.qtdMinima = qtdMinima;
	}
	
	void mudarQtdMinima(int qtdMinima) {
		this.qtdMinima = qtdMinima;
	}
	
	void reporEstoque(int qtd) {
		this.qtdAtual += qtd;
	}
	
	void darBaixa(int qtd) {
		this.qtdAtual -= qtd;
	}
	
	void relatorio() {
		System.out.println("----------------------------------------");
		System.out.printf("Nome do Produto: %s \n", produto.getNome());
		System.out.printf("Código: %s \n", produto.getCodigo());
		System.out.printf("Quantidade: %d \n", qtdAtual);
		System.out.printf("Quantidade mínima: %d \n", qtdMinima);
		System.out.println("----------------------------------------");
	}
}
