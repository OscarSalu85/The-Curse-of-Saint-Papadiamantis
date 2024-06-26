#ifndef STRUCTURES_H
#define STRUCTURES_H
#define MAX_CHAR_DESC 1024
#define MAX_CHAR_NAME 20
#define MAX_ENEMIES 3
#define MAX_OPTIONS 3
#define MAX_DECISIONS 3
#define MAX_SKILLS 4
#define MOD_NUMBER 3
#define SKILL_DATA_SIZE 10
#define SCENARIO_N 8
#define ENEMY_SKILL_AMM 2
//Skills
typedef struct Skills{
    char *name;
    char *description;
    int duration;
    int damage;
    int modifiers[MOD_NUMBER];
}Skills;

//Character
typedef struct Character{
    char *name;
    int hp;
    int current_hp;
    int atk;
    int def;
    Skills *skill[MAX_SKILLS];
}Character;

//Enemy
typedef struct Enemy{
    char *name;
    int hp;
    int atk;
    int def;
    int num_skills;
    Skills skill[ENEMY_SKILL_AMM];
}Enemy;

//Option
typedef struct Option{
    char r_text[MAX_CHAR_DESC];
    Enemy *enemies[MAX_ENEMIES];
}Option;

//Decision
typedef struct Decisions{
    char question[MAX_CHAR_DESC];
    int n_options;
    Option *options[MAX_OPTIONS];
}Decisions;

//Scenario
typedef struct Scenario{
    char *name;
    char *description;
    char *image;
    Decisions *decision;
    char *next_scenario_name_1;
    char *next_scenario_name_2;
}Scenario;

//DATA
typedef struct Data{
    Character *character;
    Scenario *current_scenario;
    Scenario *sceneNodes;
}Data;

typedef struct Time_Strike{
    Skills *array;
    int used;
    int num_skills;
}Time_Strike;

#endif