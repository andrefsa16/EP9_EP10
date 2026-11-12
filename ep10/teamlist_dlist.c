#include "teamlist.h"
#include <assert.h>
#include <stdlib.h>

// Implementação do TAD TeamList com LISTA DUPLAMENTE ENCADEADA.

typedef struct node Node;

struct node {
    Team *team;
    Node *next;
    Node *prev;
};

struct teamlist {
    Node *first;
    Node *last;
    int count;
};

TeamList *tl_create(void) {
    TeamList *tl = (TeamList *)malloc(sizeof(TeamList));
    tl->first = NULL;
    tl->last = NULL;
    tl->count = 0;
    return tl;
}

void tl_append(TeamList *tl, Team *t) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->team = t;
    node->next = NULL;
    node->prev = tl->last;

    if (tl->last != NULL)
        tl->last->next = node;
    else
        tl->first = node;

    tl->last = node;
    tl->count++;
}

int tl_size(TeamList *tl) {
    return tl->count;
}

Team *tl_get(TeamList *tl, int i) {
    assert(i >= 0 && i < tl->count);
    Node *p = tl->first;
    for (int k = 0; k < i; k++)
        p = p->next;
    return p->team;
}

void tl_free(TeamList *tl) {
    Node *p = tl->first;
    while (p != NULL) {
        Node *next = p->next;
        team_free(p->team);
        free(p);
        p = next;
    }
    free(tl);
}
