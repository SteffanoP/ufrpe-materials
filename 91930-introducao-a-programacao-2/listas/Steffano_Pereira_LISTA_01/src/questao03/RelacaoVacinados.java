package questao03;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class RelacaoVacinados {
    private RegistroVacina vacinados[] = new RegistroVacina[50];
    //Atributos não relacionados ao que foi pedido:
    private int quantidadeRegistros = 0;
    private int totalDeIdosos2aDose;
    
    
    //Construtor
    public RelacaoVacinados () {
    	
    }
    
    //Métodos públicos
    public void adicionar(RegistroVacina registro) {
    	this.vacinados[quantidadeRegistros] = registro;
    	quantidadeRegistros++;
    }
    
    public double calcularTotalVacinadosAcimade(int idade) {
    	int quantidadeTotalVacinados = 0;
    	
    	for (int i = 0; i < quantidadeRegistros; i++) {
    		if ((vacinados[i].getDose() == 2) && 
    				(vacinados[i].getVacinado().calcularIdade() > idade)) {
    			quantidadeTotalVacinados++;
    		}    		
    	}
    	
    	return quantidadeTotalVacinados;
    }
    
    //Método público extra:
    public long calcularTotalVacinados1aDoseAcimade(int idade) {
    	int quantidadeTotalVacinados = 0;
    	
    	for (int i = 0; i < quantidadeRegistros; i++) {
    		if ((vacinados[i].getDose() == 1) && 
    				(vacinados[i].getVacinado().calcularIdade() > idade)) {
    			quantidadeTotalVacinados++;
    		}    		
    	}
    	
    	return quantidadeTotalVacinados;
    }
    
    //Esse é um método que foi requisitado no UML, porém não instruído para uso...
    //Seria melhor se retornasse um long, porém vou manter a estrutura do UML
    public void totalDeIdososQueTomaram2aDose() {
    	int quantidadeIdosos2aDose = 0;
    	
    	for (int i = 0; i < quantidadeRegistros; i++) {
    		if (vacinados[i].getDose() == 2)
    			quantidadeIdosos2aDose++;
    	}
    	
    	this.totalDeIdosos2aDose = quantidadeIdosos2aDose;
    }
    
    //TODO: Remover Vacinados 2ª dose
    public void listarPessoasQueNaoTomaram2aDose() {
    	System.out.printf("CPF \t   |\tNome\t\t|  Idade  | Data Indicada p. 2ª dose\n");
    	System.out.printf("---------------------------------------------------------------------\n");
    	
    	for (int i = 0; i < quantidadeRegistros; i++) {    		
    		if (vacinados[i].getDose() == 1 && vacinados[i].getVacinado().isValid() && !tomou2aDose(i)) {    			
    			System.out.printf("%s | ",vacinados[i].getVacinado().getCpf());
    			System.out.printf("%-15s\t|",vacinados[i].getVacinado().getNome()); 
    			System.out.printf("\t%2d|",vacinados[i].getVacinado().calcularIdade());
    			
    			//Lógica de cálculo para Segunda Dose
    			LocalDate data2aDose = null;
    			
    			if (vacinados[i].getVacina().getNome().equals("CORONAVAC")) {
    				data2aDose = vacinados[i].getData_vacinacao().plusDays(21);    				
    			} else if (vacinados[i].getVacina().getNome().equals("OXFORD")) {
    				data2aDose = vacinados[i].getData_vacinacao().plusDays(90);
    			}
    			
    			DateTimeFormatter formatoData = DateTimeFormatter.ofPattern("dd/MM/YYYY");
    			System.out.printf("\t\t%s\n",data2aDose.format(formatoData));
    		}
    	}

    	System.out.printf("---------------------------------------------------------------------\n");
    	System.out.printf("Total de vacinados acima de 65 anos: %d\n",calcularTotalVacinados1aDoseAcimade(65));
    	totalDeIdososQueTomaram2aDose();
    	System.out.printf("Total de vacinados que não tomaram a 2ª dose: %d\n",calcularTotalVacinados1aDoseAcimade(65) - totalDeIdosos2aDose);
    	System.out.printf("Total de vacinados que tomaram a 2º dose: %d\n",(long) calcularTotalVacinadosAcimade(0));
    	
    }
    
    //Método extra
    public boolean tomou2aDose(int num_registro) {
    	String cpf = vacinados[num_registro].getVacinado().getCpf();
    	
    	for (int i = 0; i < quantidadeRegistros; i++) {
    		if (vacinados[i].getVacinado().getCpf().equals(cpf)) {
    			if (vacinados[i].getDose() == 2)
    				return true;
    		}
    	}    	
    	return false;
    }
  
    //Getter/Setters
    public RegistroVacina[] getVacinados() {
		return vacinados;
	}

	public void setVacinados(RegistroVacina[] vacinados) {
		this.vacinados = vacinados;
	}
    
}
