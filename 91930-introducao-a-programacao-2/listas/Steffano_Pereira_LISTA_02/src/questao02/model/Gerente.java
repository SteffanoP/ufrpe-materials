package questao02.model;

import java.time.LocalDate;

public class Gerente extends Funcionario {
    private String area;

    public Gerente(String nome, LocalDate dataNascimento, double salario, String area) {
        super(nome, dataNascimento, salario);
        this.setArea(area);
    }

    @Override
    public String toString() {
        return String.format("%s\n%s: %s",super.toString(),"Area",this.getArea());
    }

    @Override
    public boolean equals(Object objGerente) {
        if (this == objGerente) return true;
        if (!(objGerente instanceof Gerente)) return false;
        if (!super.equals(objGerente)) return false;

        Gerente gerente = (Gerente) objGerente;
        return this.area.equals(gerente.getArea());
    }

    public String getArea() {
        return area;
    }

    public void setArea(String area) {
        this.area = area;
    }
}
