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
			System.out.println("Há campos nulos!");
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
    			System.out.println("Não foi possível identificar o nome da vacina: " + nome);
    			System.out.println("Por Favor, verifique se a vacina é CORONAVAC ou OXFORD");
    			System.out.println("Caso não seja nenhuma das duas, entre em contato com o Ministério da Saúde: Disque 136");
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
