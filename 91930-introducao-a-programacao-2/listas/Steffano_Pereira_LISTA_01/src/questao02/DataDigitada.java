/*--------------------------------------------------------------
 * Esclarecimentos sobre esta Classe
 * 
 * Criei essa classe apenas para utilizar minhas habilidades com
 * Programa��o Orientada a objeto, n�o h� nenhuma conex�o desta
 * classe com o que foi requisitado na disciplina, funciona ape-
 * nas para manter a Data a ser digitada coerente.
 * -------------------------------------------------------------
 */

package questao02;

public class DataDigitada {
	private int ano;
	private int mes;
	private int dia;
	private boolean anoBissexto;
	public boolean anoValidado;
	
	public DataDigitada () {
		ano = 0;
		mes = 0;
		dia = 0;
		anoBissexto = false;
		anoValidado = false;
	}
	
	//M�todos Externos
	
	//M�todos Internos
	private boolean verificaAno(int ano) {
		if (ano < 2022) {
			return true;
		}
		return false;
	}
	
	private boolean verificaMes(int mes) {
		if ((mes > 0) && (mes < 13)) {
			return true;
		}
		return false;
	}
	
	private boolean verificaDia(int dia) {
		//Verifica logo se � um dia v�lido para todo calend�rio
		if ((dia < 1) || (dia > 31)) {
			return false;
		}
		
		//Verifica as condi��es para meses terminados com 30
		if (this.mes == 4 ||
			this.mes == 6 ||
			this.mes == 9 ||
			this.mes == 11 ) {
			
			if (dia > 30) {
				return false;
			}
			return true;
		} else if (!(this.mes == 2)) {
			return true;
		}
		
		//Verifica as condi��es do m�s de Fevereiro
		if (this.mes == 2) {
			if (!this.anoBissexto && (dia > 28)) {
				return false;
			} else if (this.anoBissexto && (dia > 29)) {
				return false;
			}
			return true;
		}
		
		return false;
	}
	
	//Getters/Setters
	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		if (verificaAno(ano)) {
			if ((ano % 4) == 0)
				this.anoBissexto = true;
			else
				this.anoBissexto = false;
			
			this.ano = ano;
			anoValidado = true;
		} else {
			System.out.println("Ano inv�lido, por favor digite um ano v�lido");
			anoValidado = false;
		}
	}

	public int getMes() {
		return mes;
	}

	public void setMes(int mes) {
		if (verificaMes(mes)) {
			this.mes = mes;
		} else {
			System.out.println("M�s inv�lido, por favor digite um m�s v�lido");
			this.mes = 0; //N�o validado
		}
		
	}

	public int getDia() {
		return dia;
	}

	public void setDia(int dia) {
		if (verificaDia(dia)) {
			this.dia = dia;
		} else {
			System.out.println("Dia inv�lido, por favor digite um dia v�lido");
			this.dia = 0; //N�o validado
		}
		
	}
}
