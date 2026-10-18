#pragma once
#include "Electrical.h"

class Monitor : public Electrical {
private:
	double      diagonal;
public:
	double      getDiagonal() const;
	void        setDiagonal(double);
	std::string toString() const override;
};
