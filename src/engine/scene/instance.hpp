
template <typename T>
bool CSCEInstance::Initialize( CGPURenderer<T> *renderer )
{
	const GLuint camera_buffer_index = 0;
	return p_camera->BindGpuProgram( &renderer->m_program, camera_buffer_index );
}