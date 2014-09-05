#ifndef LUX_CONTROLLER_H
#define LUX_CONTROLLER_H

namespace Lux {

class Controller
{
public:
    enum Direction {
        NoDirection,
        Right,
        Left,
        Up,
        Down
    };

    enum Button {
        NoButton,
        Enter,
        Back,
        Shoot,
        Jump
    };

    Controller();
    static void init();
    static bool isPressed(const Controller::Direction&);
    static bool isPressed(const Controller::Button&);

};
}

#endif // LUX_CONTROLLER_H