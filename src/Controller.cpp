#include "Controller.h"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Joystick.hpp>

namespace Lux {

bool Controller::isPressed(const Controller::Direction& dir)
{
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 25;
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -25;
    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 25;
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -25;

    switch (dir) 
    {
    case NoDirection:
        return !right && !left && !up && !down;
    case Right:
        return right;
    case Left:
        return left;
    case Up:
        return up;
    case Down:
        return down;
    }

    return false;
}

bool Controller::isPressed(const Controller::Button& button)
{
    bool enter = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
    bool back = sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace);
    bool shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
    bool jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    switch (button)
    {
    case NoButton:
        return !enter && !back && !shoot && !jump;
    case Enter:
        return enter;
    case Back:
        return back;
    case Shoot:
        return shoot;
    case Jump:
        return jump;
    }

    return false;
}
}