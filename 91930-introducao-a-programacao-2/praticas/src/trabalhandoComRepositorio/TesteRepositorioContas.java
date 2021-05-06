package trabalhandoComRepositorio;

public class TesteRepositorioContas {
    public static void main(String[] args) {
        RepositorioContas repo = new RepositorioContas(100);

        repo.adicionarConta(new Conta("1234-5", 150.95));
        repo.adicionarConta(new Conta("6789-1", 560.80));
        repo.adicionarConta(new Conta("0123-4", 400.00));
        repo.adicionarConta(new Conta("0123-4", 450.00)); //Não adiciona

        String resultado = repo.toString();
        System.out.println(resultado);

        repo.removerConta("6789-1");

        System.out.println(repo);
    }
}
