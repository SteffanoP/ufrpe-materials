package questao04.negocio.beans;

import java.util.Objects;

public class Loja {
    private long uid;
    private String nome;
    private String site;

    public Loja(long uid, String nome, String site) {
        this.setUid(uid);
        this.setNome(nome);
        this.setSite(site);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Loja)) return false;
        Loja loja = (Loja) o;
        return uid == loja.uid && nome.equals(loja.nome) && site.equals(loja.site);
    }

    @Override
    public int hashCode() {
        return Objects.hash(uid, nome, site);
    }

    public long getUid() {
        return uid;
    }

    public void setUid(long uid) {
        this.uid = uid;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSite() {
        return site;
    }

    public void setSite(String site) {
        this.site = site;
    }
}
