#ifndef ENGINE_SCENE_CAMERA_H
#define ENGINE_SCENE_CAMERA_H

#include <glm/glm.hpp>

#include "../gpu/state.h"
#include "../gpu/shader.h"

namespace Engine
{
	class CSCECamera
	{
		private:
			struct SCamera
			{
				SCamera(): zoom( 1.0f ){}
				glm::vec2 position;
				float 	  zoom;
			};
			
			SCamera m_state;
			CGPUState<SCamera> m_gpu_state;
		
			friend class CSCEInstance;
		
			/**
				Tries to bind "sce_camera" uniform block
				in program to the camera buffer. 
			**/
			bool BindGpuProgram(CProgram* program, GLuint location);
			
		
		public:
			CSCECamera();
			
		
			
			/**
				Update camera GPU buffer. 
				Should be done before rendering. 
				Will be made private. 
			**/
			void UpdateGpuBuffer();
			
			
			
			glm::vec2& Position();
			const glm::vec2& Position() const;
			
			float& Zoom();
			const float& Zoom() const;
	};
}

#endif //ENGINE_SCENE_CAMERA_H