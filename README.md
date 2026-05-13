# GIVIC Delivery System

Implementação de um sistema de processamento de entregas utilizando estruturas de dados desenvolvidas manualmente em C++20, como parte do Projeto Prático 1 (PP1) da disciplina de Algoritmos e Estruturas de Dados I (AED I) da Universidade do Estado do Amazonas (UEA).

---

# Objetivo

O objetivo deste projeto é implementar, do zero, os principais Tipos Abstratos de Dados (TADs) estudados na disciplina, aplicando conceitos de:

- Estruturas de dados dinâmicas
- Programação orientada a objetos
- Templates em C++
- Gerenciamento manual de memória
- Encapsulamento
- Modularização de código

Todo o desenvolvimento será realizado sem o uso de containers prontos da STL ou bibliotecas auxiliares de estruturas de dados. Todas as implementações serão feitas manualmente.

---

# Estruturas Implementadas

O projeto implementa manualmente:

- Lista encadeada
- Deque
- Fila (Queue)
- Pilha (Stack)

As estruturas serão genéricas utilizando templates em C++20.

---

# Regras do Projeto

O desenvolvimento segue os requisitos definidos no enunciado do PP1:

- Implementação obrigatória em C++20
- Proibido utilizar STL (`vector`, `queue`, `stack`, `deque`, `list`, etc.)
- Implementação totalmente manual das estruturas de dados
- Uso obrigatório de templates
- Uso de programação orientada a objetos
- Sem variáveis globais
- Sem herança
- Sem `friend class`

---

# Funcionamento

O sistema é dividido em dois módulos principais:

## Biggy

Responsável pelo processamento inicial dos comandos de entrada.

Operações realizadas:

- Encaminhamento de pacotes
- Cancelamento de entregas
- Descarte de pacotes avariados
- Gerenciamento das filas de processamento

Estruturas utilizadas:

- FEP
- CANCEL
- DESC

---

## Bang

Responsável pelo processamento final dos pacotes.

Operações realizadas:

- Empilhamento de pacotes
- Remoção de pacotes cancelados
- Remoção de pacotes avariados
- Reorganização da pilha utilizando estrutura auxiliar

Estruturas utilizadas:

- PEP
- AUX
- CANCEL
- DESC

---

# Objetivos de Aprendizado

Este projeto tem como foco:

- Implementação manual de estruturas de dados
- Manipulação dinâmica de memória
- Desenvolvimento de TADs genéricos
- Organização modular de software
- Aplicação prática de pilhas e filas
- Desenvolvimento de algoritmos sem dependência de bibliotecas prontas

---

# Tecnologias Utilizadas

- C++20
- Programação Orientada a Objetos
- Templates
- Estruturas de Dados Dinâmicas
- Gerenciamento manual de memória