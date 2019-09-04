#ifndef _OCCVIEW_H_
#define _OCCVIEW_H_

#include <QtWidgets/QOpenGLWidget>

#include <AIS_InteractiveContext.hxx>

class QMenu;
class QRubberBand;

//! adapted a QGLWidget for OpenCASCADE viewer.
class OccView : public QOpenGLWidget
{
	Q_OBJECT

public:
	//! mouse actions.
	enum CurrentAction3d
	{
		CurAction3d_Nothing,
		CurAction3d_DynamicZooming,
		CurAction3d_WindowZooming,
		CurAction3d_DynamicPanning,
		CurAction3d_GlobalPanning,
		CurAction3d_DynamicRotation
	};

public:
	//! constructor.
	OccView(QWidget* parent);

	const Handle_AIS_InteractiveContext& getContext() const;

signals:
	void selectionChanged(void);

	public slots:
	//! operations for the view.
	void pan(void);
	void fitAll(void);
	void reset(void);
	void zoom(void);
	void rotate(void);

protected:
	// Paint events.
	virtual void paintEvent(QPaintEvent* e);
	virtual void resizeEvent(QResizeEvent* e);

	// Mouse events.
	virtual void mousePressEvent(QMouseEvent* e);
	virtual void mouseReleaseEvent(QMouseEvent* e);
	virtual void mouseMoveEvent(QMouseEvent * e);
	virtual void wheelEvent(QWheelEvent * e);

	// Button events.
	virtual void onLButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onMButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onRButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onMouseWheel(const int theFlags, const int theDelta, const QPoint thePoint);
	virtual void onLButtonUp(const int theFlags, const QPoint thePoint);
	virtual void onMButtonUp(const int theFlags, const QPoint thePoint);
	virtual void onRButtonUp(const int theFlags, const QPoint thePoint);
	virtual void onMouseMove(const int theFlags, const QPoint thePoint);

	// Popup menu.
	virtual void addItemInPopup(QMenu* theMenu);

protected:
	void init(void);
	void popup(const int x, const int y);
	void dragEvent(const int x, const int y);
	void inputEvent(const int x, const int y);
	void moveEvent(const int x, const int y);
	void multiMoveEvent(const int x, const int y);
	void multiDragEvent(const int x, const int y);
	void multiInputEvent(const int x, const int y);
	void drawRubberBand(const int minX, const int minY, const int maxX, const int maxY);
	void panByMiddleButton(const QPoint& thePoint);

private:

	//! the occ viewer.
	Handle(V3d_Viewer) myViewer;

	//! the occ view.
	Handle(V3d_View) myView;

	//! the occ context.
	Handle(AIS_InteractiveContext) myContext;

	//! save the mouse position.
	Standard_Integer myXmin;
	Standard_Integer myYmin;
	Standard_Integer myXmax;
	Standard_Integer myYmax;

	//! the mouse current mode.
	CurrentAction3d myCurrentMode;

	//! save the degenerate mode state.
	Standard_Boolean myDegenerateModeIsOn;

	//! rubber rectangle for the mouse selection.
	QRubberBand* myRectBand;

};

#endif // _OCCVIEW_H_
