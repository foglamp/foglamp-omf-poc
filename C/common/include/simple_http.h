#ifndef _SIMPLE_HTTP_H
#define _SIMPLE_HTTP_H
/*
 * FogLAMP HTTP Sender wrapper.
 *
 * Copyright (c) 2018 OSisoft, LLC
 *
 * Released under the Apache 2.0 Licence
 *
 * Author: Massimiliano Pinto, Mark Riddoch
 */

#include <string>
#include <vector>
#include <http_sender.h>
#include <client_http.hpp>

using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;

class SimpleHttp: public HttpSender
{
	public:
		/**
		 * Constructor:
		 */
		SimpleHttp(const std::string& host_port);

		// Destructor
		~SimpleHttp();

		/**
		 * HTTP(S) request: pass method and path, HTTP headers and POST/PUT payload.
		 */
		int sendRequest(const std::string& method = std::string(HTTP_SENDER_DEFAULT_METHOD),
				const std::string& path = std::string(HTTP_SENDER_DEFAULT_PATH),
				const std::vector<std::pair<std::string, std::string>>& headers = {},
				const std::string& payload = std::string());
	private:
		std::string	m_host_port;
		HttpClient	*m_sender;
		
};

#endif
