package questao04.dados;

import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;

import java.util.List;

public interface IRepositorio<T> {
    void inserir(T objeto) throws ObjetoDuplicadoException;
    List<T> listar();
    void atualizar(T objeto) throws ObjetoNaoExisteException;
    void remover(T objeto) throws ObjetoNaoExisteException;
}
