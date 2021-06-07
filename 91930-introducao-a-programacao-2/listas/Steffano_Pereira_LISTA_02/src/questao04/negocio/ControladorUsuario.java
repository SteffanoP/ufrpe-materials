package questao04.negocio;

import questao04.dados.IRepositorio;
import questao04.dados.Repositorio;
import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;
import questao04.negocio.beans.Usuario;

import java.util.List;

public class ControladorUsuario {

    private IRepositorio<Usuario> repoUsuario;

    public ControladorUsuario() {
        this.repoUsuario = new Repositorio<>();
    }

    public void inserir(Usuario objUsuario) throws ObjetoDuplicadoException {
        this.repoUsuario.inserir(objUsuario);
    }

    public List<Usuario> listar() {
        return this.repoUsuario.listar();
    }

    public void atualizar(Usuario objUsuario) throws ObjetoNaoExisteException {
        this.repoUsuario.atualizar(objUsuario);
    }

    public void remover(Usuario objUsuario) throws ObjetoNaoExisteException {
        this.repoUsuario.remover(objUsuario);
    }
}
