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

namespace Game
{
	class CGame
	{
		public:
			CGame();
			~CGame();
			
			bool Initialize( int width, int height, const char *title, bool fullscreen = false );
			
			void Run();
			
		private:
			GLFWwindow* m_window;
			bool m_glfw_init_state;
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
