#ifndef ENGINE_GPU_RENDERER_H
#define ENGINE_GPU_RENDERER_H

#include "shader.h"
#include "instance.h"

namespace Engine
{
	/*
		There are a possibility that this file will be moved to /scene. 
		Don't relie on this file's path or class-name, typedef them. 
		
		The functionality is unlikely to change. 
		
		The Render function dosen't do anything except calling render in
		instance, but garanties that the data will be of T-type. This 
		maybe changed in the future. 
		
		The "Program" functions will removed in near future. 
		Don't use them.    
	*/
	
	template <typename T>
	class CGPURenderer
	{
		public:
			CGPURenderer();
			
			/*
				Enable/Disable should be called before/after Render. 
				Try to render everything of T-type between and don't
				Enable/Disable to much. it will have a  performance 
				impact. 
			*/
			
			void Enable();
			void Disable();
			
			void Render( CGPUInstance<T> * instance, EDrawMode mode, GLuint count );
			
			
			//NO, DON'T USE THEM. WILL BE REMOVED!
			//But I like them :(
			CProgram& Program();
			const CProgram& Program() const;
			
		private:
			friend class CSCEInstance;
			CProgram m_program;
	};
	#include "renderer.hpp"
}

#endif //ENGINE_GPU_RENDERER_H
