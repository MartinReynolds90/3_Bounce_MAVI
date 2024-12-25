#include "SFML/Graphics.hpp"
#include "iostream"

using namespace std;
using namespace sf;

int main() {
	RenderWindow v(VideoMode(800, 600), "Bounce");
	v.setFramerateLimit(60);

	Event e;
	Clock reloj;
	Time tiempo;

	CircleShape objeto;
	objeto.setFillColor(Color::Blue);
	objeto.setRadius(40);
	objeto.setOrigin(40, 40);
	objeto.setPosition(v.getSize().x / 2, 50);

	
	float vel_caida = 0.0;
	float aceleracion = 9.8;

		while (v.isOpen()) {
		tiempo = reloj.getElapsedTime();

		vel_caida = vel_caida + (aceleracion * (tiempo.asSeconds() / 60));
		objeto.move(0, vel_caida);// la velocidad de caida se esta aplicando todo el tiempo
		
		if (objeto.getPosition().y >= 570) {//rebota
			vel_caida = vel_caida * (-1) + (vel_caida* 0.1);//disminuye un 10% con cada rebote
			objeto.setPosition(objeto.getPosition().x, 569);
		}
		if (objeto.getPosition().y <= 10) {  
			vel_caida = vel_caida * (-1);
		}

		while (v.pollEvent(e)) {
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					v.close();
				}
			}
		}


		v.clear(Color::Black);
		v.draw(objeto);
		v.display();
	}

	return 0;

}