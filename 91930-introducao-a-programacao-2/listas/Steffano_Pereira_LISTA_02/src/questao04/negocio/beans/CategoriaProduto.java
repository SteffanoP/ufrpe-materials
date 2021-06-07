package questao04.negocio.beans;

//Baseado nas categorias da Magalu
public enum CategoriaProduto {
    CELULARES           ("Celular"),
    MOVEIS              ("Móvel"),
    ELETRODOMESTICOS    ("Eletrodomésticos"),
    TV_E_VIDEO          ("TV e Vídeo"),
    INFORMATICA         ("Informática");

    private String nome;

    CategoriaProduto(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return nome;
    }

    public String getNome() {
        return nome;
    }
}
