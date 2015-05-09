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
	}
			
	State::CState::SReturn CRunState::Run()
	{
		//Run the game here..
		CGame Game;
		Game.Run();
		return State::CState::SReturn();
	}
}
