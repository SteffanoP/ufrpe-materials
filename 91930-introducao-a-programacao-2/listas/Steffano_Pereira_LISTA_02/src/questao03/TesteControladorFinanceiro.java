package questao03;

import questao03.despesa.DespesaComAgua;
import questao03.despesa.DespesaComEnergia;
import questao03.despesa.DespesaComInternet;
import questao03.receita.LicencaBasica;
import questao03.receita.LicencaEnterprise;
import questao03.receita.LicencaPlus;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class TesteControladorFinanceiro {
    public static void main(String[] args) {
        //Instanciando as despesas
        Transacao despesaTim = new DespesaComInternet(LocalDateTime.of(2021,5,20,22,19),
                                                        "Conta TIM",197.26D);
        Transacao despesaLuz = new DespesaComEnergia(LocalDateTime.of(2021,5,20,22,21),
                                                        "Conta Celpe",204);
        Transacao despesaAgua = new DespesaComAgua(LocalDateTime.of(2021,5,20,22,23),
                                                        "Conta Compesa",32);

        //Instanciando as Receitas
        Transacao receitaBasica = new LicencaBasica(LocalDateTime.of(2021,5,20,22,26),
                                                "Plano Básico",5);
        Transacao receitaPlus = new LicencaPlus(LocalDateTime.of(2021,5,20,22,46),
                                            "Plano Plus",10);
        Transacao receitaEnterprise = new LicencaEnterprise(LocalDateTime.of(2021,5,20,22,48),
                                                        "Plano Enterprise",3);

        //Criando o Fluxo de Caixa e Empresa
        FluxoCaixa minhaEmpresa = new FluxoCaixa("Minha Empresa","76.658.370/0001-82");
        minhaEmpresa.adicionarTransacao(despesaTim); //668,844
        minhaEmpresa.adicionarTransacao(despesaLuz); //
        minhaEmpresa.adicionarTransacao(despesaAgua);
        minhaEmpresa.adicionarTransacao(receitaBasica); //+100
        minhaEmpresa.adicionarTransacao(receitaPlus); //+350
        minhaEmpresa.adicionarTransacao(receitaEnterprise); //+450

        LocalDate dataInicio = LocalDate.of(2021,05,18);
        LocalDate dataFim = LocalDate.of(2021,05,21);
        System.out.printf("Saldo da Empresa: R$%,.2f\n",minhaEmpresa.saldoAtual());
        System.out.printf("Despesas: R$%,.2f\n",minhaEmpresa.calcularDespesas(dataInicio,dataFim));
        System.out.printf("Percentual de Despesa: %,.2f%%\n",minhaEmpresa.percentualDespesasNoMes(5,2021));
        System.out.printf("Receitas: R$%,.2f\n",minhaEmpresa.calcularReceitas(dataInicio,dataFim));
        System.out.printf("Percentual de Receita: %,.2f%%\n",minhaEmpresa.percentualReceitasNoMes(5,2021));

        System.out.println("----- Teste listarTransacoesNoMes() -----");
        List<Transacao> transacoes = new ArrayList<>(minhaEmpresa.listarTransacoesNoMes(5,2021));
        for (Transacao transacao : transacoes) {
            System.out.printf("%s | %s | %s\n",transacao.getData().toString(),transacao.getTipo(),transacao.getDescricao());
        }
    }
}
