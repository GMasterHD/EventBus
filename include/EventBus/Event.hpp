#pragma once

namespace eb {
	class Event {
	public:
		Event() {
		}

		/**
		 * @brief Sets if the event has already been cancelled object
		 * 
		 * @param cancel If the event should be cancelled
		 */
		inline void setCancelled(bool cancel = true) { this->cancelled = cancel; }
		/**
		 * @brief Checks if the event is already cancelled
		 * 
		 * @return true Cancelled
		 * @return false Not cancelled
		 */
		inline bool isCancelled() const { return cancelled; }

	private:
		bool cancelled;
	};
}
