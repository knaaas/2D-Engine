#include "camera.h"

namespace Engine
{
	
	bool CSCECamera::BindGpuProgram(CProgram* program, GLuint index)
	{
		GLint uniform_index = program->UniformBlock("sce_camera");
		
		if( uniform_index == -1)
			return false;
		
		program->BindBlock( uniform_index, index );
		m_state.Bind( index );
	}
			
	
	glm::vec2& CSCECamera::Position()
	{
		return m_state.position;
	}
	
	const glm::vec2& CSCECamera::Position() const
	{
		return m_state.position;
	}
	

	float& CSCECamera::Zoom()
	{
		return m_state.zoom;
	}
	
	const float& CSCECamera::Zoom() const
	{
		return m_state.zoom;
	}
	
	void+ CSCECamera::UpdateGpuBuffer()
	{
		m_gpu_state.state( m_state );
	}
	
}