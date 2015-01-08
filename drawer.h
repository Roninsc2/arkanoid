#include <QPainter>
#include "field.h"

class Drawer
{
public:
    Drawer(Field &_field, ImageManager &_image);

public:
    Field &field;
    ImageManager &image;

public:
    void drawField(QPainter &painter);
};
