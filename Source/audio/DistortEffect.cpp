#include "DistortEffect.h"

DistortEffect::DistortEffect(bool vertical) : vertical(vertical) {}

DistortEffect::~DistortEffect() {}

Point DistortEffect::apply(int index, Point input, const std::vector<double>& values, double sampleRate) {
	double value = values[0];
	int vertical = (int)this->vertical;
	if (index % 2 == 0) {
		input.translate((1 - vertical) * value, vertical * value);
	} else {
		input.translate((1 - vertical) * -value, vertical * -value);
	}
	return input;
}
