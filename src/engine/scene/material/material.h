#ifndef ENGINE_SCENE_MATERIAL_H
#define ENGINE_SCENE_MATERIAL_H

namespace Engine
{
	namespace Material
	{
		class CMaterial
		{
			public:
				virtual bool InitializeProgram( CProgram* program ) = 0;
				virtual void Enable() = 0;
				virtual void Disable() = 0;	
			private:
		};
	}
}

#endif //ENGINE_SCENE_MATERIAL_H