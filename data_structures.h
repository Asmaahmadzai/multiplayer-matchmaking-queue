#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct player {
    int id;
    char name[50];
    int level;
    struct player *next;
} player_t;

typedef struct queue {
    player_t *front;
    player_t *rear;
    int size;
} queue_t;

#endif
