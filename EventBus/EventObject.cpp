#include <EventBus/EventObject.hpp>
#include <cstdint>

namespace eb {
	EventObject::EventObject() {
	}
	EventObject::~EventObject() {
	}

	void EventObject::on(const std::string& event, EventFunction func) {
		if(onFunctions.find(event) == onFunctions.end()) {
			onFunctions.insert(std::pair(event, std::vector<EventFunction>()));
		}
		onFunctions[event].push_back(func);
	}
	void EventObject::once(const std::string& event, EventFunction func) {
		if(onceFunctions.find(event) == onFunctions.end()) {
			onceFunctions.insert(std::pair(event, std::vector<EventFunction>()));
		}
		onceFunctions[event].push_back(func);
	}
	
	void EventObject::dispatchEvent(const std::string& event, void* data) {
		for(auto it = onFunctions.begin(); it != onFunctions.end(); ++it) {
			if(it->first == event) {
				for(uint32_t i = 0; i < it->second.size(); ++i) {
					it->second[i](data);
				}
			}
		}
		for(auto it = onceFunctions.begin(); it != onceFunctions.end(); ++it) {
			if(it->first == event) {
				for(uint32_t i = 0; i < it->second.size(); ++i) {
					it->second[i](data);
				}
			}
		}
	}
}
