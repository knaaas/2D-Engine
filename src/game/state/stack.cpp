#include "stack.h"

namespace state
{
	void cstack::run( cstate& state ){
						
		cstate *active = &state;
		LOG("state::cstack::run - begin" );
		
		//If there are any sub states
		while( active ){
		
			LOG("Running active: " << active );	
			//Run it and grab next sub state
			cstate *sub_state = active->run();
			
			//If any substate. Push the current state
			if( sub_state ){
				LOG( "Pushing active state.");
				m_state.push( active );
			}
			//Otherwise pop previous state
			else if( !m_state.empty() ){
				LOG( "Poping previous state");
				sub_state = m_state.top();
				m_state.pop();
			}
			
			//Make the new state active
			active = sub_state;
		}
		LOG("state::cstack::run - end");
	}
}