
public class Automovel {
	
	String cor;
	String modelo;
	boolean ligado;
	int velocidade;
	
	Automovel() {
		cor = "Azul";
		modelo = "Fusca";
		ligado = false;
		velocidade = 0;
	}
	
	void ligar() {
		ligado = true;
	}
	
	void acelerar() {
		velocidade += 10;
	}
	
	void frear() {
		velocidade -= 10;
	}
	
}

