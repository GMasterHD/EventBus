# Event Bus
## Intention
This library was made in the intention to be as lightweight as possible.  
The event system here may not be for everyone but is a simple way of implementing
it into your own projects.

## Usage
To create a class that can handle events, just let in inherit from `eb::EventObject`

Example:
```C++
#include <EventBus/EventObject.hpp>

class EventClass: public eb::EventObject {
public:
};
```
Now you can use the `dispatchEvent()` function to send a event to it's listeners.

If you wnat to listen on a event, you have to call the `on()` function on your object.

```C++
obj.on("test", [](void* data) {
})
```
The void* can be of any type. In best practice you should create a struct which holds your event data

```C++
class EventClass: public eb::EventObject {
public:
	struct EventData {
		std::string name;
	};

	void run() {
		EventData* d = new EventData;
		d->name = "Name";
		dispatchEvent("test", d);
		delete d;
	}
};

int main() {
	obj.on("test", [](void* data) {
		EventData* e = (EventData*) data;
		std::cout << e->name << std::endl;
	})
}
```
