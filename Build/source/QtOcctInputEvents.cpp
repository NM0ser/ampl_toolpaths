#include "stdafx.h"

#include "QtOcct.h"

void QtOcct::mousePressEvent(QMouseEvent* e)
{

	if (e->button() == Qt::LeftButton)
	{
		onLButtonDown((e->button() | e->modifiers()), e->pos());
	}
	else if (e->button() == Qt::MidButton)
	{
		onMButtonDown((e->button() | e->modifiers()), e->pos());
	}
	else if (e->button() == Qt::RightButton)
	{
		onRButtonDown((e->button() | e->modifiers()), e->pos());
	}
}

void QtOcct::mouseMoveEvent(QMouseEvent * e)
{
	onMouseMove(e->buttons(), e->pos());
}

void QtOcct::wheelEvent(QWheelEvent * e)
{
	myView->StartZoomAtPoint(e->x(), e->y());
	onMouseWheel(e->buttons(), e->delta(), e->pos());
}

void QtOcct::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Up)
	{
		onUpKeyPress((e->key() | e->modifiers()));
	}
	else if (e->key() == Qt::Key_Down)
	{
		onDownKeyPress((e->key() | e->modifiers()));
	}
	else if (e->key() == Qt::Key_Right)
	{
		onRightKeyPress((e->key() | e->modifiers()));
	}
	else if (e->key() == Qt::Key_Left)
	{
		onLeftKeyPress((e->key() | e->modifiers()));
	}

}

void QtOcct::onRightKeyPress(const int theFlags)
{
	if ((theFlags & Qt::ShiftModifier) || (theFlags & Qt::ControlModifier))
	{
		myView->Pan(40,0);
	}
	else
	{
		if (myCurrentRotAxis == CurRotAxis_X)
		{
			myView->Rotate(V3d_X, 5 * PI / 180.0, 0.0, 0.0, 0.0);
		}
		else if (myCurrentRotAxis == CurRotAxis_Y)
		{
			myView->Rotate(V3d_Y, 5 * PI / 180.0, 0.0, 0.0, 0.0);
		}
		else
		{
			myView->Rotate(V3d_Z, 5 * PI / 180.0, 0.0, 0.0, 0.0);
		}
	}
}

void QtOcct::onLeftKeyPress(const int theFlags)
{
	if ((theFlags & Qt::ShiftModifier) || (theFlags & Qt::ControlModifier))
	{
		myView->Pan(-40, 0);
	}
	else
	{
		if (myCurrentRotAxis == CurRotAxis_X)
		{
			myView->Rotate(V3d_X, -5 * PI / 180.0, 0.0, 0.0, 0.0);
		}
		else if (myCurrentRotAxis == CurRotAxis_Y)
		{
			myView->Rotate(V3d_Y, -5 * PI / 180.0, 0.0, 0.0, 0.0);
		}
		else
		{
			myView->Rotate(V3d_Z, -5 * PI / 180.0, 0.0, 0.0, 0.0);
		}
	}

}

void QtOcct::onUpKeyPress(const int theFlags)
{
	if ((theFlags & Qt::ShiftModifier) || (theFlags & Qt::ControlModifier))
	{
		myView->Pan(0, 40);
	}
	else
	{
		myView->Zoom(0, 0, 10, 10);
	}
}

void QtOcct::onDownKeyPress(const int theFlags)
{
	if ((theFlags & Qt::ShiftModifier) || (theFlags & Qt::ControlModifier))
	{
		myView->Pan(0, -40);
	}
	else
	{
		myView->Zoom(10, 10, 0, 0);
	}
}

void QtOcct::onLButtonDown(const int theFlags, const QPoint thePoint)
{
	Q_UNUSED(theFlags);

	// Save the current mouse coordinate in min.
	myXmin = thePoint.x();
	myYmin = thePoint.y();
	myXmax = thePoint.x();
	myYmax = thePoint.y();

	if (myCurrentMode == CurAction3d_DynamicRotation)
	{
		myView->StartRotation(thePoint.x(), thePoint.y(), 0.4);
	}
	else if (myCurrentMode == CurAction3d_DynamicZooming)
	{
		//myView->StartZoomAtPoint(thePoint.x(), thePoint.y());
	}

}

void QtOcct::onMButtonDown(const int theFlags, const QPoint thePoint)
{
	Q_UNUSED(theFlags);

	// Save the current mouse coordinate in min.
	myXmin = thePoint.x();
	myYmin = thePoint.y();
	myXmax = thePoint.x();
	myYmax = thePoint.y();

	myView->StartRotation(thePoint.x(), thePoint.y(), 0.4);
}

void QtOcct::onRButtonDown(const int theFlags, const QPoint thePoint)
{
	Q_UNUSED(theFlags);
	myXmin = thePoint.x();
	myYmin = thePoint.y();
	myXmax = thePoint.x();
	myYmax = thePoint.y();
}

void QtOcct::onMouseWheel(const int theFlags, const int theDelta, const QPoint thePoint)
{
	Q_UNUSED(theFlags);

	Standard_Integer aFactor = 16;

	Standard_Integer aX = thePoint.x();
	Standard_Integer aY = thePoint.y();

	if (theDelta > 0)
	{
		aX += aFactor;
		aY += aFactor;
	}
	else
	{
		aX -= aFactor;
		aY -= aFactor;
	}

	myView->ZoomAtPoint(thePoint.x(), thePoint.y(), aX, aY);
}

