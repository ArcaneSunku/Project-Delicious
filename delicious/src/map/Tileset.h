#pragma once

#include <raylib.h>

namespace map {

	struct Tile {
		int id = -1;
		Rectangle rect;
	};

	class Tileset {
	public:
		Tileset(const char* name, const char* texturePath);
		~Tileset();

	private:
		const char* m_Name;
		Texture m_Texture;
	};

}