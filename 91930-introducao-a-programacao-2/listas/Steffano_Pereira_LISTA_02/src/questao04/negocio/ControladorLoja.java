package questao04.negocio;

import questao04.dados.IRepositorio;
import questao04.dados.Repositorio;
import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;
import questao04.negocio.beans.Loja;

import java.util.List;

public class ControladorLoja {
    IRepositorio<Loja> repoLoja;

    public ControladorLoja() {
        this.repoLoja = new Repositorio<>();
    }

    public void inserir(Loja objLoja) throws ObjetoDuplicadoException {
        this.repoLoja.inserir(objLoja);
    }

    public List<Loja> listar() {
        return this.repoLoja.listar();
    }

    public void atualizar(Loja objLoja) throws ObjetoNaoExisteException {
        this.repoLoja.atualizar(objLoja);
    }

    public void remover(Loja objLoja) throws ObjetoNaoExisteException {
        this.repoLoja.remover(objLoja);
    }
}
