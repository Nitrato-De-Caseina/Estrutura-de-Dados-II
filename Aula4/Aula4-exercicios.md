# Resolução de Exercícios - Estruturas de Dados LIFO e FIFO

*   **Exercício 1: O Simulador "Desfazer"**
    *   **Estrutura de Dados Utilizada**: Pilha (LIFO - Last In, First Out)
    *   **Justificativa**: Em um editor de texto, a última ação executada pelo usuário deve ser a primeira a ser desfeita ao acionar o comando "Desfazer" (Ctrl + Z).
    *   **Implementação em Python**:
        ```python
        class SimuladorDesfazer:
            def __init__(self):
                self.pilha = []

            def registrar_acao(self, acao: str):
                self.pilha.append(acao)

            def desfazer(self):
                if not self.pilha:
                    return None
                return self.pilha.pop()
        ```

*   **Exercício 2: O Sistema de Impressão**
    *   **Estrutura de Dados Utilizada**: Fila (FIFO - First In, First Out)
    *   **Justificativa**: O spooler de impressão deve processar os documentos na ordem em que foram enviados, garantindo que o primeiro arquivo enviado seja o primeiro a ser impresso.
    *   **Implementação em Python**:
        ```python
        from collections import deque

        class SpoolerImpressao:
            def __init__(self):
                self.fila = deque()

            def enfileirar_documento(self, documento: str):
                self.fila.append(documento)

            def imprimir(self):
                if not self.fila:
                    return None
                return self.fila.popleft()
        ```

*   **Desafio Master: Triagem Hospitalar**
    *   **Estrutura de Dados Utilizada**: Deque (Double-Ended Queue / Fila de duas pontas)
    *   **Justificativa**: O atendimento hospitalar segue o fluxo padrão sequencial de chegada (inserção no final da fila), mas casos prioritários exigem inserção imediata no início da fila de atendimento. O deque permite operações eficientes de inserção em ambas as pontas.
    *   **Implementação em Python**:
        ```python
        from collections import deque

        class TriagemHospitalar:
            def __init__(self):
                self.fila_atendimento = deque()

            def adicionar_paciente(self, nome: str, prioritario: bool = False):
                if prioritario:
                    self.fila_atendimento.appendleft(nome)
                else:
                    self.fila_atendimento.append(nome)

            def chamar_proximo(self):
                if not self.fila_atendimento:
                    return None
                return self.fila_atendimento.popleft()
        ```
