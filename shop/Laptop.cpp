#include "Laptop.h"
#include <format>

std::string Laptop::getHardware() const {
	return hardware;
}

Laptop* Laptop::setHardware(std::string hardware) {
	this->hardware = hardware;
	return this;  // "fluent interface" - каскадне встановлення властивостей
}

std::string Laptop::toString() const {
	return std::format("{} {} hrn, {} ({} W)",
		getName(),
		getPrice(),
		hardware,
		getPower()
	);
}

std::ostream& operator <<(std::ostream& out, const Laptop& obj) {
	out << obj.toString();
	return out;
}

std::ostream& operator <<(std::ostream& out, const Laptop* obj) {
	out << *obj;  // розіменування покажчика (Dereferencing)
	return out;
}
/*
Type obj;  -- об'єкт статичного типу, розміщується у стеку, 
	створюється оголошенням (окремої команди не треба)
obj.method();  -- виклик методу об'єкта
знищується (запускається деструктор) при завершенні функції
	(при руйнуванні стеку), окремої команди не треба

Type *ptr;  -- покажчик, що може зберігати адресу об'єкта типу Type
	на момент оголошення самого об'єкту немає, а значення ptr випадкове.
ptr = new Type;  -- створення об'єкту у "купі" та одержання його адреси
ptr->method();   -- виклик методу об'єкта через покажчик на нього
при завершенні функції звільняється місце для ptr, але  не сам об'єкт
необхідна окрема команда:
delete ptr;  -- звільнити пам'ять, що виділена під об'єкт (+ запуск деструктора)
*/