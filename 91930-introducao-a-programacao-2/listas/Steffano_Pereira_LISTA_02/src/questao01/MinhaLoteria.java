package questao01;

import java.util.ArrayList;

public class MinhaLoteria {
    public static void main(String[] args) {
        BilheteLoteria bilhetePremiado = new BilheteLoteria(6);

        for (int i = 6; i <= 15; i++) {
            ArrayList<BilheteLoteria> bilhetes = new ArrayList<>();
            int qtdNumeros = 0, qtdQuadras = 0, qtdQuina = 0;
            do {
                BilheteLoteria bilheteSorteado = new BilheteLoteria(i);
                bilhetes.add(bilheteSorteado);

                qtdNumeros = bilheteSorteado.qtdNumerosContidos(bilhetePremiado);
                if (qtdNumeros == 4)
                    qtdQuadras++;
                else if (qtdNumeros == 5)
                    qtdQuina++;

                //Depuração, caso necessária:
//                System.out.printf("Sorteio de número %d realizado. O bilhete sorteado %s NÃO CONTÉM todos os números do " +
//                        "bilhete premiado %s\n",bilhetes.size(),bilheteSorteado.toString(),bilhetePremiado.toString());
            } while (!(qtdNumeros == 6));

            System.out.printf("Jogos de %2d números: você apostou %d vezes para ganhar na mega-sena. " +
                    "Dentre esses jogos, você acertou %d quadras e %d quinas.\n",i,bilhetes.size(),qtdQuadras,qtdQuina);
        }
    }
}
