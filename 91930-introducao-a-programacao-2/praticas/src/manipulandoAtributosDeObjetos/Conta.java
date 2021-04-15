package manipulandoAtributosDeObjetos;

public class Conta {
	
	private String numero;
	private double saldo;
	
	public Conta() { //Construtor Default
		saldo = 0;
		numero = "000-0";
	}
	
	public Conta(String numeroInicial, double saldoInicial) {
		numero = numeroInicial;
		saldo = saldoInicial;
	}
	
	public void creditar(double valor) {
		saldo += valor;
	}
	
	public void debitar(double valor) {
		if (valor < saldo) {
			saldo -= valor;
		} else {
			System.out.println("Saldo insuficiente");
		}
	}
	
	public String getNumero() {
		return numero;
	}
	
	public double getSaldo() {
		return saldo;
	}

}
