#include "Tileset.h"

namespace map {

	Tileset::Tileset(const char* name, const char* filePath) :
		m_Name(name) 
	{
		m_Texture = LoadTexture(filePath);
	}

	Tileset::~Tileset() {
		UnloadTexture(m_Texture);
	}

}