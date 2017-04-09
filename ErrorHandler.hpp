#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <exception>

namespace aube
{
	class ErrorMessage
	{
	private:
		std::string m_file;
		std::vector<std::string> m_location;
		std::string m_message;
	public:
		ErrorMessage(std::string file, std::vector<std::string> location, std::string message);
		std::string getFile() const;
		std::string getLocation();
		std::string getMessage() const;
	};

	class ErrorHandler
	{
	private:
		static std::map<std::string, ErrorMessage> m_errors;
	public:
		static void Load(std::string errorId, std::string filename, std::vector<std::string> location, std::string message);
		static std::exception Raise(std::string errorId);
	};
}