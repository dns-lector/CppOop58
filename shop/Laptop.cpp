#include "Laptop.h"
#include <format>

std::string Laptop::getHardware() const {
	return hardware;
}

void Laptop::setHardware(std::string hardware) {
	this->hardware = hardware;
}

std::string Laptop::toString() const {
	return std::format("{} {} hrn, {} ({} W)",
		getName(),
		getPrice(),
		hardware,
		getPower()
	);
}