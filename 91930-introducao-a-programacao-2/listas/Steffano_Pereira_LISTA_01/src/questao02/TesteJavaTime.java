package questao02;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

public class TesteJavaTime {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		DataDigitada dataDigitada = new DataDigitada();
		
		//Pega o Ano digitado
		do {
			System.out.println("Digite um ano v�lido");
			dataDigitada.setAno(scanner.nextInt());
		} while (!dataDigitada.anoValidado);
		
		//Pega o m�s digitado
		do {
			System.out.println("Digite um m�s v�lido");
			dataDigitada.setMes(scanner.nextInt());
		} while (dataDigitada.getMes() == 0);
		
		//Pega o dia digitado
		do {
			System.out.println("Digite um dia v�lido");
			dataDigitada.setDia(scanner.nextInt());
		} while (dataDigitada.getDia() == 0);
		
		//Alternativa A - Criar o objeto LocalDate
		LocalDate minhaData = LocalDate.of(dataDigitada.getAno(), dataDigitada.getMes(), dataDigitada.getDia());
		
		System.out.println("A minhaData �: " + minhaData.toString());
		
		//Alternativa B - Comparar o objeto minhaData com a data de Hoje
		LocalDate dataHoje = LocalDate.now();
		
		System.out.println("O per�odo da data digitada at� hoje em dias � " + minhaData.until(dataHoje, ChronoUnit.DAYS) + " dias");
		/* Aqui achei interessante o uso da ChronoUnit, que faz a convers�o do until para dias
		 * usando apenas o m�todo until, s� � poss�vel obter o per�odo em anos, meses e dias,
		 * todavia, caso eu colete apenas os dias com o m�todo .getDays() ele capta apenas o
		 * argumento de dias, sem calcular os anos e meses.
		 */
		
		//Alternativa C - Criar uma nova data somada 110 dias da data digitada pelo usu�rio
		LocalDate dataSomada = minhaData.plusDays(110);
		
		System.out.println("A data somada em 110 dias �: " + dataSomada.toString());
		
		//Alternativa D - Alterar a minhaData para o m�s de Agosto
		minhaData = minhaData.withMonth(8);
		
		System.out.println("minhaData agora ser� do M�s de: " + minhaData.toString());
		
		//Alternativa E - Formatar a data para "dd-MMM-YYYY"
		DateTimeFormatter formatoData = DateTimeFormatter.ofPattern("dd-MMM-YYYY");
		
		System.out.println("minhaData formatada �: " + formatoData.format(minhaData));
		
		//Alternativa F - Criar um novo m�todo que calcula os dias �teis entre um range
		System.out.println("Digite a primeira data:");
		LocalDate novaData1 = LocalDate.of(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
		System.out.println("Digite a segunda data:");
		LocalDate novaData2 = LocalDate.of(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
		
		System.out.println("A quantidade de dias �teis s�o: "+ quantidadeDiasUteis(novaData1,novaData2));
		
		//System.out.println("A quantidade de dias �teis s�o: "+ quantidadeDiasUteis2(novaData1,novaData2));
		
		scanner.close();
	}
	
	/*Como pedido na alternativa F, criar um m�todo na mesma classe
	 * 
	 * OBS: Ao calcular os dias, ele inclui a dataInicial e a dataFinal
	 */
	static int quantidadeDiasUteis(LocalDate dataInicial, LocalDate dataFinal) {
		int contadorDiasUteis = 0, contadorDiasFinaisSemana = 0;
		int quantidadeDias;
		
		if (dataInicial.isBefore(dataFinal)) {
			//Aqui, utilizo o m�todo anterior para calcular range com um cast
			quantidadeDias = (int) dataInicial.until(dataFinal, ChronoUnit.DAYS) + 1;
			//+1, pois quero contar o dia que se inicia
			
			for (int contador = 0; contador < quantidadeDias; contador++) {
				/*
				 * Aqui h� um truque para otimizar o processamento, pois
				 * eu sei que h� mais dias da semana do que s�bados e dom-
				 * ingos. Logo, para otimizar, basta contar os finais de
				 * semana, que na condi��o, apenas eles ser�o processados
				 */
				if ((dataInicial.plusDays(contador).getDayOfWeek() == DayOfWeek.SATURDAY) ||
					(dataInicial.plusDays(contador).getDayOfWeek() == DayOfWeek.SUNDAY)) {
							contadorDiasFinaisSemana++;
				}
			}
			contadorDiasUteis = quantidadeDias - contadorDiasFinaisSemana;
			
			return contadorDiasUteis;
		} else if (dataInicial.isAfter(dataFinal)) {
			System.out.println("Opa! Vimos isso da�");
			System.out.println("Para n�o te frustrar, vamos calcular em ordem inversa");
			
			quantidadeDias = (int) dataFinal.until(dataInicial, ChronoUnit.DAYS) + 1;
			
			for (int contador = 0; contador < quantidadeDias; contador++) {
				if ((dataInicial.minusDays(contador).getDayOfWeek() == DayOfWeek.SATURDAY) ||
					(dataInicial.minusDays(contador).getDayOfWeek() == DayOfWeek.SUNDAY)) {
							contadorDiasFinaisSemana++;
				}
			}
			
			contadorDiasUteis = quantidadeDias - contadorDiasFinaisSemana;
		} else {
			System.out.println("Desculpa, n�o conseguimos identificar esse per�odo.");
			contadorDiasUteis = 0;
		}
		
		return contadorDiasUteis;
	}
}