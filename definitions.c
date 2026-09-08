#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "declarations.h"
#include "data_structures.h"

queue_t *alloc_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    assert(queue != NULL);
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue_player(queue_t *queue, int id, char name[], int level)
{
    assert(queue != NULL);
    player_t *new_player = malloc(sizeof(player_t));
    assert(new_player != NULL);
    new_player->id = id;
    strcpy(new_player->name, name);
    new_player->level = level;
    new_player->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = new_player;
        queue->rear = new_player;
    }
    else
    {
        queue->rear->next = new_player;
        queue->rear = new_player;
    }
    queue->size++;
}

_Bool front_player(queue_t *queue, int *id, char name[], int *level)
{
    if (queue == NULL || queue->front == NULL)
    {
        return false;
    }
    *id = queue->front->id;
    strcpy(name, queue->front->name);
    *level = queue->front->level;
    return true;
}

_Bool dequeue_player(queue_t *queue, int *id, char name[], int *level)
{
    if (queue == NULL || queue->front == NULL)
    {
        return false;
    }
    player_t *temp = queue->front;
    *id = temp->id;
    strcpy(name, temp->name);
    *level = temp->level;
    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return true;
}

void load_players(queue_t *queue, char filename[])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open input file\n");
        return;
    }
    int id;
    char name[50];
    int level;
    while (fscanf(file, "%d %49s %d", &id, name, &level) == 3)
    {
        if (id > 0 && level >= 1 && level <= 100)
        {
            enqueue_player(queue, id, name, level);
        }
        else
        {
            printf("Invalid player skipped\n");
        }
    }
    fclose(file);
}

void print_queue(queue_t *queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    player_t *current = queue->front;
    while (current != NULL)
    {
        printf("Player ID: %d\n", current->id);
        printf("Name: %s\n", current->name);
        printf("Level: %d\n", current->level);
        current = current->next;
    }
}

int queue_size(queue_t *queue)
{
    return queue->size;
}

double average_level(queue_t *queue)
{
    if (queue == NULL || queue->size == 0)
    {
        return 0;
    }
    int total = 0;
    player_t *current = queue->front;
    while (current != NULL)
    {
        total += current->level;
        current = current->next;
    }
    return (double)total / queue->size;
}

player_t *highest_level_player(queue_t *queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        return NULL;
    }
    player_t *highest = queue->front;
    player_t *current = queue->front->next;
    while (current != NULL)
    {
        if (current->level > highest->level)
        {
            highest = current;
        }
        current = current->next;
    }
    return highest;
}

void free_queue(queue_t *queue)
{
    if (queue == NULL)
    {
        return;
    }
    player_t *current = queue->front;
    while (current != NULL)
    {
        player_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}
