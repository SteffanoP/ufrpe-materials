package trabalhandoComRepositorio;

import java.util.ArrayList;

public class RepositorioContas {
    private ArrayList<Conta> contas;

    public RepositorioContas (int quantidadeInicial) {
        this.contas = new ArrayList<Conta>(quantidadeInicial);
    }

    public boolean adicionarConta(Conta c) {
        boolean resultado = false;
        if (c != null) {
            String num = c.getNumero();
            boolean contaIgual = false;

            for (Conta conta : contas) {
                if (conta.getNumero().equals(num)) {
                    contaIgual = true;
                    break;
                }
            }

            if (contaIgual == false) {
                this.contas.add(c);
                resultado = true;
            }
        }
        return resultado;
    }

    public boolean removerConta(String numero) {
        boolean resultado = false;
        boolean contaExiste = false;

        int i;
        for (i = 0; (i < this.contas.size()) && !contaExiste; i++) {
            Conta c = this.contas.get(i);

            if (c.numero.equals(numero)) {
                contaExiste = true;
            }
        }

        if (contaExiste) {
            this.contas.remove(i-1);
            resultado = true;
        }

        return resultado;
    }

    public String toString() {
        String resultado = "";
        for (Conta conta : contas) {
            resultado += conta.getNumero() + "  | Saldo: " + conta.getSaldo() + "\n";
        }

        return resultado;
    }
}
