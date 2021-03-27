//Fenêtre des parametres
int parametre(SDL_Renderer *renderer);

int parametre(SDL_Renderer *renderer) {
    //SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE)
    if ( SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE) != 0 )
        SDL_ExitWithError("Changement de couleur => bleu");

    SDL_Rect textInput;

    textInput.w = 200;
    textInput.h = 50;
    textInput.x = 0;
    textInput.y = 0;

    //SDL_RenderFillRect(renderer, &textInput)
    if ( SDL_RenderFillRect(renderer, &textInput) != 0 ) 
        SDL_ExitWithError("affichage rectangle textinput");
    
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    SDL_bool parametreFenetre = SDL_TRUE;
    int posX, posY;

    while(parametreFenetre) {
        SDL_Event event;

        SDL_Delay(16);  //met en 60fps 'fin presque     1000ms / 60images/sec = 16ms
        SDL_RenderPresent(renderer);
        
        while (SDL_PollEvent(&event) ) {     // des qu'il y a un evenement on rentre dans la boucle

            if(SDL_GetMouseState(&posX, &posY) & SDL_BUTTON_LMASK ) {
            
                if ((posX < 52) & (posX > 0)) {             
                    if ((posY < 52) & (posY > 2)) {
                        return EXIT_SUCCESS;
                    }
                }
            }

            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)   //en fonction des touches du clavier
                    {
                    case SDLK_ESCAPE: {      //si appuie sur echap
                        parametreFenetre = SDL_FALSE;
                    } continue; 

                    default: continue;
                    }

                case SDL_QUIT: parametreFenetre = SDL_FALSE; break; //si on clique sur la croix on sort de la boucle
                default: continue;
            }


        }
    }
    return EXIT_SUCCESS;
}