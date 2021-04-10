
public class TesteSimplesAutomovel {
	
	public static void main(String[] args) {
		Automovel meuCarro = new Automovel();
		meuCarro.modelo = "Gol";
		meuCarro.cor = "Azul";
		
		meuCarro.acelerar();
		
		Automovel outroCarro = new Automovel();
		outroCarro.modelo = "Gol";
		outroCarro.cor = "Azul";
		
		outroCarro.acelerar();
		outroCarro.acelerar();
		
		System.out.println(meuCarro.velocidade);
		System.out.println(outroCarro.velocidade);
	}
	
}
