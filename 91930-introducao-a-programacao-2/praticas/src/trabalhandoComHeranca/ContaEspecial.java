package trabalhandoComHeranca;

public class ContaEspecial extends Conta {
    double limite;

    public ContaEspecial(String numeroConta) {
        super(numeroConta,0.0);
        this.limite = 100.0;
    }

    public void aumentarLimite(double aumento) {
        this.limite += aumento;
    }

    public double getLimite() {
        return limite;
    }

    @Override
    public void debitar (double valor) {
        if (valor < this.saldo + this.limite) {
            this.saldo -= valor;
        }
    }

    public void calcularJuros() {
        if (this.saldo < 0) {
            double juros = Math.abs(this.saldo * 0.05);
            this.debitar(juros);
        }
    }

    public static void main(String[] args) {
        Conta contae = new ContaEspecial("456-7");

        contae.creditar(500.0);
        contae.debitar(550.0);
        ((ContaEspecial) contae).aumentarLimite(100.0);
        contae.debitar(75.0);
        ((ContaEspecial) contae).calcularJuros();
        System.out.println(contae.getSaldo());

        //Exemplificando a diferença entre as classes
        Conta c = new Conta("567-8", 55.0);
        System.out.println(c.getClass());
        System.out.println(contae.getClass());
    }
}
