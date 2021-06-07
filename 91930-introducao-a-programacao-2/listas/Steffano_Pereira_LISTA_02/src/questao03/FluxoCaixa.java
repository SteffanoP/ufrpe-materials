package questao03;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class FluxoCaixa {
    private String nomeEmpresa;
    private String cnpj;

    private List<Transacao> transacoes;

    public FluxoCaixa(String nomeEmpresa, String cnpj) {
        this.setNomeEmpresa(nomeEmpresa);
        this.setCnpj(cnpj);
        transacoes = new ArrayList<>();
    }

    public void adicionarTransacao(Transacao transacao) {
        boolean transacaoDuplicada = false;

        for (Transacao t : transacoes) {
            if (transacao != null) {
                if (t.equals(transacao))
                    transacaoDuplicada = true;
            }
        }

        if (!transacaoDuplicada)
            this.transacoes.add(transacao);
        else System.out.println("Transação já cadastrada!");
    }

    public double calcularDespesas(LocalDate inicio, LocalDate fim) {
        double despesas = 0;
        for (Transacao transacao : transacoes) {
            if (inicio.isBefore(transacao.getData().toLocalDate()) &&
                    fim.isAfter(transacao.getData().toLocalDate())) {
                if (transacao.getTipo().equals("DESPESA"))
                    despesas += transacao.calcularTotal();
            }
        }
        return despesas;
    }

    public double calcularReceitas(LocalDate inicio, LocalDate fim) {
        double receitas = 0;
        for (Transacao transacao : transacoes) {
            if (inicio.isBefore(transacao.getData().toLocalDate()) &&
                    fim.isAfter(transacao.getData().toLocalDate())) {
                if (transacao.getTipo().equals("RECEITA"))
                    receitas += transacao.calcularTotal();
            }
        }
        return receitas;
    }

    private double calcularReceitasNoMes(int mes, int ano) {
        double receitasNoMes = 0;

        for (Transacao transacao : transacoes) {
            if (transacao.getData().getYear() == ano &&
                    transacao.getData().getMonthValue() == mes) {
                if (transacao.getTipo().equals("RECEITA"))
                    receitasNoMes += transacao.calcularTotal();
            }
        }

        return receitasNoMes;
    }

    private double calcularDespesasNoMes(int mes, int ano) {
        double despesasNoMes = 0;

        for (Transacao transacao : transacoes) {
            if (transacao.getData().getYear() == ano &&
                    transacao.getData().getMonthValue() == mes) {
                if (transacao.getTipo().equals("DESPESA"))
                    despesasNoMes += transacao.calcularTotal();
            }
        }

        return despesasNoMes;
    }

    public double percentualReceitasNoMes(int mes, int ano) {
        double receitasMes = calcularReceitasNoMes(mes, ano);
        double despesasMes = calcularDespesasNoMes(mes, ano);
        double percentualReceitas;

        //Garantia que não retorna porcentagem negativa
        if ((receitasMes - despesasMes) < 0) return 0;

        percentualReceitas = (receitasMes - despesasMes)/receitasMes;
        percentualReceitas *= 100;

        return percentualReceitas;
    }

    public double percentualDespesasNoMes(int mes, int ano) {
        double receitasMes = calcularReceitasNoMes(mes, ano);
        double despesasMes = calcularDespesasNoMes(mes, ano);
        double percentualDespesas;

        //Garantia que não retorna porcentagem negativa
        if ((despesasMes - receitasMes) < 0) return 0;

        percentualDespesas = (despesasMes - receitasMes)/despesasMes;
        percentualDespesas *= 100;

        return percentualDespesas;
    }

    public double saldoAtual() {
        double saldoReceitas = 0, saldoDespesas = 0;

        for (Transacao transacao : transacoes) {
            if (transacao.getTipo().equals("RECEITA"))
                saldoReceitas += transacao.calcularTotal();

            if (transacao.getTipo().equals("DESPESA"))
                saldoDespesas += transacao.calcularTotal();
        }

        return saldoReceitas - saldoDespesas;
    }

    public List<Transacao> listarTransacoesNoMes(int mes, int ano) {
        List<Transacao> transacoesMes = new ArrayList<>();

        for (Transacao transacao : transacoes) {
            if (transacao.getData().getYear() == ano &&
                    transacao.getData().getMonthValue() == mes) {
                transacoesMes.add(transacao);
            }
        }

        return transacoesMes;
    }

    public String getNomeEmpresa() {
        return nomeEmpresa;
    }

    public void setNomeEmpresa(String nomeEmpresa) {
        if (nomeEmpresa != null)
            this.nomeEmpresa = nomeEmpresa;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        if (cnpj != null)
            this.cnpj = cnpj;
    }

    public List<Transacao> getTransacoes() {
        return transacoes;
    }
}
