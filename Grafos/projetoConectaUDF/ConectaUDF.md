# Caderno do Estudante
# Projeto ConectaUDF: redes sociais com grafos
**Disciplina:** Algoritmos / Matemática Discreta / Ciência de Dados

## 1. O desafio
Você faz parte da equipe que analisa a rede social fictícia **ConectaUDF**. Sua missão é representar as amizades em um grafo, realizar cálculos e usar Python para interpretar a estrutura da rede.

## 2. Conceitos essenciais
- **Vértice (ou nó):** representa um usuário.
- **Aresta:** representa uma amizade entre dois usuários.
- **Grau:** quantidade de conexões diretas de um usuário.
- **Caminho:** sequência de usuários em que cada par consecutivo está conectado.
- **Densidade:** proporção entre as amizades existentes e todas as amizades possíveis.

Neste projeto, a amizade é recíproca. Portanto, usamos um **grafo não direcionado**.

## 3. Conheça os usuários
| Código | Usuário |
|---|---|
| A | Ana |
| B | Bruno |
| C | Carla |
| D | Diego |
| E | Elisa |
| F | Felipe |

As amizades são:
1. Ana — Bruno
2. Ana — Carla
3. Bruno — Carla
4. Bruno — Diego
5. Carla — Elisa
6. Diego — Elisa
7. Diego — Felipe
8. Elisa — Felipe

## 4. Desenho do grafo

<img width="362" height="212" alt="image" src="https://github.com/user-attachments/assets/da510a9f-e959-44bd-8c09-c12793f28c81" />

## 5. Passo a passo: calcule o grau
Conte quantas linhas chegam a cada círculo. Registre o resultado.

| Usuário | Amigos diretos | Grau |
|---|---|---|
| Ana | Bruno e Carla | 2 |
| Bruno | Ana, Carla e Diego  | 3 |
| Carla | Ana, Bruno e Elisa | 3 |
| Diego | Bruno, Elisa e Felipe | 3 |
| Elisa | Carla, Diego e Felipe | 3 |
| Felipe | Diego e Elisa | 2 |

**Pergunta 1:** quem tem mais conexões diretas?  
Resposta: Bruno, Carla, Diego e Elisa possuem 3 conexões diretas

## 6. Passo a passo: calcule o número de amizades
Some todos os graus. Como cada amizade conecta dois usuários, cada aresta é contada duas vezes.

**Fórmula:**  
`Número de arestas = soma dos graus ÷ 2`

1. Soma dos graus: 16
2. Divida por 2: 16 ÷ 2 = 8
3. Quantas amizades existem no grafo? 8

## 7. Passo a passo: calcule a densidade
A densidade compara as amizades existentes com o total de amizades possíveis.

Para um grafo simples não direcionado:

`D = 2 × E / (V × (V − 1))`

Em que:
- `D` = densidade;
- `E` = número de arestas;
- `V` = número de vértices.

Substitua os valores:
`D = 2 × 8 / (6 × (6 − 1))`

Resultado decimal: 0,53333  
Resultado percentual: 53,33 %

**Interprete:** a rede tem poucas ou muitas das conexões possíveis? Possuem uma quantidade razoável, pois podemos ter muito mais conexões, visto que possuem 6 vértices, portanto, considerando o máximo de conexões possíveis entre todos os amigos, essa rede possui um valor razoável.

________________________________________________________________

## 8. Passo a passo: represente o grafo em Python
A lista de adjacência registra, para cada usuário, os nomes de seus amigos. Digite o código em Python (por exemplo, no Google Colab ou em outro ambiente disponível).

```python
rede = {
    "Ana": ["Bruno", "Carla"],
    "Bruno": ["Ana", "Carla", "Diego"],
    "Carla": ["Ana", "Bruno", "Elisa"],
    "Diego": ["Bruno", "Elisa", "Felipe"],
    "Elisa": ["Carla", "Diego", "Felipe"],
    "Felipe": ["Diego", "Elisa"]
}

# Quantidade de usuarios
n = len(rede)

# Calcule o grau de cada usuario
for usuario, amigos in rede.items():
    print(usuario, "tem", len(amigos), "conexoes")

# A soma dos graus conta cada amizade duas vezes
soma_graus = sum(len(amigos) for amigos in rede.values())
arestas = soma_graus // 2

print("Total de usuarios:", n)
print("Total de amizades:", arestas)

# Densidade do grafo
densidade = (2 * arestas) / (n * (n - 1))
print(f"Densidade: {densidade:.2%}")
```

