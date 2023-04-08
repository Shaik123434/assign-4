#include <stdio.h>

#define MAX_PLAYERS 11

struct Player {
    char name[50];
    int runs_scored;
};

int main() {
    struct Player players[MAX_PLAYERS];
    int num_players,i;
    int total_runs = 0;
    
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    
    printf("Enter the batting information:\n");
    for (i = 0; i < num_players; i++) {
        printf("Player %d:\n", i+1);
        printf("Name: ");
        scanf("%s", players[i].name);
        printf("Runs scored: ");
        scanf("%d", &players[i].runs_scored);
        
        total_runs += players[i].runs_scored;
    }
    
    printf("Total runs scored by the team: %d\n", total_runs);
    
    return 0;
}

