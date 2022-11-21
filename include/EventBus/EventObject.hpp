#pragma once
#include <string>
#include <functional>
#include <unordered_map>

namespace eb {
	class EventObject {
	public:
		using EventFunction = std::function<void(void*)>; 

		EventObject();
		~EventObject();

		/**
		 * @brief Listens on a event
		 * 
		 * @param event The event name
		 * @param func The event function
		 */
		void on(const std::string& event, EventFunction func);
	
	protected:
		/**
		 * @brief Dispatches an event into the event stack
		 * 
		 * @param event The event name
		 * @param data The event data
		 */
		void dispatchEvent(const std::string& event, void* data);

	private:
		std::unordered_map<std::string, std::vector<EventFunction>> onFunctions;
	};
}
