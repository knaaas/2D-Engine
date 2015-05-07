#ifndef ENGINE_GPU_INSTANCE_H
#define ENGINE_GPU_INSTANCE_H

#include "storage.h"

namespace Engine
{
	template <typename T>
	class CGPUInstance
	{
		public:
			CGPUInstance();
			~CGPUInstance();
			
			template <typename T>
			void Enable( CGPUStorage<T> *Storage );
			
			void Render( GLint count );
	};
}

#endif //ENGINE_GPU_INSTANCE_H