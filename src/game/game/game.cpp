#include "game.h"

namespace Game
{
	CGame::CGame()
	: m_window( nullptr )
	{
	
		// GLFW Init
		if(!glfwInit())
			std::cerr << "ERROR: CGame glfwInit() failed" << std::endl;
			
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		if ((m_window = glfwCreateWindow(640, 480, "This is a game title", NULL, NULL)) == false)
			std::cerr << "ERROR: CGame glfwCreateWindow() failed" << std::endl;
		
		glfwMakeContextCurrent(m_window);

		// OpenGL Init
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			std::cerr << "ERROR: CGame glewInit() failed" << std::endl;
		}
	}
	
	CGame::~CGame()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void CGame::Run()
	{
	}
}