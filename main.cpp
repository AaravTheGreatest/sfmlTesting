#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Zandris");
  sf::Texture placeholder ("gradientPlaceholder.png", false, sf::IntRect({1, 1}, {750, 550}));
  sf::Texture texture("image.png", false, sf::IntRect({1, 1}, {40, 32}));
  sf::Sprite sprite(texture);
  sf::Sprite heart(placeholder);
  float normalSpeed = 1.f, sprintSpeed = 5.f, speed = 1.f;
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) window.close();
      else if (const auto* key = event -> getIf<sf::Event::KeyPressed>()) {
        speed = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift) ? sprintSpeed : normalSpeed;
        if (key -> scancode == sf::Keyboard::Scancode::Escape) window.close();
      }
      else if (event -> is<sf::Event::FocusLost>())
        std::cout << "Come back :(\n";
      else if (event -> is<sf::Event::FocusGained>())
        std::cout << "Welcome back :D\n";
      sf::Vector2f direction(0.f, 0.f);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) direction.x -= speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) direction.x += speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) direction.y -= speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) direction.y += speed;
      float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
      if (length != 0.f) {
        direction.x /= length;
        direction.y /= length;
      }
      sprite.move(direction * speed);
      heart.setPosition({780.f, 580.f});
      window.clear(sf::Color::Black);
      window.draw(heart);
      window.draw(sprite);
      window.display();
    }
  }
}
