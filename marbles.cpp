// marbles.cpp /////////////////////////////////////////////////////////////////
// testing a shader to draw nice planets in 2d without /////////////////////////
// crazy opengl work ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Shaders");
	sf::Texture planet_tex;
	if(!planet_tex.loadFromFile("./earth.png"))
	{	std::cout << "Unable to load planet png file" << std::endl;
		return -1;
	}
	planet_tex.setRepeated(true	);
	sf::Sprite planet_sprite;
	planet_sprite.setTexture(planet_tex);
	//planet_sprite.setPosition(sf::Vector2f(200,200));
	planet_sprite.setScale(0.25, 0.25);
	
	 sf::Shader shader;

	// load only the vertex shader
	if(!shader.loadFromFile("./awesome.vert", "./awesome.frag"))
	{	std::cout << "Unable to load shaders" << std::endl;
		// error...
		return -2;
	}
	shader.setParameter("resolution", sf::Vector2f(1000, 600));
	//shader.setParameter("resolution.x", 1000);
	//shader.setParameter("resolution.y", 600);		
	
	// dont know why this dont work, b

	sf::Clock clock;
	float time = 0;

	while (window.isOpen())
	{	sf::Event event;
		while (window.pollEvent(event))
		{	if (event.type == sf::Event::Closed)
			{	window.close();
			}
		}
		
		window.clear();
		time += clock.restart().asSeconds()/10;
		shader.setParameter("time", time);
		
		window.draw(planet_sprite, &shader);
		//window.draw(planet_sprite);		
		window.display();
    }
    return 0;
}


