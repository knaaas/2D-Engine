#ifndef ENGINE_GPU_STORAGE_H
#define ENGINE_GPU_STORAGE_H

#include <cstring>

#include <GL/glew.h>

namespace Engine
{
	template <typename T>
	class CGPUStorage
	{
		public:
			CGPUStorage();
			~CGPUStorage();
			
			//Size in elements of T
			size_t Size();
			
			//Upload memory to GPU, size is not byte-size. It's n of T!
			void Upload( T* src , size_t size );
			
			//Enables vertex array in Opengl. Should be private? 
			void Attribute( bool instanced = false, GLuint devisor =  0);
			
		private:
			
			GLuint m_gpu_buffer_id;
			GLuint m_gpu_buffer_byte_size;
	};
	#include "storage.hpp"
}

#endif //ENGINE_GPU_STORAGE_H
