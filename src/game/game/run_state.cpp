#include "run_state.h"

namespace Game
{
	CRunState::CRunState(Engine::CPlatform *platform)
	: p_platform( platform )
	{
		assert( p_platform );
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
		p_platform->CreateWindow( 800, 600, "Game", false );
		m_game.Run( p_platform );
		p_platform->DestroyWindow();
		return State::CState::SReturn();
	}
}