### Entenda o código
1. `rede` guarda os usuários e suas listas de amigos.
2. `len(rede)` conta os usuários.
3. `len(amigos)` calcula o grau de cada usuário.
4. `sum(...)` soma os graus.
5. `// 2` divide a soma por dois para contar cada amizade uma única vez.
6. A fórmula final calcula a densidade.

## 9. Passo a passo: encontre um caminho
Encontre um caminho de Ana até Felipe. Cada passagem por uma linha corresponde a uma aresta.

Exemplo de registro:
`Ana → Carla → Elisa → Felipe`

- Quantas arestas há no caminho? 3
- Você encontrou outro caminho com a mesma quantidade de arestas? Qual? Sim, o caminho `Ana → Bruno → Diego → Felipe`.

________________________________________________________________

## 10. Desafio em grupo
Amplie a rede social:
1. Adicione pelo menos quatro usuários fictícios = Criei Gabriela, Heitor, Iago e Janaina
2. Crie no mínimo cinco novas amizades.
3. Atualize a lista de adjacência no Python.
4. Recalcule os graus, o total de arestas e a densidade.
5. Compare a densidade antes e depois da ampliação.
6. Identifique os usuários com mais conexões.
7. Explique como a rede poderia recomendar uma nova amizade.

## 11. Entrega
Entregue:
- desenho do grafo:
  
  <img width="362" height="452" alt="image" src="https://github.com/user-attachments/assets/51ef3662-9df8-41b5-b706-2c4395b037d8" />

- tabela com os graus;
- cálculos de arestas e densidade:
    - Arestas: Somar todos os graus e dividir por 2: (3+4+4+3+3+4+2+1+4+2) / 2 = 30/2 = 10
    - Densidade:  2*15 / [10 x (10 - 1)] = 30 / 90 = 0,333333 ou 33,3333%
- código Python executável:
```python
rede = {
    "Ana": ["Bruno", "Carla", "Gabriela"],
    "Bruno": ["Ana", "Carla", "Diego", "Gabriela"],
    "Carla": ["Ana", "Bruno", "Elisa", "Iago"],
    "Diego": ["Bruno", "Elisa", "Felipe"],
    "Elisa": ["Carla", "Diego", "Felipe"],
    "Felipe": ["Diego", "Elisa", "Iago", "Janaina"],
    "Gabriela": ["Ana", "Bruno"],
    "Heitor": ["Iago"],
    "Iago": ["Carla", "Felipe", "Heitor", "Janaina"],
    "Janaina": ["Felipe", "Iago"]
}

# Quantidade de usuarios
n = len(rede)

# Calcule o grau de cada usuario
for usuario, amigos in rede.items():
    print(usuario, "tem", len(amigos), "conexoes")

# A soma dos graus conta cada amizade duas vezes
soma_graus = sum(len(amigos) for amigos in rede.values())
arestas = soma_graus // 2

print("Total de usuarios:", n)
print("Total de amizades:", arestas)

# Densidade do grafo
densidade = (2 * arestas) / (n * (n - 1))
print(f"Densidade: {densidade:.2%}")
```
4. Recalcule os graus, o total de arestas e a densidade.
    | - | Arestas | Densidade |
    |---|---|---|
    | Antiga | 8 | 53,33% |
    | Nova | 15  | 33,33% |
5. Compare a densidade antes e depois da ampliação. A densidade possui niveis mais elevados antes da alteração, muito por conta do aumento das ligações e variações entre si, antes era de 53,33% e agora de 33,33%
6. Identifique os usuários com mais conexões = Bruno, Carla, Felipe e Iago possuem 4 conexões.
7. Explique como a rede poderia recomendar uma nova amizade = A rede pode indicar amizades por meio de amizades em comum, por exemplo, Iago e Eliza, possuem dois amigos em comum, porém não são amigos, portanto a rede poderia indicar essa amiade.

## 12. Pergunta de reflexão
Duas pessoas ainda não são amigas, mas têm três amigos em comum. Como essa informação poderia ser usada para sugerir uma nova conexão? Quais cuidados de privacidade devem ser considerados ao analisar redes sociais?

Sim, poderia ser usado. xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
