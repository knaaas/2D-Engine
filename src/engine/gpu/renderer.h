#ifndef ENGINE_GPU_RENDERER_H
#define ENGINE_GPU_RENDERER_H

#include "program.h"

namespace Engine
{
	template <typename T>
	class CGPURenderer
	{
		public:
			CGPURenderer();
			
			void Initialize( Material::CMaterial *material );
			
			void Enable();
			void Disable();
			
			void Render( CGPUInstance<T> * instance, GLuint count );
			
		private:
			friend class CSCEInstance:
			
			CProgram m_program;
	};
	#include "renderer.hpp"
}

#endif //ENGINE_GPU_RENDERER_H