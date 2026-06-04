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

**Compilação:** 
```bash
make run
```
ou
```bash
gcc -o main main.c
```
**Execução:**
```bash
./main
```
**Bugs conhecidos:**
1. Ainda não há persistência em arquivo; os dados se perdem
ao encerrar o programa.
2. A validação para adicionar abelhas ainda é inconsistente
3. Vetor de abelhas é completamente excluido ao tentar adicionar novas abelhas

---
## Estrutura do trabalho:
```text
/hackBee
    /functions <- Aqui estão guardadas as funções em header files.
    /interfaces <- Aqui ficam as interfaces.
    /structs <- Aqui ficam guardadas as structs.
    > main.c <- Código principal.
```