#----------------------------Exercicio 1----------------------------
# Implementação de uma Pilha (LIFO) para o Simulador de "Desfazer" (Undo) no Editor de Texto.
# O último comando registrado é sempre o primeiro a ser removido/desfeito.

class SimuladorDesfazer:
    def __init__(self):
        # A lista nativa do Python é usada como pilha devido à eficiência do append() e pop() no final.
        self.historico = []

    def registrar_acao(self, acao: str):
        # Empilha a ação executada no topo da pilha
        self.historico.append(acao)

    def desfazer(self):
        # Remove e retorna a última ação (topo da pilha)
        if len(self.historico) == 0:
            return "Nenhuma ação para desfazer."
        return self.historico.pop()


### --- Teste do Exercício 1 ---
if __name__ == "__main__":
    editor = SimuladorDesfazer()
    
    # Registrando ações
    editor.registrar_acao("Digitar texto 'Olá Mundo'")
    editor.registrar_acao("Aplicar negrito")
    editor.registrar_acao("Apagar palavra 'Mundo'")
    
    print("Histórico antes de desfazer:", editor.historico)
    
    # Executando operações de desfazer
    print("Desfeito:", editor.desfazer())  # Reverte "Apagar palavra 'Mundo'"
    print("Desfeito:", editor.desfazer())  # Reverte "Aplicar negrito"
    
    print("Histórico atual:", editor.historico)


#----------------------------Exercicio 2----------------------------
# Implementação de uma Fila (FIFO) para o Spooler de Impressão.
# O primeiro documento inserido na fila é obrigatoriamente o primeiro a ser impresso.

from collections import deque

class SpoolerImpressao:
    def __init__(self):
        # collections.deque é utilizado por ser otimizado para inserções no final e remoções no início (O(1)).
        self.fila_documentos = deque()

    def adicionar_documento(self, documento: str):
        # Enfileira o documento ao final da fila
        self.fila_documentos.append(documento)

    def imprimir_proximo(self):
        # Desenfileira o primeiro elemento do início (mais antigo)
        if len(self.fila_documentos) == 0:
            return "Spooler vazio. Nenhum documento pendente."
        return self.fila_documentos.popleft()


### --- Teste do Exercício 2 ---
if __name__ == "__main__":
    spooler = SpoolerImpressao()
    
    # Adicionando documentos na fila
    spooler.adicionar_documento("Relatorio_Financeiro.pdf")
    spooler.adicionar_documento("Apresentacao_Projeto.pptx")
    spooler.adicionar_documento("Tese_Mestrado.pdf")
    
    print("\nDocumentos na fila:", list(spooler.fila_documentos))
    
    # Imprimindo documentos sequencialmente
    print("Imprimindo:", spooler.imprimir_proximo())  # Imprime "Relatorio_Financeiro.pdf"
    print("Imprimindo:", spooler.imprimir_proximo())  # Imprime "Apresentacao_Projeto.pptx"
    
    print("Documentos restantes na fila:", list(spooler.fila_documentos))


#----------------------------------------Desafio Master----------------------------------------
# Implementação de um Deque (Fila de duas pontas) para o Sistema de Triagem Hospitalar.
# Pacientes prioritários furam a fila sendo inseridos na esquerda (início).
# Pacientes padrão entram no final da fila na direita (fim).

from collections import deque

class TriagemHospitalar:
    def __init__(self):
        # Inicializa o deque para permitir inserções rápidas em ambas as pontas
        self.fila_atendimento = deque()

    def cadastrar_paciente(self, nome: str, prioritario: bool = False):
        if prioritario:
            # Insere no início da fila (esquerda)
            self.fila_atendimento.appendleft(nome)
        else:
            # Insere no final da fila (direita)
            self.fila_atendimento.append(nome)

    def chamar_paciente(self):
        # Remove e atende o paciente na frente da fila (esquerda)
        if len(self.fila_atendimento) == 0:
            return "Não há pacientes aguardando atendimento."
        return self.fila_atendimento.popleft()


### --- Teste do Desafio Master ---
if __name__ == "__main__":
    hospital = TriagemHospitalar()
    
    # Chegada de pacientes padrão
    hospital.cadastrar_paciente("Ana Silva", prioritario=False)
    hospital.cadastrar_paciente("Carlos Souza", prioritario=False)
    
    # Chegada de paciente prioritário (fura-fila)
    hospital.cadastrar_paciente("Sr. José Oliveira (Idoso)", prioritario=True)
    
    # Chegada de mais um paciente prioritário (entra na frente de todos, inclusive do Sr. José)
    hospital.cadastrar_paciente("Dona Maria Santos (Gestante)", prioritario=True)
    
    print("\nFila atual de atendimento (Frente -> Fim):", list(hospital.fila_atendimento))
    
    # Atendimento sequencial
    print("Chamado para atendimento:", hospital.chamar_paciente())  # Deve ser Dona Maria
    print("Chamado para atendimento:", hospital.chamar_paciente())  # Deve ser Sr. José
    print("Chamado para atendimento:", hospital.chamar_paciente())  # Deve ser Ana Silva
