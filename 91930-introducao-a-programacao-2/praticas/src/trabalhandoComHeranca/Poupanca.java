package trabalhandoComHeranca;

public class Poupanca extends Conta {

    public Poupanca(String numeroConta) {
        super(numeroConta, 0.0);
    }

    public void renderJuros(double taxa) {
        super.creditar(this.getSaldo()*taxa);
    }
}
