
public class TesteSimplesConta {
	public static void main(String[] args) {
		Conta minhaConta = new Conta();
		minhaConta.creditar(50);
		
		System.out.println(minhaConta.saldo);  
	}
}
