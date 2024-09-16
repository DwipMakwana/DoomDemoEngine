#pragma once

	class TextureLoader
	{
	public:

		struct TextureMaps
		{
			int w, h;					//Texture width and height
			const int* name;			//Texture name
		};

		TextureMaps Textures[64];

		void Load();
		void DefineTextures();
	};

