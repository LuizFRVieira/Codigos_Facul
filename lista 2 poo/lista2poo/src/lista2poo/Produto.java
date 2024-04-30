package lista2poo;

public abstract class Produto implements Interface {
    private String nome;
    private int id;
    private float preco;

    public Produto(String nome, int id, float preco) {
        this.nome = nome;
        this.id = id;
        this.preco = preco;
    }

    public void calcularFrete() {
    }

    public void calcularPrazoEntrega() {
    }
}