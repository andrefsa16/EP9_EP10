#include "teamlist.h"
#include <assert.h>
#include <stdlib.h>

// Implementação do TAD TeamList com VETOR DINÂMICO.

struct teamlist {
    int n;
    int n_max;
    Team **v;
};

static void reallocate(TeamList *tl) {
    tl->n_max *= 2;
    tl->v = (Team **)realloc(tl->v, tl->n_max * sizeof(Team *));
}

TeamList *tl_create(void) {
    TeamList *tl = (TeamList *)malloc(sizeof(TeamList));
    tl->n = 0;
    tl->n_max = 4;
    tl->v = (Team **)malloc(tl->n_max * sizeof(Team *));
    return tl;
}

void tl_append(TeamList *tl, Team *t) {
    if (tl->n == tl->n_max)
        reallocate(tl);
    tl->v[tl->n++] = t;
}

int tl_size(TeamList *tl) {
    return tl->n;
}

Team *tl_get(TeamList *tl, int i) {
    assert(i >= 0 && i < tl->n);
    return tl->v[i];
}

void tl_free(TeamList *tl) {
    for (int i = 0; i < tl->n; i++)
        team_free(tl->v[i]);
    free(tl->v);
    free(tl);
}
