## 11. Entrega
Entregue:
- desenho do grafo:
  
  <img width="657" height="590" alt="image" src="https://github.com/user-attachments/assets/c4375501-3151-4e09-98f2-29728f6fa82c" />

- tabela com os graus;

| Usuário | Amigos diretos | Grau |
|---|---|---:|
| Ana | Thiago | 1 |
| Bruno | Thiago | 1 |
| Carla | Thiago | 1 |
| Diego | Thiago | 1 |
| Elisa | Ian | 1 |
| Gabriela | Ian | 1 |
| Heitor | Ian | 1 |
| Iago | Ian | 1 |
| Janaina | Fellipe | 1 |
| Kaua | Fellipe | 1 |
| Leticia | Fellipe | 1 |
| Maria | Fellipe | 1 |
| Olga | Nicolas | 1 |
| Patricia | Nicolas | 1 |
| Queila | Nicolas | 1 |
| Renato | Nicolas | 1 |
| Felipe | Janaina, Kaua, Leticia, Maria, Ian, Nicolas, Thiago | 7 |
| Ian | Elisa, Gabriela, Heitor, Iago, Fellipe, Nicolas, Thiago | 7 |
| Nicolas | Olga, Patricia, Queila, Renato, Ian, Fellipe, Thiago | 7 |
| Thiago | Ana, Bruno, Carla, Diego, Ian, Nicolas, Fellipe | 7 |

- cálculos de arestas e densidade:
    - Arestas: Somar todos os graus e dividir por 2: (1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+7+7+7+7) / 2 = 44/2 = 22
    - Densidade:  2*22 / [20 x (20 - 1)] = 30 / 90 = 0,115789 ou 11,58%
- código Python executável:
```python
rede = {
    "Ana": ["Thiago"],
    "Bruno": ["Thiago"],
    "Carla": ["Thiago"],
    "Diego": ["Thiago"],
    "Renato": ["Nicolas"],
    "Queila": ["Nicolas"],
    "Patricia": ["Nicolas"],
    "Olga": ["Nicolas"],
    "Maria": ["Fellipe"],
    "Leticia": ["Fellipe"],
    "Kaua": ["Fellipe"],
    "Janaina": ["Fellipe"],
    "Elisa": ["Ian"],
    "Gabriela": ["Ian"],
    "Heitor": ["Ian"],
    "Iago": ["Ian"],
    "Nicolas": ["Renato", "Queila", "Patricia", "Olga", "Thiago", "Fellipe", "Ian"],
    "Thiago": ["Ana", "Bruno", "Carla", "Diego", "Nicolas", "Fellipe", "Ian"],
    "Fellipe": ["Maria", "Leticia", "Kaua", "Janaina", "Nicolas", "Thiago", "Ian"],
    "Ian": ["Elisa", "Gabriela", "Heitor", "Iago", "Nicolas", "Thiago", "Fellipe"]

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

https://colab.research.google.com/drive/1rhqPQxoTIqZbxZIyjD6SW5gUjvTRBvCa

4. Recalcule os graus, o total de arestas e a densidade.
    | - | Arestas | Densidade |
    |---|---|---|
    | Antiga | 8 | 53,33% |
    | Nova | 22  | 11,58% |
5. Compare a densidade antes e depois da ampliação. A densidade possui niveis mais elevados antes da alteração, muito por conta do aumento das ligações e variações entre si, antes era de 53,33% e agora de 11,58%
6. Identifique os usuários com mais conexões = Fellipe, Ian, Thiago e Nicolas com 7 conexões cada.
7. Explique como a rede poderia recomendar uma nova amizade = A rede pode indicar amizades por meio de amizades em comum, por exemplo, Iago e Heitor, possuem um amigo em comum (Ian), porém não são amigos, portanto a rede poderia indicar essa amizade.

## 12. Pergunta de reflexão
Duas pessoas ainda não são amigas, mas têm três amigos em comum. Como essa informação poderia ser usada para sugerir uma nova conexão? Quais cuidados de privacidade devem ser considerados ao analisar redes sociais?

Sim, essa informação poderia ser usada para recomendar uma nova amizade, pois ter três amigos em comum indica que as duas pessoas possuem relações próximas dentro da rede social. Assim, a plataforma poderia sugerir que elas se conectassem, aumentando as possibilidades de interação.

Porém, é importante respeitar a privacidade dos usuários, utilizando apenas informações autorizadas, protegendo seus dados pessoais e permitindo que cada pessoa escolha se deseja aceitar ou não as sugestões de amizade. Além disso, as informações das conexões não devem ser compartilhadas sem consentimento.
