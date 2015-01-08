#include <QPainter>
#include "field.h"

class TDrawer
{
public:
    TDrawer(TField &_field, TImageManager &_image);
    void drawField(QPainter &painter);

public:
    TField &field;
    TImageManager &image;
};
