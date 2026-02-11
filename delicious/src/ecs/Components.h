#pragma once

namespace ecs {

	struct Position {
		float x, y;
	};

	struct Size {
		float width, height;
	};

	struct MobData {
		float health, maxHealth;
		float stamina, maxStamina;
		float mana, maxMana;
	} typedef Mob;

}