package trabalhandoComScanner;

import java.util.Scanner;

public class scannerTestes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        sc.nextLine();
        String linha = sc.nextLine();

        System.out.println(x);
        System.out.println(linha);
    }
}
