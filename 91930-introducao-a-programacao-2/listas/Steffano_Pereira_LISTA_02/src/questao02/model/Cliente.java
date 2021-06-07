package questao02.model;

import java.time.LocalDate;

public class Cliente extends Pessoa {
    private long codigo;

    public Cliente (String nome, LocalDate dataNascimento, long codigo) {
        super(nome,dataNascimento);
        this.setCodigo(codigo);
    }

    @Override
    public String toString() {
        return String.format("%s\n%s: %d",super.toString(),"Código",this.getCodigo());
    }

    @Override
    public boolean equals(Object objCliente) {
        if (this == objCliente) return true;
        if (!(objCliente instanceof Cliente)) return false;
        if (!super.equals(objCliente)) return false;

        Cliente cliente = (Cliente) objCliente;
        return this.codigo == cliente.codigo;
    }

    public long getCodigo() {
        return codigo;
    }

    public void setCodigo(long codigo) {
        if (codigo != 0) this.codigo = codigo;
    }
}
