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

	//! ���ֵ�һʵ��
	static inline GISers *instance() { return sm_instance; };
public slots:
	/**
	 *  ���ʸ��ͼ��
	 *
	 * @return void -
	**/
	void addVectorLayers();

	/**
	 * ���դ��ͼ��
	 *
	 * @return void -
	**/
	void addRasterLayers();

	void autoSelectAddedLayer(QList<QgsMapLayer*> layers);
private:
	Ui::GISersClass ui;
	static GISers* sm_instance;

	QgsMapCanvas* mapCanvas; // ��ͼ����

	

	//! ͼ�����
	QgsLayerTreeView* m_layerTreeView;
	QgsLayerTreeMapCanvasBridge *m_layerTreeCanvasBridge;


	QDockWidget *m_layerTreeDock;
	QDockWidget *m_layerOrderDock;


	QLabel* m_scaleLabel; // ��״̬������ʾ��scale 1:��
	QgsScaleComboBox* m_scaleEdit; //! ��״̬������ʾ������ֵ
	QProgressBar* m_progressBar;
	QLabel* m_coordsLabel; //! ��״̬����ʾ"Coordinate / Extent"
	QLineEdit* m_coordsEdit; //! ��״̬����ʾ��������

	QList<QgsMapLayer*> mapCanvasLayerSet; // ��ͼ�������õ�ͼ�㼯��



	void initLayerTreeView();
	void createStatusBar();


};
