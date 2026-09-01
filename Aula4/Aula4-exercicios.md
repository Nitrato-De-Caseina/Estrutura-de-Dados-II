#----------------------------Exercicio 1----------------------------
# Objetivo: Implementar uma Pilha (LIFO) para gerenciar o "Desfazer" de um editor de texto.

class EditorTexto:
    def __init__(self):
        self.pilha_acoes = []  # LIFO: o último comando inserido é o primeiro a ser desfeito

    def registrar_acao(self, acao):
        self.pilha_acoes.append(acao)

    def desfazer(self):
        if self.pilha_acoes:
            return self.pilha_acoes.pop()
        return None

# --- Teste do Exercício 1 ---
editor = EditorTexto()
editor.registrar_acao("digitar 'Olá'")
editor.registrar_acao("apagar 'a'")
editor.registrar_acao("substituir 'Ol' por 'Oi'")

print("Pilha de ações:", editor.pilha_acoes)
print("Desfazendo:", editor.desfazer())
print("Pilha após desfazer:", editor.pilha_acoes)


#----------------------------Exercicio 2----------------------------
# Objetivo: Implementar uma Fila (FIFO) para gerenciar o spooler de impressão.

from collections import deque

class SpoolerImpressao:
    def __init__(self):
        self.fila_impressao = deque()  # FIFO: o primeiro documento a entrar é o primeiro a ser impresso

    def adicionar_documento(self, documento):
        self.fila_impressao.append(documento)

    def imprimir(self):
        if self.fila_impressao:
            return self.fila_impressao.popleft()
        return None

# --- Teste do Exercício 2 ---
impressora = SpoolerImpressao()
impressora.adicionar_documento("Relatorio.pdf")
impressora.adicionar_documento("Trabalho_Escolar.docx")
impressora.adicionar_documento("Boleto.pdf")

print("\nFila de impressão:", list(impressora.fila_impressao))
print("Imprimindo:", impressora.imprimir())
print("Fila restante:", list(impressora.fila_impressao))


#----------------------------------------Desafio Master----------------------------------------
# Objetivo: Triagem Hospitalar usando Deque (fila de duas pontas) para gerenciar prioridades.

from collections import deque

class TriagemHospitalar:
    def __init__(self):
        self.fila_atendimento = deque()  # Deque permite inserções eficientes em ambas as extremidades

    def adicionar_paciente(self, nome, prioritario=False):
        if prioritario:
            self.fila_atendimento.appendleft(nome)  # Inserção no início (fura a fila)
        else:
            self.fila_atendimento.append(nome)  # Inserção no final (fluxo comum)

    def chamar_proximo(self):
        if self.fila_atendimento:
            return self.fila_atendimento.popleft()
        return None

# --- Teste do Desafio Master ---
hospital = TriagemHospitalar()
hospital.adicionar_paciente("Joao (Normal)", prioritario=False)
hospital.adicionar_paciente("Maria (Normal)", prioritario=False)
hospital.adicionar_paciente("Sr. Pedro (Prioritario)", prioritario=True)

print("\nFila de triagem:", list(hospital.fila_atendimento))
print("Chamando proximo:", hospital.chamar_proximo())
print("Fila de triagem atualizada:", list(hospital.fila_atendimento))
