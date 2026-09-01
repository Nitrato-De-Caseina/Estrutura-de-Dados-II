# Resolução dos Exercícios - Aula 03: Ponteiros, Referências e Estruturas Dinâmicas em Python

Este documento contém a resolução completa e detalhada de todos os exercícios propostos no final da Aula 03, incluindo os exercícios conceituais, de depuração e o sistema completo de atendimento da clínica com o desafio de atendimento prioritário implementado.

---

## 1. Exercício 1 — Referências

### Contexto do Exercício
Considerando um cenário clássico de manipulação de referências em Python:
```python
a = [10, 20, 30]
b = a
b.append(40)
```

### Respostas:

1. **Qual será a saída ao exibir as variáveis a e b?**
   * **Saída:**
     ```python
     print(a)  # Saída: [10, 20, 30, 40]
     print(b)  # Saída: [10, 20, 30, 40]
     ```

2. **a e b representam o mesmo objeto?**
   * **Sim.** Ambas as variáveis apontam para o mesmo e único objeto do tipo lista na memória.

3. **Por quê?**
   * Em Python, a atribuição b = a não cria uma cópia dos dados da lista; ela apenas copia a **referência** (o endereço de memória) do objeto associado à variável a. Como as duas variáveis compartilham a mesma referência, qualquer alteração feita no objeto por meio de uma delas (como o método .append(), visto que listas são objetos mutáveis) será refletida ao acessar a outra. Se utilizarmos a função id(a) e id(b), veremos que ambos os identificadores de memória são idênticos.

4. **O que aconteceria com b = a.copy()?**
   * Se utilizarmos b = a.copy(), o Python realizará uma **cópia rasa** (*shallow copy*) da lista. Isso cria um **novo objeto lista na memória** contendo os mesmos elementos originais. Nesse caso:
     * id(a) seria diferente de id(b).
     * Se adicionarmos um elemento a b (ex: b.append(40)), apenas b seria alterado (ficando [10, 20, 30, 40]), enquanto a permaneceria intacto ([10, 20, 30]).

---

## 2. Exercício 2 — Construindo uma cadeia

### Implementação do Código
Abaixo está o código completo que cria a classe de nó (Node), conecta três nós de maneira encadeada e realiza o percurso para exibir a estrutura.

```python
class Node:
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None  # Referência para o próximo nó da cadeia

# 1. Criando os nós individuais
no1 = Node("A")
no2 = Node("B")
no3 = Node("C")

# 2. Conectando os nós (Cadeia: A -> B -> C)
no1.proximo = no2
no2.proximo = no3

# 3. Percorrendo a estrutura e gerando a saída formatada
atual = no1
elementos = []

while atual is not None:
    elementos.append(str(atual.valor))
    atual = atual.proximo

# Produzindo a saída visual da cadeia
saida = " -> ".join(elementos)
print(saida)
```

### Saída produzida:
```text
A -> B -> C
```

---

## 3. Exercício 3 — Depuração

### Análise do Código com Erro
No código de travessia original, o programa entrava em loop infinito ao tentar percorrer uma sequência de nós.

### Respostas:

1. **Qual é o problema?**
   * O loop while entra em um estado de **loop infinito**, executando indefinidamente e travando o programa.

2. **Por que o programa não termina?**
   * Porque a variável de controle do loop (atual) nunca é atualizada dentro do escopo do bloco while. Como o seu valor inicial (o primeiro nó) não é nulo (None), a condição while atual is not None permanece verdadeira (True) para sempre.

3. **Qual linha deve ser acrescentada para corrigir o erro?**
   * Deve ser acrescentada a linha de avanço de ponteiro/referência dentro do bloco while:
     ```python
     atual = atual.proximo
     ```

4. **Qual será a saída depois da correção?**
   * O loop imprimirá com sucesso o valor de cada nó sequencialmente e terminará assim que o ponteiro atual receber o valor None (indicando o fim da cadeia):
     ```text
     A
     B
     C
     ```

---

## 4. Problema Real — Sistema de Atendimento de uma Clínica

