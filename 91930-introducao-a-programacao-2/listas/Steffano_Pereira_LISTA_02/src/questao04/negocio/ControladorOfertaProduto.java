package questao04.negocio;

import questao04.dados.IRepositorio;
import questao04.dados.Repositorio;
import questao04.exception.ObjetoDuplicadoException;
import questao04.exception.ObjetoNaoExisteException;
import questao04.negocio.beans.OfertaProduto;
import questao04.negocio.beans.Produto;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ControladorOfertaProduto {
    private IRepositorio<OfertaProduto> repoOfertaProduto;

    public ControladorOfertaProduto() {
        this.repoOfertaProduto = new Repositorio<>();
    }

    public void inserir(OfertaProduto objOfertaProduto) throws ObjetoDuplicadoException {
        this.repoOfertaProduto.inserir(objOfertaProduto);
    }

    public List<OfertaProduto> listar() {
        return this.repoOfertaProduto.listar();
    }

    public List<OfertaProduto> listarRecentes() {
        List<OfertaProduto> ofertasRecentes = new ArrayList<>();
        LocalDate dataHoje = LocalDate.now();
        for (OfertaProduto oferta : repoOfertaProduto.listar()) {
            if (oferta.getData().compareTo(dataHoje) == 0) {
                ofertasRecentes.add(oferta);
            }
        }

        return ofertasRecentes;
    }

    public List<OfertaProduto> listarOfertasOrdenadasPorPrecoNaData(Produto produto, LocalDate dataAtual) {
        List<OfertaProduto> ofertasRecentes = new ArrayList<>();

        for (OfertaProduto oferta : repoOfertaProduto.listar()) {
            if (oferta.getProduto().equals(produto)) {
                if (oferta.getData().compareTo(dataAtual) == 0) {
                    ofertasRecentes.add(oferta);
                }
            }
        }

        return ofertasRecentes;
    }

    public Map<LocalDate, List<OfertaProduto>> montarHistoricoDeOfertasDoProdutoNoPeriodo(Produto produto,
                                                                                          LocalDate dataInicial,
                                                                                          LocalDate dataFinal) {
        Map<LocalDate, List<OfertaProduto>> historicoDeOfertas = new HashMap<>();

        //Filtra as ofertas para o período (Condição da função <=> negócio)
        List<OfertaProduto> ofertasPeriodo = new ArrayList<>();
        for (OfertaProduto oferta : repoOfertaProduto.listar()) {
            if (oferta.getProduto().equals(produto)) {
                if (oferta.getData().isAfter(dataInicial) && oferta.getData().isBefore(dataFinal)) {
                    ofertasPeriodo.add(oferta);
                }
            }
        }

        //Algoritmo de ordenação
        for (OfertaProduto oferta : ofertasPeriodo) {
            //Para que a operação seja exclusiva para cada dia
            if (historicoDeOfertas.containsKey(oferta.getData())) break;

            //Separação para lista de ofertas no dia
            List<OfertaProduto> ofertasDia = new ArrayList<>();
            ofertasDia.add(oferta);

            //Inserção de outras ofertas no mesmo dia
            for (OfertaProduto outraOferta : ofertasPeriodo) {
                if (outraOferta.getData().isEqual(oferta.getData())) {
                    if (!(ofertasDia.contains(outraOferta)))
                        ofertasDia.add(outraOferta);
                }
            }

            //Adiciona as informações do algoritmo ao Map
            historicoDeOfertas.put(oferta.getData(),ofertasDia);
        }

        return historicoDeOfertas;
    }

    public void atualizar(OfertaProduto objOfertaProduto) throws ObjetoNaoExisteException {
        this.repoOfertaProduto.atualizar(objOfertaProduto);
    }

    public void remover(OfertaProduto objOfertaProduto) throws ObjetoNaoExisteException {
        this.repoOfertaProduto.remover(objOfertaProduto);
    }
}
