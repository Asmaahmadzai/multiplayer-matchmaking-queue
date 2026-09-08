/*************************************************
 * Student Name: Asma Ahmadzai
 * Student Number: 101333739
 * SYSC1006 - Assignment 03
 *************************************************/

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

/********** DON'T MODIFY **********/
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
/********** DON'T MODIFY **********/

#endif
