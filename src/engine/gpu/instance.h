#ifndef ENGINE_GPU_INSTANCE_H
#define ENGINE_GPU_INSTANCE_H

#include "storage.h"

namespace Engine
{
	enum EDrawMode : GLenum 
	{
		Points = GL_POINTS
	};
	
	template <typename T>
	class CGPUInstance
	{
		public:
			CGPUInstance();
			~CGPUInstance();
		
			void Enable( CGPUStorage<T>* storage, bool instanced = false, GLuint devisor = 0 );
			
			void Render( EDrawMode mode, GLint count );
			
		private:
			GLuint m_gpu_vertexarray;
	};
	#include "instance.hpp"
}

#endif //ENGINE_GPU_INSTANCE_H