static int TestThread(void *ptr)
{
    int cnt;

    for (cnt = 0; cnt < 10; ++cnt) {
        printf("Thread counter: %d\n", cnt);
        SDL_Delay(50);
    }

    return cnt;
}

int test(void)
{
    SDL_Thread *thread;
    int threadReturnValue;

    printf("Simple SDL_CreateThread test:\n");

    /* Simply create a thread */
    thread = SDL_CreateThread(TestThread, "TestThread", (void *)NULL);

    if (NULL == thread) {
        printf("SDL_CreateThread failed: %s\n", SDL_GetError());
    } else {
        SDL_WaitThread(thread, &threadReturnValue);
        printf("Thread returned value: %d\n", threadReturnValue);
    }

    return 0;
}
