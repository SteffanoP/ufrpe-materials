package trabalhandoComHeranca;

import java.time.LocalDate;

public class Conta {

    String numero;
    protected double saldo;

    public Conta(String numero, double saldo) {
        this.setNumero(numero);
        this.setSaldo(saldo);
    }

    public String toString() {
        return this.numero + "  " + this.saldo;
    }

    public void creditar(double valor) {
        if (valor > 0) {
            this.saldo += valor;
        } else {

        }
    }

    public void debitar(double valor) {
        if (valor > 0 && this.saldo >= valor) {
            this.saldo -= valor;
        } else {

        }
    }

    @Override
    public boolean equals(Object obj) {
        boolean resultado = false;

        if (obj instanceof Conta) {
            Conta param = (Conta) obj;

            if (param.getNumero() != null) {
                if (param.equals(this.getNumero())
                        && param.getSaldo() == this.getSaldo()) {
                    resultado = true;
                }
            }
        }
        return resultado;
    }

    public String getNumero() {
        return numero;
    }

    public double getSaldo() {
        return saldo;
    }

    private void setNumero(String numero) {
        if (numero != null) {
            this.numero = numero;
        } else {

        }
    }

    private void setSaldo(double saldo) {
        if (saldo >= 0.0) {
            this.saldo = saldo;
        } else {

        }
    }

    public static void main(String[] args) {
        Conta c1 = new Conta("678-9", 1567.95);
        LocalDate ld = LocalDate.now();
        c1.equals(ld);

    }
}
