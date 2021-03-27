void SDL_ExitWithError(const char *messageErreur);
void SDL_ExitErrorTexture (const char *message, SDL_Window **window, SDL_Renderer **renderer , SDL_Texture **texture);

//Fonction qui détecte erreur et la renvoie
void SDL_ExitWithError(const char *messageErreur) {    
    SDL_Log("ERREUR : %s, %s", messageErreur, SDL_GetError() );

    getchar(); //laisse le temps de lire le msg d'erreur
    SDL_Quit();
    exit(EXIT_FAILURE);
}

//Fonction affiche l'erreur, détruit fenetre et rendu puis ferme prog
void SDL_ExitErrorTexture (const char *message, SDL_Window **window, SDL_Renderer **renderer , SDL_Texture **texture) {
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_DestroyTexture(*texture);
    SDL_ExitWithError(message);
}