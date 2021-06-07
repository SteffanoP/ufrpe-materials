package questao04.dados;

import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Repositorio<T> implements IRepositorio<T>{
    private List<T> elementos; //Nomenclatura baseada no Repo Genérico de @lmarques7

    public Repositorio() {
        this.elementos = new ArrayList<>();
    }

    public Repositorio(int capacidadeInicial) {
        this.elementos = new ArrayList<>(capacidadeInicial);
    }

    @Override
    public void inserir(T objeto) throws ObjetoDuplicadoException {
        if (!this.elementos.contains(objeto)) {
            this.elementos.add(objeto);
        } else {
            throw new ObjetoDuplicadoException(objeto);
        }
    }

    @Override
    public List<T> listar() {
        return Collections.unmodifiableList(this.elementos);
    }

    @Override
    public void atualizar(T objeto) throws ObjetoNaoExisteException {
        if (this.elementos.contains(objeto)) {
            int indice = this.elementos.indexOf(objeto);
            this.elementos.set(indice,objeto);
        } else {
            throw new ObjetoNaoExisteException(objeto);
        }
    }

    @Override
    public void remover(T objeto) throws ObjetoNaoExisteException {
        if (this.elementos.contains(objeto)) {
            this.elementos.remove(objeto);
        } else {
            throw new ObjetoNaoExisteException(objeto);
        }
    }
}
