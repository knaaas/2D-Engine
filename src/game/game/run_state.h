#ifndef GAME_RUN_STATE_H
#define GAME_RUN_STATE_H

#include "game.h"
#include "../state/state.h"

#include "../../engine/platform/platform.h"


namespace Game
{
	class CRunState : public State::CState
	{
		public:
			CRunState(Engine::CPlatform *platform);
			virtual ~CRunState();

			void Initialize( void );
			
			virtual State::CState::SReturn Run();
			
		private:
			Engine::CPlatform *p_platform;
			CGame m_game;
	};
}

#endif // GAME_RUN_STATE_H
