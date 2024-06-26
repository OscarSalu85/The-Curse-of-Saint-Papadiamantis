
#include "structures.h"
#include <stdlib.h>
#ifndef QUEQUE_H
#define QUEQUE_H
#define NUM_TURNS 50

//Creates the necessary data structures for the combat queue
typedef struct Turn{
    char *name;
    int mod[3];
    int type;
    Enemy *enemy;
    struct Turn *next;
}Turn;

typedef struct Queue{
    Turn *first;
    Turn *last;
}Queue;


//Adds an element to the queue
void AddElement(Turn *turn, Queue *queue){
    if(queue->first == NULL){
        queue->first = turn;
        queue->last = turn;
    }
    else if(queue->first == queue->last){
        queue->last = turn;
        queue->first->next = turn;
    }
    else{
        queue->last->next = turn;
        queue->last = turn;
    }
}

//Creates the Queue based turn system
Queue* createQueue(Character *character, Enemy *enemies[MAX_ENEMIES],Queue *queue,int num_enemies){
    queue->first = NULL;
    queue->last = NULL;
    for(int i = 0; i < NUM_TURNS; i++){
        Turn *turn = malloc(sizeof(Turn));
        turn->enemy = NULL;
        turn->name = NULL;
        turn->next = NULL;
        turn->mod[0] = 0;
        turn->mod[1] = 0;
        turn->mod[2] = 0;
        turn->type = -1;

        //Obtains a random value to determine the queue
        int random = rand()%2;
        if(random == 0){
            turn->enemy = NULL;
            turn->name = "character";
            turn->type = 0;
        }
        else{
            //Adds a random enemy to the queue
            if(num_enemies != 0){
                random = rand()%(num_enemies);
                turn->enemy = enemies[random];
                turn->type = 1;
                turn->name = enemies[random]->name;
            }
        }
        AddElement(turn,queue);
    }
    return queue;
}
#endif