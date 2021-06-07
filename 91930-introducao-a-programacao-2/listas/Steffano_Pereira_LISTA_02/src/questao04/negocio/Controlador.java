package questao04.negocio;

public class Controlador {
    private ControladorUsuario usuarios;
    private ControladorProduto produtos;
    private ControladorLoja lojas;
    private ControladorAlertaPreco alertas;
    private ControladorOfertaProduto ofertas;

    public Controlador() {
        this.usuarios = new ControladorUsuario();
        this.produtos = new ControladorProduto();
        this.lojas = new ControladorLoja();
        this.alertas = new ControladorAlertaPreco();
        this.ofertas = new ControladorOfertaProduto();
    }

}
