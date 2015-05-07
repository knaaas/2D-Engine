#include <gl/glew.h>
#include <gl/glfw.h>

#include "gpu/storage.h"
#include "gpu/instance.h"


struct SSprite
{
	glm::vec2 position;
	glm::vec2 size;
};

typedef Engine::CGPUStorage< SSprite > GPUSpriteStorage;
typedef Engine::CGPUInstance< SSprite > GPUSpriteInstance;

int main( int args, char *argv[])
{
	
	//Platform init code
	GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    
	if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
	glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
	
	glewExperimental = GL_TRUE;
	if( GL_TRUE != glewInit())
	{
		glfwTerminate();
        exit(EXIT_FAILURE);
	}
	//End of platform init code
	

	
	const size_t sprite_count = 128;
	SSprite *SpritesOfGods = new SSprite[sprite_count];
	
	
	GPUSpriteStorage *SpriteStorage = new GPUSpriteStorage();
	GPUSpriteInstance *SpriteInstance = new GPUSpriteInstance();
	
	SpriteStorage->upload( SpritesOfGods, sprite_count );
	SpriteInstance->enable( SpriteStorage );
	
	
	SpriteInstance->render( SpriteStorage->size() );
	
	
	//PLATFORM
	glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
	
}