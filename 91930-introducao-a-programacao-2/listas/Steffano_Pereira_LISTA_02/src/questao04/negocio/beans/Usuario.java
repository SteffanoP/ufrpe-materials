package questao04.negocio.beans;

import java.time.LocalDate;
import java.util.Objects;

public class Usuario {
    private String nome;
    private String email; //Também UID do usuário
    private LocalDate dataNascimento;

    public Usuario(String nome, String email, LocalDate dataNascimento) {
        this.setNome(nome);
        this.setEmail(email);
        this.setDataNascimento(dataNascimento);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Usuario)) return false;
        Usuario usuario = (Usuario) o;
        return nome.equals(usuario.nome) && email.equals(usuario.email) && Objects.equals(dataNascimento, usuario.dataNascimento);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, email, dataNascimento);
    }

    @Override
    public String toString() {
        return String.format("%s",this.getNome());
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        if (email != null)
            this.email = email;
    }

    public LocalDate getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(LocalDate dataNascimento) {
        if (dataNascimento != null)
            this.dataNascimento = dataNascimento;
    }
}
