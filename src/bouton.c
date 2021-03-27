//Creation des boutons => lisibiliter code
void rendu1(SDL_Renderer *renderer, int couleur[2], SDL_bool ModeNuit);



void rendu1(SDL_Renderer *renderer, int couleur[2], SDL_bool ModeNuit) {
    char couleurFond;
    SDL_Rect rectFond;
    rectFond.w = 800;
    rectFond.h = 600;
    rectFond.x = 0;
    rectFond.y = 0;
    if(ModeNuit == SDL_TRUE) couleurFond = 30;
    else couleurFond = 255;
    if ( SDL_SetRenderDrawColor(renderer, couleurFond, couleurFond, couleurFond, SDL_ALPHA_OPAQUE) != 0 ) SDL_ExitWithError("Changement de couleur fond");
    if ( SDL_RenderFillRect(renderer, &rectFond) != 0 ) SDL_ExitWithError("Chargement fond");



    //pour le bouton pour les sons
    if ( SDL_SetRenderDrawColor(renderer, couleur[0], couleur[1], couleur[2], SDL_ALPHA_OPAQUE) != 0 )
        SDL_ExitWithError("Changement de couleur");

    SDL_Rect rectBP1;
    rectBP1.w = 100;
    rectBP1.h = 100;
    rectBP1.x = 248;
    rectBP1.y = 148;

    if ( SDL_RenderFillRect(renderer, &rectBP1) != 0 ) 
        SDL_ExitWithError("Chargement bouton1");

    SDL_Rect rectBP2;
    rectBP2.w = 100;
    rectBP2.h = 100;
    rectBP2.x = 349;
    rectBP2.y = 148;

    if ( SDL_RenderFillRect(renderer, &rectBP2) != 0 ) 
        SDL_ExitWithError("Chargement bouton2");

    SDL_Rect rectBP3;
    rectBP3.w = 100;
    rectBP3.h = 100;
    rectBP3.x = 450;
    rectBP3.y = 148;

    if ( SDL_RenderFillRect(renderer, &rectBP3) != 0 ) 
        SDL_ExitWithError("Chargement bouton3");

    SDL_Rect rectBP4;
    rectBP4.w = 100;
    rectBP4.h = 100;
    rectBP4.x = 248;
    rectBP4.y = 249;

    if ( SDL_RenderFillRect(renderer, &rectBP4) != 0 ) 
        SDL_ExitWithError("Chargement bouton4");

    SDL_Rect rectBP5;
    rectBP5.w = 100;
    rectBP5.h = 100;
    rectBP5.x = 349;
    rectBP5.y = 249;

    if ( SDL_RenderFillRect(renderer, &rectBP5) != 0 ) 
        SDL_ExitWithError("Chargement bouton5");

    SDL_Rect rectBP6;
    rectBP6.w = 100;
    rectBP6.h = 100;
    rectBP6.x = 450;
    rectBP6.y = 249;

    if ( SDL_RenderFillRect(renderer, &rectBP6) != 0 ) 
        SDL_ExitWithError("Chargement bouton6");

    SDL_Rect rectBP7;
    rectBP7.w = 100;
    rectBP7.h = 100;
    rectBP7.x = 248;
    rectBP7.y = 350;

    if ( SDL_RenderFillRect(renderer, &rectBP7) != 0 ) 
        SDL_ExitWithError("Chargement bouton7");

    SDL_Rect rectBP8;
    rectBP8.w = 100;
    rectBP8.h = 100;
    rectBP8.x = 349;
    rectBP8.y = 350;

    if ( SDL_RenderFillRect(renderer, &rectBP8) != 0 ) 
        SDL_ExitWithError("Chargement bouton8");

    SDL_Rect rectBP9;
    rectBP9.w = 100;
    rectBP9.h = 100;
    rectBP9.x = 450;
    rectBP9.y = 350;

    if ( SDL_RenderFillRect(renderer, &rectBP9) != 0 ) 
        SDL_ExitWithError("Chargement bouton9");


    //bouton gamer
    SDL_Rect rectBpNuit;
    rectBpNuit.w = 50;
    rectBpNuit.h = 50;
    rectBpNuit.x = 2;
    rectBpNuit.y = 2;


    if ( SDL_RenderFillRect(renderer, &rectBpNuit) != 0 ) 
        SDL_ExitWithError("Chargement bouton nuit");

    //bouton gamer
    SDL_Rect rectBpGamer;
    rectBpGamer.w = 50;
    rectBpGamer.h = 50;
    rectBpGamer.x = 53;
    rectBpGamer.y = 2;


    if ( SDL_RenderFillRect(renderer, &rectBpGamer) != 0 ) 
        SDL_ExitWithError("Chargement bouton parametre");

}