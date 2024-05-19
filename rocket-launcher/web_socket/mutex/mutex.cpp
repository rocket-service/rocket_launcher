#include "mutex.h"

void fi::web::c_mutex::lock( )
{
	m_mutex.lock( );
}

void fi::web::c_mutex::unlock( )
{
	m_mutex.unlock( );
}

fi::web::c_lock_guard::c_lock_guard( c_mutex& mutex_ )
	: m_mutex( mutex_ )
{
	m_mutex.lock( );
}

fi::web::c_lock_guard::~c_lock_guard( )
{
	if ( m_locked )
		m_mutex.unlock( );
}

void fi::web::c_lock_guard::unlock( )
{
	m_mutex.unlock( );
	m_locked = false;
}
