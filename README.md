<div style="display: flex; justify-content: center; padding: 10px;">
    <h1>Trabalho: HiveGuardian</h1>
</div>

*Universidade Federal do Piauí* -
*Campus Senador Helvídio Nunes de Barros*
> Bacharelado em Sistemas de Informação | Primeiro Período (2026.1)

**Integrantes do grupo**:
1. Davi Reis;
2. Francisco de Assis;
3. Francisco Victor;
4. José Victor;
5. Ryan Willys.

**Disciplina:** Algoritmos e Programação I <br>
**Professor(a):** Alcilene Dalília de Sousa

**Descrição:** Sistema de cadastro e monitoramento de abelhas sem ferrão, sensores ambientais associados e sistema de alertas ambientais.

**Requisitos:**
- GCC (compilador C)
- Make

**Compilação:** 
### Opção 1: Usando Make (recomendado)
```bash
make run
```
Compila e executa o programa automaticamente.

### Opção 2: Compilação manual com GCC
```bash
gcc -o main main.c functions/**/*.c interfaces/**/*.c
```

### Opção 3: Limpeza (remover executável)
```bash
make clean
```

**Execução:**
```bash
./main
```
**Bugs conhecidos:**
1. Ainda não há persistência em arquivo; os dados se perdem
ao encerrar o programa.

---
## Estrutura do trabalho:
```text
Trabalho Algoritmos/
├── functions/
│   ├── gerenciarAbelhas/
│   │   ├── gerenciarAbelhas.c
│   │   ├── gerenciarAbelhas.h
│   │   ├── switchGerenciarAbelhas.c
│   │   └── switchGerenciarAbelhas.h
│   ├── gerenciarRelatorios/
│   │   ├── gerenciarRelatorios.c
│   │   ├── gerenciarRelatorios.h
│   │   ├── switchGerenciarRelatorios.c
│   │   └── switchGerenciarRelatorios.h
│   ├── gerenciarSensores/
│   │   ├── gerenciarSensores.c
│   │   ├── gerenciarSensores.h
│   │   ├── switchGerenciarSensores.c
│   │   └── switchGerenciarSensores.h
│   ├── limparBuffer/
│   │   ├── limparBuffer.c
│   │   └── limparBuffer.h
│   └── limparTela/
│       ├── limparTela.c
│       └── limparTela.h
├── interfaces/
│   ├── cores.h
│   ├── gerenciarAbelhas/
│   │   ├── gerenciarAbelhasInterface.c
│   │   └── gerenciarAbelhasInterface.h
│   ├── gerenciarSensores/
│   │   ├── gerenciarSensoresInterface.c
│   │   └── gerenciarSensoresInterface.h
│   ├── menuPrincipal/
│   │   ├── interfaceMenuPrincipal.c
│   │   └── interfaceMenuPrincipal.h
│   └── relatoriosInterface/
│       ├── relatoriosInterface.c
│       └── relatoriosInterface.h
├── structs/
│   └── structs.h
├── Makefile
├── main.c
├── main (executável)
└── README.md
```