package questao04.negocio;

import questao04.dados.IRepositorio;
import questao04.dados.Repositorio;
import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;
import questao04.negocio.beans.Produto;

import java.util.List;

public class ControladorProduto {
    private IRepositorio<Produto> repoProduto;

    public ControladorProduto() {
        this.repoProduto = new Repositorio<>();
    }

    public void inserir(Produto objProduto) throws ObjetoDuplicadoException {
        this.repoProduto.inserir(objProduto);
    }

    public List<Produto> listar() {
        return this.repoProduto.listar();
    }

    public void atualizar(Produto objProduto) throws ObjetoNaoExisteException {
        this.repoProduto.atualizar(objProduto);
    }

    public void remover(Produto objProduto) throws ObjetoNaoExisteException {
        this.repoProduto.remover(objProduto);
    }
}
