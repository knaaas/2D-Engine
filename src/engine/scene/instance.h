#ifndef ENGINE_SCENE_INSTANCE_H
#define ENGINE_SCENE_INSTANCE_H

#include "camera.h"
#include "../gpu/renderer.h"

namespace Engine
{
	class CSCEInstance
	{
		public:
			CSCEInstance( CSCECamera *camera );
			~CSCEInstance();
			
			template <typename T>
			bool Initialize( CRenderer<T> *renderer );
			
			
		private:
			CSCECamera *p_camera;
	};
}

#endif //ENGINE_SCENE_INSTANCE_H