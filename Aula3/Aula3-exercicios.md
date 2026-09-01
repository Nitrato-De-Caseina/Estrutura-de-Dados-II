Exercícios de Estruturas de Dados e Referências em Python

Exercício 1 — Referências

Considerando o código fornecido:
a = [10, 20, 30]
b = a
b.append(40)

1. Qual será a saída?
A saída ao imprimir a será [10, 20, 30, 40].
A saída ao imprimir b será [10, 20, 30, 40].
O id(a) e id(b) terão exatamente o mesmo valor, por exemplo: <endereço de memória X>.

2. a e b representam o mesmo objeto?
Sim.

3. Por quê?
Em Python, quando fazemos a atribuição b = a, não estamos duplicando a lista ou gerando um novo objeto na memória. Estamos apenas associando um novo rótulo (variável b) ao mesmo objeto lista que a já referenciava. Como as listas são mutáveis, modificações feitas a partir de qualquer uma das variáveis alteram o mesmo objeto compartilhado.

4. O que aconteceria com b = a.copy()?
Se fosse utilizado o método copy, o Python criaria uma nova lista independente na memória com os mesmos elementos iniciais. Nesse cenário, alterar b adicionando o número 40 não alteraria a lista original a. O id de a e o id de b passariam a ser diferentes, e a saída ao imprimir a seria [10, 20, 30], enquanto b seria [10, 20, 30, 40].


Exercício 2 — Construindo uma cadeia

Código de implementação e conexão dos nós:

class Elemento:
    def __init__(self, dado):
        self.dado = dado
        self.proximo = None

no_a = Elemento("A")
no_b = Elemento("B")
no_c = Elemento("C")

no_a.proximo = no_b
no_b.proximo = no_c

auxiliar = no_a
registro_valores = []

while auxiliar is not None:
    registro_valores.append(str(auxiliar.dado))
    auxiliar = auxiliar.proximo

print(" -> ".join(registro_valores))


Exercício 3 — Depuração

1. Qual é o problema?
O código entra em um loop infinito.

2. Por que o programa não termina?
O ponteiro auxiliar atual nunca avança para o próximo elemento dentro do loop while. Como o primeiro nó é diferente de None, a condição while atual is not None é sempre verdadeira, fazendo o loop rodar indefinidamente.

3. Qual linha deve ser acrescentada?
Deve ser adicionada a linha atual = atual.proximo dentro do bloco while.

4. Qual será a saída depois da correção?
A saída mostrará o valor de cada nó em linhas separadas:
A
B
C


Exercício de revisão e desafio — Sistema de atendimento clínico

Código completo:

class CadastroPaciente:
    def __init__(self, nome, idade, preferencial):
        self.nome = nome
        self.idade = idade
        self.preferencial = preferencial

    def __str__(self):
        grupo = "Prioritário" if self.preferencial else "Comum"
        return f"{self.nome} ({self.idade} anos) - [{grupo}]"


class CelulaFila:
    def __init__(self, paciente):
        self.paciente = paciente
        self.proximo = None


class FilaAtendimentoClinica:
    def __init__(self):
        self.cabeca = None
        self.contagem = 0

    def esta_vazia(self):
        return self.cabeca is None

    def tamanho(self):
        return self.contagem

    def adicionar(self, paciente):
        nova_celula = CelulaFila(paciente)
        self.contagem += 1

        if self.esta_vazia():
            self.cabeca = nova_celula
            return

        if paciente.preferencial:
            if not self.cabeca.paciente.preferencial:
                nova_celula.proximo = self.cabeca
                self.cabeca = nova_celula
            else:
                navegador = self.cabeca
                while navegador.proximo is not None and navegador.proximo.paciente.preferencial:
                    navegador = navegador.proximo
                nova_celula.proximo = navegador.proximo
                navegador.proximo = nova_celula
        else:
            navegador = self.cabeca
            while navegador.proximo is not None:
                navegador = navegador.proximo
            navegador.proximo = nova_celula

    def atender(self):
        if self.esta_vazia():
            print("Não existem pacientes na fila.")
            return None
        celula_chamada = self.cabeca
        self.cabeca = self.cabeca.proximo
        self.contagem -= 1
        return celula_chamada.paciente

    def listar(self):
        if self.esta_vazia():
            print("Fila vazia.")
            return
        navegador = self.cabeca
        indice = 1
        while navegador is not None:
            print(f"  {indice}º: {navegador.paciente}")
            navegador = navegador.proximo
            indice += 1


if __name__ == "__main__":
    gerenciador = FilaAtendimentoClinica()
    pacientes_cadastro = [
        CadastroPaciente("João Silva", 35, False),
        CadastroPaciente("Maria Souza", 72, True),
        CadastroPaciente("Carlos Santos", 19, False),
        CadastroPaciente("Ana Oliveira", 65, True),
        CadastroPaciente("Pedro Lima", 28, False)
    ]

    for pac in pacientes_cadastro:
        gerenciador.adicionar(pac)

    print("Total de pacientes na fila:", gerenciador.tamanho())
    print("Ordem de atendimento:")
    gerenciador.listar()

    print("\nIniciando atendimento:")
    while not gerenciador.esta_vazia():
        atendido = gerenciador.atender()
        print("Atendendo:", atendido)


Erro documentado e sua correção:
Ao escrever o loop para inserir pacientes prioritários na posição correta, a verificação direta navegador.proximo.paciente.preferencial causava um erro AttributeError quando a busca chegava ao final da fila, pois navegador.proximo era None. Para corrigir o problema, foi adicionada a verificação navegador.proximo is not None antes de testar as propriedades do paciente do próximo nó, garantindo que o programa termine a busca sem interrupções.
