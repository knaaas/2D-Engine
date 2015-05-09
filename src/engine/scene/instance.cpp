#include "instance.h"

namespace Engine
{
	CSCEInstance::CSCEInstance( CSCECamera *camera )
	: p_camera( camera )
	{
		
	}

	CSCEInstance::~CSCEInstance()
	{
		
	}
	
	CSCECamera *CSCEInstance::Camera()
	{
		return p_camera;
	}
				
}