#include "Platform.hpp"
#include <glad/glad.h>
#include <SDL.h>
#include <iostream>


Platform::Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window) {
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	gl_context = SDL_GL_CreateContext(window);
	if (!gl_context) {
		std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	glGenTextures(1, &framebuffer_texture);
	glBindTexture(GL_TEXTURE_2D, framebuffer_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 640, 320, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Platform::~Platform()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Platform::Update(void const* buffer, int pitch)
{
	SDL_UpdateTexture(texture, nullptr, buffer, pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
}

bool Platform::ProcessInput(uint8_t* keys)
{
	bool quit = false;

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				quit = true;
			} break;

			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						quit = true;
					} break;

					case SDLK_x:
					{
						keys[0] = 1;
					} break;

					case SDLK_1:
					{
						keys[1] = 1;
					} break;

					case SDLK_2:
					{
						keys[2] = 1;
					} break;

					case SDLK_3:
					{
						keys[3] = 1;
					} break;

					case SDLK_q:
					{
						keys[4] = 1;
					} break;

					case SDLK_w:
					{
						keys[5] = 1;
					} break;

					case SDLK_e:
					{
						keys[6] = 1;
					} break;

					case SDLK_a:
					{
						keys[7] = 1;
					} break;

					case SDLK_s:
					{
						keys[8] = 1;
					} break;

					case SDLK_d:
					{
						keys[9] = 1;
					} break;

					case SDLK_z:
					{
						keys[0xA] = 1;
					} break;

					case SDLK_c:
					{
						keys[0xB] = 1;
					} break;

					case SDLK_4:
					{
						keys[0xC] = 1;
					} break;

					case SDLK_r:
					{
						keys[0xD] = 1;
					} break;

					case SDLK_f:
					{
						keys[0xE] = 1;
					} break;

					case SDLK_v:
					{
						keys[0xF] = 1;
					} break;
				}
			} break;

			case SDL_KEYUP:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_x:
					{
						keys[0] = 0;
					} break;

					case SDLK_1:
					{
						keys[1] = 0;
					} break;

					case SDLK_2:
					{
						keys[2] = 0;
					} break;

					case SDLK_3:
					{
						keys[3] = 0;
					} break;

					case SDLK_q:
					{
						keys[4] = 0;
					} break;

					case SDLK_w:
					{
						keys[5] = 0;
					} break;

					case SDLK_e:
					{
						keys[6] = 0;
					} break;

					case SDLK_a:
					{
						keys[7] = 0;
					} break;

					case SDLK_s:
					{
						keys[8] = 0;
					} break;

					case SDLK_d:
					{
						keys[9] = 0;
					} break;

					case SDLK_z:
					{
						keys[0xA] = 0;
					} break;

					case SDLK_c:
					{
						keys[0xB] = 0;
					} break;

					case SDLK_4:
					{
						keys[0xC] = 0;
					} break;

					case SDLK_r:
					{
						keys[0xD] = 0;
					} break;

					case SDLK_f:
					{
						keys[0xE] = 0;
					} break;

					case SDLK_v:
					{
						keys[0xF] = 0;
					} break;
				}
			} break;
		}
	}

	return quit;
}
