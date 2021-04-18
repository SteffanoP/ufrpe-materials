package montandoClassesDeDiagramaUML;

public class Carro {
    //Atributos
    private String cor;
    private String modelo;
    private int velocidadeAtual;
    private boolean ligado;
    private Proprietario proprietario;

    //Construtores
    public Carro () {
        this.velocidadeAtual = 0;
        this.ligado = false;
    }

    public Carro(String cor, String modelo) {
        this.cor = cor;
        this.modelo = modelo;
        this.velocidadeAtual = 0;
        this.ligado = false;
    }

    public Carro(String cor, String modelo, Proprietario proprietario) {
        this.cor = cor;
        this.modelo = modelo;
        this.proprietario = proprietario;
        this.velocidadeAtual = 0;
        this.ligado = false;
    }

    //Métodos
    public void ligar() {
        this.ligado = true;
    }

    public void acelerar() {
        this.velocidadeAtual += 10;
    }

    public void frear() {
        this.velocidadeAtual -= 10;
    }

    public void mostrarPainel() {
        //sem ideia do que seja isso
    }

    public void desligar() {
        this.ligado = false;
    }

    public void vincularProprietario(Proprietario proprietario) {
        this.proprietario = proprietario;
    }

    //Getters/Setters

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getVelocidadeAtual() {
        return velocidadeAtual;
    }

    public void setVelocidadeAtual(int velocidadeAtual) {
        this.velocidadeAtual = velocidadeAtual;
    }
}
