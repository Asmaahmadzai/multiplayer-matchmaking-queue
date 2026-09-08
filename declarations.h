#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <stdbool.h>
#include "data_structures.h"

queue_t *alloc_queue(void);
void enqueue_player(queue_t *queue, int id, char name[], int level);
_Bool front_player(queue_t *queue, int *id, char name[], int *level);
_Bool dequeue_player(queue_t *queue, int *id, char name[], int *level);
void load_players(queue_t *queue, char filename[]);
void print_queue(queue_t *queue);
int queue_size(queue_t *queue);
double average_level(queue_t *queue);
player_t *highest_level_player(queue_t *queue);
void free_queue(queue_t *queue);

#endif
