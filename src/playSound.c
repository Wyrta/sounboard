//Joue le son en parametre
void playSound(char* son, char *audioID, SDL_Renderer *renderer);



void playSound(char* son, char *audioID, SDL_Renderer *renderer) {
    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;


    // open audio device
    SDL_LoadWAV(son, &wavSpec, &wavBuffer, &wavLength);
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(audioID, 0, &wavSpec, NULL, 0);   //1er parametre => audio device peripheriqueAudio

    // play audio
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);

    SDL_FreeWAV(wavBuffer);
    
    SDL_Rect sonJouerBP;
    sonJouerBP.h = 30;
    sonJouerBP.w = 30;
    sonJouerBP.x = 748;
    sonJouerBP.y = 548;
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &sonJouerBP);
    SDL_RenderPresent(renderer);

    SDL_Delay(wavLength/176);
    
    SDL_CloseAudioDevice(deviceId);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    //audiolenght/((44100(frequence)*2(bytes)*2(stereo))/1000)

}