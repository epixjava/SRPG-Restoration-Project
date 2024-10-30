/*
 * SRPG GameCube Edition - SRPG GC Revival Project
 * Recreated by Epixjava
 * 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>

//storage for framebuffer 
static u32 *xfb;
static GXRModeObj *rmode;

// Game variables
int s = 500;    // PV Sonic
int a = 500;    // PV Shadow
int choice;     // input choice 
int gameplay = 1;  // store continue value


void input(int *choice);
void main_screen();
void ShadowAi();

// Gamecube Display Properties
void Display() {
  
	VIDEO_Init();
	PAD_Init();
 
	rmode = VIDEO_GetPreferredMode(NULL);

	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
 
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
}

//Scans for button pushed then pairs that with choice 
void input(int *choice) {
    *choice = 0;
    while (!(*choice == 1 || *choice == 2 || *choice == 3 || *choice == 4 || *choice == 5)) {
        PAD_ScanPads();
		u16 buttonsDown = PAD_ButtonsDown(0);

        if (buttonsDown & PAD_BUTTON_A)
            *choice = 1;
        else if (buttonsDown & PAD_BUTTON_B)
            *choice = 2;
        else if (buttonsDown & PAD_BUTTON_X)
            *choice = 3;
        else if (buttonsDown & PAD_BUTTON_Y)
            *choice = 4;
        else if (buttonsDown & PAD_BUTTON_START)
            *choice = 5;

    }
}

//Gameplay logic 
int main() {
	Display();
	PAD_ScanPads();
	
	
	while (gameplay) {
		
		VIDEO_Flush();
		
		main_screen();
		
		input(&choice);
		
		switch (choice) {
			 
			 //attack
			 case 1:
				printf("\n");
				printf("Tu choisissez d'attaquer\n");
				printf("\n");
				a -= 150;
				printf("Shadow perd 150 pv!\n");
				ShadowAi();
				break;
			

			 // Defend
			 case 2:
			 	printf("\n");
			 	printf("Shadow attaques Sonic!\n");
             	s -= 60;
             	printf("\n");
             	printf("Tu choisis de defendre.\n");
			 	printf("\n");
			 	printf("Sonic perd 60 pv! \n");
             	break;


			 //Heal 
			 case 3: 
				printf("\n");
				printf("Sonic guerit! \n");
				s += 200;
				printf("\n");
				printf("Tu choisis de guerir \n");
				printf("\n");
				printf("Sonic soigne 200 pv!\n");
                break;    

			 //Spin Dash 
			 case 4:
				printf("\n");
				printf("Tu choisissez Spin Dash!\n ");
				printf("\n");
				printf("Sonic utilise Spin Dash!\n");
				printf("\n");
				printf("Shadow perd 300 pv!\n");
				a -= 300;
				ShadowAi();
				break;
             
             //Restart game by pressing START
             case 5:
                s = 500;
                a = 500;
                main();
            
		}	
		input(&gameplay);

	}
	
}

void main_screen() {
	 
    // Win/lose/health check 
    if (a <= 0){
		VIDEO_Flush();
        printf("\n");
        printf("Sonic gagne le combat!\n");
        printf("\n");
        printf("\n");
        printf("Merci d'avoir joue! Appuyez sur Demarrer pour jouer a nouveau.\n");
        s = 500; 
        a = 500;
        input(&gameplay);
    }
    else if (s <= 0){
		VIDEO_Flush();
        printf("\n");
        printf("Shadow gange le combat!\n");
		printf("\n");
        printf("\n");
        printf("Merci d'avoir joue! Appuyez sur Demarrer pour reessayer.\n");
        s = 500; 
        a = 500;
        input(&gameplay);
    }
    else if (s > 500){
        s = 500;
	    VIDEO_Flush();
        printf("\n");
        printf("\n");
        printf("PV est au maximum!\n");
        printf("\n");
        input(&gameplay);
	}
    else if (a > 500){
        a = 500;
    }				
    
    printf("                     \n"); 
	printf("                     \n");
    printf("                     \n");
    printf("SONIC: 500 pv max    \n");
    printf("PV ACIVEL: %d        \n", s);
    printf("                     \n");
    printf("SHADOW: 500 pv max   \n");
    printf("PV ACIVEL: %d        \n", a);
	printf("                     \n");
    printf("Choissisez           \n");
	printf("                     \n");
    printf(" 1 - Attaquer        \n");
    printf("                     \n");
    printf(" 2 - Defendre        \n");
    printf("                     \n");
    printf(" 3 - Guerir          \n");
    printf("                     \n");
    printf(" 4 - Spin Dash MP 25 \n"); 
	printf("                     \n");
}

// Shadow Attack "logic"
void ShadowAi() {
    if ( a > 300 ) {
        printf("\n");
        printf("Shadow t'attaque!\n");
        s -= 120;
        printf("\n");
        printf("Tu perd 120 pv!\n");
    } else if ( a <= 50 && s <= 200) {
        printf("\n");
        printf("Shadow guerit!\n");
        a += 190;
        printf("\n");
        printf("Shadow restaure 190 pv! \n");
    } else if ( a <= 200 && s >= 300 ) {
        printf("\n");
        printf("Shadow utilise Chaos Control!\n");
        s -= 310;
        printf("\n");
        printf("Tu perd 310 pv!\n");
    } else if ( a <= 200) {
        printf("\n");
        printf("Shadow utilise Chaos Guard!\n");
        a -= 60;
        printf("\n");
        printf("Shadow se defend et ne perd que 60 pv!\n");
    }
}