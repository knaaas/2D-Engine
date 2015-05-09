#include "run_state.h"

namespace Game
{
	CRunState::CRunState()
	{
	}
	
	CRunState::~CRunState()
	{
	}
			
	void CRunState::Initialize( void )
	{
		m_game.Initialize( 800, 600, "GameWindow", false );

	}
			
	State::CState::SReturn CRunState::Run()
	{
		//Run the game here..
		m_game.Run();
		return State::CState::SReturn();
	}
}
