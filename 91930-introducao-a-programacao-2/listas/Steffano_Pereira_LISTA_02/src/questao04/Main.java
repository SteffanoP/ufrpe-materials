package questao04;

import javafx.application.Application;
import javafx.scene.control.Alert;
import javafx.stage.Stage;
import questao04.exception.ObjetoDuplicadoException;
import questao04.negocio.*;
import questao04.negocio.beans.*;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    //Necessário para alerta em tela do preço; Requisito javaFX
    @Override
    public void start(Stage stage) throws ObjetoDuplicadoException {
        ControladorUsuario repoUsuario = new ControladorUsuario();

        //Instanciando 1 usuário
        Usuario steffano = new Usuario("Steffano Pereira","steffanoxpereira@gmail.com",
                LocalDate.of(2000,7,21));

        try {
            repoUsuario.inserir(steffano);
        } catch (ObjetoDuplicadoException e) {
            System.out.println("Usuário já inserido no sistema!");
        }

        //Instanciando 2 produtos
        ControladorProduto produtos = new ControladorProduto();
        Produto micro_ondas_electrolux = new Produto(1,"Micro-ondas Electrolux 31L","127 Volts",
                CategoriaProduto.ELETRODOMESTICOS);

        Produto hd_externo_seagate = new Produto(2,"HD Externo Seagate","1 TB",
                CategoriaProduto.INFORMATICA);

        try {
            produtos.inserir(micro_ondas_electrolux);
            produtos.inserir(hd_externo_seagate);
        } catch (ObjetoDuplicadoException e) {
            System.out.println("Produto já inserido no sistema!");
        }

        //Instanciando 3 lojas
        ControladorLoja lojas = new ControladorLoja();
        Loja magazine_luiza = new Loja(1,"Magazine Luiza","magalu.com.br");
        Loja americanas = new Loja(2,"Americanas","americanas.com.br");
        Loja carrefour = new Loja(3,"Carrefour","carrefour.com.br");

        try {
            lojas.inserir(magazine_luiza);
            lojas.inserir(americanas);
            lojas.inserir(carrefour);
        } catch (ObjetoDuplicadoException e) {
            System.out.println("Loja já inserida no sistema");
        }

        //Instanciando 6 Ofertas de Micro-ondas para 3 lojas
        ControladorOfertaProduto ofertas = new ControladorOfertaProduto();
        OfertaProduto microOndasJaneiroMagalu = new OfertaProduto(micro_ondas_electrolux,626.05F,
                magazine_luiza,LocalDate.of(2021,1,31));
        OfertaProduto microOndasMaioMagalu = new OfertaProduto(micro_ondas_electrolux,625.80F,
                magazine_luiza, LocalDate.of(2021,5,27));
        OfertaProduto microOndasJaneiroAmericanas = new OfertaProduto(micro_ondas_electrolux,750.76F,
                americanas,LocalDate.of(2021,2,2));
        OfertaProduto microOndasMaioAmericanas = new OfertaProduto(micro_ondas_electrolux,780.89F,
                americanas,LocalDate.of(2021,5,27));
        OfertaProduto microOndasJaneiroCarrefour = new OfertaProduto(micro_ondas_electrolux,691.20F,
                carrefour,LocalDate.of(2021,2,8));
        OfertaProduto microOndasMaioCarrefour = new OfertaProduto(micro_ondas_electrolux,673.20F,
                carrefour,LocalDate.of(2021,5,27));

        try {
            ofertas.inserir(microOndasJaneiroMagalu);
            ofertas.inserir(microOndasMaioMagalu);
            ofertas.inserir(microOndasJaneiroAmericanas);
            ofertas.inserir(microOndasMaioAmericanas);
            ofertas.inserir(microOndasJaneiroCarrefour);
            ofertas.inserir(microOndasMaioCarrefour);
        } catch (ObjetoDuplicadoException e) {
            System.out.println("Oferta já inserida no sistema");
        }

        //Instanciando 6 Ofertas de HD Externo para 3 lojas
        OfertaProduto hdJaneiroMagalu = new OfertaProduto(hd_externo_seagate,506.05F,
                magazine_luiza,LocalDate.of(2021,1,30));
        OfertaProduto hdMaioMagalu = new OfertaProduto(hd_externo_seagate,484.25F,
                magazine_luiza, LocalDate.of(2021,5,25));
        OfertaProduto hdJaneiroAmericanas = new OfertaProduto(hd_externo_seagate,360.90F,
                americanas,LocalDate.of(2021,2,1));
        OfertaProduto hdMaioAmericanas = new OfertaProduto(hd_externo_seagate,312.64F,
                americanas,LocalDate.of(2021,5,18));
        OfertaProduto hdJaneiroCarrefour = new OfertaProduto(hd_externo_seagate,372.34F,
                carrefour,LocalDate.of(2021,2,7));
        OfertaProduto hdMaioCarrefour = new OfertaProduto(hd_externo_seagate,339.00F,
                carrefour,LocalDate.of(2021,5,18));

        try {
            ofertas.inserir(hdJaneiroMagalu);
            ofertas.inserir(hdMaioMagalu);
            ofertas.inserir(hdJaneiroAmericanas);
            ofertas.inserir(hdMaioAmericanas);
            ofertas.inserir(hdJaneiroCarrefour);
            ofertas.inserir(hdMaioCarrefour);
        } catch (ObjetoDuplicadoException e) {
            System.out.println("Oferta já inserida no sistema");
        }


        //Instanciando 2 alertas
        ControladorAlertaPreco alertas = new ControladorAlertaPreco();
        AlertaPreco alertaMicroOndas = new AlertaPreco(steffano,micro_ondas_electrolux,630.00F);
        alertas.inserir(alertaMicroOndas);
        AlertaPreco alertaHD = new AlertaPreco(steffano,hd_externo_seagate,320.00F);
        alertas.inserir(alertaHD);


        //Utilizando os métodos
        System.out.println("---------------------------------------------------");
        //Método listarOfertasOrdenadasPorPrecoNaData()
        LocalDate dataHoje = LocalDate.now();

        List<OfertaProduto> ofertasMicroOndas;
        ofertasMicroOndas = ofertas.listarOfertasOrdenadasPorPrecoNaData(micro_ondas_electrolux,dataHoje);

        System.out.println("Teste Método listarOfertasOrdenadasPorPrecoNaData()");
        for (OfertaProduto oferta : ofertasMicroOndas) {
            System.out.printf("%s\t |\tR$ %,.2f\t|\t%s\n",oferta.getLoja().getNome(),oferta.getPreco(),
                    oferta.getLoja().getSite());
        }

        System.out.println("---------------------------------------------------");

        //Método montarHistoricoDeOfertasDoProdutoNoPeriodo()
        //Foi utilizado o artifício de transformar o map em um TreeMap, para ordenar conforme a questão
        System.out.println("Teste Método montarHistoricoDeOfertasDoProdutoNoPeriodo()");
        TreeMap<LocalDate, List<OfertaProduto>> historicoHD =
                new TreeMap<>(ofertas.montarHistoricoDeOfertasDoProdutoNoPeriodo(hd_externo_seagate,
                LocalDate.of(2021, 4, 1), dataHoje));

        System.out.println("\tData\t|\t  Preço");
        for (Map.Entry<LocalDate, List<OfertaProduto>> entry : historicoHD.entrySet()) {
            for (OfertaProduto oferta : entry.getValue()) {
                System.out.printf("%s\t|\tR$ %,.2f\n",entry.getKey().toString(),oferta.getPreco());
            }
        }

        System.out.println("---------------------------------------------------");

        //Método verificarAlertasDePrecoAtingido
        List<AlertaPreco> alertasPreco = new ArrayList<>();

        alertasPreco = alertas.verificarAlertasDePrecoAtingido(steffano,ofertas);

        for (AlertaPreco alerta : alertasPreco) {
            Alert alertaPreco = new Alert(Alert.AlertType.WARNING);
            alertaPreco.setTitle("Preço atingido! Aproveite e compre agora!");
            alertaPreco.setHeaderText("O grande dia chegou!");
            alertaPreco.setContentText(alerta.toString());
            alertaPreco.showAndWait();
        }
    }
}
