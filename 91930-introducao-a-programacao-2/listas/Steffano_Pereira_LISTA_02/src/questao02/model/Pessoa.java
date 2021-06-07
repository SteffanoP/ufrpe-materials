package questao02.model;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public abstract class Pessoa {
    private String nome;
    private LocalDate dataNascimento;

    public Pessoa (String nome, LocalDate dataNascimento) {
        this.setNome(nome);
        this.setDataNascimento(dataNascimento);
    }

    @Override
    public String toString() {
        //Formatação da data para formato legal toString
        DateTimeFormatter formatoToString = DateTimeFormatter.ofPattern("dd/MM/YYYY");
        String strDataNascimento = dataNascimento.format(formatoToString);

        return String.format("%s: %s\n%s: %s","Pessoa",this.nome,
                                "Data de nascimento", strDataNascimento);
    }

    @Override
    public boolean equals(Object objPessoa) {
        if (this == objPessoa) return true;
        if (objPessoa == null || getClass() != objPessoa.getClass()) return false;
        Pessoa pessoa = (Pessoa) objPessoa;
        return nome.equals(pessoa.nome) && dataNascimento.equals(pessoa.dataNascimento);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome != null) this.nome = nome;
    }

    public LocalDate getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(LocalDate dataNascimento) {
        if (dataNascimento != null) this.dataNascimento = dataNascimento;
    }
}
