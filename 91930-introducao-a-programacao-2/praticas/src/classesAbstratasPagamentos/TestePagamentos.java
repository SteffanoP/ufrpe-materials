package classesAbstratasPagamentos;

public class TestePagamentos {
    public static void main(String[] args) {
        EmpregadoAssalariado joao = new EmpregadoAssalariado("João","Silva","123",500);
        EmpregadoComissionado maria = new EmpregadoComissionado("Maria","Silva","236",
                150,5);
        EmpregadoPorHora fernando = new EmpregadoPorHora("Fernando","Silva","356",
                120,8);
        EmpregadoComissionadoComBase rui = new EmpregadoComissionadoComBase("Rui","Pereira",
                "589",120,5, 800);

        System.out.println("Empregados individuais");

        System.out.printf("%s\n%s: R$%,.2f\n\n",joao,"ganhou",joao.ganhos());
        System.out.printf("%s\n%s: R$%,.2f\n\n",maria,"ganhou",maria.ganhos());
        System.out.printf("%s\n%s: R$%,.2f\n\n",fernando,"ganhou",fernando.ganhos());
        System.out.printf("%s\n%s: R$%,.2f\n\n",rui,"ganhou",rui.ganhos());
    }
}
