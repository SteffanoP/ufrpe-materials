package trabalhandoComHeranca;

import java.util.ArrayList;

public class RepositorioContas {
    private ArrayList<Conta> contas;

    public RepositorioContas (int capacidadeInicial) {
        this.contas = new ArrayList<>(capacidadeInicial);
    }

    /**
     * Este método adiciona uma nova conta no ArrayList se e somente se nenhuma
     * outra conta com o mesmo número não tiver sido adicionado anteriormente
     *
     * @param conta A conta a ser adicionada ao repositório
     * @return true - se a conta foi adicionada.
     *         false - se não foi
     */
    public boolean addConta(Conta conta) {
        boolean resultado = false;

        if (conta != null) {
            String numeroConta = conta.getNumero();
            boolean contaExiste = false;
            for (Conta contaAtual : contas) {
                if (contaAtual.equals(numeroConta)) {
                    contaExiste = true;
                    break;
                }
            }

            if (!contaExiste) {
                this.contas.add(conta);
                resultado = true;
            }
        }

        return resultado;
    }

    /**
     * Remove o objeto Conta cujo número seja igual ao número informado como
     * parâmetro.
     *
     * @param numeroConta O número da Conta a ser removida
     * @return true - se a conta foi removida.
     *         false - se não foi
     */
    public boolean removerConta(String numeroConta) {
        boolean numeroExiste = false;

        int i;
        for (i = 0; i < contas.size() && !numeroExiste; i++) {
            Conta c = this.contas.get(i);
            if (c.getNumero().equals(numeroConta)) {
                numeroExiste = true;
            }
        }

        if (numeroExiste) {
            this.contas.remove(i-1);
        }

        return numeroExiste;
    }

    public String toString() {
        String resultado = "";
        for (Conta contaAtual : contas) {
            resultado += contaAtual.getNumero() + "  | Saldo: " + contaAtual.getSaldo() + "\n";
        }
        return resultado;
    }
}
