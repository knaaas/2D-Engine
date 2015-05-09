#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include <cstdlib>

#include <gl/glew.h> 
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "../../engine/gpu/state.h"
#include "../../engine/gpu/shader.h"
#include "../../engine/gpu/storage.h"
#include "../../engine/gpu/instance.h"
#include "../../engine/gpu/renderer.h"

#include "../../engine/platform/platform.h"


namespace Game
{
	class CGame
	{
		public:
			CGame();
			~CGame();
			
			void Run(Engine::CPlatform* platform);
			
		private:
	};
	
	struct SSprite
	{
		glm::vec2 position;
		glm::vec2 size;
		glm::vec3 color;
		
		static void Attribute( bool instanced, GLuint devisor );
	};

	typedef Engine::CGPUStorage< SSprite >  GPUSpriteStorage;
	typedef Engine::CGPUInstance< SSprite > GPUSpriteInstance;
	typedef	Engine::CGPURenderer< SSprite > GPUSpriteRenderer;
}

#endif // GAME_GAME_H