Esta seção apresenta a modelagem completa e funcional do sistema de atendimento solicitado, implementado em Python puro utilizando estruturas encadeadas.

### Funcionalidades do Código:
* **Classe Paciente:** Modela os dados de cada paciente (nome, idade e prioridade).
* **Classe Node:** Modela os nós da estrutura de dados dinâmica, encapsulando um paciente e apontando para o próximo nó.
* **Classe FilaAtendimento:** Gerencia a estrutura dinâmica, implementando os métodos obrigatórios: adicionar(), atender(), listar(), esta_vazia() e tamanho().
* **Desafio - Atendimento Prioritário Integrado:** Pacientes prioritários (com prioridade=True) são automaticamente posicionados à frente dos pacientes normais na fila. Para garantir a justiça no atendimento, a ordem cronológica de chegada é mantida rigorosamente dentro de cada grupo de prioridade (os prioritários mais antigos ficam antes dos prioritários mais novos, e todos ficam antes dos normais).

### Código Completo (Python)

```python
class Paciente:
    def __init__(self, nome, idade, prioridade):
        self.nome = nome
        self.idade = idade
        self.prioridade = prioridade  # True para prioritário, False para normal

    def __str__(self):
        status = "Prioritário" if self.prioridade else "Normal"
        return f"{self.nome} ({self.idade} anos) - Status: {status}"


class Node:
    def __init__(self, paciente):
        self.paciente = paciente
        self.proximo = None  # Referência para o próximo nó


class FilaAtendimento:
    def __init__(self):
        self.inicio = None
        self._tamanho = 0

    def esta_vazia(self):
        """Retorna True se a fila estiver vazia, False caso contrário."""
        return self.inicio is None

    def tamanho(self):
        """Retorna a quantidade de pacientes na fila."""
        return self._tamanho

    def adicionar(self, paciente):
        """
        Adiciona um paciente na fila respeitando as seguintes regras:
        - Se for normal, entra no final da fila.
        - Se for prioritário, passa à frente de todos os normais,
          mas se posiciona atrás de outros prioritários que chegaram antes.
        """
        novo_no = Node(paciente)
        self._tamanho += 1

        # Caso 1: Fila vazia
        if self.esta_vazia():
            self.inicio = novo_no
            return

        # Caso 2: Paciente é prioritário (Desafio de Atendimento Prioritário)
        if paciente.prioridade:
            # Se o primeiro paciente da fila já for normal, o prioritário assume o início
            if not self.inicio.paciente.prioridade:
                novo_no.proximo = self.inicio
                self.inicio = novo_no
            else:
                # Caminha pela fila enquanto houver nós prioritários
                atual = self.inicio
                while atual.proximo is not None and atual.proximo.paciente.prioridade:
                    atual = atual.proximo
                # Insere o novo nó prioritário após o último prioritário encontrado
                novo_no.proximo = atual.proximo
                atual.proximo = novo_no
        
        # Caso 3: Paciente é normal
        else:
            # Caminha até o final da fila e insere o nó lá
            atual = self.inicio
            while atual.proximo is not None:
                atual = atual.proximo
            atual.proximo = novo_no

    def atender(self):
        """Remove e retorna o primeiro paciente da fila."""
        if self.esta_vazia():
            print("Fila vazia! Nenhum paciente para atender.")
            return None
        
        no_atendido = self.inicio
        self.inicio = self.inicio.proximo
        self._tamanho -= 1
        return no_atendido.paciente

    def listar(self):
        """Exibe todos os pacientes na fila em ordem de atendimento."""
        if self.esta_vazia():
            print("Fila vazia.")
            return
        
        atual = self.inicio
        posicao = 1
        while atual is not None:
            print(f"  {posicao}º Lugar: {atual.paciente}")
            atual = atual.proximo
            posicao += 1


# --- Simulação e Teste Prático (conforme o checklist) ---
if __name__ == "__main__":
    print("=== INICIALIZANDO FILA DE ATENDIMENTO CLINICO ===\n")
    fila = FilaAtendimento()
    
    # Criando 5 pacientes com diferentes prioridades e idades
    p1 = Paciente("João Silva", 35, False)     # Normal
    p2 = Paciente("Maria Souza", 72, True)     # Prioritário (Idosa)
    p3 = Paciente("Carlos Santos", 19, False)   # Normal
    p4 = Paciente("Ana Oliveira", 65, True)    # Prioritário (Idosa)
    p5 = Paciente("Pedro Lima", 28, False)     # Normal

    # Adicionando-os na fila sequencialmente
    print("Inserindo pacientes na fila...")
    fila.adicionar(p1)  # Entra João (Normal)
    fila.adicionar(p2)  # Entra Maria (Prioritária) -> Passa à frente de João
    fila.adicionar(p3)  # Entra Carlos (Normal) -> Vai para o fim
    fila.adicionar(p4)  # Entra Ana (Prioritária) -> Passa à frente de João e Carlos (atrás de Maria)
    fila.adicionar(p5)  # Entra Pedro (Normal) -> Vai para o fim
    
    print(f"\nTotal de pacientes aguardando: {fila.tamanho()}")
    
    print("\n--- Lista de Espera em Ordem de Chamada ---")
    fila.listar()
    
    print("\n--- Iniciando os Atendimentos ---")
    while not fila.esta_vazia():
        paciente_atendido = fila.atender()
        print(f"Chamando: {paciente_atendido}")
        print(f"  [Pacientes restantes na fila: {fila.tamanho()}]")
        print("-" * 50)
```

