package trabalhandoComInterface;

public class TesteInterfacePagamentos {
    public static void main(String[] args) {
        Pagavel objetosPagaveis[] = new Pagavel[4];

        objetosPagaveis[0] = new Conta("123-4","relogio",1,5.50);
        objetosPagaveis[1] = new Conta("234-5","papeis",50,0.90);
        objetosPagaveis[2] = new EmpregadoAssalariado("Steffano","Pereira","123456789",
                                                    400);
        objetosPagaveis[3] = new EmpregadoAssalariado("Pereira","Steffano","987654321",
                                                    004);

        System.out.println("Contas e Empregados:");

        for (Pagavel p : objetosPagaveis) {
            System.out.printf("%s \n %s: R$%,.2f\n\n",p.toString(),"Pagamento",p.getValorPagamento());
        }
    }
}
