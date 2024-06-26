#include <stdio.h>
#include "structures.h"
#include "game.h"
#include "cJSON.c"

int main(){
    Data *data;
    create_data(&data);
    data->sceneNodes = allocate_scenarios(8);
    data->sceneNodes = get_scenario_nodes(data->sceneNodes);
    int main_menu_choice;
    while(1){
        //Menu inicial
        main_menu_choice = main_menu(data);   
        if(main_menu_choice == 1){
            continue_game(data);
            break;
        }
        else if(main_menu_choice == 2){
            new_game(data);
            data->current_scenario[0] = data->sceneNodes[0];
            break;
        }
        else if(main_menu_choice == 3){
            configure_menu(data);
        }
    }
    mainLoop(data);
}

