#include <C:\Users\Tenegan\Desktop\Some_Bytes\projet_tut\src\header_sb.h>

//dimention fenetre
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/*
compiler => 
gcc src/main.c -o bin/prog.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2
gcc src/main.c -o bin/prog.exe -mwindow -I include -L lib -lmingw32 -lSDL2main -lSDL2   => pour ne pas avoir cmd en arriere plan
*/


int main(int argc, char *argv[]) {
    //initialisation de la SDL > si erreur > on retourne l'erreur et on quitte
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0) 
        SDL_ExitWithError("initialisation SDL");

    SDL_Window *window = NULL;  //declaration variable pour la fenetre
    SDL_Renderer *renderer = NULL;

    
    //Creation fenetre + rendu
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0 ) SDL_ExitWithError("creation fenetre et rendu");

    //pour le titre
    const char *windowTitle = "Soundboard v1.7.0";
    SDL_SetWindowTitle(window, windowTitle);

    //pour l'icon
    SDL_Surface* imgIcon = SDL_LoadBMP("../src/img/mainIcon.bmp");
    if (imgIcon == NULL) printf("erreur icone");
    SDL_SetWindowIcon(window, imgIcon);
    SDL_FreeSurface(imgIcon);
    
    //pour le fond
    if ( SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0 ) SDL_ExitWithError("Changement de couleur => blanc");

    SDL_Rect rectFond;

    rectFond.w = WINDOW_WIDTH;
    rectFond.h = WINDOW_HEIGHT;
    rectFond.x = 0;
    rectFond.y = 0;

    if ( SDL_RenderFillRect(renderer, &rectFond) != 0 ) SDL_ExitWithError("Chargement fond");

    
    
    char audioID[100] = "";
    FILE *fichier = fopen("../src/driver.txt", "r");
    fgets(audioID, 100, fichier);
    fclose(fichier);
    
    if(audioID[0] == 0) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Peripherique", "Fichier driver.txt dans le dossier src est vide. Les sons ne seront pas joue correctement", NULL);


    int couleur[6] = {0, 0, 0, 0, 1, 0};  //r g b comptage en cours r g b
    SDL_bool gamerMod = SDL_FALSE;  //mode RGB
    SDL_bool ModeNuit = SDL_FALSE;  //mode nuit
    int couleurFond = 255;          //couleur du fond => changer avec le mode nuit
    int couleurDefaut = 100;        //couleur bp mode nuit
    SDL_bool program_launched = SDL_TRUE;   //le programme est lancé ?
    int posX, posY; //position curseur quand clic

    
    printf("Initialisation en %d ms\n", SDL_GetTicks() );
    rendu1(renderer, couleur, ModeNuit);

    int frameTicks = SDL_GetTicks();                    //init fps
    int tempsFrame = SDL_GetTicks() - frameTicks;  