### Saída Esperada da Simulação:
```text
=== INICIALIZANDO FILA DE ATENDIMENTO CLINICO ===

Inserindo pacientes na fila...

Total de pacientes aguardando: 5

--- Lista de Espera em Ordem de Chamada ---
  1º Lugar: Maria Souza (72 anos) - Status: Prioritário
  2º Lugar: Ana Oliveira (65 anos) - Status: Prioritário
  3º Lugar: João Silva (35 anos) - Status: Normal
  4º Lugar: Carlos Santos (19 anos) - Status: Normal
  5º Lugar: Pedro Lima (28 anos) - Status: Normal

--- Iniciando os Atendimentos ---
Chamando: Maria Souza (72 anos) - Status: Prioritário
  [Pacientes restantes na fila: 4]
--------------------------------------------------
Chamando: Ana Oliveira (65 anos) - Status: Prioritário
  [Pacientes restantes na fila: 3]
--------------------------------------------------
Chamando: João Silva (35 anos) - Status: Normal
  [Pacientes restantes na fila: 2]
--------------------------------------------------
Chamando: Carlos Santos (19 anos) - Status: Normal
  [Pacientes restantes na fila: 1]
--------------------------------------------------
Chamando: Pedro Lima (28 anos) - Status: Normal
  [Pacientes restantes na fila: 0]
--------------------------------------------------
```

---

## 5. Documentação de Erro Encontrado e sua Correção (Requisito do Checklist)

Durante o desenvolvimento de estruturas de dados dinâmicas como a FilaAtendimento, é comum cometer erros relacionados à atualização das referências. 

### Erro Comum de Referência Nula (NullPointerException / AttributeError)
* **O Erro:** Ao implementar o método adicionar para pacientes prioritários, uma primeira tentativa de código poderia omitir a verificação se o próximo nó existe antes de acessar seus atributos.
  ```python
  # Trecho com Bug
  atual = self.inicio
  while atual.paciente.prioridade:  # E se 'atual' for None ou o próximo for None?
      atual = atual.proximo
  ```
  Isso causaria o erro AttributeError: 'NoneType' object has no attribute 'paciente' quando a fila estivesse vazia ou quando percorrêssemos a lista até o último elemento.
* **A Correção:** Sempre garantir que o ponteiro que está sendo avaliado (atual ou atual.proximo) não é None antes de tentar acessar suas propriedades, garantindo a integridade física da estrutura dinâmica de nós na memória:
  ```python
  # Trecho Corrigido
  atual = self.inicio
  while atual.proximo is not None and atual.proximo.paciente.prioridade:
      atual = atual.proximo
  ```
