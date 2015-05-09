#ifndef GAME_RUN_STATE_H
#define GAME_RUN_STATE_H

#include "game.h"
#include "../state/state.h"

namespace Game
{
	class CRunState : public State::CState
	{
		public:
			CRunState();
			virtual ~CRunState();

			void Initialize( void );
			
			virtual State::CState::SReturn Run();
			
		private:
			CGame m_game;
	};
}

#endif // GAME_RUN_STATE_H
