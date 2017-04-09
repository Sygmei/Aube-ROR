#include "ErrorHandler.hpp"

namespace aube
{
	ErrorMessage::ErrorMessage(std::string file, std::vector<std::string> location, std::string message)
	{
		m_file = file;
		m_location = location;
		m_message = message;
	}

	std::string ErrorMessage::getFile() const
	{
		return m_file;
	}

	std::string ErrorMessage::getLocation()
	{
		std::string stringLocation = m_location[0];
		for (int i = 1; i < m_location.size(); i++)
		{
			stringLocation += "::" + m_location[i];
		}
		return stringLocation;
	}

	std::string ErrorMessage::getMessage() const
	{
		return m_message;
	}

	void ErrorHandler::Load(std::string errorId, std::string filename, std::vector<std::string> location, std::string message)
	{
		m_errors[errorId] = ErrorMessage(filename, location, message);
	}

	std::exception ErrorHandler::Raise(std::string errorId)
	{
		ErrorMessage currentError = m_errors[errorId];
		std::string errorMessage = "[" + errorId + "]{" + currentError.getFile() + "}";
		errorMessage += "<" + currentError.getLocation() + "> : " + currentError.getMessage();
		return std::exception(errorMessage.c_str());
	}
}