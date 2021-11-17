import java.util.ArrayList;
import java.util.List;

public class TesteEco2 {
  public static void main(String[] args) {
    String nome = args[0];
    char ultimaLetraNome = nome.charAt(nome.length() - 1);
    String sobrenome = args[1];
    char ultimaLetraSobrenome = sobrenome.charAt(sobrenome.length() - 1);
    
    List<Object> roteiro = new ArrayList<>();
    roteiro.add(nome);
    roteiro.add(ultimaLetraNome);
    roteiro.add(ultimaLetraNome);
    roteiro.add(ultimaLetraNome);
    roteiro.add(" ");
    roteiro.add(sobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);

    roteiro.forEach(System.out::print);
  }
}