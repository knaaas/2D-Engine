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
	
	
	const size_t sprite_count = 128;
	SSprite *SpritesOfGods = new SSprite[sprite_count];
	
	
	GPUSpriteStorage *SpriteStorage = new GPUSpriteStorage();
	GPUSpriteInstance *SpriteInstance = new GPUSpriteInstance();
	
	SpriteStorage->upload( SpritesOfGods, sprite_count );
	SpriteInstance->enable( SpriteStorage );
	
	
	SpriteInstance->render( SpriteStorage->size() );
	
	
}