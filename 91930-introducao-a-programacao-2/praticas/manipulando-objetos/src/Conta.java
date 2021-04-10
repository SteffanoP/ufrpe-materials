
public class Conta {
	
	String numero;
	double saldo;
	
	public Conta() {
		saldo = 0;
		numero = "000-0";
	}
	
	void creditar(double valor) {
		saldo += valor;
	}
	
	void debitar(double valor) {
		saldo -= valor;
	}

}
