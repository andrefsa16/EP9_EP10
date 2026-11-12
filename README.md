# EP9 & EP10 — Coleção de Times

Repositório contendo as implementações dos exercícios práticos **EP 09** e **EP 10** de Estruturas de Dados ("Campeonato Computacional de Futebol").

## Estrutura do Repositório

- [`ep9/`](ep9/) — **EP 09: Coleção de times** (TAD `Team` e TAD `TeamVec` com vetor dinâmico)
- [`ep10/`](ep10/) — **EP 10: Coleção de times: o retorno** (TAD `Team` e TAD `TeamList` com duas implementações intercambiáveis via `config.mk`: vetor dinâmico `dynvec` e lista duplamente encadeada `dlist`)

## Como Compilar e Executar

### EP 09
```bash
cd ep9
make
```

### EP 10
Altere `IMPL = dynvec` ou `IMPL = dlist` em `ep10/config.mk` e execute:
```bash
cd ep10
make
```
