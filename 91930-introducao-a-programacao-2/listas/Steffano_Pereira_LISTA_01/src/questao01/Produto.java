package questao01;

public class Produto {
	private String codigo;
	private String nome;
	
	public Produto() {
		
	}
	
	public Produto(String codigoInicial, String nomeInicial) {
		if (codigoInicial != null) {
			this.codigo = codigoInicial;			
		} else {
			System.out.println("Nome inválido!");
		}
		
		if (nomeInicial != null) {
			this.nome = nomeInicial;			
		} else {
			System.out.println("Nome inválido!");
		}
	}
	
	
	void mudarNome (String nomeNovo) {
		if (nomeNovo != null) {
			this.nome = nomeNovo;			
		}
	}
	
	String getNome () {
		return nome;
	}
	
	String getCodigo () {
		return codigo;
	}
}
