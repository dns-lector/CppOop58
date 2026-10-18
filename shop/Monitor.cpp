#include "Monitor.h"
#include <format>

double Monitor::getDiagonal() const {
	return diagonal;
}

void Monitor::setDiagonal(double diagonal) {
	this->diagonal = diagonal;
}

std::string Monitor::toString() {
	return std::format(
		"{} {}'' {} hrn ({} W)",
		getName(),
		diagonal,
		getPrice(),
		getPower()
	);
}