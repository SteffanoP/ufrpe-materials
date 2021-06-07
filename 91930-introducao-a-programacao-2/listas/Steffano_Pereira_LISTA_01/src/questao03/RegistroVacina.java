package questao03;

import java.time.LocalDate;

public class RegistroVacina {
    //Atributos
    private String id;
    private LocalDate data_vacinacao;
    private String atendente;
    private int dose;
    private String local;
    private String grupo;
    
    private Vacina vacina;
    private Pessoa vacinado;

	//Construtores
    public RegistroVacina () {

    }

    public RegistroVacina(String id, LocalDate data_vacinacao, String atendente, int dose, String grupo) {
    	setId(id);
    	setData_vacinacao(data_vacinacao);
    	setAtendente(atendente);
    	setDose(dose);
    	setGrupo(grupo);
    }
    
	//Métodos
    public void setVacinacao (Vacina vacina, Pessoa vacinado) {
    	this.vacina = vacina;
    	this.vacinado = vacinado;
    }
    
    //Getters/Setters

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public LocalDate getData_vacinacao() {
        return data_vacinacao;
    }

    public void setData_vacinacao(LocalDate data_vacinacao) {
        this.data_vacinacao = data_vacinacao;
    }

    public String getAtendente() {
        return atendente;
    }

    public void setAtendente(String atendente) {
        this.atendente = atendente;
    }

    public int getDose() {
        return dose;
    }

    public void setDose(int dose) {
        if ((dose == 1) || (dose == 2)) {
            this.dose = dose;
        } else {
            System.out.println("Dose inválida, certifique-se que você digitou corretamente.");
        }
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
    	if (local == null) {
			System.out.println("Local nulo!");
		} else if (local.equals("DRIVE THRU - UFRPE - UNIVERSIDADE RURAL") 	||
        	local.equals("DRIVE THRU GERALDÃO")                         ||
        	local.equals("CENTRO DE VACINAÇÃO PARQUE DE EXPOSIÇÃO")     ||
        	local.equals("CENTRO DE VACINAÇÃO COMPAZ ARIANO SUASSUNA")  ||
        	local.equals("DRIVE THRU PARQUE DE EXPOSIÇÃO")              ||
        	local.equals("DRIVE THRU ARRUDA")) {
            this.local = local;
        } else {
            System.out.println("Local não encontrado.");
        }

    }

    public String getGrupo() {
        return grupo;
    }

    public void setGrupo(String grupo) {
    	if (grupo == null) {
			System.out.println("Grupo inválido!");
		} else if (grupo.equals("IDOSOS") || grupo.equals("TRABALHADORES DA SAÚDE") ||
        	grupo.equals("OUTRAS PRIORIDADES")) {
            this.grupo = grupo;
        } else {
            System.out.println("Grupo de Risco não encontrado.");
        }
    }
    
    public Vacina getVacina() {
		return vacina;
	}

	public void setVacina(Vacina vacina) {
		this.vacina = vacina;
	}

	public Pessoa getVacinado() {
		return vacinado;
	}

	public void setVacinado(Pessoa vacinado) {
		this.vacinado = vacinado;
	}

}
