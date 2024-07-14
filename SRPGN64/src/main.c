/** 
 * SRPG N64 Edition 
 * port by Epixjava 
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



// Functions
void input(int *choice);
void clear_input_buffer(void);
void main_screen();

// main gameplay loop
int main() {
    console_init();
    controller_init();

    while (gameplay) {
        // Clear screen
        console_clear();

        // Render game screen
        main_screen();
        
        // Handle player input
        input(&choice);
        
        switch (choice) {
            // Attack
            case 1:  
                console_clear();
                printf("\n");
                printf("Sonic: Alright! Homing Attack!\n");
                printf("-----\n");
                printf("\n");
                printf("Sonic attacks Shadow!\n");
                a -= 15;
                printf("\n");
                printf("Shadow loses -15 HP!\n");
                
                //Shadow Attack Logic
                if (a > 16 ) {
                    printf("\n");
                    printf("\n");
                    printf("Shadow: How pathetic!\n");
                    printf("------\n");
                    printf("\n");
                    printf("Shadow attacks Sonic!\n");
                    s -= 25;
                    printf("\n");
                    printf("Sonic takes damage! -25 HP!\n");
                } else if (a <= 20 && y > 20) {
                    printf("\n");
                    printf("\n");
                    printf("Shadow: Maria...I won't lose!\n");
                    printf("------\n");
                    printf("\n");
                    printf("Shadow opens a Heal Unit!\n");
                    a += 30;
                    y -= 20;
                    printf("\n");
                    printf("Shadow restores +30 HP! \n");
                } else if (a <= 16 && y > 29) {
                    printf("\n");
                    printf("Shadow: Chaos....CONTROL!\n");
                    printf("-----\n");
                    printf("\n");
                    printf("Shadow used Chaos Control!!!\n");
                    s -= 31;
                    y -= 30;
                    printf("\n");
                    printf("Sonic takes damage -31 HP!\n");
                }   else if ( y <= 15) {
                    console_clear();
                    printf("\n");
                    printf("Shadow:....Not today Hedgehog!\n");
                    printf("------\n");
                    printf("\n");
                    printf("Shadow uses Chaos Guard!\n");
                    a -= 6;
                    printf("\n");
                    printf("It was kinda extra...Shadow loses -6 HP! \n");
                    y += 10;
                    printf("\n");
                    printf("Shadow feels increased fortitude and gains +10 MP!\n");
                }
                break;
            // Defend
            case 2: 
                console_clear();
                printf("\n");
                printf("Sonic: All this fighting is making me hungry!\n");
                printf("-----\n");
                printf("\n");
                printf("Shadow attacks Sonic!\n");
                s -= 6;
                printf("\n");
                printf("Sonic defends himself with a chili dog and loses -6 HP! \n");
                m += 10;
                printf("\n");
                printf("Sonic eats the chili dog and gains +10 MP!\n");
                break;
            // Spin Dash
            case 3:  
                if (m > 19) {
                    console_clear();
                    printf("\n");
                    printf("Sonic turns into a blue blur!\n\n");
                    m -= 20;
                    printf("\n");
                    printf("Sonic rocketed toward Shadow with a Spin Dash! \n");
                    a -= 30;
                    printf("\n");
                    printf("Shadow loses -30 HP! \n");
                } else {
                    console_clear();
                    printf("\n");
                    printf("Sonic: Mannnn! I dont have enough MP to get fast enough!\n");
                    printf("-----\n");
                }
                break;

            // Defend
            case 4:  
                if (m > 9) {
                    console_clear();
                    printf("\n");
                    printf("Sonic: I'm beat up pretty bad. Time to heal!\n");
                    printf("-----\n");
                    m -= 10;
                    s += 30;
                    printf("\n");
                    printf("Sonic breaks open a ring box!\n");
                    printf("\n");
                    printf("Sonic heals +30 HP!\n");
                } else {
                    //Add MP check for Heal
                    console_clear();
                    printf("\n");
                    printf("Sonic: Drat, not enough MP to Heal!\n");
                    printf("-----\n");
                }
                break;    
        }
        // Pause the game to wait for player input
            input(&gameplay);
        
    }

    
}

// main screen
void main_screen() {
    
    // Win,lose,HP,MP Check
            if (a <= 0){
                console_clear();
                w += 1;
                printf("\n");
                printf("Sonic has won the fight!!!\n");
                printf("\n");
                printf("\n");
                printf("Wins:  %d  \n", w);
                printf("Loses: %d  \n", l);
                printf("\n");
                printf("\n");
                printf("Thanks for playing! Press any button to play again.\n");
                s = 100; 
                m = 50;
                a = 100;
                y = 50;
                input(&gameplay);
                }
                else if (s <= 0){
                console_clear();
                l += 1;
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
                printf("Thanks for playing! Press any button to play again.\n");
                s = 100; 
                m = 50;
                a = 100;
                y = 50;
                input(&gameplay);
                }
                else if (m > 50){
                m = 50;
                printf("\n");
                printf("\n");
                printf("Sonic is full and can't eat anymore! (MP Full)\n");
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
    
        // Main screen
        printf("\n");
        printf("\n");
        printf("      Sonic RPG!    \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("--------------------\n");
        printf("- Sonic:           *\n");
        printf("-  HP : %d       *\n", s);
        printf("-  MP : %d      *\n", m);
        printf("----------------\n");
        printf("\n");
        printf("\n");
        printf("--------------------\n");
        printf("- Shadow:          *\n");
        printf("-  HP : %d       *\n", a);
        printf("-  MP : %d      *\n", y);
        printf("----------------\n");
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

// input function
void input(int *choice) {
    *choice = 0;
    while (!(*choice == 1 || *choice == 2 || *choice == 3 || *choice == 4 )) {
        controller_scan();
        struct controller_data keys = get_keys_down();

        if (keys.c[0].A)
            *choice = 1;
        else if (keys.c[0].B)
            *choice = 2;
        else if (keys.c[0].Z)
            *choice = 3;
        else if (keys.c[0].R)
            *choice = 4;

        // Clear input buffer
        clear_input_buffer();
    }
}

// clear input buffer
void clear_input_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
