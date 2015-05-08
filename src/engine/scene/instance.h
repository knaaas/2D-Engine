#ifndef ENGINE_SCENE_INSTANCE_H
#define ENGINE_SCENE_INSTANCE_H

#include "camera.h"
#include "../gpu/renderer.h"

namespace Engine
{
	/*
		This should only be created once,
		due to my lazy-ass and some limitations in OpenGL.
		
		To solve the issue, different uniform-buffer indexes 
		must be used in different instances. Or at least I 
		believe so, so far as I know. 
		
		NOTE: 
		Singleton is ugly, don't do it.  
		
	*/
	class CSCEInstance
	{
		public:
			CSCEInstance( CSCECamera *camera );
			~CSCEInstance();
			
			/*
				Make a renderer usable in this instance.
				
				Note: It can only belong to one instance,
				calling the function in another instance
				will break the old. 
			*/
			
			template <typename T>
			bool Initialize( CGPURenderer<T> *renderer );
			
			
		private:
			CSCECamera *p_camera;
	};
}

#endif //ENGINE_SCENE_INSTANCE_H
