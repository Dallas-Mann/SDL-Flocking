#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_
#include "Vector2D.h"
#include <vector>

class BoundingBox {
private:
	Vector2D center;
	Vector2D halfSize;

public:
	BoundingBox();
	BoundingBox(Vector2D center, Vector2D halfSize);
	bool contains(Vector2D testPoint) const;
	bool intersects(BoundingBox testBox) const;
};

#endif
