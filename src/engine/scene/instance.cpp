#include "instance.cpp"

namespace Engine
{
	CSCEInstance::CSCEInstance( CSCECamera *camera )
	: p_camera( camera )
	{
		
	}

	CSCEInstance::~CSCEInstance()
	{
		
	}
				
	template <typename T>
	bool CSCEInstance::Initialize( CGPURenderer<T> *renderer )
	{
		return p_camera->BindGPUProgram( renderer->m_program );
	}
}