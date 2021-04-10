
public class TesteSimplesConta {
	public static void main(String[] args) {
		Conta minhaConta = new Conta();
		Conta minhaContaComAtributosIniciais = new Conta("123-4", 100.50);
		
		//minhaConta.numero = ""; //É um attribute private da Conta.java
		minhaConta.getNumero();
		
		//minhaConta.saldo = 500000; //É um attribute private da Conta.java
		minhaConta.creditar(500000);
		
		System.out.println(minhaConta.getNumero());
		System.out.println(minhaConta.getSaldo());
		System.out.println();
		System.out.println(minhaContaComAtributosIniciais.getNumero());
		System.out.println(minhaContaComAtributosIniciais.getSaldo());
		System.out.println();
		
		minhaContaComAtributosIniciais.debitar(50);
		System.out.println(minhaContaComAtributosIniciais.getSaldo());
		
		//Testa condição de débito
		minhaContaComAtributosIniciais.debitar(100);
	}
}
