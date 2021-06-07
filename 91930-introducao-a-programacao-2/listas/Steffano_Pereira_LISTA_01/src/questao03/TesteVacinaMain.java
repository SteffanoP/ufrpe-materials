package questao03;

import java.time.LocalDate;

public class TesteVacinaMain {

	public static void main(String[] args) {
		
		//Instanciar as pessoas
		Pessoa joseMaria = new Pessoa("Jose Maria","0333787383", "IDOSOS", LocalDate.of(1954, 1, 1));
		Pessoa mariaJose = new Pessoa("Maria Jose","3830333787", "IDOSOS", LocalDate.of(1952, 1, 1));
		Pessoa joseSilva = new Pessoa("Jose Silva","7870333383", "IDOSOS", LocalDate.of(1950, 1, 1));
		Pessoa mariaSilva = new Pessoa("Maria Silva","3787303383", "IDOSOS", LocalDate.of(1955, 1, 1));
		//Pessoas Extras
		Pessoa mariaAnunciada = new Pessoa("Maria Anunciada","7894651234", "IDOSOS", LocalDate.of(1930, 8, 13));
		Pessoa mariaDosAnjos = new Pessoa("Maria dos Anjos","5468948975", "IDOSOS", LocalDate.of(1947, 8, 1));
		
		//Instanciar as vacinas
		Vacina coronavac = new Vacina(1,"CORONAVAC","0001");
		Vacina oxford = new Vacina(2,"OXFORD","0001"); //Boatos que essa vacina não conseguiu vacinar nem 10% dos pernambucanos
		
		//Instanciar RegistroVacina
		RegistroVacina joseMariaCoronavac1Dose = new RegistroVacina("001", LocalDate.of(2021, 4, 22), "Ângela", 1, joseMaria.getGrupo());
		joseMariaCoronavac1Dose.setVacinacao(coronavac, joseMaria);
		joseMariaCoronavac1Dose.setLocal("DRIVE THRU - UFRPE - UNIVERSIDADE RURAL");
		RegistroVacina mariaJoseCoronavac1Dose = new RegistroVacina("002", LocalDate.of(2021, 4, 25), "Ângela", 1, mariaJose.getGrupo());
		mariaJoseCoronavac1Dose.setVacinacao(coronavac, mariaJose);
		RegistroVacina joseSilvaCoronavac1Dose = new RegistroVacina("003", LocalDate.of(2021, 4, 24), "Ângela", 1, joseSilva.getGrupo());
		joseSilvaCoronavac1Dose.setVacinacao(coronavac, joseSilva);
		RegistroVacina mariaSilvaCoronavac1Dose = new RegistroVacina("004", LocalDate.of(2021, 4, 30), "Ângela", 1, mariaSilva.getGrupo());
		mariaSilvaCoronavac1Dose.setVacinacao(coronavac, mariaSilva);
		//Extras:
		RegistroVacina mariaAnunciadaOxford1Dose = new RegistroVacina("005", LocalDate.of(2021, 1, 28), "Rosalinda", 1, mariaAnunciada.getGrupo());
		mariaAnunciadaOxford1Dose.setVacinacao(oxford, mariaAnunciada);
		RegistroVacina mariaDosAnjosCoronavac1Dose = new RegistroVacina("006", LocalDate.of(2021, 4, 1), "Ângela", 1, mariaDosAnjos.getGrupo());
		mariaDosAnjosCoronavac1Dose.setVacinacao(coronavac, mariaDosAnjos);
		//2ª Dose:
		RegistroVacina mariaDosAnjosCoronavac2Dose = new RegistroVacina("007", LocalDate.of(2021, 4, 22), "Ângela", 2, mariaDosAnjos.getGrupo());
		mariaDosAnjosCoronavac2Dose.setVacinacao(coronavac, mariaDosAnjos);

		
		//Instanciar RelacaoVacinados
		RelacaoVacinados relacao = new RelacaoVacinados();
		relacao.adicionar(joseMariaCoronavac1Dose);
		relacao.adicionar(mariaJoseCoronavac1Dose);
		relacao.adicionar(joseSilvaCoronavac1Dose);
		relacao.adicionar(mariaSilvaCoronavac1Dose);
		relacao.adicionar(mariaAnunciadaOxford1Dose);
		relacao.adicionar(mariaDosAnjosCoronavac1Dose);
		relacao.adicionar(mariaDosAnjosCoronavac2Dose);
		
		relacao.listarPessoasQueNaoTomaram2aDose();
	}

}
