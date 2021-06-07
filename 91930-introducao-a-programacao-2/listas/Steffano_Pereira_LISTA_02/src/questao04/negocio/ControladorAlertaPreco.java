package questao04.negocio;

import questao04.dados.IRepositorio;
import questao04.dados.Repositorio;
import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;
import questao04.negocio.beans.AlertaPreco;
import questao04.negocio.beans.OfertaProduto;
import questao04.negocio.beans.Usuario;

import java.util.ArrayList;
import java.util.List;

public class ControladorAlertaPreco {
    IRepositorio<AlertaPreco> repoAlertaPreco;

    public ControladorAlertaPreco() {
        this.repoAlertaPreco = new Repositorio<>();
    }

    public void inserir(AlertaPreco objAlertaPreco) throws ObjetoDuplicadoException {
        this.repoAlertaPreco.inserir(objAlertaPreco);
    }

    public List<AlertaPreco> listar() {
        return this.repoAlertaPreco.listar();
    }

    public List<AlertaPreco> verificarAlertasDePrecoAtingido(Usuario u, ControladorOfertaProduto ofertas) {
        if (u == null) return null;
        List<AlertaPreco> meusAlertasAtingidos = new ArrayList<>();

        for (AlertaPreco alerta : this.repoAlertaPreco.listar()) {
            if (alerta.getUsuario() == u) {
                for (OfertaProduto oferta : ofertas.listarRecentes()) {
                    if (oferta.getPreco() <= alerta.getPrecoDesejado()) {
                        meusAlertasAtingidos.add(alerta);
                    }
                }
            }
        }

        return meusAlertasAtingidos;
    }

    public void atualizar(AlertaPreco objAlertaPreco) throws ObjetoNaoExisteException {
        this.repoAlertaPreco.atualizar(objAlertaPreco);
    }

    public void remover(AlertaPreco objAlertaPreco) throws ObjetoNaoExisteException {
        this.repoAlertaPreco.remover(objAlertaPreco);
    }
}
