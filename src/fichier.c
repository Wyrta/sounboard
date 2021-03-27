//Test si un fichier existe : retourne 1 si il existe sinon 0.
int fichierExiste(const char *nomFichier); 

//Retourne le contenu du fichier en parametre, si le fichier est inexistant retourne 0.
char *contenuFichier(const char *nomFichier);

int fichierExiste(const char  *nomFichier) {
    //on essaye d'ouvrir le fichier pour voir si il existe

    FILE *fichier;
    if (fichier = fopen(nomFichier, "r")) {
        fclose(fichier);
        return 1;
    }
    return 0;
}

char *contenuFichier(const char *nomFichier) {
    char *txtFichier;
    FILE *fichier;

    if (fichier = fopen(nomFichier, "r")) {
        fgets(txtFichier, 100, fichier);

        //if((txtFichier[1] == 32) | (txtFichier[1] == 0)) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Leture fichier", "On dirais que le fichier est vide", NULL);

        fclose(fichier);
        return txtFichier;
    }
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Leture fichier", "Fichier inexistant", NULL);
    return 0;
}