//----------------------------------------------------------------

    while(program_launched) {
        SDL_Event event;
        //limiter les fps a 60images/secondes
        tempsFrame = SDL_GetTicks() - frameTicks;
        if( tempsFrame  <= 16 ) SDL_Delay(16 - tempsFrame);

        frameTicks = SDL_GetTicks();

        
        if(gamerMod == SDL_TRUE) {
            if(couleur[3] == 1) {    //si on compte le rouge 

                if(couleur[0] = 254) {  //si on a fini de compte rouge
                    couleur[2] = couleur[2] - 2;    //on decompte bleu

                    if(couleur[2] <= 4) {
                        //si on a fini de compté le rouge on compte le vert, suppr le bleu, garde le rouge
                        /*couleur[0] = 255;
                        couleur[1] = 0;
                        couleur[2] = 0;*/
                        couleur[3] = 0;
                        couleur[4] = 1;
                        couleur[5] = 0;
                    }
                } else couleur[0] = couleur[0] + 2;
            }
            if(couleur[4] == 1) {    //si on compte le vert

                if(couleur[1] = 254) {  //si on a fini de compte vert
                    couleur[0] = couleur[0] - 2;    //on decompte rouge

                    if(couleur[0] <= 4) {   
                        //si on a fini de compté le vert on compte le bleu, suppr le rouge, garde le vert
                        /*couleur[0] = 0;
                        couleur[1] = 255;
                        couleur[2] = 0;*/
                        couleur[3] = 0;
                        couleur[4] = 0;
                        couleur[5] = 1;
                    }
                } else couleur[1] = couleur[1] + 2;
            }
            if(couleur[5] == 1) {    //si on compte le bleu 

                if(couleur[2] = 254) {  //si on a fini de compte bleu
                    couleur[1] = couleur[1] - 2;    //on decompte vert

                    if(couleur[1] <= 4) {
                        //si on a fini de compté le bleu on compte le rouge, suppr le vert, garde le bleu
                        /*couleur[0] = 0;
                        couleur[1] = 0;
                        couleur[2] = 255;*/
                        couleur[3] = 1;
                        couleur[4] = 0;
                        couleur[5] = 0;
                    }
                } else couleur[2] = couleur[2] + 2;
            }
        } else {
            if(ModeNuit) couleurDefaut = 20; else couleurDefaut = 100;
            couleur[0] = couleurDefaut;
            couleur[1] = couleurDefaut;
            couleur[2] = couleurDefaut;
        }
        rendu1(renderer, couleur, ModeNuit);
        SDL_RenderPresent(renderer);
        
        while (SDL_PollEvent(&event) ) {     // des qu'il y a un evenement on rentre dans la boucle

            
            if(SDL_GetMouseState(&posX, &posY) & SDL_BUTTON_LMASK ) {
                SDL_bool Bpclique = SDL_FALSE;
                
                //bp pour le son
                if ((posX < 348) & (posX > 248)) {          //bp1
                    if ((posY < 248) & (posY > 148)) {
                        char* son = "../src/sound/son1.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 449) & (posX > 349)) {          //bp2
                    if ((posY < 248) & (posY > 148)) {
                        char *son = "../src/sound/son2.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 550) & (posX > 450)) {         //bp3 
                    if ((posY < 248) & (posY > 148)) {
                        char* son = "../src/sound/son3.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 348) & (posX > 248)) {          //bp4
                    if ((posY < 349) & (posY > 249)) {
                        char* son = "../src/sound/son4.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 449) & (posX > 349)) {          //bp5
                    if ((posY < 349) & (posY > 249)) {
                        char* son = "../src/sound/son5.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 550) & (posX > 450)) {          //bp6
                    if ((posY < 349) & (posY > 249)) {
                        char* son = "../src/sound/son6.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 348) & (posX > 248)) {          //bp7
                    if ((posY < 450) & (posY > 350)) {
                        char* son = "../src/sound/son7.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 449) & (posX > 349)) {          //bp8
                    if ((posY < 450) & (posY > 350)) {
                        char* son = "../src/sound/son8.wav";
                        playSound(son, audioID, renderer);
                    }
                }
                if ((posX < 550) & (posX > 450)) {          //bp9
                    if ((posY < 450) & (posY > 350)) {
                        char* son = "../src/sound/son9.wav";
                        playSound(son, audioID, renderer);
                    }
                }

                //bp le mode gamer
                if ((posX < 103) & (posX > 53)) {             
                    if ((posY < 52) & (posY > 2)) {
                        //printf("Tu as clic sur le BP gamer\n");

                        if(gamerMod == SDL_TRUE) gamerMod = SDL_FALSE;
                        else gamerMod = SDL_TRUE;
                    }
                }

                //pour le bouton nuit
                if ((posX < 52) & (posX > 2)) {             
                    if ((posY < 52) & (posY > 2)) {
                        //printf("Tu as clic sur le BP nuit\n");
                        if(ModeNuit == SDL_TRUE) ModeNuit = SDL_FALSE;
                        else ModeNuit = SDL_TRUE;

                    }
                }
            }
            if(event.type == SDL_QUIT) program_launched = SDL_FALSE;    //si on clique la croix on quitte

            if(event.type == SDL_KEYDOWN) { 
                switch (event.key.keysym.sym) {
                    case SDLK_F1: {      //pour afficher tout les peripherques audio
                            char messageBox[] = "";

                            int i, count = SDL_GetNumAudioDevices(0);
                            if(count >= 3) count = 3;

                            for(i = 0; i < count; ++i) {
                                strcat(messageBox, SDL_GetAudioDeviceName(i, 0));
                                strcat(messageBox, "\n");
                            }
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Peripherique", messageBox, NULL);
                        } break;
                    case SDLK_F5: {
                            char* son = "../src/sound/sonF5.wav";
                            playSound(son, audioID, renderer);
                    } break;
                    case SDLK_F6: playSound("../src/sound/sonF6.wav", audioID, renderer); break;
                    case SDLK_F7: playSound("../src/sound/sonF7.wav", audioID, renderer); break;
                    case SDLK_F8: playSound("../src/sound/sonF8.wav", audioID, renderer); break;
                    case SDLK_F9: playSound("../src/sound/sonF9.wav", audioID, renderer); break;
                    case SDLK_F10: playSound("../src/sound/sonF10.wav", audioID, renderer); break;
                    case SDLK_F11: playSound("../src/sound/sonF11.wav", audioID, renderer); break;
                    case SDLK_F12: playSound("../src/sound/sonF12.wav", audioID, renderer); break;

                default:
                    break;
                }
            }



        }   //fin while event
    }   //fin while programme lancé

    //------------------------------------------------------------------------------------------------------

    //ci apres destruction de tt les elements
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();     // libère la memoire dynamique

    return EXIT_SUCCESS;       // retourne 0
}