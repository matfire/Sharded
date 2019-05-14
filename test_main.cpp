#include "Engine.h"

int main()
{
	Engine engine;

	if (!engine.start("test win"))
		return 1;

	while(true) {
		engine.update();
		engine.render();
	}
}
