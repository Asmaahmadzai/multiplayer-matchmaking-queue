/*************************************************
 * Student Name: Asma Ahmadzai
 * Student Number: 101333739
 * SYSC1006 - Assignment 03
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
#include "data_structures.h"

int main(void)
{
    int id;
    int level;
    char name[50];
    printf("Welcome to the Multiplayer Matchmaking Queue\n");
    printf("\nLoading players from file...\n");
    queue_t *queue = alloc_queue();
    load_players(queue, "players.txt");
    printf("\nCurrent Matchmaking Queue\n");
    printf("-----------------------------------------------\n");
    print_queue(queue);
    printf("-----------------------------------------------\n");
    printf("Players Waiting: %d\n", queue_size(queue));
    printf("Average Level: %.2f\n", average_level(queue));
    player_t *highest = highest_level_player(queue);
    if (highest != NULL)
    {
        printf("Highest-Level Player: %s\n", highest->name);
    }
    printf("\nNext Player Waiting:\n");
    if (front_player(queue, &id, name, &level))
    {
        printf("Player ID: %d\n", id);
        printf("Name: %s\n", name);
        printf("Level: %d\n", level);
    }
    printf("\nMatching next two players...\n");
    if (dequeue_player(queue, &id, name, &level))
    {
        printf("Matched Player:\n");
        printf("Player ID: %d\n", id);
        printf("Name: %s\n", name);
        printf("Level: %d\n", level);
    }
    if (dequeue_player(queue, &id, name, &level))
    {
        printf("Matched Player:\n");
        printf("Player ID: %d\n", id);
        printf("Name: %s\n", name);
        printf("Level: %d\n", level);
    }
    printf("\nUpdated Matchmaking Queue\n");
    printf("-----------------------------------------------\n");
    print_queue(queue);
    printf("-----------------------------------------------\n");
    printf("Players Waiting: %d\n", queue_size(queue));
    printf("Average Level: %.2f\n", average_level(queue));
    free_queue(queue);
    printf("Memory freed successfully.\n");
    return EXIT_SUCCESS;
}