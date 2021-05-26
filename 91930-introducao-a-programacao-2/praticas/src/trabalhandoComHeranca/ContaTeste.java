package trabalhandoComHeranca;

public class ContaTeste {
    public static void main(String[] args) {
        RepositorioContas repo = new RepositorioContas(100);
        Conta c = new Conta("123-4",500.0);
        Conta p = new Poupanca("234-5");
        Conta ce = new ContaEspecial("345-6");

        repo.addConta(c);
        repo.addConta(p);
        repo.addConta(ce);
    }
}
