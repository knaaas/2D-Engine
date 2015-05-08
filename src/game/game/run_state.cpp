#include "run_state.h"

namespace Game
{
	CRunState::CRunState()
	: m_window( nullptr ) 
	{}
	
	CRunState::~CRunState()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
			
	void CRunState::Initialize( void )
	{
		if(!glfwInit())
			std::cerr << "ERROR: run_state glfwInit() failed" << std::endl;
			
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		if ((m_window = glfwCreateWindow(640, 480, "This is a game title", NULL, NULL)) == false)
			std::cerr << "ERROR: run_state glfwCreateWindow() failed" << std::endl;
		
		glfwMakeContextCurrent(m_window);
	}
			
	State::CState::SReturn CRunState::Run()
	{
	
		//Run the game here..
		return State::CState::SReturn();
	}
}
