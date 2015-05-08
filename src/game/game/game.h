#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>

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
			void Run();
			
		private:
			GLFWwindow* m_window;
	};
}

#endif // GAME_GAME_H
