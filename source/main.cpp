#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

#include "gamemanager.h"
#include "window.h"

void mainLoop(GameManager* m, Window* w) {
    bool quit = false;
    while (!quit) {
        quit = m->pollInput();
        m->runFrame();
        w->draw(m);
    }
}

int main(int argc, char* args[]) {
    Window* w = new Window();
    GameManager* g = new GameManager();
    if (g->init() && w->init(SCREEN_WIDTH, SCREEN_HEIGHT)) {
        mainLoop(g, w);
    }
    delete w;
    delete g;
    SDL_Quit();
    return 0;
}
