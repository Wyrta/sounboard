#include <C:\Users\****\Desktop\projet_tut\include/SDL/SDL.h>

//dimention fenetre
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int afficherImage(const char imagePath, SDL_Window **window, SDL_Renderer **renderer);

int afficherImage(char imagePath, SDL_Window **window, SDL_Renderer **renderer) {
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;

    image = SDL_LoadBMP(imagePath);
    
    if(image == NULL)
        SDL_ExitErrorTexture ("Erreur creation image", &window, &renderer, &texture); //si bug => exit en tuant tt

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image); //libere la memoire de l'image : creation de la texture fait

    if(texture == NULL) 
        SDL_ExitErrorTexture ("Erreur creation texture avec l'image", &window, &renderer, &texture); //si bug => exit en tuant tt

    SDL_Rect rectangleImage;

    // parametre => texture a afficher, format RAW : NULL pour pas de prob, point acces texture NULL pour pas de prob, largeur img, hauteeur img
    if (SDL_QueryTexture(texture, NULL, NULL, &rectangleImage.w, &rectangleImage.h) != 0)
        SDL_ExitErrorTexture ("Erreur chargement texture", &window, &renderer, &texture); //si bug => exit en tuant tt


    rectangleImage.x = (WINDOW_WIDTH - rectangleImage.w) / 2;
    rectangleImage.y = (WINDOW_HEIGHT - rectangleImage.h) / 2;

    if (SDL_RenderCopy(renderer, texture, NULL, &rectangleImage) != 0) 
        SDL_ExitErrorTexture ("Erreur affichage texture", &window, &renderer, &texture); //si bug => exit en tuant tt

    SDL_RenderPresent(renderer);
    return EXIT_SUCCESS;
}

