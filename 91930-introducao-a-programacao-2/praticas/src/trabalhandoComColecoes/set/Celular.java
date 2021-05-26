package trabalhandoComColecoes.set;

import java.util.Comparator;
import java.util.Objects;

public class Celular {
    private String celular;
    private String iMEI;

    public Celular(String celular, String iMEI) {
        this.celular = celular;
        this.iMEI = iMEI;
    }

    /*Se x.equals(y) == true
     *  y.hashCode() == x.hashCode();
     *
     *  y.hashCode() == x.hashCode() -> não necessariamente poderá retornar true
     *
     * Se x.equals(y) == false
     *
     * Se y.hashCode != x.hashCode()
     *   x.equals(y) deverá ser false
     */

    @Override
    public int hashCode() {
        return iMEI != null ? iMEI.hashCode() : 1;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Celular)) return false;
        Celular celular1 = (Celular) o;
        return Objects.equals(celular, celular1.celular) && Objects.equals(iMEI, celular1.iMEI);
    }

    @Override
    public String toString() {
        return "Celular{" +
                "celular='" + celular + '\'' +
                ", iMEI='" + iMEI + '\'' +
                '}';
    }

    public String getCelular() {
        return celular;
    }

    public void setCelular(String celular) {
        this.celular = celular;
    }

    public String getiMEI() {
        return iMEI;
    }

    public void setiMEI(String iMEI) {
        this.iMEI = iMEI;
    }
}
