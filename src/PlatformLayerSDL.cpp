#include "Platform.hpp"
#include <SDL3/SDL.h>
#include <iostream>

Platform::Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }

    window = SDL_CreateWindow(title, windowWidth, windowHeight, 0);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }

    texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, textureWidth, textureHeight);
    if (!texture) {
        std::cerr << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }
}

Platform::~Platform()
{
    if (texture) SDL_DestroyTexture(texture);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void Platform::Update(void const* buffer, int pitch)
{
    SDL_UpdateTexture(texture, nullptr, buffer, pitch);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

bool Platform::ProcessInput(uint8_t* keys)
{
    bool quit = false;
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                quit = true;
                break;

            case SDL_EVENT_KEY_DOWN:
            case SDL_EVENT_KEY_UP: {
                bool pressed = (event.type == SDL_EVENT_KEY_DOWN);
                switch (event.key.key) {
                    case SDL_SCANCODE_ESCAPE: quit = pressed; break;
                    case SDL_SCANCODE_X: keys[0] = pressed; break;
                    case SDL_SCANCODE_1: keys[1] = pressed; break;
                    case SDL_SCANCODE_2: keys[2] = pressed; break;
                    case SDL_SCANCODE_3: keys[3] = pressed; break;
                    case SDL_SCANCODE_Q: keys[4] = pressed; break;
                    case SDL_SCANCODE_W: keys[5] = pressed; break;
                    case SDL_SCANCODE_E: keys[6] = pressed; break;
                    case SDL_SCANCODE_A: keys[7] = pressed; break;
                    case SDL_SCANCODE_S: keys[8] = pressed; break;
                    case SDL_SCANCODE_D: keys[9] = pressed; break;
                    case SDL_SCANCODE_Z: keys[0xA] = pressed; break;
                    case SDL_SCANCODE_C: keys[0xB] = pressed; break;
                    case SDL_SCANCODE_4: keys[0xC] = pressed; break;
                    case SDL_SCANCODE_R: keys[0xD] = pressed; break;
                    case SDL_SCANCODE_F: keys[0xE] = pressed; break;
                    case SDL_SCANCODE_V: keys[0xF] = pressed; break;
                }
                break;
            }
        }
    }
    return quit;
}