#include <QtWidgets/QMainWindow>
#include "ui_GISers.h"

#include <QList>
#include <QDockWidget>
#include <QProgressBar>
#include <QLabel>
#include<QDockWidget>
// QGis include
#include <qgsmapcanvas.h>
#include <qgsmaplayer.h>
#include <qgslayertreeview.h>
#include <qgslayertreemapcanvasbridge.h>
#include <qgsscalecombobox.h>

class GISers : public QMainWindow
{
	Q_OBJECT

public:
	GISers(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~GISers();

	void addDockWidget(Qt::DockWidgetArea area, QDockWidget* dockwidget);

	//! 保持单一实例
	static inline GISers *instance() { return sm_instance; };
public slots:
	/**
	 *  添加矢量图层
	 *
	 * @return void -
	**/
	void addVectorLayers();

	/**
	 * 添加栅格图层
	 *
	 * @return void -
	**/
	void addRasterLayers();

	void autoSelectAddedLayer(QList<QgsMapLayer*> layers);
private:
	Ui::GISersClass ui;
	static GISers* sm_instance;

	QgsMapCanvas* mapCanvas; // 地图画布

	

	//! 图层管理
	QgsLayerTreeView* m_layerTreeView;
	QgsLayerTreeMapCanvasBridge *m_layerTreeCanvasBridge;


	QDockWidget *m_layerTreeDock;
	QDockWidget *m_layerOrderDock;


	QLabel* m_scaleLabel; // 在状态栏中显示“scale 1:”
	QgsScaleComboBox* m_scaleEdit; //! 在状态栏中显示比例尺值
	QProgressBar* m_progressBar;
	QLabel* m_coordsLabel; //! 在状态栏显示"Coordinate / Extent"
	QLineEdit* m_coordsEdit; //! 在状态栏显示地理坐标

	QList<QgsMapLayer*> mapCanvasLayerSet; // 地图画布所用的图层集合



	void initLayerTreeView();
	void createStatusBar();


};