void QtOcct::onMouseMove(const int theFlags, const QPoint thePoint)
{

	if (theFlags & Qt::LeftButton)
	{
		switch (myCurrentMode)
		{
		case CurAction3d_DynamicRotation:
			myView->Rotation(thePoint.x(), thePoint.y());
			break;

		case CurAction3d_DynamicZooming:
		{
			Standard_Real curX = thePoint.x();
			Standard_Real curY = thePoint.y();

			if(zoomInBool == true)
			{
				zoomInBool = false;
				myXmax = curX;
				myYmax = curY;
				myView->Zoom(myXmin, myYmin, curX, curY);
			}
			else
			{
				zoomInBool = true;
				myXmin = curX;
				myYmin = curY;
				myView->Zoom(myXmax, myYmax, curX, curY);
			}
			break;
		}

		case CurAction3d_DynamicPanning:
			myView->Pan(thePoint.x() - myXmin, myYmin - thePoint.y());
			myXmin = thePoint.x();
			myYmin = thePoint.y();
			break;

		//default:
		//	drawRubberBand(myXmin, myYmin, thePoint.x(), thePoint.y());
		//	dragEvent(thePoint.x(), thePoint.y());
		//	break;
		}
	}
	else if (theFlags & Qt::MiddleButton)
	{
		myView->Rotation(thePoint.x(), thePoint.y());
	}
	else if (theFlags & Qt::RightButton)
	{
		myView->Pan(thePoint.x() - myXmin, myYmin - thePoint.y());
		myXmin = thePoint.x();
		myYmin = thePoint.y();
	}


	//// Ctrl for multi selection.
	//if (theFlags & Qt::ControlModifier)
	//{
	//	multiMoveEvent(thePoint.x(), thePoint.y());
	//}
	//else
	//{
	//	moveEvent(thePoint.x(), thePoint.y());
	//}
}

/* Code snippets for selection features -> No need for user selection at this stage */
void QtOcct::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		onLButtonUp((e->button() | e->modifiers()), e->pos());
	}
	//else if (e->button() == Qt::MidButton)
	//{
	//	onMButtonUp((e->button() | e->modifiers()), e->pos());
	//}
	//else if (e->button() == Qt::RightButton)
	//{
	//	onRButtonUp((e->button() | e->modifiers()), e->pos());
	//}
}
//
//void QtOcct::dragEvent(const int x, const int y)
//{
//	myContext->Select(myXmin, myYmin, x, y, myView);
//
//	emit selectionChanged();
//}
//
//void QtOcct::multiDragEvent(const int x, const int y)
//{
//	myContext->ShiftSelect(myXmin, myYmin, x, y, myView);
//
//	emit selectionChanged();
//
//}
//
//void QtOcct::inputEvent(const int x, const int y)
//{
//	Q_UNUSED(x);
//	Q_UNUSED(y);
//
//	myContext->Select();
//
//	emit selectionChanged();
//}
//
//void QtOcct::multiInputEvent(const int x, const int y)
//{
//	Q_UNUSED(x);
//	Q_UNUSED(y);
//
//	myContext->ShiftSelect();
//
//	emit selectionChanged();
//}
//
//void QtOcct::moveEvent(const int x, const int y)
//{
//	myContext->MoveTo(x, y, myView);
//}
//
//void QtOcct::multiMoveEvent(const int x, const int y)
//{
//	myContext->MoveTo(x, y, myView);
//}
//
//void QtOcct::drawRubberBand(const int minX, const int minY, const int maxX, const int maxY)
//{
//	QRect aRect;
//
//	// Set the rectangle correctly.
//	(minX < maxX) ? (aRect.setX(minX)) : (aRect.setX(maxX));
//	(minY < maxY) ? (aRect.setY(minY)) : (aRect.setY(maxY));
//
//	aRect.setWidth(abs(maxX - minX));
//	aRect.setHeight(abs(maxY - minY));
//
//	if (!myRectBand)
//	{
//		myRectBand = new QRubberBand(QRubberBand::Rectangle, this);
//
//		// setStyle is important, set to windows style will just draw
//		// rectangle frame, otherwise will draw a solid rectangle.
//		myRectBand->setStyle(QStyleFactory::create("windows"));
//	}
//
//	myRectBand->setGeometry(aRect);
//	myRectBand->show();
//}

//void QtOcct::addItemInPopup(QMenu* theMenu)
//{
//	Q_UNUSED(theMenu);
//}

//void QtOcct::popup(const int x, const int y)
//{
//	Q_UNUSED(x);
//	Q_UNUSED(y);
//}
//
void QtOcct::onLButtonUp(const int theFlags, const QPoint thePoint)
{
	//// Hide the QRubberBand
	//if (myRectBand)
	//{
	//	myRectBand->hide();
	//}

	//// Ctrl for multi selection.
	//if (thePoint.x() == myXmin && thePoint.y() == myYmin)
	//{
	//	if (theFlags & Qt::ControlModifier)
	//	{
	//		multiInputEvent(thePoint.x(), thePoint.y());
	//	}
	//	else
	//	{
	//		inputEvent(thePoint.x(), thePoint.y());
	//	}
	//}

}
//
//void QtOcct::onMButtonUp(const int theFlags, const QPoint thePoint)
//{
//	Q_UNUSED(theFlags);
//	Q_UNUSED(thePoint);
//}
//
//void QtOcct::onRButtonUp(const int theFlags, const QPoint thePoint)
//{
//	Q_UNUSED(theFlags);
//
//	popup(thePoint.x(), thePoint.y());
//}