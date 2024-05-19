#pragma once
#include <memory>
#include <system_error>

#include <asio.hpp>
#include <asio/steady_timer.hpp>

namespace fi::web
{
	namespace make_error_code = std;
	namespace error = asio::error;

	using error_code_t = std::error_code;
	using errc_t = std::errc;
	using system_error_t = std::system_error;

	using io_context_t = asio::io_context;
	using resolver_results_t = asio::ip::tcp::resolver::results_type;

	using async_connect_endpoint_t = asio::ip::tcp::endpoint;
	using strand_t = asio::strand<asio::any_io_executor>;

	template <typename _handler_type>
	FORCEINLINE void post( io_context_t& ctx, _handler_type&& handler )
	{
		asio::post( ctx, std::forward<_handler_type>( handler ) );
	}

	template<typename _socket_type, typename _duration_type>
	FORCEINLINE std::unique_ptr<asio::steady_timer> make_steady_timer( _socket_type& socket, std::chrono::duration<_duration_type> duration )
	{
		return std::make_unique<asio::steady_timer>( socket.get_executor( ), duration );
	}

	template<typename _socket_type>
	FORCEINLINE asio::basic_socket<asio::ip::tcp>::executor_type get_executor( _socket_type& socket )
	{
		return socket.get_executor( );
	}

	template<typename _execution_ctx, typename _handler_type>
	FORCEINLINE asio::executor_binder<typename asio::decay<_handler_type>::type, typename _execution_ctx::executor_type>
		bind_executor( strand_t& strand, _handler_type&& handler )
	{
		return asio::bind_executor( strand, std::forward<_handler_type>( handler ) );
	}

	template<typename _handler_type>
	FORCEINLINE void async_resolve( asio::ip::tcp::resolver& resolver,
									const std::pair<std::string, std::string>& host_port, _handler_type&& handler )
	{
		return resolver.async_resolve( host_port.first, host_port.second, std::forward<_handler_type>( handler ) );
	}

	void restart( io_context_t& ctx ) noexcept;

	asio::ip::address make_address( std::string const& str ) noexcept;
	asio::executor_work_guard<io_context_t::executor_type> make_work_guard( io_context_t& ctx );
}
