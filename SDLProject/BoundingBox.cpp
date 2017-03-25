#include "BoundingBox.h"

BoundingBox::BoundingBox() {
	
}

BoundingBox::BoundingBox(Vector2D center, Vector2D halfSize) : center(center), halfSize(halfSize) {
	
}

bool BoundingBox::contains(Vector2D testPoint) const {
	if (center.x - halfSize.x < testPoint.x && testPoint.x < center.x + halfSize.x) {
		if (center.y - halfSize.y < testPoint.y && testPoint.y < center.y + halfSize.y) {
			return true;
		}
	}
	return false;
}

bool BoundingBox::intersects(BoundingBox testBox) const {
	if (center.x - halfSize.x < testBox.center.x + testBox.halfSize.x || testBox.center.x - testBox.halfSize.x < center.x + halfSize.x) {
		if (center.y - halfSize.y < testBox.center.y + testBox.halfSize.y || testBox.center.y - testBox.halfSize.y < center.y + halfSize.y) {
			return true;
		}
	}
	return false;
}