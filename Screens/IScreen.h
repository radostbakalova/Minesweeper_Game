#pragma once
#include "ScreenResult.h"

class IScreen {
public:
	virtual void display() const = 0;
	virtual ScreenResult handleInput() = 0;
	virtual ~IScreen() = default;
};

