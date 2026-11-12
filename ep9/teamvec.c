#include "teamvec.h"
#include <assert.h>
#include <stdlib.h>

struct teamvec {
    int n;
    int n_max;
    Team **v;
};

static void reallocate(TeamVec *tv) {
    tv->n_max *= 2;
    tv->v = (Team **)realloc(tv->v, tv->n_max * sizeof(Team *));
}

TeamVec *tv_create(void) {
    TeamVec *tv = (TeamVec *)malloc(sizeof(TeamVec));
    tv->n = 0;
    tv->n_max = 4;
    tv->v = (Team **)malloc(tv->n_max * sizeof(Team *));
    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    if (tv->n == tv->n_max)
        reallocate(tv);
    tv->v[tv->n++] = t;
}

int tv_size(TeamVec *tv) {
    return tv->n;
}

Team *tv_get(TeamVec *tv, int i) {
    assert(i >= 0 && i < tv->n);
    return tv->v[i];
}

void tv_free(TeamVec *tv) {
    for (int i = 0; i < tv->n; i++)
        team_free(tv->v[i]);
    free(tv->v);
    free(tv);
}
