package trabalhandoComPacoteTime;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class DatasEmJava {
    public static void main(String[] args) {
        LocalDate minhaData = LocalDate.of(2021,04,15);
        System.out.println(minhaData);

        DateTimeFormatter meuFormatador = DateTimeFormatter.ofPattern("dd/MM/YYYY");
        String resultado = meuFormatador.format(minhaData);

        System.out.println(resultado);

        LocalDateTime minhaDataHora = LocalDateTime.of(2020,04,15,16,42,00);

        LocalDate dtHoje = LocalDate.now();
        LocalDate dtFeriado = LocalDate.of(2021,04,21);

        Period p = Period.between(dtHoje,dtFeriado);

        System.out.println(p.getDays());

        long v = dtHoje.until(dtFeriado, ChronoUnit.DAYS);

        System.out.println(v);
    }
}
