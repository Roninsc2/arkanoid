#include <QPainter>
#include "field.h"

class Drawer
{

public:
    Field field;
    void drawField(int countLife, QPainter & painter);
};
