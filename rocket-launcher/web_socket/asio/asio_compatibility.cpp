#include "asio_compatibility.h"

void fi::web::restart(io_context_t& ctx) noexcept
{
	ctx.restart( );
}

asio::ip::address fi::web::make_address(std::string const& str) noexcept
{
	return asio::ip::make_address( str );
}

asio::executor_work_guard<asio::io_context::executor_type> fi::web::make_work_guard(io_context_t& ctx)
{
	return asio::make_work_guard( ctx );
}
