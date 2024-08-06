/*
 * SRPG N64 Edition 
 * Made by Epixjava 
 * 2024
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <libdragon.h>

#define CONSOLE_WIDTH 64
#define CONSOLE_HEIGHT 28
#define HORIZONTAL_PADDING 64
#define VERTICAL_PADDING 8


// Game variables
int s = 100;    // HP Sonic
int m = 50;     // MP Sonic
int a = 100;    // HP Shadow
int y = 50;     // MP Shadow
int w = 0;      //wins
int l = 0;      //losses
int choice;     // input choice 
int gameplay = 1;  // store continue value
int p = 0;     // postgame check 


// Functions
void input(int *choice);
void clear_input_buffer(void);
void main_screen();
void postgame();

// main gameplay loop
int main() {
    console_init();
    joypad_init();
    
    while (gameplay) {

        console_clear();
        main_screen();
        input(&choice);   


    if (p == 2) {
        postgame();
    } 
    else {
        switch (choice) {
            // Attack
            case 1:  
                console_clear();
                a -= 15;
                printf("\n");
                printf("Sonic: Alright! Homing Attack!\n");
                printf("-----\n");
                printf("\n");
                printf("Sonic attacks Shadow!\n");
                printf("\n");
                printf("Shadow loses -15 HP!\n");
            //Shadow Attack Logic
            if ( p >= 3) {
                s -= 27;
                printf("\n");
                printf("\n");
                printf("Super Shadow: H*w path#ic!\n");
                printf("&!@--\n");
                printf("\n");
                printf("Supa Shadow uses Ch@00$ uPPER!\n");
                printf("\n");
                printf("S0ni takes damage! -27 HP!\n");
                } else if ( p >= 3 && a <= 25 && y >=19) {
                a += 30;
                y -= 20;
                printf("\n");
                printf("\n");
                printf("Super Shadow: This is not the end!\n");
                printf("*^@!-\n");
                printf("\n");
                printf("Super Shadow opens a Heal Unit!\n");
                printf("\n");
                printf(" Super Shadow restores +30 HP! \n");
                } else if ( p >= 3 && a <= 17 && y >= 29){
                    s -= 35;
                    y -= 20; 
                printf("\n");
                printf("SUper sHad0w: CHAOS BLAST!\n");
                printf("_*^#-\n");
                printf("\n");
                printf("Super Shadow shook the earth with Chaos blast!!!\n");
                printf("\n");
                printf("Sonic is knocked into a wall -35 HP!\n");
                } else if ( p >= 3 && y <= 30) {
                a -= 9;
                y += 15;
                printf("\n");
                printf("Super Shadow: M@11ra...watch m3. I will fulf#$ your w1SH!\n");
                printf("*$#@-\n");
                printf("\n");
                printf("Super Shadow uses Chaos Guard!\n");
                printf("\n");
                printf("NULL loses -9 HP! \n");
                printf("\n");
                printf("Super S*)_--# burns with passion and G/-] +15 MP!\n");
                } else if (a > 16 ) {
                s -= 25;
                printf("\n");
                printf("\n");
                printf("Shadow: How pathetic!\n");
                printf("------\n");
                printf("\n");
                printf("Shadow uses Chaos Upper!\n");
                printf("\n");
                printf("Sonic takes damage! -25 HP!\n");
                } else if (a <= 20 && y >= 19) {
                a += 30;
                y -= 20;
                printf("\n");
                printf("\n");
                printf("Shadow: Maria...I won't lose!\n");
                printf("------\n");
                printf("\n");
                printf("Shadow opens a Heal Unit!\n");
                printf("\n");
                printf("Shadow restores +30 HP! \n");
                } else if (a <= 16 && y > 29) {
                s -= 31;
                y -= 30;
                printf("\n");
                printf("Shadow: Chaos....CONTROL!\n");
                printf("-----\n");
                printf("\n");
                printf("Shadow used Chaos Control!!!\n");
                printf("\n");
                printf("Sonic takes damage -31 HP!\n");
                }   else if ( y <= 30) {
                console_clear();
                a -= 7;
                y += 10;
                printf("\n");
                printf("Shadow:....Not today Hedgehog!\n");
                printf("------\n");
                printf("\n");
                printf("Shadow uses Chaos Guard!\n");
                printf("\n");
                printf("It was kinda extra...Shadow loses -7 HP! \n");
                printf("\n");
                printf("Shadow feels increased fortitude and gains +10 MP!\n");
            }
                break;
            // Defend
            case 2: 
            if ((p >= 3)) {
                console_clear();
                s -= 10;
                m += 15;
                printf("##*$(@)()(-47620+938#@!!\n");
                printf("Sonic: I will never give up!\n");
                printf("-(*$#-\n");
                printf("\n");
                printf("Super Sh@dow a1t@c#s S0nic!\n");
                printf("\n");
                printf("Sonic d3fend2 hims#l3f with ^>C#4h0!li@)d0g and loses -10 HP! \n");
                printf("\n");
                printf("Sonic summons all his stength and gains +15 MP!\n");
            }
            else {
                console_clear();
                s -= 7;
                m += 10;
                printf("\n");
                printf("Sonic: All this fighting is making me hungry!\n");
                printf("-----\n");
                printf("\n");
                printf("Shadow attacks Sonic!\n");
                printf("\n");
                printf("Sonic defends himself with a chili dog and loses -7 HP! \n");
                printf("\n");
                printf("Sonic eats the chili dog and gains +10 MP!\n");
            }
                break;
            // Spin Dash
            case 3:  
            if ((p >= 3)) {
                console_clear();
                m -= 22;
                a -= 25;
                s -= 10;
                printf("\n");
                printf("Sonic: bRin@ it 0n!\n");
                printf("^8&#@-\n");
                printf("\n");
                printf("Sonic rocketed toward Super Shadow with a Spin Dash! \n");
                printf("\n");
                printf("Super Shadow loses -25 HP! \n");
                printf("\n");
                printf("suPer Sh@dow c@)t^er$ with Chaos Magic! \n");
                printf("\n");
                printf("Sanic los33#s -10 HP!\n");
            }
            else if (m > 19) {
                console_clear();
                m -= 20;
                a -= 30;
                s -= 10;
                printf("\n");
                printf("Sonic turns into a blue blur!\n");
                printf("\n");
                printf("Sonic rocketed toward Shadow with a Spin Dash! \n");
                printf("\n");
                printf("Shadow loses -30 HP! \n");
                printf("\n");
                printf("Shadow counters with Chaos Magic! \n");
                printf("\n");
                printf("Sonic loses -10 HP!\n");
            } 
                else {
                console_clear();
                printf("\n");
                printf("Sonic: Mannnn! I dont have enough MP to get fast enough!\n");
                printf("-----\n");
            }
                break;
            // Defend
            case 4:  
                if ((p >= 3)) {
                console_clear();
                a += 20;
                s += 10;
                printf("\n");
                printf("Super Shadow knocked the ring box away!\n");
                printf("\n");
                printf("$0nic was ^nabl3 to He&l!\n"); 
                printf("\n");
                printf("1-per Shd0w took the rings for h1mself!\n");
                printf("\n");
                printf("Super Shadow G7*1nD +20 hp!?!\n");
                printf("\n");
                printf("Sonic snags a Ring and gains +10 HP! \n");
            }
                else if ((m > 9)) {
                console_clear();
                m -= 10;
                s += 30;
                printf("\n");
                printf("Sonic: I'm beat up pretty bad. Time to heal!\n");
                printf("-----\n");
                printf("\n");
                printf("Sonic breaks open a ring container!\n");
                printf("\n");
                printf("Sonic heals +30 HP!\n");    
            } 
                else  {
                // MP check for Heal
                console_clear();
                printf("\n");
                printf("Sonic: Drat! Not enough MP to Heal!\n");
                printf("-----\n");
            }
                break; 
        }   }
            
        // Pause the game to wait for player input
            input(&gameplay);
        
    }
    
}

// main screen
void main_screen() {
    
    // Win,lose,HP,MP Check  
            if ((p >= 3 && a <= 0)) {
                console_clear();
                w = 0;
                l = 0;
                s = 100; 
                m = 50;
                a = 100;
                y = 50;
                p = 0;
                printf("\n");
                printf("             Super Shadow has been defeated! \n");
                printf("\n");
                printf("                Sonic has won the fight!     \n");
                printf("\n");
                printf("      Thanks for playing my game! I hope you had fun. \n");
                printf("\n");
                printf("                Press A to play again.....\n");
                input(&gameplay);
            }
            else if(a <= 0){
                console_clear();
                w += 1;
                s = 100; 
                m = 50;
                a = 100;
                y = 50;
                p += 1;
                printf("\n");
                printf("Sonic has won the fight!!!\n");
                printf("\n");
                printf("\n");
                printf("Wins:  %d  \n", w);
                printf("Loses: %d  \n", l);
                printf("\n");
                printf("\n");
                printf("Thanks for playing! Press A to play again.\n");
                input(&gameplay);
                }
            else if (s <= 0){
                console_clear();
                l += 1;
                s = 100; 
                m = 50;
                a = 100;
                y = 50;
                printf("\n");
                printf("GAME OVER! Shadow has won the fight!!!\n");
                printf("\n");
                printf("\n");
                printf("Shadow: Tsch... Weak.\n");
                printf("------\n");
                printf("\n");
                printf("Losses: %d \n", l);
                printf("Wins:   %d \n", w);
                printf("\n");
                printf("\n");
                printf("Thanks for playing! Press A to play again.\n");
                input(&gameplay);
                }
            else if (m > 50){
                m = 50;
                printf("\n");
                printf("\n");
                printf("Sonic is full!! (MP Full)\n");
                printf("\n");
                printf("                                           X X \n");
                printf("Sonic: Oh man I think im gonna barrrffff....O  \n");
                input(&gameplay);
                }
            else if (s > 100){
                s = 100;
                }   
            else if (y > 50){
                y = 50;
                }
            else if (a > 100){
                a = 100;
                }
        //Main Screen 
        if ((p >= 3)) {   
        printf("\n");
        printf("\n");
        printf("  Defeat Super Shadow!  \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf(" --------------------\n");
        printf(" - Sonic:           *\n");
        printf(" -  HP :   %d      *\n", s);
        printf(" -  MP :   %d     *\n", m);
        printf(" -----------------\n");
        printf("\n");
        printf("\n");
        printf(" --------------------\n");
        printf(" - Super Shadow!:   *\n");
        printf(" -  HP :   %d      *\n", a);
        printf(" -  MP :   %d     *\n", y);
        printf(" -----------------\n");
        printf("\n");
        printf("-------------------------\n");
        printf("| A | - Homing Attack!   |\n");
        printf("                         |\n");
        printf("| B | - Defend           |\n");
        printf("                         |\n");
        printf("| Z | - Spin Dash -20MP  |\n");
        printf("                         |\n");
        printf("| R | - Heal +30 HP -20MP|\n");
        printf("-------------------------\n");
        } else {
        printf("\n");
        printf("\n");
        printf(" Sonic RPG  N64 Edition   \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf(" --------------------\n");
        printf(" - Sonic:           *\n");
        printf(" -  HP :   %d      *\n", s);
        printf(" -  MP :   %d     *\n", m);
        printf(" -----------------\n");
        printf("\n");
        printf("\n");
        printf(" --------------------\n");
        printf(" - Shadow:          *\n");
        printf(" -  HP :   %d      *\n", a);
        printf(" -  MP :   %d     *\n", y);
        printf(" -----------------\n");
        printf("\n");
        printf("-------------------------\n");
        printf("| A | - Homing Attack!   |\n");
        printf("                         |\n");
        printf("| B | - Defend           |\n");
        printf("                         |\n");
        printf("| Z | - Spin Dash -20MP  |\n");
        printf("                         |\n");
        printf("| R | - Heal +30 HP -20MP|\n");
        printf("-------------------------\n");
        }
}

// input function
void input(int *choice) {
    *choice = 0;
    while (!(*choice == 1 || *choice == 2 || *choice == 3 || *choice == 4 )) {
        joypad_poll();
        struct controller_data keys = get_keys_down();
        if (keys.c[0].A)
            *choice = 1;
        else if (keys.c[0].B)
            *choice = 2;
        else if (keys.c[0].Z)
            *choice = 3;
        else if (keys.c[0].R)
            *choice = 4;
        clear_input_buffer();
    }
}

// clears input buffer to avoid errors
void clear_input_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Postgame function
void postgame() {
        printf("???????????????????????????\n");
        printf(" SONIC RPG??? n64^&^4\n");
        printf("\n");
        printf(" - NULL:                        *\n");
        printf(" -  HP :   %d                   *\n", s);
        printf(" -  MP :   %d                *\n", m);
        printf("\n");
        printf(" -----------           ---------\n");
        printf(" - SUPER Shadow:          *\n");
        printf(" -  HP :   %d                  *\n", a);
        printf(" -  MP :   %d                *\n", y);
        printf(" -----------            ------\n");
        printf("\n");
        printf("| A | - Homing              Attaque!!   |\n");
        printf("                         |\n");
        printf("| ? | - Defendre       (*&*4**(@@##)    |\n");
        printf("                         |\n");
        printf("| ? | - Spin          Dash -20MP  |\n");
        printf("              ^^@(@)!*)#&)D(987&&)           |\n");
        printf("| ! | - Heal +30                     HP -20MP|\n");
        printf("------ !*((----------    @@@        -##$@()&--------\n");
    printf("??$?7?9?86@@^*@??3<^*&!??2@31>'?????\n");
    printf("\n");
    printf("Shadow: Now, witness my true power! \n");
    printf("------\n");
    printf("Shadow has turned into Super Shadow!\n");
    printf("\n");
    printf("            Good Luck!              \n");
    w = 0;
    p += 1;
    input(&gameplay);  
}
