package questao03;

public class Vacina {
    //Atributos
    private int codigo;
    private String nome;
    private String lote;

    //Construtores
    public Vacina () {

    }
    
    public Vacina (int codigo, String nome, String lote) {
    	if (nome == null || lote == null) {
			System.out.println("H� campos nulos!");
		} else {			
			this.codigo = codigo;
			setNome(nome);
			this.lote = lote;
		}
    }

    //Get/Sets
    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    //TODO: Implementar/Estudar compatibilidade para entrada null
    public void setNome(String nome) {
    	if (nome != null) {			
    		if (nome.equals("CORONAVAC") || nome.equals("OXFORD")) {
    			this.nome = nome;
    		} else {
    			System.out.println("N�o foi poss�vel identificar o nome da vacina: " + nome);
    			System.out.println("Por Favor, verifique se a vacina � CORONAVAC ou OXFORD");
    			System.out.println("Caso n�o seja nenhuma das duas, entre em contato com o Minist�rio da Sa�de: Disque 136");
    		}
		} else {
			System.out.println("Nome nulo");
		}
    }

    public String getLote() {
        return lote;
    }

    public void setLote(String lote) {
        this.lote = lote;
    }
}
