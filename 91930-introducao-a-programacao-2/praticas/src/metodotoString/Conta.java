package metodotoString;

public class Conta {

    String numero;
    double saldo;

    public Conta() {
        saldo = 0;
        numero = "000-0";
    }

    public Conta(String numeroInicial, double saldoInicial) {
        numero = numeroInicial;
        saldo = saldoInicial;
    }

    public String toString() {
        return this.numero + "  " + this.saldo;
    }

    public void creditar(double valor) {
        saldo += valor;
    }

    public void debitar(double valor) {
        saldo -= valor;
    }

}
